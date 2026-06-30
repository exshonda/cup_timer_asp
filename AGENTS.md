# CLAUDE.md

このファイルはSTM32を用いたカップラーメンタイマの作成に関する仕様書です．

## 概要
- タイマを起動してから，設定した時間が経過したことを知らせる．
- 設定時間は30秒刻みで設定できる．

## 実装ステータス
- [x] ハードウェア抽象化レイヤ（`device/`）: 実装済み
- [ ] アプリケーションロジック（`cup_timer/`）: 未実装（設計段階）


## ハードウェ仕様
- LED1-LED4 : GPIOで制御可能なLED
- SW1 : スライドスイッチ．ON/OFFの状態をGPIOで読み込める
- PUSH1 : PUSHスイッチ．ON/OFFの状態をGPIOで読み込める

## 外部仕様
- 電源がONの間（プログラムが動いている間），LED1の点灯・消灯を1秒間隔で繰り返す．
- SW1がONになると設定時間を30秒にして，タイマを起動する．
- SW1がOFFになると，タイマを停止する．
- タイマが動いている間にPUSH1がONになると，ONの間LED2を点灯させ，設定時間を30秒延長する．
- タイマが動いている間は，10秒間隔で，LED4を2回点滅させる．LED4の2回点滅は，点灯・消灯を0.25秒間隔で2回繰り返すことで行う．
- 設定時間が経過すると，LED4を15秒間点滅させた後，消灯する．LED4の点滅は，点灯・消灯を0.25秒間隔で繰り返すことで行う．

## 設計
### 設計方針
- タスク
    - タイマーを管理するタイマータスクと，LED4の点滅を行うLED4点滅タスクの2つ
- 周期ハンドラ
    - スイッチの状態取得は周期ハンドラで行う
    - 各種時間制性も周期ハンドラで行う
- イベント通知
    - 周期ハンドラとタスク間，タスク間のイベント通知はイベントフラグにより行う

## タイマタスクの設計
- イベント（`FLG_TIMER`）
    - `TIMER_SW1_ON` (0x01)：SW1 ON
    - `TIMER_SW1_OFF` (0x02)：SW1 OFF
    - `TIMER_PUSH1_ON` (0x04)：PUSH1 ON
    - `TIMER_BASE_TIME` (0x08)：１秒経過
- 状態遷移図
@startuml
[*] --> タイマーOFF

タイマーOFF : entry / 
タイマーOFF --> タイマーOFF : SW1 OFF / LED1 OFF
タイマーOFF --> タイマーON : SW1 ON / timeout = 30

タイマーON --> タイマーON : SW8 ON / timeout += 30
タイマーON --> タイマーOFF : SW1 OFF / LED4 OFF
タイマーON --> C : 1秒経過 / timeout -= 1

state C <<choice>>
C --> タイマーOFF : if (timeout == 0) /\nLED4点滅タスクに60回点滅要求
C --> タイマーON : [else] /\nif ((timeout %% 10) == 0)\nLED4点滅タスクに4回点滅要求

@enduml


## LED4点滅タスク
- イベント（`FLG_BLINK`）
    - `BLINK_ACTIVE` (0x01)：アクティブ点滅要求（2回点滅）
    - `BLINK_TIMEOUT` (0x02)：タイムアウト通知（15秒間点滅）
    - `BLINK_OFF` (0x08)：OFF通知
    - `BLINK_BLINK` (0x04)：0.25秒経過（点滅タイミング）
- 状態遷移図
@startuml
[*] --> 休止

state 点滅 {
  [*] --> 点灯
  点灯 --> 消灯 : 0.25秒経過 /\nbcount -= 1\nLED4消灯
  消灯 --> 点灯 : 0.25秒経過 /\nbcount -= 1\nLED4点灯
}

休止 --> 点滅 : タイムアウト通知 /\nbcount = 60
休止 --> 点滅 : 4回点滅要求 /\nbcount = 4
点滅 --> 休止 : OFF通知 /\nLED4消灯

@enduml

### 周期ハンドラと初期化ルーチン
- 周期ハンドラ
    - `LED1_BLINK_HANDLER` (led1_blink_handler) ：1秒周期
    - `LED4_BLINK_TIME_HANDLER` (led4_blink_time_handler) ：250ms周期
    - `SW_SCAN_HANDLER` (sw_scan_handler) ：10ms周期
    - `BASE_TIME_HANDLER` (base_time_handler) ：1秒周期

### 初期化ルーチン
- ハードウェアを初期化
- スイッチの初期状態を初期化

## 時間定数の計算根拠
- LED4点滅周期：`LED4_BLINK_INTERVAL` = 250ms
- 2回点滅（アクティブ時）：`ACT_BLINK_TIME` (4回状態遷移) $\times$ 250ms = 1.0秒
- 15秒点滅（タイムアウト時）：`TIMEOUT_BLINK` (60回状態遷移) $\times$ 250ms = 15.0秒

## 実装詳細

### 1. タスクおよびハンドラの優先度
- **周期ハンドラ**: 高優先度（カーネル規定の優先度）
- **タイマタスク**: 優先度 10
- **LED4点滅タスク**: 優先度 11

### 2. イベントフラグの定義
- `FLG_TIMER` および `FLG_BLINK` の各ビット定義は、`cup_timer.h` 内に `#define` マクロとして定義する。

### 3. スイッチの論理レベル
- 本プロジェクトでは、「High (1) = ON」として扱う。

### 4. LED1の点滅制御
- `LED1_BLINK_HANDLER` 内で LED1 の状態を反転（トグル）させることで、タスクを介さず独立して点滅させる。

### 5. 初期化シーケンス
1. **ハードウェア初期化**: `led_init`, `switch_slide_init`, `switch_push_init` 等の関数を順次呼び出し、物理ポートを初期化する。
2. **カーネルオブジェクト生成**: ASPカーネルの起動処理により、`.cfg` ファイルの定義に基づきタスクやイベントフラグが自動的に生成される。
3. 
## アーキテクチャ

### ディレクトリ構成
- [cup_timer/](cup_timer/) — アプリケーションプロジェクト
- [device/](device/) — STM32F4共通ハードウェアライブラリ

### 主要ファイル
| ファイル | 役割 |
|----------|------|
| [cup_timer/cup_timer.c](cup_timer/cup_timer.c) | タスクなど |
| [cup_timer/cup_timer.h](cup_timer/cup_timer.h) | cup_timerのタスク定義など |
| [cup_timer/asp_prog.cfg](cup_timer/asp_prog.cfg) | カーネルコンフィギュレーションファイル |
| [cup_timer/Makefile](cup_timer/Makefile) | メイクファイル |

### 共通ファイル
| ファイル | 役割 |
|----------|------|
| [device/device.c](device/device.c) | デバイスドライバ |
| [device/device.h](device/device.h) | 上記のヘッダファイル |
| [device/cmsis_f4.h](device/cmsis_f4.h) | Cortex-M4用定義 |
| [device/stm32f4xx.h](device/stm32f4xx.h) | ハードウェア初期化等の必要定義 |


## 開発実行環境

### OS
- TOPPERS/ASPカーネル(ASPカーネル)を使用する
  - ITRON仕様をベースにしているが異なるため，必ずコードの書く前にはマニュアルを読むこと
- ASPカーネルは **μITRON 4.0仕様をベースとしているが完全互換ではない**。`TA_TFIFO`/`TA_MFIFO` 等の値=0属性，`acre_*`/`del_*` の動的生成API，`frsm_tsk`/`set_tim` 等は **使えない**。差分の詳細は `doc/TOPPERS-ASP_RTOS仕様.md` の §1.1 を参照。
- **すべてのカーネルオブジェクトは静的API（`.cfg`）で生成**する。動的生成APIはASP標準では未サポート。タスク・セマフォ・イベントフラグ・データキュー・ミューテックス・固定長メモリプール・周期ハンドラ・アラームハンドラ・ISR等は `.cfg` の `CRE_*`/`DEF_*`/`ATT_*`/`CFG_INT` で予め登録する。
- device/ 以下のファイルは変更しない

#### ASPカーネルのマニュアル

`../toppers-asp/doc/` 配下のスタイルガイドを参照すること

- `doc/TOPPERS-ASP_RTOS仕様.md` — 概念・状態モデル・初期化／終了。**§1.1 にμITRON 4.0との差分一覧**
- `doc/TOPPERS-ASP_API仕様.md` — サービスコール（C言語API）
- `doc/TOPPERS-ASP_静的API_API仕様.md` — `.cfg` の静的API
- `doc/TOPPERS-ASP_静的API_エラー.md` — エラーコード一覧
- `doc/TOPPERS-ASP_クイックルール.md` — FreeRTOS/Zephyr対応表＋頻出パターン

#### サンプル

`../toppers-asp/example/` 配下のサンプル19本をテンプレートとして使う。インデックスは `README.md` を参照。

### 評価ボード
- NUCLEO-F401RE + enpit-Emb シールド
  - ST-Linkによるデバッグが可能

### 開発環境
- STM32CubeIDE 2.1.1
  - https://www.st.com/ja/development-tools/stm32cubeide.html

### ビルド

### STM32CubeIDEよるGUIビルド
- STM32CubeIDEを起動して，ワークスペースを作成する．
  - 本レポジトリをトップとすることを推奨
- File -> Import を選択して，ダイアログボックス開いたらExisting Project int Workspaceを選択
- 次のダイアログボックスでSelect root directory のBrowseを選択して，本レポジトリをトップを選択
  - すでに指定されていてももう一度選択
  - Projects に cup_timer があるのでチェックボックスをチェック
  - Finishを選択してインポート
- ビルド
  - プロジェクトビューからcup_timerを選択して右クリックしてBuild Projectを選択
  - asp.elf が完成すれば成功
- 実行&デバッグ
  - cup_timer.launch を右クリック
    - Debug As -> cup_timer を選択
  - シリアルポートにRTOSの出力が出力される
    - 115200bps

### CLIビルド
- 環境構築
  - Cygwin/WSL2等のUNIXコマンドがが使用可能な環境をインストールする
    - make が必要
  - コンパイラ(GCC)にパスを通す
    - STM32CubeIDEのインストールパス以下にコンパイラがあるので通す
    - \STM32CubeIDE_2.1.1\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.14.3.rel1.win32_1.0.100.202602081740\tools\bin
  - 書き込みツールのパスを通す
    - Makefile
      - STM32CUBEIDE_PLUGINS = C:/sw/ST/STM32CubeIDE_2.1.1/STM32CubeIDE/plugins
- ターミナルの実行
  - Cygwinの場合 : Cygwinを起動する(-l -cをオプションで指定する)
  - cup_timerに移動
- ビルド
  - make
- 実行
  - maker run 
- gdbによるデバッグ
  - maker db

## 開発に伴うドキュメント

### 作業単位のドキュメント（`.steering/[YYYYMMDD]-[開発タイトル]/`）

特定の開発作業における「**今回何をするか**」を定義する一時的なステアリングファイル。
作業完了後は参照用として保持されますが、新しい作業では新しいディレクトリを作成します。

- **requirements.md** - 今回の作業の要求内容
  - 変更・追加する機能の説明
  - ユーザーストーリー
  - 受け入れ条件
  - 制約事項

- **design.md** - 変更内容の設計
  - 実装アプローチ
  - 変更するコンポーネント
  - データ構造の変更
  - 影響範囲の分析

- **tasklist.md** - タスクリスト
  - 具体的な実装タスク
  - タスクの進捗状況
  - 完了条件

### ステアリングディレクトリの命名規則

```
.steering/[YYYYMMDD]-[開発タイトル]/
```

**例：**
- `.steering/20250103-initial-implementation/`
- `.steering/20250115-add-tag-feature/`
- `.steering/20250120-fix-filter-bug/`
- `.steering/20250201-improve-performance/`

## 開発プロセス

### 初回セットアップ時の手順

#### 初回実装用のステアリングファイル作成

初回実装用のディレクトリを作成し、実装に必要なドキュメントを配置します。

```bash
mkdir -p .steering/[YYYYMMDD]-initial-implementation
```

作成するドキュメント：
1. `.steering/[YYYYMMDD]-initial-implementation/requirements.md` - 初回実装の要求
2. `.steering/[YYYYMMDD]-initial-implementation/design.md` - 実装設計
3. `.steering/[YYYYMMDD]-initial-implementation/tasklist.md` - 実装タスク


### 機能追加・修正時の手順

#### 作業ドキュメント作成

作業単位のドキュメントを作成します。
各ドキュメント作成後、必ず確認・承認を得てから次に進みます。

1. `.steering/[YYYYMMDD]-[開発タイトル]/requirements.md` - 要求内容
2. `.steering/[YYYYMMDD]-[開発タイトル]/design.md` - 設計
3. `.steering/[YYYYMMDD]-[開発タイトル]/tasklist.md` - タスクリスト

**重要：** 1ファイルごとに作成後、必ず確認・承認を得てから次のファイル作成を行う
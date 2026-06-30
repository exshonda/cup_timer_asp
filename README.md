# RTOSを用いたカップラーメンタイマー開発プロジェクト

TOPPERS/ASP カーネル上で動作する「カップラーメンタイマー」教材。
**NUCLEO-F401RE**（Cortex-M4）と **NUCLEO-H533RE**（Cortex-M33）の2ボードに対応。

- 仕様・設計・ビルド手順の詳細は [AGENTS.md](AGENTS.md) を参照。

## ディレクトリ構成

```
cup_timer_asp/
├── AGENTS.md          仕様・設計・開発手順
├── F401RE/            NUCLEO-F401RE 版
│   ├── cup_timer/     アプリ（cup_timer.c/.h, asp_prog.cfg, Makefile, CubeIDEプロジェクト）
│   └── device/        HAL（STM32F4・生レジスタ）
├── H533RE/            NUCLEO-H533RE 版（Cortex-M33）
│   ├── cup_timer/     アプリ（TARGET=nucleo_h533re_gcc）
│   └── device/        HAL（STM32H5・CMSIS）
├── asp/               TOPPERS/ASP カーネル本体＋ターゲット依存部
│                       （target/nucleo_f401re_gcc, target/nucleo_h533re_gcc,
│                        arch/arm_m_gcc/stm32f4xx_stm32cube, .../stm32h5xx_stm32cube）
├── asp_docs/          ASP仕様マニュアル（TOPPERS-ASP_*.md）
└── asp_examples/      ASPサンプル（19本）
```

## ビルド（CLI 概要）

```sh
cd F401RE/cup_timer    # または H533RE/cup_timer
make                   # asp.elf を生成
```
- ツールチェーン: `arm-none-eabi-gcc` ＋ make（UNIX環境）。
- H533RE版は SYSCLK 250MHz / **ソフト浮動小数点**（Cortex-M33の制約。AGENTS.md参照）。

## ボード差（F401RE → H533RE）
enpit-Emb シールドの Arduino 位置→MCUピン対応がボードで一部異なる：
- LED1-4=PA8/7/6/5, SW1-3=PB3/4/5 は両ボード共通。
- **SW4**: F401=PB6 → **H533=PC9**、**PUSH1/2**: F401=PA9/PA10 → **H533=PC7/PC8**（内部プルダウン）。

詳細・状態遷移・開発プロセスは [AGENTS.md](AGENTS.md)。

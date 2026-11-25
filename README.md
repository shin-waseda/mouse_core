# mouse_core

マイクロマウスのファームの機体によらない部分．今はロジック層(ハードにさわらない計算)だけで，アプリ層も移す予定．
(2026-11-25 に mouse_logic から名前を変えた)
yuho(クラシック)と宵桜(yozakura，ハーフ)の両方から git submodule で使う．

## 写した元

- yuho(shin-waseda/yuho_vre1)の `15b08f8` の `Core/Inc/logic/` と `Core/Src/logic/`(2026-11-24)．それまでの履歴は yuho のリポジトリにある．
- `crc32` は宵桜から移した．
- `maze/maze_types.h` の `MAZE_COST_BITS` を params.h で変えられるようにした(宵桜の変更．既定は 13 で yuho は変わらない)．

## 構成

```
Inc/logic/   ヘッダ(include は "logic/..." の形)
Src/logic/   ソース
```

使う側(各機体)の CMake で，`Src/logic/` の .c をビルドに入れ，`Inc/` を include のパスに足す．

## 決まり

- ロジック層は `global.h` と `params.h` だけを include してよい(ロジック層の中どうしは自由)．HAL や interface 層，app 層は include しない．
- `global.h` と `params.h` は各機体のリポジトリに置く．params.h にはロジック層が使う名前をすべて定義する(値は機体ごと)．
- 機体ごとに変わる値は params.h に置き，ここに直接書かない．
- ここを変えたら，両方の機体でビルドを確かめる．

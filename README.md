## VMC4UE とは
VirtualMotionCapture から OSC で姿勢情報を受信して UE に反映するためのプラグインです。

動作には sh_akira さんの VirtualMotionCapture(v0.36～) が必要です。
https://sh-akira.github.io/VirtualMotionCapture/download.html

※それ以前のバージョン(～v0.35)では使えません

## 動作環境
- UE4.26
- UE4.27
- UE5.0
- UE5.1

## 使い方
https://github.com/HAL9HARUKU/VMC4UE/wiki

## ライセンス
MIT

## 作者
[はるく](https://twitter.com/HAL9_HARUKU)

## 履歴

2022/11/20 v0.4.7
UE5.1 に対応。

2022/05/25 v0.4.7
通信が途切れる問題の対策。
一部環境で Shipping ができない問題の対策。

2022/03/26 v0.4.6
UE5.0 を EA2 から Preview2 に変更。

2021/09/20 v0.4.5
UE4.27 対応。
UE5.0EA を 1 から 2 に変更。
UE4.25 の DLL 非サポート。
データを長時間受信できないコネクションの再接続機能を追加。

2021/05/29 v0.4.4
UE5.0EA1 対応。
Shipping 対応。

2020/12/06 v0.4.3
UE4.26 対応。
UE4.21 の DLL 非サポート。

2020/07/25 v0.4.2
UE4.25 対応。
2 バージョン対応のため DLL ファイルを再び削除。

2020/06/13 v0.4.1
DLL ファイルを追加。

2019/12/19 v0.4.0
複数人のキャプチャーデータに対応。

2019/11/24 v0.3.0
ブレンドシェイプに対応。
新しいマッピングファイルに対応。

2019/11/10 v0.2.0
ボーンマップを Unity で生成して UE4 でインポートするように変更。

2019/11/09 v0.1.0
VirtualMotionCapture で使用する VRM と同じ VRM での位置・姿勢の反映のみ対応。


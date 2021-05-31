# mycat（練習プロジェクト）

ファイルの内容を標準出力に出力するコマンド `mycat` を作成しなさい．

* `main.c`が与えられます．
* 25行目にファイルを開く処理を適切に実装しなさい．
* 実装が終われば，正しく実装できたかを確認しましょう．
* 正しく実装できたことを確認できれば，GitHub に更新内容を push してください．

### 入出力例

```sh
$ ls
file1.txt   file2.txt   file3.txt
$ mycat file1.txt
file1
file1file1
file1file1file1
$ mycat file3.txt file1.txt
file3file3file3
file3file3
file3
file1
file1
file1file1
file1file1file1
$ mycat # このステップでは何も行わない．
```

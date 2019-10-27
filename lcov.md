## 1.使用 `gcc` 编译程序
```
gcc -fprofile-arcs -ftest-coverage test.c -o test
```
`-fprofile-arcs`、`-ftest-coverage` 参数可以通过 `man gcc` 查看。

## 2.运行程序
```
./test
```
注：需要先运行程序才能得到代码的执行情况！

## 3.使用 `lcov` 统计代码执行情况
```
$ lcov -c -d . -o coverage.info
$ genhtml coverage.info -o out
```
`lcov` 使用可以参考[这里]

[这里]:http://ltp.sourceforge.net/coverage/lcov.php

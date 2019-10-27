# 1.使用 `gcc` 编译程序
```
gcc -fprofile-arcs -ftest-coverage test.c -o test
```

# 2.运行程序
```
./test
```

# 3.使用 `lcov` 统计代码执行情况
```
$ lcov -c -d . -o coverage.info
$ genhtml coverage.info -o out
```

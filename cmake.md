## 修改默认编译器
```
SET(CMAKE_C_COMPILER /usr/local/bin/afl-gcc)
SET(CMAKE_CXX_COMPILER /usr/local/bin/afl-g++)
```

## 添加编译选项
```
add_compile_options(-O0)
add_compile_options(-g)
```

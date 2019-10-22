# Building llvm
尝试编译 `debug` 模式，但是每次编译都失败，最后编译 `Release` 版本顺利通过，并且编译时间节省很多。  
找了很多非官方的build方法，但是都没能成功，最终老老实实按照[官方教程][build]成功build。

按照[官方教程][build]下载好 `llvm-project`, project 比较大，下载了 90%+ 断了一次，然后又重新下了一遍:sweat:
```
git clone https://github.com/llvm/llvm-project.git
```
下载完成后执行如下命令:
```
cd llvm-project
mkdir build
cd build
```
注意：build目录不能放在llvm-project/llvm目录里面，否则会导致编译失败([Create a build directory. Building LLVM in the source directory is not supported][not support])。因为试了很多次(编译不同的版本，以及同一个版本编译几次)不加 `Debug` 每次都是编译 2h+ 后出现错误，编译不完整，clang也没法用。
最终尝试加上如下参数，编译成功了，而且编译速度也缩短到一个多小时。
```
~/LLVM/build$ cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang" ../llvm
```


--------------------
[build]:https://llvm.org/docs/GettingStarted.html
[not support]:http://releases.llvm.org/9.0.0/docs/CMake.html#quick-start

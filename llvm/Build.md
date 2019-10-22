尝试编译 `debug` 模式，但是每次编译都失败，最后编译 `Release` 版本顺利通过，并且编译时间节省很多。  
找了很多非官方的build方法，但是都没能成功，最终老老实实按照[官方教程][build]成功build。

按照[官方教程][build]下载好 `llvm-project`, `project`比较大，下载了90%+断了一次，然后又重新下了一遍:sweat:
```
git clone https://github.com/llvm/llvm-project.git
```
下载完成后执行如下命令
```
cd llvm-project
mkdir build
cd build
cmake -G <generator> [options] ../llvm
```















--------------------
[build]:https://llvm.org/docs/GettingStarted.html

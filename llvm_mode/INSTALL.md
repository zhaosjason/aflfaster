# Building AFLFaster (ie. AFL in llvm_mode)
## Install Install LLVM 3.8.1 & clang 3.8.1
 * Download and unzip llvm-3.8.1
```
    wget http://releases.llvm.org/3.8.1/llvm-3.8.1.src.tar.xz
    tar -xf llvm-3.8.1.src.tar.xz
```
 * Download and unzip clang-3.8.1
```
    wget http://releases.llvm.org/3.8.1/cfe-3.8.1.src.tar.xz
    tar -xf cfe-3.8.1.src.tar.xz
```
 * Rename clang and move to llvm-3.8.1.src/tools/
```
    mv cfe-3.8.1.src llvm-3.8.1.src/tools/clang
```
 * Configure and build LLVM using cmake
```
    cd llvm-3.8.1.src && mkdir build && cd build
    cmake ..
    make -j16
```
 * Install LLVM (alternatively you may be able to build AFLFaster by appending build/bin/ to your $PATH environment variable before compiling afl-clang-fast in llvm_mode/)
```
    sudo make install
```

That's it, you should now be able to build AFLFaster!


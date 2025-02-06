
# build

mkdir build && cd build

cmake ..

make

# deps

```
build $ ldd compiler 
        linux-vdso.so.1 (0x00007ffc83bf6000)
        libclang-cpp.so.18.1 => /usr/lib/llvm-18/lib/libclang-cpp.so.18.1 (0x00007f7ed8033000)
        libLLVM-18.so.18.1 => /lib/x86_64-linux-gnu/libLLVM-18.so.18.1 (0x00007f7ed09fa000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f7ed0818000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f7ed07fd000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f7ed060b000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f7ed05e8000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f7ed0497000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f7edbf49000)
        libffi.so.7 => /lib/x86_64-linux-gnu/libffi.so.7 (0x00007f7ed048b000)
        libedit.so.2 => /lib/x86_64-linux-gnu/libedit.so.2 (0x00007f7ed0453000)
```

#!/bin/bash
# - travishelper.sh
# - helps set up travis with the proper gcc/clang

echo CXX: $1

if [ "$1" == "g++" ]; then
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -qq
    sudo apt-get install -qq gcc-4.8 g++-4.8
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
fi

if [ "$1" == "clang++" ]; then
    wget -O - http://llvm.org/apt/llvm-snapshot.gpg.key | sudo apt-key add -
    sudo echo deb http://llvm.org/apt/precise/ llvm-toolchain-precise-3.5 main >> /etc/apt/sources.list
    sudo echo deb-src http://llvm.org/apt/precise/ llvm-toolchain-precise-3.5 main >> /etc/apt/sources.list
    apt-get install clang-3.5 clang-3.5-doc libclang-common-3.5-dev libclang-3.5-dev libclang1-3.5 libclang1-3.5-dbg libllvm-3.5-ocaml-dev libllvm3.5 libllvm3.5-dbg lldb-3.5 llvm-3.5 llvm-3.5-dev llvm-3.5-doc llvm-3.5-examples llvm-3.5-runtime clang-modernize-3.5 clang-format-3.5 python-clang-3.5 lldb-3.5-dev
fi

#!/bin/bash
# - travishelper.sh
# - helps set up travis with the proper gcc/clang

echo CXX: $1

#gcc 4.8
if [ "$1" == "g++" ]; then
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -qq
    sudo apt-get install -qq gcc-4.8 g++-4.8
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
fi

#clang 3.5
if [ "$1" == "clang++" ]; then
    sudo apt-get update
    sudo echo deb http://llvm.org/apt/precise/ llvm-toolchain-precise-3.5 main >> /etc/apt/sources.list
    sudo echo deb-src http://llvm.org/apt/precise/ llvm-toolchain-precise-3.5 main >> /etc/apt/sources.list
    sudo echo deb http://ppa.launchpad.net/ubuntu-toolchain-r/test/ubuntu precise main >> /etc/apt/sources.list
    wget -O - http://llvm.org/apt/llvm-snapshot.gpg.key | sudo apt-key add -
    sudo apt-get update
    apt-get install clang-3.5 lldb-3.5
    cat /etc/apt/sources.list
    ls /usr/bin
fi

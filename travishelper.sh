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

#clang stable
if [ "$1" == "clang++" ]; then
    sudo add-apt-repository -y ppa:h-rayflood/llvm-upper
    sudo apt-get update -qq
    sudo apt-get install -qq llvm-3.5
    clang --version
fi

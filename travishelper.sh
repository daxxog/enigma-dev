#!/bin/bash
# - travishelper.sh
# - helps set up travis with the proper gcc/clang

echo CXX: $1

sudo add-apt-repository -y ppa:h-rayflood/gcc-upper
sudo apt-get update -qq
sudo apt-get dist-upgrade -qq

#gcc 4.9
if [ "$1" == "g++" ]; then
    yes | sudo  apt-get install -qq gcc-4.9 g++-4.9
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 90
fi

#clang 3.5
if [ "$1" == "clang++" ]; then
    sudo add-apt-repository -y ppa:h-rayflood/llvm-upper
    sudo apt-get update -qq
    sudo apt-get dist-upgrade -qq
    yes | sudo apt-get install -qq llvm-3.5
    sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-3.5 90
    clang++ --version
fi

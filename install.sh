#!/bin/sh

export LANG=ru_RU.UTF-8

# Installing libraries and C++ compiler

sudo apt update
sudo apt install libncurses6 libstdc++6 libncurses5-dev libncursesw5-dev libgcc1 libc6 g++

# Downloading source code

sudo apt install git
sudo apt install wget
wget https://github.com/Concorde34/menu_demo/archive/refs/heads/main.zip

# Unpacking source archive

unzip main.zip
cd menu_demo-main

# Build

sudo apt install make
make
mv main*[0-9] ..
cd ..
chmod +x main*[0-9]

# Cleanup
rm -rf main.zip menu_demo-main
sudo apt autoremove

echo "Исполняемый файл программы находится в текущей дерриктории и начинается с main"

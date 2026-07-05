# console-menu-lib

Reusable C++ library for building interactive console menus using ncurses.

## What it does
Provides a `Menu` class that handles keyboard navigation,
item selection and callback execution in a terminal UI.

## Concepts demonstrated
- OOP: `Menu` class with nested `menu_item` class
- Function pointers as callbacks
- `std::vector` for dynamic item storage
- ncurses for terminal input/output

## How to build
Requires ncurses:
```bash
sudo apt install libncurses5-dev
g++ main.cpp menu.cpp -o menu-demo -lncurses
./menu-demo
```

## Notes
University coursework project (2022–2023).

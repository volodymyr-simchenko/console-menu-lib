// file: main.cpp
#include <iostream>
#include "menu.hpp"
#include <ncurses.h>
#include <clocale>

using namespace std;

void foo1 ();
void foo2 ();
void foo3 ();
void foo4 ();
void foo5 ();
void foo6 ();

int main ()
{
    setlocale (LC_ALL, "ru_RU.UTF-8");

    Menu menu ("Choose an option:", menu_type::SIMPLE_MENU);

    menu.add_item(foo1, "Option 1");
    menu.add_item(foo2, "Option 2");
    menu.add_item(foo3, "Option 3");
    menu.add_item(foo4, "Option 4");
    menu.add_item(foo5, "Option 5");

    menu.exec();

    return 0;

}

void foo1 ()
{
    printw ("Executing foo1\n");
}

void foo2 ()
{
    printw ("Executing foo2\n");
    refresh ();
}

void foo3 ()
{
    printw ("Executing foo3\n");
    refresh ();
}

void foo4 ()
{
    printw ("Executing foo4\n");
    refresh ();
}

void foo5 ()
{
    printw ("Executing foo5\n");
    refresh ();
}

void foo6 ()
{
    printw ("Executing foo6\n");
    refresh ();
}

// file: menu.cpp

#include "menu.hpp"
#include <cstdio>
#include <curses.h>
#include <cwchar>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <system_error>
#include <ncurses.h>
#include <locale>

#define K_ENTER 10

//typedef unsigned short ushort;

Menu::Menu ( std::string menu_header, menu_type mtype) : menu_header (menu_header)
{
    // size > 0 ? this->size = size : throw std::invalid_argument ("Invalid menu size");
    // menu_header.empty () ? this->menu_header = "Menu:" : this->menu_header = menu_header;
    // menu = new menu_item [size];
    this->mtype = mtype;
    bool corr_mtype = mtype == menu_type::SIMPLE_MENU or mtype == menu_type::SIMPLE_CONTEXT_MENU or mtype == menu_type::ADVANCED_MENU or mtype == menu_type::ADVANCED_CONTEXT_MENU;
    corr_mtype ? this->mtype = mtype : throw std::invalid_argument ("Неизвестный тип мен��");

    //is_size_init = true;

}

void Menu::add_item (void (*exec) () , std::string item_str)
{

    menu.push_back (menu_item (exec, item_str));
    menu.back().is_init = true;


    // if (inum >= 0 and inum < size)
    // {
    //     menu[inum].exec = exec;
    //     menu[inum].str = item_str;
    //     menu[inum].is_init = true;
    // }
    // else
    // {
    //     throw std::out_of_range("Invalid menu item number");
    // }

}

bool Menu::is_all_init () const
{
    for (auto item : menu)
    {
        if (not item.is_init)
            return false;
    }
    return true;
}

void Menu::exec () const
{
    if (!is_all_init())
    {
        throw std::logic_error ("Не все элементы меню инициализированы");
    }
    // Will be implemented later
    // if (mtype != menu_type::SIMPLE_MENU)
    // {
    //
    // }
    // Initialize ncurses

    setlocale (LC_ALL, "ru_RU.UTF-8");

    initscr();
    cbreak();
    noecho();

    // Disable blinking cursor
    curs_set (0);

    keypad(stdscr, true); // Enable processing of command keys

    // Otherwise, continue method execution:

    ushort selected = 0;
    int input;

    // Start menu loop
    do
    {
        clear ();
        printw ( "\t%s\n" , this->menu_header.c_str()); printw ("\n");

        // Print menu items at the moment

        for (ushort i = 0; i < menu.size(); ++i)
        {
            if (i == selected)
            {
                printw ("\t==>%s", menu.at(i).str.c_str());
            }
            else
            {
                printw ("\t\t%s", menu.at(i).str.c_str());
            }
            printw ("\n");
        }
        printw ("\n\t\tДля выхода нажмите кнопку 'Q'\n");
        refresh ();

        // Wait for user key press
        input = getch ();

        switch (input)
        {
        case KEY_UP:
            selected == 0 ? selected = menu.size() - 1 : --selected;
            break;
        case KEY_DOWN:
            selected == menu.size() - 1 ? selected = 0 : ++selected;
            break;
        case K_ENTER:
            clear ();
            menu.at(selected).exec ();

            getch ();
        }

    } while (input != KEY_q and input != KEY_Q);

    refresh();

    endwin ();
}

// void Menu::print_menu () const
// {
//
// }

Menu::~Menu ()
{
    menu.clear();
}

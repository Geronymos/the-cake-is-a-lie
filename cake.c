#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main()
{

    WINDOW *stdscr = initscr(); cbreak(); noecho();
    curs_set(0);
    // start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    WINDOW *left = newwin(stdscr->_maxy, stdscr->_maxx/2, 0, 0);
    WINDOW *right = newwin(stdscr->_maxy, stdscr->_maxx/2, 0, stdscr->_maxx/2);
    WINDOW *left_sub = subwin(left, stdscr->_maxy-5, stdscr->_maxx/2 -5, 2, 2);
    WINDOW *right_sub = subwin(right, stdscr->_maxy - 5, stdscr->_maxx/2 -5, 2, stdscr->_maxx/2 + 2);
    refresh();

    long long t = 1668898800 - time(NULL);

    box(left, 0, 0);
    box(right, 0, 0);
    scrollok(right_sub, TRUE);
    wrefresh(left);
    wrefresh(right);
    
    WINDOW *gameover = newwin(10, 57, stdscr->_maxy/2 - 5, stdscr->_maxx/2 - 27);
    wprintw(gameover, "  ____                         ___                      \n");
    wprintw(gameover, " / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __     \n");
    wprintw(gameover, "| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n");
    wprintw(gameover, "| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |       \n");
    wprintw(gameover, " \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|  \n");

    WINDOW *win = newwin(10, 55, stdscr->_maxy/2 - 5, stdscr->_maxx/2 - 27);
    wprintw(win, "__   __                     _       _       \n");
    wprintw(win, "\\ \\ / /__  _   _  __      _(_)_ __ | |    \n");
    wprintw(win, " \\ V / _ \\| | | | \\ \\ /\\ / / | '_ \\| |\n");
    wprintw(win, "  | | (_) | |_| |  \\ V  V /| | | | |_|     \n");
    wprintw(win, "  |_|\\___/ \\__,_|   \\_/\\_/ |_|_| |_(_) \n");

    // the cake is a lie
    wprintw(left_sub, "              ,:/+/-                        \n");
    wprintw(left_sub, "              /M/              .,-=;//;-    \n");
    wprintw(left_sub, "         .:/= ;MH/,    ,=/+%%$XH@MM#@:      \n");
    wprintw(left_sub, "        -$##@+$###@H@MMM#######H:.    -/H#  \n");
    wprintw(left_sub, "   .,H@H@ X######@ -H#####@+-     -+H###@X  \n");
    wprintw(left_sub, "    .,@##H;      +XM##M/,     =%%@###@X;-   \n");
    wprintw(left_sub, "  X%%-  :M##########$.    .:%%M###@%%:      \n");
    wprintw(left_sub, "  M##H,   +H@@@$/-.  ,;$M###@%%,          - \n");
    wprintw(left_sub, "  M####M=,,---,.-%%%%H####M$:          ,+@##\n");
    wprintw(left_sub, "  @##################@/.         :%%H##@$-  \n");
    wprintw(left_sub, "  M###############H,         ;HM##M$=       \n");
    wprintw(left_sub, "  #################.    .=$M##M$=           \n");
    wprintw(left_sub, "  ################H..;XM##M$=          .:+  \n");
    wprintw(left_sub, "  M###################@%%=           =+@MH%%\n");
    wprintw(left_sub, "  @################M/.          =+H#X%%=    \n");
    wprintw(left_sub, "  =+M##############M,       -/X#X+;.        \n");
    wprintw(left_sub, "    .;XM##########H=    ,/X#H+:,            \n");
    wprintw(left_sub, "       .=+HM######M+/+HM@+=.                \n");
    wprintw(left_sub, "           ,:/%%XM####H/.                   \n");
    wprintw(left_sub, "                ,.:=-.                      \n");
    
    wprintw(left_sub, "\n - Nice Party. Now compile your cake yourself!\n\n\n");

    // calendar from cal program
    wattron(left_sub, A_REVERSE);
    wprintw(left_sub, "  Mo   Di   Mi   Do   Fr   Sa   So  \n");
    wattrset(left_sub, 0);
    wprintw(left_sub, "        1    2    3    4    5    6  \n");
    wprintw(left_sub, "   7    8    9   10   11   12   13  \n");
    wprintw(left_sub, "  14   15   16   17   18  ");
    wattron(left_sub, A_REVERSE);
    wprintw(left_sub, " 19 ");
    wattrset(left_sub, 0);
    wprintw(left_sub, "  20  \n");
    wprintw(left_sub, "  21   22   23   24   25   26   27  \n");
    wprintw(left_sub, "  28   29   30                      \n");

    wprintw(left_sub, "\nOnly %lld days left! \n", t / (24 * 60 * 60));

    wprintw(right_sub, "Orangerot reaches level 20. \n");
    wprintw(right_sub, "He invites you to celebrate with him on the \n");
    wprintw(right_sub, "19nth of November at RetroGames e.V.\n\n");
    wprintw(right_sub, "It is advised to have the item ");
    wattron(right_sub, A_UNDERLINE);
    wprintw(right_sub, "Kneipenquartet");
    wattrset(right_sub, 0);
    wprintw(right_sub, ".");

    char c = 0;
    for (int i = 0; i < 10 && c != 'y'; i++) {
        wprintw(right_sub, "\n\n");
        wprintw(right_sub, "Do you accept? [Y|n]\n");
        wattron(right_sub, A_REVERSE);
        wprintw(right_sub, " Yes ");
        wattrset(right_sub, 0);
        wprintw(right_sub, " No ");

        wrefresh(left_sub);
        wrefresh(right_sub);
        refresh();
        c = getch();
    }
    
    if ( c != 'y')
    {
        for (int y = 0; y < stdscr->_maxy; y++)
        {
            for (int x = 0; x < stdscr->_maxx; x++)
            {
                mvprintw(y,x, " ");
                refresh();
                napms(1);
            }
        }
        
        wrefresh(gameover);
    }
    else
    {
        clear();
        refresh();
        wrefresh(win);
        for (int i = 0; i < 50; i++)
        {
            attron(A_REVERSE);
            mvprintw(random() % stdscr->_maxy, random() % stdscr->_maxx, " ");
            attrset(0);
            refresh();
            napms(100);
        }
        
    }
    getch();
    endwin();
}

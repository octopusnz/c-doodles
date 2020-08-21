#include <stdio.h>

#include <curses.h>

int main(void) {

    initscr();
    printw("%ld\n",__STDC_VERSION__);
    refresh();
    getch();
    endwin();

    return 0;
}

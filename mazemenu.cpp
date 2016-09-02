#include "mazemenu.h"
#include <cstdlib>
#include <cstring>

const char* generation_options[] = {
    "Yes",
    "No",
};

void get_flags()
{
    WINDOW *global_menu_win;

    ITEM** generation_items;
    MENU* generation_menu;

    generation_items = (ITEM**)calloc(GEN_NUM, sizeof(ITEM*));
    for (int i = 0; i < GEN_NUM; i++)
    {
        generation_items[i] = new_item(generation_options[i], "");
    }
    generation_items[GEN_NUM] = (ITEM*)NULL;

    // Create menu
    generation_menu = new_menu((ITEM**)generation_items);


    global_menu_win = newwin(HEIGHT, WIDTH, 2, (COLS - WIDTH) / 2);
    keypad(global_menu_win, TRUE);

    // Set the format to ONE row and TWO columns
    set_menu_format(generation_menu, 1, 2);

    set_menu_win(generation_menu, global_menu_win);
    set_menu_sub(generation_menu, derwin(global_menu_win, 1, 0, 3, 1));

    box(global_menu_win, 0 , 0);

    mvwaddch(global_menu_win, 2, 0, ACS_LTEE);
    mvwhline(global_menu_win, 2, 1, ACS_HLINE, WIDTH - 2);
    mvwaddch(global_menu_win, 2, WIDTH - 1, ACS_RTEE);

    refresh();

    // Post the generation menu
    post_menu(generation_menu);
    wrefresh(global_menu_win);      /* Show that box     */

    int c;
    while ((c = getch()) != 10)
    {
        // Do nothing, for now
    }

}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{
    int length, x, y;
    float temp;

    if (win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if (startx != 0)
        x = startx;
    if (starty != 0)
        y = starty;
    if (width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length) / 2;
    x = startx + (int)temp;
    mvwprintw(win, y, x, "%s", string);
    refresh();
}
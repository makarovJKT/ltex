#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <curses.h>
#include "bin/compare.h"

#define TYPE_CALLOC(type,elts) typeCalloc(type, (unsigned)(elts))

WINDOW *__MAINWND__;
WINDOW *__HTOOLWND__;
WINDOW *__TOOLSWND__;

int main(int argc, char ** argv)
{
    // int res = init_compare(argc, argv);
    
    // if(res == -1){

    //     end_compare();
    //     puts("ERROR");
    //     exit(EXIT_FAILURE);
    // }
    
    init();
    getch();
    wmove(__HTOOLWND__, 0, 0);
    wprintw(__HTOOLWND__, "this");
    wrefresh(__HTOOLWND__);
    getch();
    wend();
    // int key;
    // int i=1;
    // wmove(cmdinpwnd,0,0);
    // keypad(cmdinpwnd, TRUE);
    // wbkgd(cmdinpwnd, COLOR_PAIR(CMDWND_COLOR) | A_REVERSE);
    // wrefresh(cmdinpwnd);
    // while (key = wgetch(cmdinpwnd))
    // {
    //     if(key == KEY_F(3) || key == '\n') break;
    //     //wmove(cmdinpwnd, 0, i);
    //     //wechochar(cmdinpwnd, key);
    //     // wprintw(cmdinpwnd,"");
    //     i++;
    // }

   

    

    //end_compare();
    exit(EXIT_SUCCESS);
}
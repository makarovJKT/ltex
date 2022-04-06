#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>


#define TEXT_COLOR 8
#define MAIN_BACK_COLOR 9
#define CONTROL_BACK_COLOR 10

WINDOW *mainwnd;
WINDOW *cmdwnd;
WINDOW *cmdinpwnd;


void init_color_pairs();
void sig_winch(int signo);
int init_compare(int argc, char ** argv);
int end_compare();
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include "compare.h"


u_short LLN;
u_char isNote; 


int read_file(char *path, WINDOW* wnd);
int nwrite(WINDOW* wnd);
char* insert(int x, int y, char c);
char* delete(int x, int y);
char get_symbol(int x, int y);
int end_ind(int y);
void clear_trow();
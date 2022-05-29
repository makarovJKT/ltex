#include "rw_file.h"

int insert_note(char c);
char* insert_trow(int x, char c);

int delete_note();
char* delete_trow(int x);


int read_file(char *path, WINDOW* wnd)
{
    FILE* f;
    char buffer[MAXCOL] = {0};
    int ln=0;
    int sz;

    if((f = fopen(path, "r")) == NULL)
    {
        return 1;
    }

    fseek(f, 0L, SEEK_END);
    if(ftell(f) > MAXCOL*MAXROW)
    {
        wend();
        printf("file %s (%ldbt) is too large\n", path, ftell(f));
        return -1;
    }
    fseek(f, 0L, SEEK_SET);

    wclear(wnd);
    wmove(wnd,0,0);

    while((fgets(buffer, MAXCOL, f)) != 0 && ln < MAXROW)
    {
        strncpy(NOTE[ln], buffer, MAXCOL);
        if(ln < wnd->_maxy)
        {
            wprintw(wnd, "%s", buffer);
        } 
        ln++;
    }
    wmove(wnd,0,0);
    wrefresh(wnd);
    LLN = ln-1<0?0:ln-1;

    fclose(f);
    
    return 1;
}

int rewrite(WINDOW* wnd, int d)
{
    int ln=PN.y, col = PN.x+d;
    while(ln <= LLN)
    {
        if(ln < wnd->_maxy){
            wprintw(wnd, "%s", &NOTE[ln][col]);
        }
        else{
            break;
        }
        col=0;
        ln++;
    }
    wrefresh(wnd);
}

int insert(char c)
{
    if (isNote)
    {
        return insert_note(c);
    }
    else
    {
        //return insert_trow(x,c);
    }
    
}

int insert_note(char c)
{
    if(NOTE[PN.y][PN.x] == 0)
    {
        NOTE[PN.y][PN.x] = c;
        return 1;
    }

    int sl = strlen(&NOTE[PN.y][PN.x]);
    char* bf = (char*)malloc(sl+1*sizeof(char));
    
    strncpy(bf, &NOTE[PN.y][PN.x], sl+1);
    NOTE[PN.y][PN.x]=c;
    strcpy(&NOTE[PN.y][PN.x+1], bf); 
    free(bf);  

    return 1;
}

char* insert_trow(int x, char c)
{
    x  -= strlen(HTOOL_MES);
    if(TROW[x] == 0)
    {
        TROW[x] = c;
        return "";
    }

    int sl = strlen(&TROW[x]);
    char* bf = (char*)malloc(sl*sizeof(char));
    
    strncpy(bf, &TROW[x], sl+1);
    TROW[x] = c;
    strcpy(&TROW[++x], bf);

    return bf;
}

int delete()
{
    if(isNote)
    {
        return delete_note();
    }
    else
    {
        // return delete_trow(x);
    }
}

char* delete_trow(int x)
{
    int i = x-strlen(HTOOL_MES)-1;
    int sl = strlen(&TROW[x]);
    char* bf = (char*)malloc(sizeof(char)*sl+1);
    strncpy(bf, &TROW[x], sl+1);

    while(TROW[i] != 0)
    {
        TROW[i] = 0;
        i++;
    }
    strcpy(&TROW[--x], bf);
    return bf;
}

int delete_note()
{
    int i = PN.x;
    int sl;
    char* bf;

    if(NOTE[PN.y][i] == '\n' && i==0){
        int y = PN.y;
        NOTE[PN.y][i] = 0;
        
        while(NOTE[y+1][0]!=0){
            sl = strlen(&NOTE[y+1][0]);
            strncpy(&NOTE[y][0], &NOTE[y+1][0], sl+1);
            
            while(sl>0){
                NOTE[y+1][sl--] = 0;
            }
            y++;
        }
        return 1;
    }

    sl = strlen(&NOTE[PN.y][PN.x]);
    bf = (char*)malloc(sizeof(char)*sl+1);
    strncpy(bf, &NOTE[PN.y][PN.x], sl+1);

    while(NOTE[PN.y][i] != 0)
    {
        NOTE[PN.y][i] = 0;
        i++;
    }
    strcpy(&NOTE[PN.y][PN.x-1], bf);
    free(bf);
    return 1;
}

char get_symbol(int x, int y)
{
    if(isNote == 1) return NOTE[y][x];
    else return TROW[x-strlen(HTOOL_MES)-1];
}

int end_ind(int y)
{
    int i = 0;
    while(NOTE[y][i] != 0){
        i++;
    }
    return i;
}

void clear_trow()
{
    int i = 0;
    while(i<MAXCOL2){
        i++;
        TROW[i]=0;
    }
}


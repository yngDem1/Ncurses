#include <ncursesw/ncurses.h>
#include <stdio.h>
#include <stdlib.h>

/* void food(int x, int y, int snakeX, int snakeY, int snakeBody)
{
    int foodX = rand() % x;
    int foodY = rand() % y;
    int foodValue = rand() % 10;
    if (snakeX == foodX && snakeY == foodY)
        snakeBody = snakeBody + foodValue;
}

void isGameOver(int x, int snakeX, int y, int snakeY, bool gameOver)
{
    if (snakeX >= x || snakeX <= 0 || snakeY >= y || snakeY <= 0)
    gameOver = true;
    
} */

void snakeSpawn(int snakeX, int snakeY, int snakeBody)
{
    snakeX = 5;
    snakeY = 5;
    snakeBody = 1;
}
    

int main() {
    bool gameOver = false;
    const int x = 20; // width of field
    const int y = 20; // heigth of field
    int snakeX, snakeY, snakeBody; // parameters of snake
    //snakeSpawn;
    
    
    
    //ncurses starts here
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, 1);
    
    for (; ;)
{
            mvprintw(y, x, "S");
            
            int ch = getch();
            if (ch == KEY_UP)
            snakeY--;
            
            if (ch == KEY_DOWN)
            snakeY++;
            
            if (ch == KEY_LEFT)
            snakeX--;
            
            if (ch == KEY_RIGHT)
            snakeX++;
            
            cbreak();
            clear();
            refresh();
}
    endwin();
}
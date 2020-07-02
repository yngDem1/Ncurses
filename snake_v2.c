#include <ncursesw/ncurses.h>
#include <stdlib.h>
#include <time.h>

void isGameOver(int *x, int *snakeX, int *y, int *snakeY, bool gameOver)
{
    if (snakeX >= x || snakeX <= 0 || snakeY >= y || snakeY <= 0)
    gameOver = true;  
}

void food(int *x, int *y, bool *foodEaten)
{
    if (*foodEaten)
    {
    srand(time(0)); // seed for random generator
    int foodX = (rand() % x) + 1;
    int foodY = (rand() % y) + 1;
    int foodValue = (rand() % 10) + 1;
    *foodEaten = false;
    }
    mvprintw(foodX, foodY, "F");
}

void eatingFood
{
   if (snakeX == foodX && snakeY == foodY)
    snakeLength = snakeLength + foodValue;
    bool foodEaten = true;
}

void snakeSpawn(int *x, int *y) 
{
    int snakeX = (rand() % x);
    int snakeY = (rand() % y);
    int snakeLength = 1;
}
    

int main() {
    bool gameOver = false;
    const int x = 20; // width of field
    const int y = 20; // heigth of field
    //snakeSpawn;
    
    
    
    //ncurses starts here
    initscr(); //ncurses initialization
    curs_set(0); //makes mouse cursor invisible
    noecho();
    keypad(stdscr, 1);
    
    while(gameOver != true)
{
    erase();
    snakeSpawn(&snakeX, &snakeY, &snakeLength);

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
    erase();
    mvprintw(smth);
    refresh();
    getch();
    endwin();

    return 0;
}
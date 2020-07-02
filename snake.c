#include <ncursesw/ncurses.h>
#include <stdlib.h>
#include <time.h>

void isGameOver(int *x, int *snakeX, int *y, int *snakeY, bool *gameOver)
{
    if (snakeX >= x || snakeX <= 0 || snakeY >= y || snakeY <= 0)
    gameOver = true;  
}

void foodSpawn(int *x, int *y, bool *foodEaten)
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

void eatingFood(int *snakeX, int *snakeY, int *snakeLength, int *foodX, int *foodY, int *foodValue, int *score)
{
    if (snakeX == foodX && snakeY == foodY)
    {
        snakeLength = snakeLength + foodValue;
        bool foodEaten = true;
    }
    
    if (foodEaten = true)
    {
        score = (score + 5) + foodValue;
    }
}

void snakeSpawn(int *x, int *y) 
{
    int snakeX = (rand() % x);
    int snakeY = (rand() % y);
    int snakeLength = 0;
}
    
void snakeMovement
{
    
}

int main() {
    bool gameOver = false;
    const int x = 20; // width of field
    const int y = 20; // heigth of field
    int score = 0; 
    // ncurses starts here
    initscr(); // ncurses initialization
    curs_set(0); // makes mouse cursor invisible
    noecho();
    keypad(stdscr, 1); // keypad initialization
    
    while(gameOver) // main cycle
{
    erase();

    snakeSpawn(&snakeX, &snakeY, &snakeLength);
    foodSpawn(x, y, *foodEaten);
    snakeMovement();
    eatingFood(*snakeX, *snakeY, *snakeLength, *foodX, *foodY, *foodValue)

    refresh();

            // mvprintw(y, x, "S");
            
            int ch = getch();
            if (ch == KEY_UP)
            snakeY--;
            
            if (ch == KEY_DOWN)
            snakeY++;
            
            if (ch == KEY_LEFT)
            snakeX--;
            
            if (ch == KEY_RIGHT)
            snakeX++;

}
    cbreak();
    mvprintw(x/2, y/2, "That's all! Game is over!");
    mvprintw(x/2, (y/2)+1, "Your final score is ", score);
    mvprintw(x/2, (y/2)+2, "Thank you for playing!");
    refresh();
    getch();
    endwin();

    return 0;
}

#include <ncursesw/ncurses.h>
#include <stdlib.h>
#include <time.h>

void isGameOver(int x, int snakeX, int y, int snakeY, bool gameOver/*, int snakeLength, int *tailX, int *tailY*/)
{
      /* for(int i = 0; i < snakeLength;i++)
       if(tailX[i] == snakeX || tailY[i] == snakeY)
gameOver = true; */
    if (snakeX >= x || snakeX <= 0 || snakeY >= y || snakeY <= 0)
    /* if(snakeX >= x+1) snakeX = 0;
    else if(snakeX < 0) snakeX = x;
    else if(snakeY >= y+1) snakeY = 0;
    else if(snakeY < 0) snakeY = y; */
    gameOver = true;  
}

void foodSpawn(int x, int y, int foodX, int foodY, int foodValue, bool foodEaten)
{
    if (!foodEaten)
    {
    srand(time(0)); // seed for random generator
    foodX = (rand() % x) + 1;
    foodY = (rand() % y) + 1;
    foodValue = (rand() % 4) + 1;
    foodEaten = false;
    }
    mvprintw(foodX, foodY, "F");
}

void eatingFood(int snakeX, int snakeY, int snakeLength, int foodX, int foodY, bool foodEaten, int foodValue, int score)
{
    if (snakeX == foodX && snakeY == foodY)
    {
        snakeLength++;
        foodEaten = true;
    }

    if (foodEaten == true)
    {
        score = foodValue;
    }
}

void snakeSpawn(int x, int y, int snakeX, int snakeY, int snakeLength) 
{
    snakeX = (rand() % x);
    snakeY = (rand() % y);
    snakeLength = 1;
}
    
void snakeMovement(int *tailX, int *tailY, int snakeX, int snakeY, int snakeLength)
{
    tailX[0] = snakeX;
    tailY[0] = snakeY;
    int lastX = tailX[0];
    int lastY = tailY[0];
    int helpX, helpY;
    for (int i = 1; i < snakeLength; i++)
    {
        helpX = tailX[i];
        helpY = tailY[i];
        tailX[i] = lastX;
        tailY[i] = lastY;
        lastX = helpX;
        lastY = helpY;
    }
}

int main() {
    bool gameOver = false;
    bool foodEaten = false;
    const int x = 20; // width of field
    const int y = 20; // heigth of field
    int score = 0;
    int foodX, foodY, foodValue;
    int snakeX, snakeY, snakeLength;
    int tailX[1000], tailY[1000];
    // ncurses starts here
    initscr(); // ncurses initialization
    curs_set(0); // makes mouse cursor invisible
    noecho();
    keypad(stdscr, 1); // keypad initialization
    
    while(!gameOver)
{
    erase();

    isGameOver(x, y, snakeX, snakeY, &gameOver);
    snakeSpawn(x, y, snakeX, snakeY, snakeLength);
    snakeMovement(&tailX[1000], &tailY[1000], snakeX, snakeY, snakeLength);
    foodSpawn(x, y, foodX, foodY, foodValue, &foodEaten);
    eatingFood(snakeX, snakeY, snakeLength, foodX, foodY, &foodEaten, foodValue, score);

    refresh();

            mvprintw(snakeY, snakeX, "S");
            
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
    mvprintw((x/2)+1, y/2, "Your final score is ", score);
    mvprintw((x/2)+2, y/2, "Thank you for playing!");
    refresh();
    getch();
    endwin();

    return 0;
}

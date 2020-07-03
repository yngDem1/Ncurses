#include <ncursesw/ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

bool gameOver = false;
bool foodEaten = false;
int snakeX = 0, snakeY = 0, snakeLength = 3;
int foodX, foodY, foodValue; 
int tailX[400], tailY[400];
int state = 0;
int score = 0;
int y = 24;
int x = 80;

void snakeTail()
{
tailY[0] = snakeY;
tailX[0] = snakeX;
int lastY = tailY[0];
int lastX = tailX[0];
int helpY, helpX;
for (int i = 1; i < snakeLength*2; i++)
    {
        helpY = tailY[i];
        helpX = tailX[i];
        tailY[i] = lastY;
        tailX[i] = lastX;
        lastX = helpX;
        lastY = helpY;
    }
} 

int keyCheck(void)
{
int ch = getch();
if (ch != ERR)
{
ungetch(ch);
return 1;
}
else
return 0;
}

void snakeMove()
{
if (state == 1)
snakeY--;

if (state == 2)
snakeY++;

if (state == 3)
snakeX++;

if (state == 4)
snakeX--;
}

void isGameOver()
{
if (snakeY == y || snakeY < 0 || snakeX == x || snakeX < 0)
gameOver = true;
}

void foodSpawn()
{
    if (!foodEaten)
    {
        srand(time(0));
        foodX = (rand() % (x-2));
        foodY = (rand() % (y-2));
        foodEaten = false;
        foodValue++;
    }
}

void eatingFood()
{
    if (snakeX == foodX && snakeY == foodY)
    {
        foodEaten = true;
    }

    if (foodEaten)
    {
        score += foodValue;
        foodEaten = false;
        foodSpawn();
        snakeLength++;
    }
}

void snakeSpawn()
{
    srand(time(0));
    snakeY = (rand() % (y-2));
    snakeX = (rand() % (x-2));
}

int main()
{
initscr();
curs_set(0);
noecho();
keypad(stdscr, 1);
halfdelay(1);

foodSpawn();
snakeSpawn();
while (!gameOver)
{
mvprintw(23,62, "Current score: %d.", score);
mvprintw(foodY, foodX, "A");
for (int i = 0; i < snakeLength; i++)
mvprintw(tailY[i], tailX[i], "K");
mvprintw(snakeY, snakeX, "S");

if (keyCheck())
{
int ch = getch();
if (ch == KEY_UP)
state = 1;

if (ch == KEY_DOWN)
state = 2;

if (ch == KEY_RIGHT)
state = 3;

if (ch == KEY_LEFT)
state = 4;

if (ch == 'q')
gameOver = true;


}
isGameOver();
snakeMove();
snakeTail();
if(foodEaten)
foodSpawn();
eatingFood();

erase();
refresh();
}
cbreak();
mvprintw(10, 20, "That's all! Game is over!");
mvprintw(11, 20, "Your final score is %d.", score);
mvprintw(12, 20, "Thank you for playing!");
refresh();
getch();
endwin();
}

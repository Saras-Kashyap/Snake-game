#include <iostream>
#include<string>
#include<windows.h>
#include<conio.h>  // for geting chercter from consol window
using namespace std;

bool gameover;
const int width = 40;     // frame size
const int height = 20;
int x,y,fruitx,fruity,score;  // defing variable
int tailx[100] , taily[100];
int ntail;

enum eDirection {stop = 0, LEFT , RIGHT , UP , DOWN }; // define variables
eDirection dir;

// defing some funtions
void setup(){
gameover = false;
dir = stop;          // st state of head
x = width/2;    // st postion of head
y = height/2;
fruitx = rand() % width;       // postion of fruit is random
fruity = rand() % height;
score = 0;

}


void draw(){
system("cls"); // for clearing the screen(console)
for (int i = 0; i < width + 2 ; i++)
    cout<< "#";
cout<<endl;

for (int  i = 0; i < height; i++)
{
    for (int  j = 0; j < width; j++)  // for boundry
    {
        if (j == 0)
            cout<< "#";
       if (i == y && j == x)
           cout<< "O";       // for head
       else if (i == fruity && j == fruitx)
       {
        cout << "F";         // for fruit
       }
           else
           {
            bool print = false;
            for (int  k = 0; k < ntail; k++)
            {
                if (tailx[k]  == j && taily[k] ==i){
                    cout << "o";   // for tail
                    print = true;
                }
            }
            if (!print)
               cout << " ";
           }
           

            if (j == width -1)
            {
                cout << "#";
            }
            
    }
    cout << endl;
}
for (int i = 0; i < width + 2; i++)
{
    cout << "#";
}
cout << endl;
cout <<"score: "<< score << endl;
}


void input(){
if (_kbhit()){  // it will +ve if keyboard is press
switch (_getch())      // for controles
{
    case 'a':    // giving keys for directiion
    dir = LEFT;
    break;
    case 'd':
    dir = RIGHT;
    break;
    case 'w':
    dir = UP;
    break;
    case 's':
    dir = DOWN;
    break;
    case 'x':   // if press x game will stop
    gameover = true;
    break;
}

}
}


void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x , prev2y;
    tailx[0] = x;    // for flow the tail
    taily[0] = y;
    // for tail
    for (int  i = 0; i < ntail; i++)
    {
        prev2x = tailx[i];  // for increcing tail
        prev2y = taily[i];  // variable swap
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    
switch (dir)  // for control
{
  case LEFT:
       x--;
      break;
  case RIGHT:
       x++;
      break;
  case UP:
       y--;
      break;
  case DOWN:
       y++;
      break;
  default:
      break;
}
            // for if snake touch the boundry code will stop/over
// if (x > width || x < 0 || y > height || y < 0)
// {                                                 // if we wanat to add wall 
//     gameover = true;                                  
// }
if (x >= width) x = 0; else if (x < 0) x = width -1;
if (y >= height) y = 0; else if (y < 0 ) y = height - 1;
{
    /* code */
}


for (int  i = 0; i < ntail; i++)
{
    if (tailx[i] == x && taily[i] == y)
        gameover = true;
}

if (x == fruitx && y == fruity)
{
    score += 10;
    fruitx = rand() % width;       // postion of fruit is random
    fruity = rand() % height;
    ntail++;
}

}


int main(){
setup();
while (!gameover)
{
    draw();
    input();
    logic();
    Sleep(80);   // for slow the game 
}

    return 0;
}
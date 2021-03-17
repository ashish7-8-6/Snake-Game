#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int width=70, height=20;
int x,y,fruitX,fruitY,score,flag,gameover,countail=0;
int tailX[100],tailY[100];

void setup()
{
    gameover = 0;
    x = width/2;
    y = height/2;

    label1:
    fruitX = rand()%70;
    if(fruitX == 0)
        goto label1;

    label2:
    fruitY = rand()%20;
    if(fruitY == 0)
        goto label2;

    score=0;

}

void draw()
{
    int i,j,k;
    system("cls");
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
                printf("#");
            }
            else
            {
                if (i==y && j==x)
                {
                    printf("o");
                }
                else if(i == fruitY && j == fruitX)
                {
                    printf("*");
                }
                else
                {
                    int ch = 0;
                    for(k=0; k<countail; k++)
                    {
                       if(j==tailX[k] && i==tailY[k])
                       {
                           printf("o");
                           ch = 1;
                       }
                    }
                    if(ch == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("score=%d",score);
}

void input()
{
    if(kbhit())  //hvm
    {
        char ch = getch();

        switch(ch)
        {
        case 'h':
            flag=1;
            break;

        case 'v':
            flag=2;
            break;

        case 'm':
            flag=3;
            break;

        case ' ':
            flag=4;
            break;

        case 'x':
            gameover = 1;
            break;
        }
    }
}

void makelogic()
{
    int t;
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    int prev2X, prev2Y;
    for(t=1; t<countail; t++)
    {
        prev2X = tailX[t];
        prev2Y = tailY[t];
        tailX[t] = prevX;
        tailY[t] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x--;
        break;
    case 3:
        x++;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }

    if(x<0 || x> width || y<0 || y>height)
        gameover=1;

    for(t=0 ; t<countail; t++)
    {
        if(x == tailX[t] && y == tailY[t])
            gameover = 1;
    }

    if(x==fruitX && y==fruitY)
    {
        label1:
        fruitX = rand()%70;
        if(fruitX == 0)
        goto label1;

        label2:
        fruitY = rand()%20;
        if(fruitY == 0)
        goto label2;

        score += 10;
        countail++;

    }
}

int main()
{
    int i,j;
    char ch;
   /* printf("Press 'H' to move up\n");
    printf("Press '<space>' to move down\n");
    printf("Press 'V' to move left\n");
    printf("Press 'M' to move right\n\n");*/
    label5:
    setup();
    while(!gameover)
    {
        draw();
        input();
        makelogic();
        for(i=0; i<1000; i++)
        {
            for(j=0; j<10000; j++)
            {

            }
        }
    }
    printf("\nGame Over \nDO you wanna play again then press Y otherwise press N\n");
    scanf("%c",ch);
    if(ch=='y' || ch=='Y')
        goto label5;
    else
        exit(1);

    return 0;
}

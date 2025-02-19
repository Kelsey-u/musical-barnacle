#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void menu()
{
    printf("***************************\n");
    printf("*****   1.play   **********\n");
    printf("*****   0.exit   **********\n");
    printf("***************************\n");
}

void initial(char board[ROWS][COLS],int row,int col,char set)
{
    int x = 0;
    int y = 0;
    for(x=0;x<ROWS;x++)
    {
        for(y=0;y<COLS;y++)
            {
                board[x][y] = set;
            }
    }
}

void setmine(char mine[ROWS][COLS],int row,int col)
{
    int count = 10;
    while(count)
    {
        int x = rand()%ROW+1;
        int y = rand()%ROW+1;
        if(mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}

int getmine(char mine[ROWS][COLS],int x,int y)
{
    int a = x;
    int b = y;
    int c = 0;
    for(a=x-1;a<=x+1;a++)
    {
        for(b=y-1;b<=y+1;b++)
        {
            if(mine[a][b] == '1')
                {
                    c++;
                }
        }
    }
    return c;
}

void findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int win = 0;
    while(win<=71)
    {   
        
    printf("输入坐标：\n");
    int x,y;
    scanf("%d %d",&x,&y);
    if(x>=1 && x<= ROW && y>=1 && y<= COL)
    {
        if(mine[x][y] == '1')
        {
            printf("游戏结束\n");
            adisplay(mine[ROWS][COLS],ROW,COL);
            break;
        }
        else
        {
            int count = getmine(mine[x][y],x,y);
            show[x][y] = count + '0';
            adisplay(show,ROW,COL);
            win++;
        }
    }
        else
        {
            printf("重输\n");
        }
    }
    printf("win\n");
}

void adisplay(char board[ROWS][COLS],int row,int col)
{
    int i = 0;
    int j = 0;
    for(j=0;j<=COL;j++)
    {
        printf("%d ",j);
    }
    printf("\n");
    for(i=1;i<=ROW;i++)
    {
        printf("%d ",i);
        for(j=1;j<=COL;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void game()
{
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    initial(mine,ROWS,COLS,'0');
    initial(show,ROWS,COLS,'*');
    setmine(mine,ROWS,COLS);
    printf("--------------------\n");
    //adisplay(mine,ROW,COL);
    printf("--------------------\n");
    adisplay(show,ROW,COL);
    printf("--------------------\n");
    findmine(mine,show,ROW,COL);
}

int main()
{
    SetConsoleOutputCP(65001);
    int a = 0;
    srand((unsigned int)time(NULL));
    do
    {menu();
    printf("选择：\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("开始\n");
        game();
        break;
    case 0:
        printf("结束\n");
        break;
    default:
        printf("重选\n");
        break;
    }
    }while(a);
    return 0;
}
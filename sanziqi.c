#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define row 3
#define col 3

void menu()
{
    printf("***************************\n");
    printf("*****   1.play   **********\n");
    printf("*****   0.exit   **********\n");
    printf("***************************\n");
}

void initial(char board[row][col],int ROW,int COL)
{
    int i = 0;
    int j = 0;
    for(i=0;i<ROW;i++)
        {
            for(j=0;j<COL;j++)
            {
                board[i][j] = ' ';
            }
        }
}

void print(char board[row][col],int ROW,int COL)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                {
                    printf(" %c ",board[i][j]);
                    if(j<col-1)
                        {
                            printf("|");
                        }
                }
                printf("\n");
            if(i<row-1)
                {
                    for(j=0;j<col;j++)
                    {   
                        printf("---");
                        if(j<col-1)
                        {
                            printf("|");
                        }
                    }
                printf("\n");
                }
        }
}

void Pm(char board[row][col],int ROW,int COL)
{   
    int x = 0;
    int y = 0;
    printf("玩家走\n");

    while(1)
    {
            printf("输入坐标:\n");
            scanf("%d %d",&x,&y);
        if(x>=1 && x<=row && y>=1 && y<=col)
            {
                if(board[x-1][y-1] == ' ')
                {
                    board[x-1][y-1] = '*';
                    break;
                }
                else
                    {
                        printf("重输\n");
                    }
            }
        else
        {
            printf("重输\n");
        }
    }
}


void Cm(char board[row][col],int ROW,int COL)
{
    printf("电脑下\n");
    while(1)
    {
        int x = rand()%row;
    int y = rand()%col;
    if(board[x][y]==' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

int asfull(char board[row][col],int ROW,int COL)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j] == ' ')
            return 0;
        }
    }
    return 1;
}
char win(char board[row][col],int ROW,int COL)
{
    int i = 0;
    for(i=0;i<row;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] ==board[i][2] && board[i][1] != ' ')
            {
                return board[i][1];
            }
    }
    for(i=0;i<row;i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] ==board[2][i] && board[1][i] != ' ')
            {
                return board[1][i];
            }
    }
    if(board[1][1] == board[0][0] && board[1][1] == board[2][2] && board[1][1] != ' ')
        {
            return board[1][1];
        }
    if(board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
        {
            return board[1][1];
        }
    
    int ret = asfull(board,row,col);
    if(ret == 1)
    {
        return 'q';
    }
    return 'c';
}
void game()
{
    char ret;
    char board[row][col];
    initial(board,row,col);
    print(board,row,col);
    while(1)
    {
        Pm(board,row,col);
        print(board,row,col);
        ret = win(board,row,col);
            if(ret!='c')
            {
                break;
            }
        Cm(board,row,col);
        print(board,row,col);
        ret = win(board,row,col);
            if(ret!='c')
                {
                    break;
                }
    }
    if(ret = '*')
    {
        printf("玩家获胜\n");
        print(board,row,col);
    }
    else if(ret = '#')
    {
        printf("电脑获胜\n");
        print(board,row,col);
    }
    else
    {
        printf("平局\n");
        print(board,row,col);
    }
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
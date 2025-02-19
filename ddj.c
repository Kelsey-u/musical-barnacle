#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{   
    char a[] = "i love u";
    char b[] = "********";
    int left = 0;
    int right = strlen(a)-1;
    while(left<=right)
    {
        b[left] = a[left];
        b[right] = a[right];
        printf("%s\n",b);
        left++;
        right--;
        Sleep(500);
        system("cls");
    }
    return 0;
}
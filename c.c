#include<stdio.h>
int main()
{
    FILE *fp;
    char data[] ="what can i say";
    fp = fopen("hello.txt","w");
    if(fp==NULL)
    {
        printf("no");
        return 0;
    }
    fwrite(data,sizeof(char),sizeof(data)-1,fp);
    fclose(fp);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
    int pi = a[low];
    while(low<high)
    {
        while (low<high && a[high]>=pi)
        {
            high--;
        }
        a[low]=a[high];
        while(low<high && a[low]<=pi)
        {
            low++;
        }
        a[high]=a[low];
    }
    a[low]=pi;
    return low;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot =partition(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}
int main()
{
    int low =0;
    int high=7;
    int a[8]={10,50,30,80,40,90,20,60};
    quicksort(a,low,high);
    for(int i=0;i<8;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
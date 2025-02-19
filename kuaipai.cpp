#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int left,int right)
{
    int pi = a[left];
    while(left<right)
    {
        while(left<right&&a[right]>=pi)
        {
            right--;
        }
        a[left]=a[right];
        while(left<right&&a[left]<=pi)
        {
            left++;
        }
        a[right]=a[left];
    }
    a[left]=pi;
    return left;
}
void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int pivot = partition(a,left,right);
        quicksort(a,left,pivot-1);
        quicksort(a,pivot+1,right);
    }
}
int main()
{
    int a[100000];
    int low=0;
    int high;
    scanf("%d",&high);
    for(int i=0;i<high;i++)
    {
        cin>>a[i];
    }
    quicksort(a,low,high-1);
    for(int i=0;i<high;i++)
    {
        cout<<a[i]<<" ";
    }
    printf("\n");
    return 0;
}
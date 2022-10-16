#include <stdio.h>
void shiftOne(int a[], int n)
{
    int temp;
    temp = a[0];
    int i;
    for (i = 0; i < n - 1; i++)
        a[i] = a[i + 1];
    a[i] = temp;
}
/*
void Flip(int a[],int start,int end){
    int temp;
    for(;start<end;start++,end--){
        temp =a[start];
        a[start]=a[end];
        a[end]=temp;
    }
}*/
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    m = m % n;
    /*
    Flip(a,0,n-1);
    Flip(a,0,n-m-1);
    Flip(a,n-m,n-1);*/
    for (int j = 0; j < m; j++)
        shiftOne(a, n);
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", a[i]);
    return 0;
}

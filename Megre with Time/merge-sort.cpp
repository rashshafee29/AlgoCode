#include<cstdio>
#include<iostream>
#include<ctime>
#include<cmath>
#define MAX_SIZE 100000

using namespace std;

int A[MAX_SIZE+5];


void merge_(int p,int q,int r)
{
    int n1,n2,l[MAX_SIZE+5],r2[MAX_SIZE+5],k,x,y;
    n1=q-p+1;
    n2=r-q;
    for(x=1; x<=n1; x++)
    {
        l[x]=A[p+x-1];
    }
    for(y=1; y<=n2; y++)
    {
        r2[y]=A[q+y];
    }
    l[n1+1]=99999999;
    r2[n2+1]=99999999;
    x=1;
    y=1;
    for(k=p; k<=r; k++)
    {
        if(l[x]<=r2[y])
        {
            A[k]=l[x];
            x=x+1;
        }
        else
        {
            A[k]=r2[y];
            y=y+1;
        }
    }
}

void merge_sort(int p,int r)
{
    int q;
    if(p<r)
    {
        q=((p+r)/2);
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge_(p,q,r);
    }
}


int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);

    int i, j, t;
    int p;
    int r, n;
    double tt;

    clock_t _start, _end;

    scanf("%d",&t); //How many Test Case

    for(i=0; i<t; i++)
    {
        p=1;
        cin >> n; // how many data in test case
        for(j=p; j<=n; j++)
        {
            cin >> A[j];
        }

        r = n;

        _start = clock(); // get start time

        merge_sort(p,r); // now sort

        _end = clock(); // get end time

        tt=(double)(_end-_start)/CLOCKS_PER_SEC;

        printf("Case %2d:\n\tTotal Data: %d\n\tTotal Execution time: %f sec.\n\n",i+1, n, tt);

    }

    return 0;
}

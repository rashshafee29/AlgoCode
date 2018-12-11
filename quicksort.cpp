#include<bits/stdc++.h>
using namespace std;
int n,a[100];
int Partition(int p,int r)
{
    int x,i,j,sw1,sw2;
    x=a[r];
    i=p-1;
    for(j=p; j<=r-1; j++)
    {
        if(a[j]<x)
        {
            i++;
            sw1=a[i];
            a[i]=a[j];
            a[j]=sw1;
            //swap(a[i],a[j]);
        }

        //swap(a[r],a[i+1]);
        int k;
    }
      sw2=a[i+1];
         a[i+1]=a[r];
         a[r]=sw2;
    return(i+1);
}
int QuickSort(int p,int r)
{
    int q;
    if(p<r)
    {
        q=Partition(p,r);
        QuickSort(p,q-1);
        QuickSort(q+1,r);
    }
}

int main()
{
    int i,j;
    cout<<"How many numbers:";
    cin>>n;
    srand(time(NULL));

    for(i=1; i<=n; i++)
    {
        a[i]=rand()%100;
        //cin>>a[i];
    }
    cout<<"Before sort:";
    for(i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    int m=n;
    int p=1;
    QuickSort(p,m);
    cout<<"\nAfter sort:";
    for(i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

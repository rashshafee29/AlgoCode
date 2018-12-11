#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<time.h>

using namespace std;
int ahs,al;
int left(int i)
{
    return (2*i);
}
int right(int i)
{
    return (2*i+1);
}
int Max_Heapify(int A[],int i)
{
    int largest;
    int l=left(i);
    int r=right(i);
    if(l<=ahs && A[l]>A[i])
    {
        largest=l;
    }
    else
        largest=i;
    if(r<=ahs && A[r]>A[largest])
    {
        largest=r;
    }
    int s;
    if(largest!=i)
    {
        s=A[i];
        A[i]=A[largest];
        A[largest]=s;
        Max_Heapify(A,largest);
    }
}
int Build_mx_heap(int A[])
{
    int n,c,i;
    srand(time(NULL));
    cout<<"How many elements:"<<"\n";
    cin>>n;
    for(c=1;c<=n;c++)
    {
       A[c]=rand()%100;
       //scanf("%d",&A[c]);
    }
    printf("Given Array: ");
    for(c=1;c<=n;c++)
    {
        printf("%d ",A[c]);
    }
    al=n;
    ahs=n;
    for(i=al/2;i>=1;i--)
    {
        Max_Heapify(A,i);
    }
    printf("\n\nMAx Heap:");
    for(c=1;c<=n;c++)
    {
        printf("%d ",A[c]);
    }
}
int main()
{
    int A[100];
    Build_mx_heap(A);
    int x,s1;
    for(x=al;x>=2;x--)
    {
        s1=A[1];
        A[1]=A[x];
        A[x]=s1;
        ahs=ahs-1;
        Max_Heapify(A,1);
    }
    int k;
    printf("\n\nAfter Heap sort: ");
    for(k=1;k<=al;k++)
    {
        printf("%d ",A[k]);
    }
    return 0;
}


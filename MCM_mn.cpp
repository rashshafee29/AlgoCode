#include<cstdio>
#include<iostream>
using namespace std;
int p[100], m[100][100],s[100][100];
int q,n;
int print_optimal(int i,int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        print_optimal(i,s[i][j]);
        cout<<"*";
        print_optimal(s[i][j]+1,j);
        printf(")");
    }
}
int MCM()
{
    n=q-1;
    int i,l,j,k,x;
    for(i=1; i<=n; i++)
    {
        m[i][i]=0;
    }
    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j=i+l-1;
            m[i][j]=99999999;
            for(k=i; k<=j-1; k++)
            {
                x=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(x<m[i][j])
                {
                    m[i][j]=x;
                    s[i][j]=k;
                }
            }
        }
    }
}
int main()
{
    int c;
    printf("How many MATRIX :");
    scanf("%d",&q);
    for(c=0; c<q; c++)
    {
        scanf("%d",&p[c]);
    }
    MCM();
    int w,z;
    printf("M array :\n");
    for(w=1; w<=n; w++)
    {
        for(z=1; z<=n; z++)
        {
            if(z<w)
                //continue;
                printf("      ");
            else
                printf("%6d",m[w][z]);
        }
        printf("\n");
    }
    printf("S array: \n");
    for(w=1; w<=n; w++)
    {
        for(z=1; z<=n; z++)
        {
            if(z<=w)
                printf("  ");
            else
                printf("%d ",s[w][z]);
        }
        printf("\n");
    }
    cout<<"optimal Parents:";
    print_optimal(1,n);
    return 0;
}

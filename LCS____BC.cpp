#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

char X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];
int lcs_len()
{

    m=strlen(X);
    n=strlen(Y);
    for (i=1; i<=m; i++)
        c[i][0]=0;
    for (j=0; j<=n; j++)
        c[0][j]=0;
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (X[i-1]==Y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
    cout<<"length:";
    cout<<c[m][n];
}

void print_lcs(int i,int j)
{
    if (i==0 || j==0) return;
    if (b[i][j]==1)
    {
        print_lcs(i-1,j-1);
        printf("%c",X[i-1]);
    }
    else if (b[i][j]==2)
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}
int  main()
{
    gets(X);
    gets(Y);
    lcs_len();

    cout<<"\nLCS:";
    print_lcs(m,n);
}

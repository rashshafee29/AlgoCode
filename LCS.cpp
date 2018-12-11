#include<bits/stdc++.h>
using namespace std;
char x[100],y[100];
//string x,y;
int co=0,m,n;
int c[100][100],b[100][100];
void print_lcs(int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]==1)

    {
        print_lcs(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]==2)
    {
        print_lcs(i-1,j);
    }
    else
    {
        print_lcs(i,j-1);
    }
}
int lcs_len()
{
    int i,j;
   // m=strlen(x);
    //cout<<m;
    //n=strlen(y);
    for(i=1;i<=m;i++)
    {
        c[i][0]=0;
        //cout<<"n lcs";
    }
    for(j=0;j<=n;j++)
    {
        c[0][j]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[i-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                //co++;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                //co++;
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                //co++;
                b[i][j]=3;
            }            //co++;
        }
    }
    print_lcs(m,n);
}
int main()
{
gets(x);
gets(y);
    //m=x.length();
    //n=y.length();   // getline(cin, &x[1]);
   // getline(cin, &y[1]);
    m=strlen(x);
    n=strlen(y);
    //puts(x);
   // puts(y);
    lcs_len();
    //cout<<co;
}

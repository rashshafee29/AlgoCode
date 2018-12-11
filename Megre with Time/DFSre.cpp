#include<stdio.h>
int r,c;
char a[100][100];
int found=0;


void check(int i ,int j)
{
    //printf("i=%d and j=%d\n",i,j);
    if(i<=0 || j<=0 || i>r || j>c||a[i][j]=='0')
    {
        //  printf("returned from 1\n");
        return;
    }
    else if(found==0)
    {
        if(a[i][j]=='B')
        {
            found=1;
            printf("Found at (%d,%d)\n",i,j);
            // printf("returned from 2\n");
            return;
        }
        else if(a[i][j]=='X')
        {
            return ;
        }
        else
        {
            a[i][j]='0';
            check(i-1,j);/// upore
            check(i,j-1);/// bamee
            check(i,j+1);/// danee
            check(i+1,j);/// niche
        }
    }
    else
    {
        return;
    }

}
int main()
{
    int i,j,x;
    scanf("%d%d",&r,&c);
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    i=1;
    j=1;
    check(i,j);
    return 0;
}

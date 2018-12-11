#include<bits/stdc++.h>
using namespace std;
int G[100][100],v,i,j,k,P[100][100],D[100][100];
int main()
{
    cout<<"How many V:";
    cin>>v;
    for(i=1; i<=v; i++)
    {
        for(j=1; j<=v; j++)
        {
            cin>>G[i][j];
            //D[i][j]=G[i][j];
            if(i==j || G[i][j]==99)
            {
                P[i][j]=-1;
            }
            else if(G[i][j]<99)
            {
                P[i][j]=i;
            }
        }
    }
    for(k=1; k<=v; k++)
    {
        for(i=1; i<=v; i++)
        {
            for(j=1; j<=v; j++)
            {
                //if(G[i][j]<=G[i][k]+G[k][j])
                {
                   // P[i][j]=P[i][j];
                }
                if(G[i][j]>G[i][k]+G[k][j])
                {
                    P[i][j]=P[k][j];
                    G[i][j]=G[i][k]+G[k][j];
                }
               // G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

            }
        }
    }
    cout<<"Shortest path:\n";
    for(i=1; i<=v; i++)
    {
        for(j=1; j<=v; j++)
        {
            cout<<G[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Parents:\n";
    for(i=1; i<=v; i++)
    {
        for(j=1; j<=v; j++)
        {
            cout<<P[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}

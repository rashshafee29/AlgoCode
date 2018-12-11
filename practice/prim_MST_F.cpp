#include<bits/stdc++.h>
using namespace std;
int key[100],r[100],w[100][100];
int main()
{
    int vv,u,wt,c,i,j,n,V;
    priority_queue<pair<int,int> , vector<int> , greater <int> >pq;
    cout<<"How many vertex:";
    cin>>V;
    for(c=1;c<=V;c++)
    {
        cin>>i>>j>>wt;
        w[i][j]=wt;
    }
    for(u=1;u<=V;u++)
    {
        key[u]=9999999;
        r[u]=-1;//NIL
    }
    key[1]=0;
    for(u=1;u<=V;u++)
    {
        pq.push(u);
    }
    while(!pq.empty())
    {
        u=pq.top();
        pq.pop();
        for(vv=1;vv<=V;vv++)
        {
            if()
        }
    }
}

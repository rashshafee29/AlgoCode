#include<bits/stdc++.h>
using namespace std;
int V,Ed,p[100],rank_[100],c=0;
struct Edge
{
    int u,v;
    double w;
} E[100*100];
int Make_Set(int x)
{
    p[x]=x;
    rank_[x]=0;
}
int FindSet(int x)
{
    if(x!=p[x])
        p[x]=FindSet(p[x]);
    return p[x];
}
int Link(int x,int y)
{
    if(rank_[x]>rank_[y])
    {
        p[y]=x;
    }
    else
    {
        p[x]=y;
    }
    if(rank_[x]==rank_[y])
    {
        rank_[y]=rank_[y]+1;
    }
}
int Union(int x,int y)
{
    Link(FindSet(x),FindSet(y));
}
bool comp(Edge e1, Edge e2)
{
    if (e1.w > e2.w)
        return false;
    return true;
}
int MST_Kruskal()
{
    int v,i;
    for(v=0; v<V; v++)
    {
        Make_Set(v);
        sort(E,E+Ed,comp);
        for(i=0; i<Ed; i++)
        {
            if(FindSet(E[i].u)!=FindSet(E[i].v))
            {
                ///A
                Union(E[i].u,E[i].v);
                c++;
            }
        }
    }
}
int main()
{
    freopen("KruskalIn.txt","r",stdin);
    cin>>V>>Ed;
    int i,j;

    for(i=0; i<Ed; i++)
    {
        //for(j=0;j<Ed;j++)
        {
            cin>>E[i].u;///source
            cin>>E[i].v;///destination
            cin>>E[i].w;///weight
            //Ed++;
        }
    }
    MST_Kruskal();
    for(int q=0; q<c; q++)
    {
        cout<<E[q].u<<"   "<<E[q].v<<"   "<<E[q].w<<"\n";
    }
}

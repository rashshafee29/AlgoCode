#include<bits/stdc++.h>
#define INF 999999
#define NIL -1
using namespace std;
int V,d[100],pa[100];
bool S[100];
int ExtractMin()
{
    int v,min_,loc_min;
    min_=INF;
    for(v=0;v<V;v++)
    {
        if((S[v] == false) && (d[v]<=min_))
        {
            min_=d[v];
            loc_min=v;
            //cout<<"FROM int ExtractMin()\n";
        }
    }
    return loc_min;
}
int Relax(int u,int v,int w[100][100])
{
    if(w[u][v] && d[v]>d[u]+w[u][v])
    {
        d[v]=d[u]+w[u][v];
        pa[v]=u;
        //cout<<"FROM int Relax()\n";
    }
}
int Initialize_Single_Source(int s)
{
    int v;
    for(v=0;v<V;v++)
    {
        d[v]=INF;
        pa[v]=NIL;
        S[v]=false;
        //cout<<"FROM int ISS\n";
    }
    d[s]=0;
}
int Dijkstra_m(int w[100][100],int s)
{
    int u,i,v;
    Initialize_Single_Source(s);
    for(i=0;i<V-1;i++)
    {
        u=ExtractMin();
        S[u]=true;
        //cout<<"FROM int DIJ()\n";
        for(v=0;v<V;v++)
        {
            //cout<<"FROM int DIJ----()\n";
            Relax(u,v,w);
        }
    }
}
int Print_D()
{
    int v;
    for(v=0;v<V;v++)
    {
        cout<<v<<"            "<<d[v]<<"            "<<pa[v]<<"\n";
    }
}
int main()
{
    freopen("DijkstraIn.txt","r",stdin);
    int i,j,u,w[100][100];
    //cout<<"How many vertex:";
    cin>>V;
    cout<<"Vertex    "<<"distance    "<<"parents\n";
    cout<<"\n";
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>w[i][j];
        }
    }
    Dijkstra_m(w,0);
    Print_D();
    return 0;
}

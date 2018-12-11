#include<bits/stdc++.h>
#define lp(x, y, start) for(x=start;x<=y;x++)
#define INF 1<<30;
#define NIL -1
#define MAX 100
using namespace std;
int V, E;
priority_queue<int, vector<int>, greater<int> > Q; // min priority queue
int used_q[MAX];
int adj[MAX][MAX];
int pi[MAX];
int key[MAX];
int w[MAX][MAX];
void mst_prim(int r)
{
    int u, v;
    lp(u, V, 1)
    {
        key[u]=INF;
        pi[u]=NIL;
    }
    key[r]=0;
    lp(v, V, 1) // Q = G.V
    {
        Q.push(v);
    }
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();

        used_q[u] = -1;
        lp(v, V, 1)
        {
            if(used_q[v]==0 && adj[u][v]==1 && w[u][v]<key[v])
            {
                pi[v] = u;
                key[v] = w[u][v];
            }
        }
    }
}
int main()
{
    //freopen("mst_prim_input.txt","r", stdin);
    cout << "Enter How many Edge and Vertex: ";
    cin >> E >> V;
    cout << "Enter the Adjacency matrix and weight: ";
    int x, y, z, e, v;
    lp(v, V, 1)
    {
        cin >> x >> y >> z;
        adj[x][y]=1;
        adj[y][x]=1;
        w[x][y]=z;
        w[y][x]=z;
    }
    mst_prim(1);
    lp(e, E, 1)
    {
        cout << e << " --- " << pi[e] << " ; Weight: " << w[e][pi[e]] << endl;
    }
    return 0;
}

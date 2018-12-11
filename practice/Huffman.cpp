#include<bits/stdc++.h>
using namespace std;
priority_queue<char ,vector<char>,greater<char> >pq;
int n,freq[100];
int HuffMan()
{
    int i;
    for(i=1;i<=n-1;i++)
    {

    }
}
int input()
{
    int i;
    cout<<"How many char";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        char m;
        cin>>m;
        pq.push(m);
    }
    for(i=1;i<n-1;i++)
    {
        cin>>freq[i];
    }
    for(i=1; i<=n; i++)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
int main()
{
    input();
}

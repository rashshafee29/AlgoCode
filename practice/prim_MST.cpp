#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,x;
    priority_queue<pair <int,int > ,vector<int>,greater<int> >pq;
    pair <int,int>q;
    //q.first=7;
    //q.second=4;
    // cout<<q.first<<" "<<q.second<<"\n";
    // pq.push(4);
    // pq.push(5);
    //pq.push(11);
    //pq.push(1);
    priority_queue<int ,vector<int>,greater<int> >::iterator itr=pq.begin();
    for(i=0; i<2; i++)
    {
        cin>>q.first>>q.second>>x;
        pq.push(x);
    }

    for(i=0; i<4; i++)
    {
        q=itr;
        cout<<q.first<<" "<<q.second<<" "<<pq.top()<<"\n";


        pq.pop();
        itr++;
    }

}

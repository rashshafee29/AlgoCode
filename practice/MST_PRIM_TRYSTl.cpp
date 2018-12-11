#include <bits/stdc++.h>
using namespace std;
pair<int, int> tempP;
int main()
{
    int n,m;

   // priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > PQ;
    priority_queue< int, vector<pair<int,int> >, greater< pair<int,int > > > PQ;
    cin >> n;
    while(n--)
    {
        cin >> tempP.first >> tempP.second;
        PQ.push(tempP);
        //cin>>m;
    }
    cout << "size: " << PQ.size() << endl;

    while(!PQ.empty())
    {
        tempP = PQ.top();

        cout << tempP.first << " " << tempP.second << " " << endl;
       //cout<<PQ.top();
         PQ.pop();
    }
    cout << "size: " << PQ.size() << endl;
}

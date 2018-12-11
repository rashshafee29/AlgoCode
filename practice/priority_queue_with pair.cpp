#include<bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int,int> __x, pair<int,int>__y) const
    {
        return __x.second > __y.second;
    }
};
priority_queue< pair<int,int>, vector <pair <int, int> >, comp > p;
int main()
{

}

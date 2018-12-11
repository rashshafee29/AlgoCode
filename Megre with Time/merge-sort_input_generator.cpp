#include<iostream>
#include<cstdio>
#define TOTAL_INPUT 10

using namespace std;

int main()
{
    freopen("input.txt", "w+", stdout);

    cout << TOTAL_INPUT << endl; //total test case

    for(int i=10000; i<=100000; i+=10000)
    {
        cout << i << endl; // total data in test case

        for(int j=i; j> 0; j--)
            cout << j << " ";

        cout << endl;
    }

    return 0;
}

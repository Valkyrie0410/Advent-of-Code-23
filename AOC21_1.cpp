#include<bits/stdc++.h>
using namespace std;
vector<string> input;
set<pair<int, int>> solve(set<pair<int, int>> current)
{
    set<pair<int, int>> next;
    for(auto it:current)
    {
        if(input[it.first-1][it.second] != '#')
        next.insert({it.first-1, it.second});
        if(input[it.first+1][it.second] != '#')
        next.insert({it.first+1, it.second});
        if(input[it.first][it.second - 1] != '#')
        next.insert({it.first, it.second -1});
        if(input[it.first][it.second +1] != '#')
        next.insert({it.first, it.second+1});
    }
    return next;
}
int main()
{
    string s;
    set<pair<int, int>> current;
    while(getline(cin, s))
    {
        input.push_back(s);
    }
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[0].size(); j++)
        {
            if(input[i][j] == 'S')
            {
            current.insert({i, j});
            }
        }
    }
    int step = 64;
    while(step--)
    {
        set<pair<int, int>> next;
        next = solve(current);
        current.clear();
        current = next;  
    }
    cout<<current.size()<<endl;
}
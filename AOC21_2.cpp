#include<bits/stdc++.h>
using namespace std;
vector<string> input;
set<pair<int, int>> solve(set<pair<int, int>> current)
{
    set<pair<int, int>> next;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto it : current) {
        for (auto dir : directions) {
            int x = (it.first + dir.first + input.size()) % input.size();
            int y = (it.second + dir.second + input[0].size()) % input[0].size();
            if (input[x][y] != '#')
                next.insert({it.first + dir.first + input.size(), it.second + dir.second + input[0].size()});
        }
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
    int step = 1000;
    while(step--)
    {
        set<pair<int, int>> next;
        next = solve(current);
        cout<<next.size()<<endl;
        current.swap(next);
    }
    cout<<current.size()<<endl;
}
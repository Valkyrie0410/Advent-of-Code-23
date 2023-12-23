#include<bits/stdc++.h>
using namespace std;
vector<string> input;
int length = 0;
void solve(vector<pair<int, int>> current, pair<int, int> next, pair<int, int> direc)
{
    current.push_back(next);
    // cout<<current.back().first<<" "<<current.back().second<<endl;
    pair<int, int> it = current.back();
    if(it.first == input.size()-1)
    {
        if(current.size() > length)
        {
            length = current.size();
        }
        return;
    }
    if(direc.first == 0 && direc.second == 0)
    {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto dir : directions) {
                int x = (it.first + dir.first);
                int y = (it.second + dir.second);
                auto it2 = find_if(current.begin(), current.end(),
                           [=](const pair<int, int>& p) { return p.first == x && p.second == y; });
                if(it2 == current.end() && (x != -1 && y != -1 && x != input.size() && y != input[0].size()) )
                {
                if (input[x][y] == '.')
                {
                    solve(current, {x,y},{0,0});
                }
                else if(input[x][y] == '>' && dir != make_pair(0, -1))
                {
                    solve(current,{x,y}, {0,1});
                }
                else if(input[x][y] == '<' && dir != make_pair(0, 1))
                {
                    solve(current,{x,y}, {0,-1});
                }
                else if(input[x][y] == 'v' && dir != make_pair(-1, 0))
                {
                    solve(current,{x,y}, {1,0});
                }
                else if(input[x][y] == '^' && dir != make_pair(1, 0))
                {
                    solve(current,{x,y}, {-1,0});
                }
            }
        }
    }
    else
    {
        int x = (it.first + direc.first);
        int y = (it.second + direc.second);
        auto it2 = find_if(current.begin(), current.end(),
                           [=](const pair<int, int>& p) { return p.first == x && p.second == y; });
            if(it2 == current.end() && (x != -1 && y != -1 && x != input.size() && y != input[0].size()) )
            {
            if (input[x][y] == '.')
            {
                solve(current,{x,y}, {0, 0});
            }
            else if(input[x][y] == '>')
            {
                solve( current,{x,y}, {0,1});
            }
            else if(input[x][y] == '<')
            {
                solve(current,{x,y}, {0,-1});
            }
            else if(input[x][y] == 'v')
            {
                solve(current,{x,y}, {1,0});
            }
            else if(input[x][y] == '^')
            {
                solve(current,{x,y}, {-1,0});
            }
            }
    }



}
int main()
{
    string s;
    while(getline(cin ,s))
    {
        input.push_back(s);
    }
    vector<pair<int, int>> current;
    int i;
    for(i = 0; i<input[0].size(); i++)
    {
    if(input[0][i] == '.')
    {
    solve(current,{0,i} ,{0,0});
    break;
    }
    }

    cout<<length-1<<endl;

}

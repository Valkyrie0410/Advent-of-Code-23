#include<bits/stdc++.h>
using namespace std;
vector<string> input;
map<pair<int, int>, char> cnt;
vector<int> Max;
void stepto(int i, int j, char dir)
{
    if(i>= input.size() || j>= input[0].size() || i<0 || j<0)
    {
    return;
    }
    if(input[i][j] == '|')
    {
        cnt.insert({{i, j}, dir});
        if(dir == 'W' || dir == 'E')
        {
            stepto(i+1, j, 'S');
            stepto(i-1, j, 'N');
        }
        if(dir == 'S')
        {
            stepto(i+1, j, 'S');
        }
        if(dir == 'N')
        {
            stepto(i-1, j, 'N');
        }
    }
    else if(input[i][j] == '-')
    {
        cnt.insert({{i, j}, dir});
        if(dir == 'W')
        stepto(i, j-1, 'W');
        if(dir == 'E')
        stepto(i, j+1, 'E');
        if(dir == 'N' || dir == 'S')
        {
            stepto(i, j-1, 'W');
            stepto(i, j+1, 'E');
        }
    }
    else if(input[i][j] == '\\')
    {
        cnt.insert({{i, j}, dir});
        if(dir == 'E')
        {
            stepto(i+1, j, 'S');
        }
        if(dir == 'W')
        {
            stepto(i-1, j, 'N');
        }
        if(dir == 'N')
        {
            stepto(i, j-1, 'W');
        }
        if(dir == 'S')
        {
            stepto(i, j+1, 'E');
        }
    }
    else if(input[i][j] == '/')
    {
        cnt.insert({{i, j}, dir});
        if(dir == 'E')
        {
            stepto(i-1, j, 'N');
        }
        if(dir == 'W')
        {
            stepto(i+1, j, 'S');
        }
        if(dir == 'N')
        {
            stepto(i, j+1, 'E');
        }
        if(dir == 'S')
        {
            stepto(i, j-1, 'W');
        }
    }
    else if(cnt[{i,j}] == dir)
    return;
    else if(cnt[{i,j}] != dir)
    {
        cnt[{i,j}] = dir;
        if(dir == 'S')
        stepto(i+1, j, 'S');
        if(dir == 'N')
        stepto(i-1, j, 'N');
        if(dir == 'E')
        stepto(i, j+1, 'E');
        if(dir == 'W')
        stepto(i, j-1, 'W');
    }
    else if(input[i][j] == '.')
    {
        cnt.insert({{i, j}, dir});
        if(dir == 'S')
        stepto(i+1, j, 'S');
        if(dir == 'N')
        stepto(i-1, j, 'N');
        if(dir == 'E')
        stepto(i, j+1, 'E');
        if(dir == 'W')
        stepto(i, j-1, 'W');
    }
}
void findstart()
{
    int row = 0;
    for(int col = 0; col<input[0].size(); col++)
    {
        stepto(row, col, 'S');
        Max.push_back(cnt.size());
        cnt.clear();
    }
    row = input.size()-1;
    for(int col = 0; col<input[0].size(); col++)
    {
        stepto(row, col, 'N');
        Max.push_back(cnt.size());
        cnt.clear();
    }
    int col = 0;
    for(int row=0; row<input.size(); row++)
    {
        stepto(row, col, 'E');
        Max.push_back(cnt.size());
        cnt.clear();  
    }
    col = input[0].size()-1;
    for(int row=0; row<input.size(); row++)
    {
        stepto(row, col, 'W');
        Max.push_back(cnt.size());
        cnt.clear();  
    }   
}
int main()
{
    string s;
    while(getline(cin , s))
    {
        input.push_back(s);
    }
    findstart();
    // stepto(0, 0, 'E');
    // cout<<cnt.size();

    cout<<*max_element(Max.begin(), Max.end());
}
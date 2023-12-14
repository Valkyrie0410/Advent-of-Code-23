#include<bits/stdc++.h>
using namespace std;
void shortestdist(map<int, pair<int,int>> c, vector<int> drow, vector<int>dcol)
{
    long long int sum = 0;
    for(auto it = c.begin(); it!=c.end(); it++)
    for(auto l = it; l!= c.end(); l++)
    {
    int rr= 0, cc=0;
    {
        if((*l).first != (*it).first)
        {
        int rdiff = abs((*l).second.first - (*it).second.first);
        int cdiff = abs((*l).second.second - (*it).second.second);
        for(auto v:drow)
        {
            if(((*l).second.first > v && (*it).second.first <v) ||((*l).second.first < v && (*it).second.first >v))
            rr ++;
        }
        for(auto v:dcol)
        {
            if(((*l).second.second > v && (*it).second.second <v) ||((*l).second.second < v && (*it).second.second >v))
            cc ++;
        }
        if(cdiff>rdiff)
        sum = sum + (rdiff * 2) + (cdiff - rdiff) + rr*(999999) + cc*(999999);
        else
        sum = sum + (cdiff * 2) + (rdiff - cdiff) + cc*(999999) + rr*(999999);
        }
    }
    }
    cout<<sum;
}
void galaxy(vector<string>& s) {
    vector<int> drow;
    vector<int> dcol;
    for (size_t row = 0; row < s.size(); row++) {
        if (s[row].find("#") == string::npos) {
              drow.emplace_back(row);
        } 
    }
    int count = 1;
    for (size_t col = 0; col < s[0].size(); col++) {
        bool foundHash = false;
        for (size_t row = 0; row < s.size(); row++) {
            if (s[row][col] == '#') {
                foundHash = true;
                break;
            }
        }
        if (!foundHash) {
            dcol.emplace_back(col);
        }
    }
    map<int, pair<int, int>> coord;
    for(int row = 0; row<s.size(); row++)
    for(int col = 0; col<s[0].size(); col++)
    if(s[row][col] == '#')
    {
    coord.emplace(count, make_pair(row, col));
    s[row][col] = char(count++ + 48);
    }
    shortestdist(coord, drow, dcol);
}

int main() {
    vector<string> input;
    string s;
    while (getline(cin, s)) {
        input.push_back(s);
    }
    galaxy(input);
    return 0;
}
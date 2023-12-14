#include<bits/stdc++.h>
using namespace std;
void shortestdist(map<int, pair<int,int>> c)
{
    int sum = 0;
    for(auto it = c.begin(); it!=c.end(); it++)
    for(auto l = it; l!= c.end(); l++)
    {
        if((*l).first != (*it).first)
        {
        int rdiff = abs((*l).second.first - (*it).second.first);
        int cdiff = abs((*l).second.second - (*it).second.second);
        if(cdiff>rdiff)
        sum = sum + (rdiff * 2) + (cdiff - rdiff);
        else
        sum = sum + (cdiff * 2) + (rdiff - cdiff);
        }
    }
    cout<<sum;
}
void galaxy(vector<string>& s) {
    vector<string> temp;
    for (auto it = s.begin(); it != s.end(); it++) {
        if ((*it).find("#") == string::npos) {
            temp.push_back(*it);
            temp.push_back(*it);  
        } else {
            temp.push_back(*it);
        }
    }
    s = temp;
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
            for (size_t i = 0; i < s.size(); i++) {
                s[i].insert(col + 1, ".");
            }
            col++; 
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
    shortestdist(coord);
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
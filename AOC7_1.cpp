#include <bits/stdc++.h>
using namespace std;

int findnum(const string& s1) {
    map<char, int> count;
    for (char c : s1) {
        count[c]++;
    }

    int t = 0, s = 0, o = 0;
    for (auto it : count) {
        if (it.second == 5) return 7;
        if (it.second == 4) return 6;
        if (it.second == 3) t++;
        if (it.second == 2) s++;
        if (it.second == 1) o++;
    }

    if (t == 1 && s == 1) return 5;
    if (t == 1) return 4;
    if (s == 2) return 3;
    if (s == 1) return 2;

    return 1;
}
int compare(string s1, string s2)
{
        for(int i=0; i<5; i++)
        {
        if(isdigit(s1[i]) || isdigit(s2[i]))
        {
        if(s1[i]>s2[i])
        return 1;
        if(s1[i]<s2[i])
        return 0;
        }
        else
        {
        if(s1[i]<s2[i])
        return 1;
        if(s1[i]>s2[i])
        return 0;
        }
        }
    return 0;
}

bool comp(const pair<int, pair<string, int>>& a, const pair<int, pair<string, int>>& b) {
    return a.first <= b.first;
}

int main() {
    vector<pair<int, pair<string, int>>> a;
    string s;
    
    while (getline(cin, s) && s != ".") {
        for(int i=0; i<5; i++)
        {
        if(s[i]=='K')
        s[i] = 'B';
        if(s[i]=='Q')
        s[i] = 'C';
        }
    cout << s << endl;
        string s1 = s.substr(0, s.find(" "));
        int num = stoi(s.substr(s.find(" ") + 1));

        a.push_back({ findnum(s1), {s1, num} });
    }

    sort(a.begin(), a.end(), comp);

    int sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a.size() - 1; ++j) {
            if (a[j].first == a[j + 1].first) {
                if (compare(a[j].second.first, a[j + 1].second.first)) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i].second.second * (i + 1);
    }

    cout << sum;
    return 0;
}

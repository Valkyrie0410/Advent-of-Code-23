#include<bits/stdc++.h>
using namespace std;
list<uint64_t> a1;
map<uint64_t,uint64_t> sts;
void seedtosoil(string s)
{
    vector<uint64_t> a(3);
        istringstream stream(s);
        uint64_t num;
        int i=0;
        while(stream>>num)
        {
        a[i++] = num;
        }
    for( int i=0; i<a[2]; i++)
    {
        sts.emplace(a[1]+i,a[0]+i);
    }
}
void findseed(string s)
{
    istringstream stream(s);
    uint64_t num;
    while(stream>>num)
    {
        a1.emplace_back(num);
    }
}
void replace()
{
    for (auto it = a1.begin(); it != a1.end(); it++) {
        if (sts.find(*it) == sts.end())
            sts.emplace(*it, *it);
        *it = sts[*it];
    }
}
int main()
{
    string seed, seed1;
    getline(cin, seed);
    seed = seed.substr(seed.find(" ")+1, seed.length());
    findseed(seed);
    int q= 7;
    getline(cin , seed1);
    getline(cin,seed1);
    while(true)
    {
        getline(cin, seed1);
        if(!seed1.empty())
        {
        seedtosoil(seed1);
        }
        else
        {
        replace();
        for(auto it:sts)
        sts.clear();
        getline(cin,seed1);
        if(seed1.empty())
        break;
        }
    }
    a1.sort();
    cout<<a1.front();
}

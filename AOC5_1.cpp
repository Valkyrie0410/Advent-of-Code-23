#include<bits/stdc++.h>
using namespace std;
list<long long int> a1;
map<long long int,long long int> sts;
void seedtosoil(string s)
{
    vector<long long int> a(3);
    for(int i=0; i<3; i++)
    {
        a[i]=stoull(s);
        int k = s.find(" ");
        if(k != -1)
        s = s.substr(k+1, s.length());
    }
    for( int i=0; i<a[2]; i++)
    {
        sts.emplace(a[1]+i,a[0]+i);
    }
}
void findseed(string s)
{
    int k;
    while(true)
    {
        k = s.find(" ");
        if(k!= -1)
        {
        s = s.substr(k+1 , s.length());
        }
        else 
        return;
        a1.push_back(stoull(s));
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
    findseed(seed);
    getline(cin, seed1);
    getline(cin, seed1);
    getline(cin, seed1);
    while(true)
    {
        if(seed1!=".")
        {
        seedtosoil(seed1);
        getline(cin, seed1);
        }
        else
        {
        replace();
        sts.clear();
        getline(cin, seed1);
        if(seed1 == ".")
        break;
        getline(cin, seed1);
        }
    }
    a1.sort();
    cout<<a1.front();
}
#include<bits/stdc++.h>
using namespace std;
int ways(int t, int d)
{
    int time=0,velocity = 0,rt,distance,count=0;
    while(time<=t)
    {
        velocity = t;
        rt = t-time;
        distance = rt * velocity;
        if(distance>d)
        count++;
    }
    return count;

}
int main()
{
    string s;
    vector<int> t(3),d(3);
    getline(cin,s);
    int l=0;
    for(int i=0; s[i]!='.';)
    {
    if(isdigit(s[i]))
    {
    string s1 = s.substr(i, s.length());
    cout<<s1<<endl;
    t[l] = stoi(s1);
    l++;
    if(isdigit(s[i+1]))
    i=i+2;
    else 
    i = i+1;
    }
    else
    i++;
    }
    l =0;
    getline(cin, s);
    for(int i=0; s[i]!='.';)
    {
    if(isdigit(s[i]))
    {
    string s1 = s.substr(i, s.length());
    d[l] = stoi(s);
    l++;
    if(isdigit(s[i+3]))
    i = i+4;
    else if(isdigit(s[i+2]))
    i = i+3;
    else if(isdigit(s[i+1]))
    i = i+2;
    else
    i++;
    }
    else
    i++;
    }
    int pdt = 1;
    for(int k=0; k<l; k++)
    {
        pdt = pdt * ways(t[k],d[k]);
    }
    cout<<pdt;
}
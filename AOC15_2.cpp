#include<bits/stdc++.h>
using namespace std;
multimap<int, pair<string , int>> boxes;
int findhash(string s)
{
    int sum =0;
    for(int i=0; i<s.size(); i++)
    {
        int ascii = s[i];
        sum = sum + ascii;
        sum = (sum * 17) % 256;
    }
    return sum; 
}
void findbox(string s)
{
    int hash;
    
    int equal = s.find("="), minus = s.find("-");
    if(equal != -1)
    {
        for(auto it = boxes.begin(); it!= boxes.end(); it++)
        {
            if(it->second.first == s.substr(0, equal))
            {
            it->second.second = stoi(s.substr(equal+1, s.length()));
            return;
            }
        }
        boxes.insert({findhash(s.substr(0, equal)),{s.substr(0, equal), stoi(s.substr(equal+1, s.length()))}});   
    }
    if(minus != -1)
    {
        hash = findhash(s.substr(0, minus));
        for (auto it = boxes.rbegin(); it != boxes.rend();) {
        if (it->second.first == s.substr(0, minus)) {
        it = decltype(it)(boxes.erase(std::next(it).base())); 
        break;
        } 
        else {
        ++it; 
        }
        }
    }
}
void calculate()
{
    int sum = 0, slot = 1;
    for(auto it = boxes.begin(); it!= boxes.end(); it++)
    {
        sum = sum + (((it->first)+1) * slot * (it->second.second));
        auto nextit = next(it);
        if(it->first != nextit->first)
        slot = 1;
        else slot++;
    }
    cout<<sum<<endl;
}
int main()
{
    int sum1= 0;
    string s;
    getline(cin, s);
    while(true)
    {
        if(s.find(",") == string::npos)
        {
        string s1 = s;
        findbox(s1);
        break;
        }
        string s1 = s.substr(0, s.find(","));
        s = s.substr(s.find(",")+1, s.length());
        findbox(s1);
    }
    calculate();
}
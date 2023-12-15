#include<bits/stdc++.h>
using namespace std;
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
        sum1 = sum1 + findhash(s1); 
        break;
        }
        string s1 = s.substr(0, s.find(","));
        s = s.substr(s.find(",")+1, s.length());
        sum1 = sum1 + findhash(s1); 
    }
    cout<<sum1<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int aoc2(string s)
{
    int i= s.find(":");
    int j = s.find(";");
    if(j==-1)
    j=s.length();
    string r;
    r = s.substr(i+1,j-i-1);
    while(i!=s.length())
    {
        int g = r.find("green");
        int red = r.find("red");
        int b= r.find("blue");
        if(g!=-1)
        {
            if(r[g-2]-48+(r[g-3]-48)*10>13)
            return 1;
            
        }
        if(red!=-1)
        {
            if(r[red-2]-48+(r[red-3]-48)*10>12)
            return 1;
        }
        if(b!=-1)
        {
            if(r[b-2]-48+(r[b-3]-48)*10>14)
            return 1;
        }
        i=j;
        j=s.find(";",i+1);
        if(j==-1)
        {
            j=s.length();
        }
        if(i==j)
        {
            return 0;
        }
        r = s.substr(i+1,j-i-1);
        cout<<r<<endl;
    }

    return 0;
}
int main()
{
    int c=1,k,sum=0;
    string s;
    getline(cin, s);
    while(s!=".")
    {
    k = aoc2(s);
    if(k==0)
    {
    sum = sum+c;
    cout<<c<<endl;
    }
    c=c+1;
    getline(cin ,s);
    }
    cout<<sum;

    return 0;
}
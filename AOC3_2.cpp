#include<bits/stdc++.h>
using namespace std;
int findpdt(vector<string> s)
{
    int r = s.size();
    int a,b,sum=0;
    int c = s[0].size();
    for(int i=0;i<r;i++)
    {
        int j=0;
    while(j<c)
    {
    if(s[i][j]=='*')
    {
       for(int k=i-1;k<=i+1;k++)
       for(int l=j-1;l<=j+1;l++)
       if(isdigit(s[k][l]))
       {
        a = findnum(s,k,l);
        if(isdigit(s[k][l+4]))
        b=findnum(s,k,l+4);
       }
    }
    }
    }
}
int findnum(vector<string> s, int i, int j)
{
    int a;
    if(isdigit(s[i][j]))
    {
        if(isdigit(s[i][j+1]))
        {
            if(isdigit(s[i][j+2]))
                {
                a = (s[i][j]-48)*100 + (s[i][j+1]-48)*10 + s[i][j+2]-48;
                }
            else 
                {
                a =(s[i][j]-48)*10 + (s[i][j+1]-48);
                }
        }
    else
        {
            a = (s[i][j]-48);
        }
    }
    return a;
}

int main()
{
    vector<string> s;
    string line;
    getline(cin,line);
    while(line !="@")
    {
        s.push_back(line);
        getline(cin,line);
    }
}
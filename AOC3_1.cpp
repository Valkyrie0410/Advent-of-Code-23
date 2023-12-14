#include<bits/stdc++.h>
using namespace std;
int sum(vector<string> s)
{
    int r = s.size();
    int a,sum=0;
    int c = s[0].size();
    for(int i=0;i<r;i++)
    {
        int j=0;
    while(j<c)
    {
    if(isdigit(s[i][j]))
    {
        if(isdigit(s[i][j+1]))
        {
            if(isdigit(s[i][j+2]))
                {
                a = (s[i][j]-48)*100 + (s[i][j+1]-48)*10 + s[i][j+2]-48;
                for(int k=i-1;k<=i+1;k++)
                for(int l=j-1;l<=j+3;l++)
                {
                if(k<0 || l<0 || k>=r || l>=c);
                else if(!isdigit(s[k][l])&& s[k][l]!='.')
                {
                sum = sum +a;
                break;
                }
                }
                j=j+4;
                }
            else 
                {
                a =(s[i][j]-48)*10 + (s[i][j+1]-48);
                for(int k=i-1;k<=i+1;k++)
                for(int l=j-1;l<=j+2;l++)
                {
                if(k<0 || l<0 || k>=r || l>=c);
                else if(!isdigit(s[k][l])&& s[k][l]!='.')
                {
                sum = sum +a;
                break;
                }
                }
                j=j+3;
                }
        }
    else
        {
            a = (s[i][j]-48);
            for(int k=i-1;k<=i+1;k++)
            for(int l=j-1;l<=j+1;l++)
            if(k<0 || l<0 || k>=r || l>=c);
            else if(!isdigit(s[k][l])&& s[k][l]!='.')
            {
            sum = sum +a;
            break;
            }
            j=j+2;
        }
    cout<<a<<endl;
    }
    else
    j=j+1;
    } 
}
return sum;
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
    int sum1 = sum(s);
    cout<<sum1;
}
#include<bits/stdc++.h>
using namespace std;

int aoc(string s)
{
    int sum=0,sum1=0;
    for(int i=0;s[i]!='\0';i++)
    {
        for(int j=48;j<=57;j++)
        {
            if(s[i]==j)
            {
            sum=10*(int(s[i])-48);
            }

        }
        if(sum!=0)
        break;
    }
    for(int i=s.length()-1;i>=0;i--)
    {
        for(int j=48;j<=57;j++)
        {
            if(s[i]==j)
            sum1 = int(s[i])-48;
        }
        if(sum1!=0)
        break;
    }
    return sum+sum1;
}

int main()
{
    int sum2=0;
    string s;
    cin>>s;
    while(s!=".")
    {
        sum2 = sum2 + aoc(s);
        cin>>s;
    }
    cout<<sum2;
    return 0;

}
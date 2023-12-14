#include<bits/stdc++.h>
using namespace std;

int aoc(string s)
{
    int sum=0,sum1=0, pos;
    string s1[]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int k = 0;k<=9;k++)
        {
        string s2(1,char(k+48));
        pos = s.find(s1[k]);
        if(pos!=-1)
        s.replace(pos,s1[k].length(),s2);
        }
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
    string s3[]={"orez","eno","owt","eerht","ruof","evif","xis","neves","thgie","enin"};
    reverse(s.begin(),s.end());
    for(int k = 0;k<=9;k++)
        {
        string s2(1,char(k+48));
        pos = s.find(s3[k]);
        if(pos!=-1)
        s.replace(pos,s3[k].length(),s2);
        }
    reverse(s.begin(),s.end());
    for(int i=s.length()-1;i>=0;i--)
    {
        for(int j=48;j<=57;j++)
        {
            if(s[i]==j)
            for(int k =0;k<=9;k++)
            {
            if(s.find(s1[k])>i)

            sum1 = int(s[i])-48;
            }
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
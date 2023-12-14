#include<bits/stdc++.h>
using namespace std;
int aoc2(string s)
{
    int green=0,red1=0,blue=0,pdt;
    int i= s.find(":");
    int j = s.find(";");
    if(j==-1)
    j=s.length();
    string r;
    r = s.substr(i+2,j-i-2);
    while(i!=s.length())
    {
        int g = r.find("green");
        int red = r.find("red");
        int b= r.find("blue");
        if(g!=-1)
        {
            int k=(r[g-3]-48)*10;
            if(k<=0)
            k=0;
            if(r[g-2]-48+k>green)
            green = r[g-2]-48 + k;

        }
        if(red!=-1)
        {
            int k=(r[red-3]-48)*10;
            if(k<=0)
            k=0;
            if(r[red-2]-48+k>red1)
            red1 = r[red-2]-48 + k;
        }
        if(b!=-1)
        {
            int k=(r[b-3]-48)*10;
            if(k<=0)
            k=0;
            if(r[b-2]-48+k>blue)
            blue = r[b-2]-48 + k;
        }
        cout<<"R"<<red1<<endl;
        cout<<"B"<<blue<<endl;
        cout<<"G"<<green<<endl;
        i=j;
        j=s.find(";",i+1);
        if(j==-1)
        {
            j=s.length();
        }
        if(i==j)
        {
            break;
        }
        r = s.substr(i+2,j-i-2);
        
    }
    pdt = red1*green*blue;
    cout<<pdt<<endl;

    return pdt;
}
int main()
{
    int k,sum=0;
    string s;
    getline(cin, s);
    while(s!=".")
    {
    sum = sum + aoc2(s);
    getline(cin ,s);
    }
    cout<<sum;

}
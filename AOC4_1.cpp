#include<bits/stdc++.h>
using namespace std;
int cn[500]={0},cnum=1;
int pdt1(string s1)
{
    cn[cnum]++;
    string s2;
    string card;
    int a1[25], a2[25];
    int i = s1.find(":");
    int j = s1.find("|");
    //card = s1.substr(0, i);
    //cnum = stoi(card);
    s2 = s1.substr(j+2,s1.length()-j-2);
    s1 = s1.substr(i+2, j-i-2);
    int l1=0;
    int i1 = 0;
    while(s1!="")
    {
        a1[l1++]= stoi(s1);
        s1 = s1.substr(i1+3,s1.length()-i1-3);
    }
    l1 = 0;
    i1 = 0;
    while(s2!="")
    {
        a2[l1++]= stoi(s2);
        s2 = s2.substr(i1+3,s2.length()-i1-3);
    }
    int k = 1;
    for(int l1 = 0; l1<10;l1++)
    for(int l2=0;l2<25;l2++)
    {
        if(a2[l2]==a1[l1])
        {
        for(int i =1; i<=cn[cnum];i++)
        {
        cn[cnum+k] ++;
        }
        k++;
        }
    }
    cnum++;
return 0;
}
int main()
{
    string s;
    int sum=0;
    getline(cin,s);
    while(s!=".")
    {
        pdt1(s);
        getline(cin,s);
    }
    for(int i =0 ;i<=202;i++)
    {
        sum = sum + cn[i];
    }
    cout<<sum;

    return 0;
}

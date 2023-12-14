#include<bits/stdc++.h>
using namespace std;
int fact(int n) 
{ 
    return (n==1 || n==0) ? 1: n * fact(n - 1);  
}
int numarr(string s, vector<int> arr)
{
    string r;
    r = s;
    int qhash = 0, qdot = 0, sum = 0, size=0;
    for(auto it: arr)
    size = size + it;

    if(s.size() == size + (arr.size() -1))
    return 1;
    if(arr.back()> arr.front())
    {
        reverse(s.begin(), s.end());
        reverse(r.begin(), r.end());
    }
        int count = 0, i, j=0;
        string s1 = s;
        for(i=0 , j =0; i<s.size() , j<s1.size(); i++ , j++)
        {
            if(arr.empty())
            {
                if(s[i] == '?')
                s[i] = '.';
                s1[j] = '.';
            }
            if(s[i] == '#')
            count ++;
            else if(s[i] == '?')
            {
                if(count == arr.back())
                {
                s[i] = '.';
                s1[j] = '.';
                s = s.substr(i+1, s.length());
                i=0;
                arr.pop_back();
                }
                else
                {
                s[i] = '#';
                s1[j] = '#';
                }
            }
            else if(s[i] == '.' && count == arr.back())
            {
                s = s.substr(i+1, s.length());
                i=0;
                arr.pop_back();
            }
        }
    cout<<s1<<endl;


    for(int i=0; i<s1.size(); i++)
    {
        if(r[i] == '?' && s1[i] == '.')
        {
            qdot++;
        }
        else if(r[i] == '?' && s1[i] == '#')
        {
            qhash++;
        for(int l=i+1; l<s1.size(); l++)
        {
            if(r[l] == '?' && s1[l] == '#');
            else 
            {
            i = l-1;
            break;
            }
        }
        }
        else if(qhash !=0 || qdot != 0)
        sum = sum + (fact(qhash + qdot)/ fact(qdot));

    }
    return sum;
}
int main()
{
    string s,s1;
    vector<int> input;
    int sum1 =0;
    while(getline(cin, s))
    {
        s1 = s.substr(s.find(" ")+1, s.length());
        s = s.substr(0, s.find(" "));
        while(true)
        {
            input.push_back(stoi(s1));
            if(s1.find(",")==string::npos)
            break;
            s1 = s1.substr(s1.find(",")+1,s1.length());
        }
        sum1 = sum1 + numarr(s, input);
    }
    cout<<sum1<<endl;
}


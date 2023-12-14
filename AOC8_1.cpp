#include<bits/stdc++.h>
using namespace std;
map<string, pair<string, string>> a;
string zedd[6];
int num(string s, string current)
{
    int count = 1;
    
    int im=1;
    while(true)
    {
        auto it = a.find(current);
        if (it == a.end()) {
            return -1;
        }
        if(s[im]== 'R')
        {
        current = it->second.second;
        count++;
        }
        else
        {
        current = it->second.first;
        count++;
        }
        if(current[2] == 'Z')
        {
        return count;
        }

        im++;
        if(im== s.length())
        im = 0;
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int findlcm(int arr[], int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}
    int main()
    {
        string s1,s;
        int steps[6];
        string current;
        getline(cin, s1);
        getline(cin, s);
        while(s != ".")
        {
            a.insert({s.substr(0,3),{s.substr(7,3),s.substr(12,3)}});
            getline(cin , s);
        }
        int i=0;
        for(auto it:a)
        {
        if(it.first[2]=='A')
        {
        cout<<it.first<<endl;
        if(s1[0]=='R')
        {
        current = it.second.second;
        steps[i] = num(s1, current);
        }
        else
        {
        current = it.second.first;
        steps[i] = num(s1, current);
        cout<<steps[i]<<endl;
        }
        i++;
        }
        }
        cout<<findlcm(steps,i);
    }


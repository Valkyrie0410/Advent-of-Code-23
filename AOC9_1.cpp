#include<bits/stdc++.h>
using namespace std;
int AP(vector<int> t)
{
    cout<<t.front()<<endl;
    if(t.front()== t.back())
    return t.front();

    vector<int> p;
    for(auto it = t.begin(); it!= t.end()-1; it++)
    {
    p.push_back((*(it+1))- (*(it)));
    }

    return t.front() - AP(p);
}
int main()
{
    string s;
    int sum = 0;
    string word;
    vector<int> input;
    getline(cin, s);
    while(s!=".")
    {
    stringstream ss(s);
    while(ss>>word)
    {
    input.push_back(stoi(word));
    }
    cout<<AP(input)<<endl;
    sum = sum + AP(input);
    input.clear();
    getline(cin, s);
    }
    cout<<sum;
}
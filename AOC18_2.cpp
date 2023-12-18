#include<bits/stdc++.h>
using namespace std;
long long int shoelace(vector<int> x, vector<int> y, int n)
{
    long long int area = 0;
     for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += static_cast<long long int>(x[j] + x[i]) * (y[j] - y[i]); 
    }

    return (abs(area)/2);
}
int convert(string s)
{
    int dec;
    stringstream ss;
    ss<<s;
    ss>>hex>>dec;

    return dec;
}
int main()
{
    vector<int> x;
    vector<int> y;
    x.push_back(0);
    y.push_back(0);
    int i=0; int j=0;
    long long int perimeter = 0;
    string s;
    while(getline(cin, s))
    {
        string s1 = s.substr(s.find("#")+1, 5);
        int dir = s[s.length()-2] - 48;
        int num = convert(s1);
        cout<<num<<endl;
        cout<<dir<<endl;
        if(dir == 2)
        j = j - (num );
        else if(dir == 0)
        j = j + (num);
        else if(dir == 1)
        i = i+ (num);
        else if(dir == 3)
        i = i - (num);

        perimeter = perimeter + num;
        x.push_back(i);
        y.push_back(j);
    }
    // x.pop_back();
    // y.pop_back();
    int n = x.size();
    for(int i = 0; i< x.size(); i++)
    cout<<x[i]<<" "<<y[i]<<endl;
    cout<<perimeter<<endl;
    cout<<shoelace(x, y, n) + (perimeter/2 + 1);
}
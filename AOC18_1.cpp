#include<bits/stdc++.h>
using namespace std;
int shoelace(vector<int> x, vector<int> y, int n)
{
    int area = 0;
     for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += (x[j] + x[i]) * (y[j] - y[i]); 
    }

    return (abs(area)/2);
}
int main()
{
    vector<int> x;
    vector<int> y;
    x.push_back(0);
    y.push_back(0);
    int i=0; int j=0;
    int n = 1;
    int perimeter = 0;
    string s;
    while(getline(cin, s))
    {
        n++;
        int num = stoi(s.substr(2, s.length()));
        if(s[0] == 'L')
        j = j - (num );
        else if(s[0] == 'R')
        j = j + (num);
        else if(s[0] == 'D')
        i = i+ (num);
        else if(s[0] == 'U')
        i = i - (num);

        perimeter = perimeter + num;
        x.push_back(i);
        y.push_back(j);
    }
    x.pop_back();
    y.pop_back();
    for(int i = 0; i< x.size(); i++)
    cout<<x[i]<<" "<<y[i]<<endl;
    cout<<perimeter<<endl;
    cout<<shoelace(x, y, n) + (perimeter/2 + 1);
}
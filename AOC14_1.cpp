#include<bits/stdc++.h>
using namespace std;
void load(vector<string> s)
{
    int load = s.size(), sum=0;
    for(auto it:s)
    {
        for(int i = 0; i< s[0].size(); i++)
        {
            if(it[i] == 'O')
            sum = sum + load;
        }
        load -- ;
    }

    cout<<sum;
  
}
void north(vector<string> s)
{
    int rnum = 0;
    for(int col=0; col<s[0].size(); col++)
    {
        for(int row=0; row<s.size(); row++)
        {
            if(s[row][col] == '.')
            {
                rnum++;
            }
            if(s[row][col] == 'O')
            {
                if(rnum>0)
                {
                s[row - rnum][col] = 'O';
                s[row][col] = '.';
                }
                row = row - rnum;
                rnum = 0;
            }
            if(s[row][col] == '#')
            {
                rnum = 0;
            }
            
        }
        rnum = 0;
    }
    load(s);
}
int main()
{
    vector<string> input;
    string s;
    while(getline(cin,s))
    {
        input.push_back(s);
    }
    north(input);
}
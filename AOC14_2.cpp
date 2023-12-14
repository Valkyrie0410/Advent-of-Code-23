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

    cout<<sum<<endl;
  
}
vector<string> cycle(vector<string> s)
{
    //north
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
    //west
    int cnum = 0;
    for(int row = 0; row<s.size(); row++)
    {
        for(int col=0; col<s[0].size(); col++)
        {
            if(s[row][col] == '.')
            {
                cnum++;
            }
            if(s[row][col] == 'O')
            {
                if(cnum>0)
                {
                s[row][col - cnum] = 'O';
                s[row][col] = '.';
                }
                col = col-cnum;
                cnum = 0;
            }
            if(s[row][col] == '#')
            {
                cnum = 0;
            }
        }
        cnum = 0;
    }
    //south
    rnum = 0;
    for(int col=0; col<s[0].size(); col++)
    {
        for(int row=s.size() - 1; row>=0; row--)
        {
            if(s[row][col] == '.')
            {
                rnum++;
            }
            if(s[row][col] == 'O')
            {
                if(rnum>0)
                {
                s[row + rnum][col] = 'O';
                s[row][col] = '.';
                }
                row = row + rnum;
                rnum = 0;
            }
            if(s[row][col] == '#')
            {
                rnum = 0;
            }
            
        }
        rnum = 0;
    }
    //east
    cnum = 0;
    for(int row = 0; row<s.size(); row++)
    {
        for(int col=s[0].size() -1; col>=0; col--)
        {
            if(s[row][col] == '.')
            {
                cnum++;
            }
            if(s[row][col] == 'O')
            {
                if(cnum>0)
                {
                s[row][col + cnum] = 'O';
                s[row][col] = '.';
                }
                col = col+cnum;
                cnum = 0;
            }
            if(s[row][col] == '#')
            {
                cnum = 0;
            }
        }
        cnum = 0;
    }
    return s;

}
int main()
{
    vector<string> input, dup;
    string s;
    while(getline(cin,s))
    {
        input.push_back(s);
    }
    dup = input;
    int q = 10000;
    while(q--)
    {
        vector<string> output;
        output = cycle(input);
        if(output == dup)
        {
        input = output;
        break;
        }
        input = output;
        load(input);
    }
}
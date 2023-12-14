#include<bits/stdc++.h>
using namespace std;
int findverticalmirror(vector<string> s)
{
    int mirror = 1, j, yes = 0;
    for(int i=mirror-1, j=mirror; i>=0 && j<s[0].size(); )
    {
    for(auto it:s)
    {
        if(it[i] == it[j])
        {
        yes = 1;
        }
        else
        {
        yes = 0;
        break;
        }  
    }
    if(yes == 0)
    {
    mirror ++;
    j = mirror;
    i = mirror -1;
    }
    else
    {
        j++;
        i--;
    }
    }

    if(yes ==1)
    return mirror;
   
    return 0; 
}
int findhorimirror(vector<string> s)
{
    int mirror = 1, yes=0;
    int mrow, row;
    for(row = mirror -1 , mrow = mirror  ; row>=0 && mrow<s.size(); )
    {
    for(int col = 0; col < s[0].size(); col++)
    {
    {
        if(s[row][col] == s[mrow][col])
        yes = 1;
        else 
        {
        yes = 0;
        break;
        }
    }
    }
    if(yes == 0)
    {
        mirror++;
        mrow = mirror;
        row = mirror -1;
    }
    else
    {
        mrow++;
        row--;
    }
    }
    return mirror*100;
}
int findsmudge(vector<string> s)
{
    int count = 0, r,c,cr;
    for(int row = 0; row<s.size(); row++)
    {
        for(int crow = row+1; crow<s.size(); crow++)
        {
        for(int col=0; col<s[0].size(); col++)
        {
            if(s[row][col] != s[crow][col])
            {
            count++;
            if(count == 1)
            {
            r= row;
            c = col;
            }
            else
            {
                count = 0;
                break;
            }
            }
        }
        if(count == 1)
        {
            if(s[r][c] == '#')
            s[r][c] = '.';
            else
            s[r][c] = '#';

            for(auto it:s)
            cout<<it<<endl;

            int x= findhorimirror(s);
            return x;
        }
        }
        
    }
    for(int row = 0; row<s.size(); row++)
    {
        for(int col = 0; col<s[0].size(); col++)
        {
        for(int ccol=col+1; ccol<s[0].size(); ccol++)
        {
            if(s[row][col] != s[row][ccol])
            {
            count++;
            if(count == 1)
            {
            r= row;
            c = col;
            }
            else
            {
                count = 0;
                break;
            }
            }
        }
        if(count == 1)
        {
            if(s[r][c] == '#')
            s[r][c] = '.';
            else
            s[r][c] = '#';

            for(auto it:s)
            cout<<it<<endl;

            int x = findverticalmirror(s);
            return x;
        }
        }
        
    }
}
int main()
{
    int sum = 0;
    vector<string> input;
    string s;
    while(getline(cin,s))
    {
        input.push_back(s);
        while(getline(cin,s))
        {
            if(s.empty())
            break;
            input.push_back(s);
        }
        int x = findsmudge(input);
        sum = sum + x;
        // int x = findverticalmirror(input);
        // if(x)
        // {
        // sum = sum+x;
        // }
        // else
        // {
        // x = findhorimirror(input);
        // sum = sum+x;
        // }
        input.clear();
    }
    cout<<sum;
}
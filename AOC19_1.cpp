#include<bits/stdc++.h>
using namespace std;
vector<string> workflow;
string findcurrent(map<char, int> cat, string current)
{
    cout<<current<<endl;
    if(current == "A" || current == "R")
    return current;

    for(int i = 0; i<workflow.size(); i++)
    {
        if(workflow[i].substr(0, workflow[i].find("{")) == current)
        {
            string s = workflow[i].substr(workflow[i].find("{")+1, workflow[i].size());
            while(true)
            {
                if(s[1] == '<')
                {
                if(cat[s[0]] < stoi(s.substr(2, s.size())))
                {
                    current = s.substr(s.find(":")+1, s.find(",")-(s.find(":")+1));
                    return findcurrent(cat, current);
                }
                else
                {
                    s = s.substr(s.find(",")+1, s.size());
                }
                }
                else if(s[1] == '>')
                {
                if(cat[s[0]] > stoi(s.substr(2, s.size())))
                {
                    current = s.substr(s.find(":")+1, s.find(",")-(s.find(":")+1));
                    return findcurrent(cat, current);
                }
                else
                {
                    s = s.substr(s.find(",")+1, s.size());
                }
                }
                else
                {
                current = s.substr(0, s.size() - 1);
                return findcurrent(cat, current);
                }
            }

        }
    }
    return "FAIL";
}
int findA(string input)
{
    map<char, int> cat;
    string s1 = input.substr(3, input.size());
    cat['x'] = stoi(s1);
    s1 = s1.substr(s1.find("=")+1, s1.length());
    cat['m'] = stoi(s1);
    s1 = s1.substr(s1.find("=")+1, s1.length());
    cat['a'] = stoi(s1);
    s1 = s1.substr(s1.find("=")+1, s1.length());
    cat['s'] = stoi(s1);

    string s = findcurrent(cat, "in");
    if(s == "A")
    return cat['x'] + cat['m'] + cat['a'] + cat['s'];

    return 0;


}
int main()
{
    string s;
    string input;
    int sum = 0;
    while(getline(cin, s))
    {
        if(s.empty())
        break;
        workflow.push_back(s);
    }
    while(getline(cin, input))
    {
        int x = findA(input);
        sum = sum + x;
    }
    cout<<sum<<endl;
}
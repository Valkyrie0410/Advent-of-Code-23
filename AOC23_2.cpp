#include <bits/stdc++.h>
using namespace std;

vector<string> input;
int maxPath = 0;
vector<vector<bool>> visited;

void solve(int x, int y, int pathLength) {
    if (x < 0 || y < 0 || x >= input.size() || y >= input[0].size() || visited[x][y] || input[x][y] == '#') {
        return;
    }
    if(x == input.size() - 1)
    {
        maxPath = max(maxPath, pathLength);
        return;
    }

    visited[x][y] = true;
    solve(x - 1, y, pathLength + 1);
    solve(x + 1, y, pathLength + 1);
    solve(x, y - 1, pathLength + 1);
    solve(x, y + 1, pathLength + 1);
    visited[x][y] = false;
}

int main() {
    string s;
    while (getline(cin, s)) {
        input.push_back(s);
    }

    visited.resize(input.size(), vector<bool>(input[0].size(), false));

    solve(0, 1, 1);
           

    cout << maxPath - 1 << endl;
    return 0;
}

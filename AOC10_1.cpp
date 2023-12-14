#include<bits/stdc++.h>
using namespace std;

vector<string> maze;

pair<int, int> findStart() {
    for (int row = 0; row < maze.size(); row++) {
        for (int col = 0; col < maze[row].size(); col++) {
            if (maze[row][col] == 'S') return { row, col };
        }
    }
}

pair<int, int> stepTo(int prevRow, int prevCol, int currRow, int currCol) {
    if (maze[currRow][currCol] == 'L') {
        if (prevRow == currRow - 1 && prevCol == currCol) return { currRow, currCol + 1 };
        else if (prevRow == currRow && prevCol == currCol + 1) return { currRow - 1, currCol };
    }
    else if (maze[currRow][currCol] == 'F') {
        if (prevRow == currRow + 1 && prevCol == currCol) return { currRow, currCol + 1 };
        else if (prevRow == currRow && prevCol == currCol + 1) return { currRow + 1, currCol };
    }
    else if (maze[currRow][currCol] == '7') {
        if (prevRow == currRow + 1 && prevCol == currCol) return { currRow, currCol - 1 };
        else if (prevRow == currRow && prevCol == currCol - 1) return { currRow + 1, currCol };
    }
    else if (maze[currRow][currCol] == 'J') {
        if (prevRow == currRow - 1 && prevCol == currCol) return { currRow, currCol - 1 };
        else if (prevRow == currRow && prevCol == currCol - 1) return { currRow - 1, currCol };
    }
    else if (maze[currRow][currCol] == '|') {
        if (prevRow == currRow - 1 && prevCol == currCol) return { currRow + 1, currCol };
        else if (prevRow == currRow + 1 && prevCol == currCol) return { currRow - 1, currCol };
    }
    else if (maze[currRow][currCol] == '-') {
        if (prevRow == currRow && prevCol == currCol - 1) return { currRow, currCol + 1 };
        else if (prevRow == currRow && prevCol == currCol + 1) return { currRow, currCol - 1 };
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "cant open!";
        return 0;
    }
    string line;
    long long int sum = 0;
    vector<long long int> datas(21);
    while (getline(file, line)) {
        maze.push_back(line);
    }
    
    pair<int, int> prev_1 = findStart();
    pair<int, int> prev_2 = prev_1;
    int step = 1;
    pair<int, int> dir_1_pos = { prev_1.first - 1, prev_1.second };
    pair<int, int> dir_2_pos = { prev_2.first, prev_2.second + 1 };
    while (dir_1_pos.first != dir_2_pos.first || dir_1_pos.second != dir_2_pos.second) {
        pair<int, int> prev_1_tmp = dir_1_pos;
        pair<int, int> prev_2_tmp = dir_2_pos;
        dir_1_pos = stepTo(prev_1.first, prev_1.second, dir_1_pos.first, dir_1_pos.second);
        dir_2_pos = stepTo(prev_2.first, prev_2.second, dir_2_pos.first, dir_2_pos.second);
        prev_1 = prev_1_tmp;
        prev_2 = prev_2_tmp;
        step++;
    }
    cout << step << endl;
}
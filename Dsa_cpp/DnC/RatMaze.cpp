#include <iostream>
#include <vector>
using namespace std;

// Fix 1: Add missing #include <vector>

bool isSafe(int i, int j, int row, int col, int arr[][3], vector<vector<bool>> &visited) {
    // Fix 2: Fix misplaced parentheses
    if ((i >= 0 && i < row) && (j >= 0 && j < col) && arr[i][j] == 1 && !visited[i][j]) {
        return true;
    }
    return false;
}

void solveMaze(int arr[][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output) {
    // Fix 3: Add 'col' to the function parameter list
    if (i == row - 1 && j == col - 1) {
        path.push_back(output);
        return;
    }

    // Down
    if (isSafe(i + 1, j, row, col, arr, visited)) {
        visited[i + 1][j] = true;
        solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');
        visited[i + 1][j] = false;
    }

    // Left
    if (isSafe(i, j - 1, row, col, arr, visited)) {
        visited[i][j - 1] = true;
        solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
        visited[i][j - 1] = false;
    }

    // Right
    if (isSafe(i, j + 1, row, col, arr, visited)) {
        visited[i][j + 1] = true;
        solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
        visited[i][j + 1] = false;
    }

    // Up
    if (isSafe(i - 1, j, row, col, arr, visited)) {
        visited[i - 1][j] = true;
        solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');  // Fix 4: Change 'R' to 'U' for up
        visited[i - 1][j] = false;
    }
}

int main() {
    int maze[3][3] = {
        {1, 1, 0},
        {1, 1, 1},
        {1, 1, 1}
    };
    
    if(maze[0][0]==0){
        cout<<"No path Exist"<<endl;
        return 0;
    }
    int row = 3;  
    int col = 3;

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true;  

    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0, 0, visited, path, output);  

    cout << "Printing the result: " << endl;
    for (auto i : path) {
        cout << i << " ";  
    }
    cout << endl;
    if(path.size()==0){
        cout<<"No Path exist"<<endl;
    }
    return 0;
}

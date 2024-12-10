#include <bits/stdc++.h>
using namespace std;

vector<int> dir = {0, 1, 0, -1};

int dfs(int i, int j, int n, int m, vector<string>& grid, vector<vector<bool>>& vis) {
    if (grid[i][j] == '9') {
        if (!vis[i][j]) {
            vis[i][j] = true;
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int x = 0; x < 4; ++x) {
        int ni = i + dir[x], nj = j + dir[(x+1)%4];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] - grid[i][j] == 1) {
            ans += dfs(ni, nj, n, m, grid, vis);
        }
    }
    return ans;
}

int dfs(int i, int j, int n, int m, vector<string>& grid) {
    if (grid[i][j] == '9') return 1;
    int ans = 0;
    for (int x = 0; x < 4; ++x) {
        int ni = i + dir[x], nj = j + dir[(x+1)%4];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] - grid[i][j] == 1) {
            ans += dfs(ni, nj, n, m, grid);
        }
    }
    return ans;
}

void part1() {
    string line; 
    vector<string> grid;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size()), ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '0') {
                vector<vector<bool>> vis(n, vector<bool>(m));
                ans += dfs(i, j, n, m, grid, vis);
            }
        }
    }
    cout << ans << endl;
}

void part2() {
    string line; 
    vector<string> grid;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size()), ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '0') {
                ans += dfs(i, j, n, m, grid);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
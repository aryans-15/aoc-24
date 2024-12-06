#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> shifts = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void part1() {
    string line;
    vector<string> grid;
    int shift = 0, x, y;
    bool found = false;
    while (getline(cin, line)) {
        grid.push_back(line);
        if (found) continue;
        for (int i = 0; i < int(line.length()); ++i) {
            if (line[i] == '^') {
                found = true;
                x = i, y = int(grid.size()) - 1;
                break;
            }
        }
    }
    set<pair<int, int>> ans;
    int n = int(grid.size()), m = int(grid[0].size());
    while (0 <= y && y < n && 0 <= x && x < m) {
        if (grid[y][x] == '#') {
            y -= shifts[shift].first, x -= shifts[shift].second;
            shift = (shift + 1) % 4;
        } else {
            ans.insert({x, y});
            y += shifts[shift].first, x += shifts[shift].second;
        }
    }
    cout << ans.size() << endl;
}

bool cycle(const vector<string>& grid, int x, int y, int n, int m, int shift=0) {
    vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(4, false)));
    while (0 <= y && y < n && 0 <= x && x < m) {
        if (grid[y][x] == '#') {
            y -= shifts[shift].first, x -= shifts[shift].second;
            shift = (shift + 1) % 4;
        } else {
            if (vis[x][y][shift]) return true;
            vis[x][y][shift] = true;
            y += shifts[shift].first, x += shifts[shift].second;
        }
    }
    return false;
}

void part2() {
    string line;
    vector<string> grid;
    int ans = 0, x, y;
    bool found = false;
    while (getline(cin, line)) {
        grid.push_back(line);
        if (found) continue;
        for (int i = 0; i < int(line.length()); ++i) {
            if (line[i] == '^') {
                found = true;
                x = i, y = int(grid.size()) - 1;
                break;
            }
        }
    }
    int n = int(grid.size()), m = int(grid[0].size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') continue;
            grid[i][j] = '#';
            ans += cycle(grid, x, y, n, m);
            grid[i][j] = '.';
        }
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
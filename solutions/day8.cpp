#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

void part1() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size());
    vector<vector<bool>> antinode(n, vector<bool>(m));
    map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                mp[grid[i][j]].push_back({i, j});
            }
        }
    }
    for (auto entry: mp) {
        int sz = int(entry.second.size());
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int dx = entry.second[i].fi - entry.second[j].fi;
                int dy = entry.second[i].se - entry.second[j].se;
                int nx = entry.second[i].fi + dx, ny = entry.second[i].se + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) antinode[nx][ny] = true;
                nx = entry.second[j].fi - dx, ny = entry.second[j].se - dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) antinode[nx][ny] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += antinode[i][j];
        }
    }
    cout << ans << endl;
}

void part2() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size());
    vector<vector<bool>> antinode(n, vector<bool>(m));
    map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                mp[grid[i][j]].push_back({i, j});
            }
        }
    }
    for (auto entry: mp) {
        int sz = int(entry.second.size());
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int dx = entry.second[i].fi - entry.second[j].fi;
                int dy = entry.second[i].se - entry.second[j].se;
                int nx = entry.second[i].fi, ny = entry.second[i].se;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    antinode[nx][ny] = true;
                    nx += dx, ny += dy;
                } 
                nx = entry.second[j].fi, ny = entry.second[j].se;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    antinode[nx][ny] = true;
                    nx -= dx, ny -= dy;
                } 
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += antinode[i][j];
        }
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
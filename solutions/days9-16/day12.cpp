#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second

vector<int> dir = {0, 1, 0, -1};
const int OFFSET = 10;

void dfs(vector<vector<bool>>& vis, vector<string>&grid, int i, int j, int m, int n, int at, vector<int>& v) {
    for (int idx = 0; idx < 4; ++idx) {
        int nx = i + dir[idx], ny = j + dir[(idx+1)%4];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!vis[nx][ny] && grid[nx][ny] == at) {
                vis[nx][ny] = true, v[0]++;
                dfs(vis, grid, nx, ny, m, n, at, v);
            } else if (grid[nx][ny] != at) {
                v[1] += 1;
            }
        } else {
            v[1] += 1;
        }
    }
}

void dfs(vector<vector<bool>>& vis, vector<string>&grid, int i, int j, int m, int n, int at, vector<int>& v, set<pii>& s) {
    for (int idx = 0; idx < 4; ++idx) {
        int nx = i + dir[idx], ny = j + dir[(idx+1)%4];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!vis[nx][ny] && grid[nx][ny] == at) {
                vis[nx][ny] = true, v[0]++;
                dfs(vis, grid, nx, ny, m, n, at, v, s);
            } else if (grid[nx][ny] != at) {
                s.insert({OFFSET * i + dir[idx], OFFSET * j + dir[(idx+1)%4]});
            }
        } else {
            s.insert({OFFSET * i + dir[idx], OFFSET * j + dir[(idx+1)%4]});
        }
    }
}

void part1() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size()), ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                vector<int> v = {1, 0};
                vis[i][j] = true;
                set<pair<int, int>> s;
                dfs(vis, grid, i, j, m, n, grid[i][j], v, s);
                ans += v[0] * v[1];
            }
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
    int n = int(grid.size()), m = int(grid[0].size()), ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                vector<int> v = {1, 0};
                vis[i][j] = true;
                set<pii> s; 
                dfs(vis, grid, i, j, m, n, grid[i][j], v, s);
                while (!s.empty()) {
                    v[1] += 1;
                    queue<pii> q;
                    pii item = *s.begin();
                    q.push(item), s.erase(item);
                    bool has = false;
                    while (!q.empty()) {
                        pii x = q.front(); q.pop();
                        pii up = {x.fi - OFFSET, x.se}, down = {x.fi + OFFSET, x.se};
                        if (s.count(up)) {
                            q.push(up), s.erase(up), has = true;
                        }
                        if (s.count(down)) {
                            q.push(down), s.erase(down), has = true;
                        }
                    }
                    if (has) continue;
                    q.push(item);
                    while (!q.empty()) {
                        pii x = q.front(); q.pop();
                        pii left = {x.fi, x.se - OFFSET}, right = {x.fi, x.se + OFFSET};
                        if (s.count(left)) {
                            q.push(left), s.erase(left);
                        }
                        if (s.count(right)) {
                            q.push(right), s.erase(right);
                        }
                    }
                }
                ans += v[0] * v[1];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
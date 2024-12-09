#include <bits/stdc++.h>
using namespace std;

const int DX = 1, DY = 1;
const string xmas = "XMAS";
const vector<string> perms = {"MSMS", "MMSS", "SSMM", "SMSM"};
vector<string> grid;
int ans = 0;

void dfs(int index, int x, int y, int dx, int dy) {
    if (index == xmas.length()) return;
    int nx = x + dx, ny = y + dy;
    if (!(0 <= nx && nx < grid.size() && 0 <= ny && ny < grid.size())) return;
    if (grid[nx][ny] != xmas[index]) return;
    if (xmas[index] == 'S') {
        ans += 1;
    } else {
        dfs(index + 1, nx, ny, dx, dy);
    }
}

void part1() {
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'X') {
                for (int dx = -DX; dx <= DX; ++dx) {
                    for (int dy = -DY; dy <= DY; ++dy) {
                        dfs(1, i, j, dx, dy);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

void part2() {
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n = int(grid.size()), m = int(grid[0].size());
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (grid[i][j] != 'A') continue;
            for (auto perm: perms) {
                if (grid[i-1][j-1] == perm[0] && grid[i-1][j+1] == perm[1] &&
                grid[i+1][j-1] == perm[2] && grid[i+1][j+1] == perm[3]) {
                    ans += 1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
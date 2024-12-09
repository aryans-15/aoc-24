#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

void part1() {
    string line; cin >> line;
    vector<int> grid;
    int index = 0, n = int(line.size());
    for (int i = 0; i < n; ++i) {
        int iters = line[i] - '0';
        if (i % 2) {
            for (int j = 0; j < iters; ++j) grid.push_back(-1);
        } else {
            for (int j = 0; j < iters; ++j) grid.push_back(index);
            index += 1;
        }
    }
    int g = int(grid.size());
    int r = g - 1;
    bool done = false;
    for (int i = 0; i < g; ++i) {
        if (grid[i] == -1) {
            swap(grid[i], grid[r]);
            while (grid[r] == -1) {
                r--;
                if (r < i) {
                    swap(grid[i], grid[i-1]);
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
    }
    long long ans = 0;
    for (int i = 0; i < g; ++i) {
        if (grid[i] == -1) break;
        ans += (i * 1LL * grid[i]);
    }
    cout << ans << endl;
}

void part2() {
    string line; cin >> line;
    vector<int> grid;
    int index = 0, n = int(line.size());
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; ++i) {
        int iters = line[i] - '0';
        if (i % 2) {
            for (int j = 0; j < iters; ++j) grid.push_back(-1);
        } else {
            v.push_back({int(grid.size()), {iters, index}});
            for (int j = 0; j < iters; ++j) grid.push_back(index);
            index += 1;
        }
    }
    reverse(v.begin(), v.end());
    int g = int(grid.size());
    for (auto& entry: v) {
        for (int i = 0; i < entry.fi; ++i) {
            int r = i;
            while (r < g && grid[r] == -1) ++r;
            int available = r - i;
            if (available >= entry.se.fi) {
                for (int j = 0; j < entry.se.fi; ++j) {
                    swap(grid[i + j], grid[entry.fi + j]);
                }
                break;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < g; ++i) {
        if (grid[i] != -1) ans += (i * 1LL * grid[i]);
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
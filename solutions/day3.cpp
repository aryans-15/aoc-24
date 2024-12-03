#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MIN_LEN = 8;
const int MAX_LEN = 12;

void part1() {
    map<string, long long> mp;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            string s = "mul(" + to_string(i) + "," + to_string(j) + ")";
            mp[s] = i * j;
        }
    }
    long long ans = 0;
    string line;
    while (getline(cin, line)) {
        int n = int(line.length());
        for (int i = 0; i < n; ++i) {
            for (int len = MIN_LEN; len <= MAX_LEN; ++len) {
                if (mp.count(line.substr(i, len))) {
                    ans += mp[line.substr(i, len)];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

void part2() {
    map<string, long long> mp;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            string s = "mul(" + to_string(i) + "," + to_string(j) + ")";
            mp[s] = i * j;
        }
    }
    long long ans = 0;
    bool operate = true;
    string line;
    while (getline(cin, line)) {
        int n = int(line.length());
        for (int i = 0; i < n; ++i) {
            if (line.substr(i, 4) == "do()") operate = true;
            if (line.substr(i, 7) == "don't()") operate = false;
            if (operate) {
                    for (int len = MIN_LEN; len <= MAX_LEN; ++len) {
                    if (mp.count(line.substr(i, len))) {
                        ans += mp[line.substr(i, len)];
                        break;
                    }
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
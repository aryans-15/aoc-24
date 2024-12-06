#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> rules;
bool ok(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rules.count(v[j]) && rules[v[j]].count(v[i])) return false;
        }
    }
    return true;
}

void part1() {
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        if (line.find("|") != string::npos) {
            int before, after; char delimiter;
            stringstream ss(line);
            ss >> before >> delimiter >> after;
            rules[before].insert(after);
        } else {
            vector<int> v;
            stringstream ss(line);
            string temp;
            while (getline(ss, temp, ',')) {
                v.push_back(stoi(temp));
            }
            int n = int(v.size());
            if (n == 0) continue;
            if (ok(v)) ans += v[n/2];
        }
    }
    cout << ans << endl;
}

void part2() {
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        if (line.find("|") != string::npos) {
            int before, after; char delimiter;
            stringstream ss(line);
            ss >> before >> delimiter >> after;
            rules[before].insert(after);
        } else {
            vector<int> v;
            stringstream ss(line);
            string temp;
            while (getline(ss, temp, ',')) {
                v.push_back(stoi(temp));
            }
            int n = int(v.size());
            if (n == 0 || ok(v)) continue;
            while (!ok(v)) {
                for (int i = 0; i < n; ++i) {
                    for (int j = i + 1; j < n; ++j) {
                        if (rules.count(v[j]) && rules[v[j]].count(v[i])) {
                            swap(v[j], v[i]);
                        }
                    }
                }
            }
            ans += v[n/2];
        }
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
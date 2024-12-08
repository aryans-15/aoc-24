#include <bits/stdc++.h>
using namespace std;

bool ok(vector<long long>& v, long long target, long long cur, int i) {
    if (i == v.size()) return cur == target;
    long long pow = powl(10, ceil(log10(v[i] + 1)));
    return ok(v, target, cur + v[i], i + 1) || ok(v, target, cur * v[i], i + 1);
}

bool ok2(vector<long long>& v, long long target, long long cur, int i) {
    if (i == v.size()) return cur == target;
    long long pow = powl(10, ceil(log10(v[i] + 1)));
    return ok2(v, target, cur + v[i], i + 1) || ok2(v, target, cur * v[i], i + 1) || ok2(v, target, cur * pow + v[i], i + 1);
}

void part1() {
    string line; long long ans = 0;
    while (getline(cin, line)) {
        size_t pos = line.find(':');
        long long target = stoll(line.substr(0, pos));
        stringstream ss(line.substr(pos + 1));
        vector<long long> v; string temp;
        while (ss >> temp) {
            v.push_back(stoll(temp));
        }
        if (ok(v, target, v[0], 1)) ans += target;
    }
    cout << ans << endl;
}

void part2() {
    string line; long long ans = 0;
    while (getline(cin, line)) {
        size_t pos = line.find(':');
        long long target = stoll(line.substr(0, pos));
        stringstream ss(line.substr(pos + 1));
        vector<long long> v; string temp;
        while (ss >> temp) {
            v.push_back(stoll(temp));
        }
        if (ok2(v, target, v[0], 1)) ans += target;
    }
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}
#include <bits/stdc++.h>
using namespace std;

void part1() {
    vector<int> x, y;
    string line;
    while (getline(cin, line)) {
        istringstream stream(line);
        int num1, num2;
        if (stream >> num1 >> num2) {
            x.push_back(num1);
            y.push_back(num2);
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long result = 0;
    for (int i = 0; i < (int)(x.size()); ++i) {
        result += abs(x[i] - y[i]);
    }
    cout << result << '\n';
}

void part2() {
    vector<int> x;
    map<int, int> mp;
    string line;
    while (getline(cin, line)) {
        istringstream stream(line);
        int num1, num2;
        if (stream >> num1 >> num2) {
            x.push_back(num1);
            mp[num2]++;
        }
    }
    long long result = 0;
    for (int i = 0; i < (int)(x.size()); ++i) {
        result += x[i] * mp[x[i]];
    }
    cout << result << endl;
}

int main() {
    //part1();
    part2();
}
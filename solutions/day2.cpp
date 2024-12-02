#include <bits/stdc++.h>
using namespace std;

bool ok(const vector<int>& a) {
    bool inc = true, dec = true, adj = true;
    for (int i = 1; i < (int)(a.size()); ++i) {
        if (a[i] >= a[i-1]) dec = false;
        if (a[i] <= a[i-1]) inc = false;
        int delta = abs(a[i] - a[i-1]);
        if (delta < 1 || delta > 3) adj = false;
    }
    return adj && (dec || inc);
}

void part1() {
    string line;
    int counter = 0;
    while (getline(cin, line)) {
        vector<int> x;
        istringstream stream(line);
        int num; vector<int> a;
        while (stream >> num) {
            a.push_back(num);
        }
        counter += ok(a);
    }
    cout << counter << endl;
}

void part2() {
    string line;
    int counter = 0;
    while (getline(cin, line)) {
        vector<int> x;
        istringstream stream(line);
        int num; vector<int> a;
        while (stream >> num) {
            a.push_back(num);
        }
        for (int skip = 0; skip < (int)(a.size()); ++skip) {
            vector<int> b;
            for (int i = 0; i < (int)(a.size()); ++i) {
                if (i != skip) b.push_back(a[i]);
            }
            if (ok(b)) {
                counter += 1;
                break;
            }
        }
    }
    cout << counter << endl;
}

int main() {
    //part1();
    part2();
}

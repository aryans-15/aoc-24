#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

int get(vector<pair<int, int>>& v) {
    int best = INT_MAX;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if (i*v[0].fi + j*v[1].fi == v[2].fi && i*v[0].se + j*v[1].se == v[2].se) {
                best = min(best, 3*i + j);
            }
        }
    }
    if (best == INT_MAX) best = 0;
    return best;
}

ll get_smart(vector<pair<ll, ll>>& v) {
    ll a = v[0].fi, b = v[1].fi, c = v[0].se, d = v[1].se, e = v[2].fi, f = v[2].se;
    ll det = a*d - b*c;
    if (det == 0) return 0;
    ll x = abs((d*e - b*f) / det);
    ll y = abs((a*f - c*e) / det);
    if (x*a + y*b == e && x*c + y*d == f) return 3*x + y;
    return 0;
}

void part1() {
    string line;
    int ans = 0;
    vector<pair<int, int>> v;
    while (getline(cin, line)) {
        if (line.empty()) {
            ans += get(v);
            v.clear();
        } else if (line.substr(0, 6) == "Button") {
            int x, y;
            sscanf(line.c_str(), "Button %*c: X+%d, Y+%d", &x, &y);
            v.push_back({x, y});
        } else {
            int x, y;
            sscanf(line.c_str(), "Prize: X=%d, Y=%d", &x, &y);
            v.push_back({x, y});
        }
    }
    ans += get(v);
    cout << ans << endl;
}

void part2() {
    string line;
    ll ans = 0;
    vector<pair<ll, ll>> v;
    while (getline(cin, line)) {
        if (line.empty()) {
            ans += get_smart(v);
            v.clear();
        } else if (line.substr(0, 6) == "Button") {
            ll x, y;
            sscanf(line.c_str(), "Button %*c: X+%lld, Y+%lld", &x, &y);
            v.push_back({x, y});
        } else {
            ll x, y;
            sscanf(line.c_str(), "Prize: X=%lld, Y=%lld", &x, &y);
            v.push_back({x + 10000000000000LL, y + 10000000000000LL});
        }
    }
    ans += get_smart(v);
    cout << ans << endl;
}

int main() {
    //part1();
    part2();
}

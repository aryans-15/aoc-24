#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
using ll = long long;
using i128 = __int128;

string trim(string &str) {
    size_t start = 0, len = str.length();
    while (start < len && str[start] == '0') ++start;
    return (start == len) ? "0" : str.substr(start);
}

void part1() {
    string line, temp;
    getline(cin, line);
    stringstream ss(line);
    vector<ll> v;
    while (ss >> temp) {
        v.push_back(stoll(temp));
    } 
    for (int i = 0; i < 25; ++i) {
        int idx = 0;
        while (idx < int(v.size())) {
            int len = int(to_string(v[idx]).length());
            if (v[idx] == 0) {
                v[idx] = 1LL, idx++;
            } else if (len % 2 == 0) {
                ll num = v[idx];
                v[idx] = stoll(to_string(num).substr(0, len/2));
                v.insert(v.begin()+idx+1, stoll(to_string(num).substr(len/2)));
                idx += 2;
            } else {
                v[idx] *= 2024, ++idx;
            }
        }
    }
    cout << v.size() << endl;
}

void part2() {
    string line, temp;
    getline(cin, line);
    stringstream ss(line);
    map<cpp_int, cpp_int> mp;
    while (ss >> temp) {
        cpp_int num(trim(temp));
        mp[num]++;
    }
    for (int i = 0; i < 75; ++i) {
        map<cpp_int, cpp_int> nxt;
        for (const auto&[num, cnt]: mp) {
            string num_str = num.str();
            int len = num_str.length();
            if (num == 0) {
                nxt[1] += cnt;
            } else if (len % 2 == 0) {
                string fh = num_str.substr(0, len/2), sh = num_str.substr(len/2);
                cpp_int fi(trim(fh)), si(trim(sh));
                nxt[fi] += cnt, nxt[si] += cnt;
            } else {
                nxt[num * 2024] += cnt;
            }
        }
        mp = nxt;
    }
    cpp_int ans = 0;
    for (const auto&[num, cnt]: mp) {
        ans += cnt;
    }
    cout << ans << endl;
}

int main() {
    //part1();
        part2();
}
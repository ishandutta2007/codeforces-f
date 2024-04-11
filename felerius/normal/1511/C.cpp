// Yet Another Card Deck (https://codeforces.com/contest/1511/problem/C)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    array<bool, 50> seen{};
    vector<pair<int, int>> a;
    rep(i, n) {
        int ai; cin >> ai; --ai;
        if (seen[ai]) continue;
        a.emplace_back(ai, i);
    }

    while (q--) {
        int t; cin >> t; --t;
        int i = 0;
        while (a[i].first != t)
            ++i;
        cout << (a[i].second + 1) << ' ';
        a[i].second = 0;
        rep(j, i)
            a[j].second++;
        rotate(begin(a), begin(a) + i, begin(a) + i + 1);
    }

    cout << '\n';
    return 0;
}
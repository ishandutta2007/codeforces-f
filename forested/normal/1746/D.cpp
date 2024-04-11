#ifndef LOCAL
#define FAST_IO
#endif

// ============
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)
#define REP3(i, m, n) for (i32 i = (i32) (m); i < (i32) (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)
#define ALL(x) begin(x), end(x)

using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using i32 = signed int;
using i64 = signed long long;
using i128 = __int128_t;
using f64 = double;
using f80 = long double;

template <typename T>
using Vec = vector<T>;

template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

istream &operator>>(istream &is, i128 &x) {
    i64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, i128 x) {
    os << (i64) x;
    return os;
}
istream &operator>>(istream &is, u128 &x) {
    u64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, u128 x) {
    os << (u64) x;
    return os;
}

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;
struct SetUpIO {
    SetUpIO() {
#ifdef FAST_IO
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#endif
        cout << fixed << setprecision(15);
    }
} set_up_io;
// ============

#ifdef DEBUGF
#else
#define DBG(x) (void) 0
#endif

void solve() {
    i32 n, k;
    cin >> n >> k;
    Vec<i32> p(n, 0);
    REP(i, 1, n) {
        cin >> p[i];
        --p[i];
    }
    Vec<i64> s(n);
    REP(i, n) {
        cin >> s[i];
    }
    
    Vec<Vec<i32>> chl(n);
    REP(i, 1, n) {
        chl[p[i]].push_back(i);
    }
    
    const auto dp = [&](const auto &dp, i32 v, i32 k) -> pair<i64, i64> {
        i64 ans = s[v] * k;
        if (chl[v].empty()) {
            return pair<i64, i64>(ans, s[v]);
        }
        i32 ch = k / (i32) chl[v].size();
        i32 more = k % (i32) chl[v].size();
        Vec<i64> pluses;
        for (i32 u : chl[v]) {
            auto [a, b] = dp(dp, u, ch);
            ans += a;
            pluses.push_back(b);
        }
        sort(ALL(pluses), greater());
        REP(i, more) {
            ans += pluses[i];
        }
        return pair<i64, i64>(ans, s[v] + pluses[more]);
    };
    i64 ans = dp(dp, 0, k).first;
    cout << ans << '\n';
}

int main() {
    i32 t;
    cin >> t;
    REP(ti, t) {
        solve();
    }
}
#ifdef LOCAL
#define FAST_IO
#endif

// ===== template.hpp =====
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

#ifdef FAST_IO
__attribute__((constructor)) void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
}
#endif
// ===== template.hpp =====

#ifdef DEBUGF
#include "cpl/template/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

pair<i32, i32> divi(i32 n, i32 k) {
    i32 cnt = 1;
    while (n % k == 0) {
        n /= k;
        cnt *= k;
    }
    return pair<i32, i32>(n, cnt);
}

void solve() {
    i32 n, m;
    cin >> n >> m;
    Vec<pair<i32, i64>> a;
    REP(i, n) {
        i32 ele;
        cin >> ele;
        pair<i32, i32> d = divi(ele, m);
        if (a.empty() || a.back().first != d.first) {
            a.emplace_back(d);
        } else {
            a.back().second += d.second;
        }
    }
    Vec<pair<i32, i64>> b;
    i32 k;
    cin >> k;
    REP(i, k) {
        i32 ele;
        cin >> ele;
        pair<i32, i32> d = divi(ele, m);
        if (b.empty() || b.back().first != d.first) {
            b.emplace_back(d);
        } else {
            b.back().second += d.second;
        }
    }
    DBG(a);
    DBG(b);
    cout << (a == b ? "Yes\n" : "No\n");
}

int main() {
    i32 t;
    cin >> t;
    while (t--) {
        solve();
    }
}
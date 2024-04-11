// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vi a(n);
    trav(ai, a) cin >> ai;

    vi suff(n), pref(n);
    rep(i, n)
        pref[i] = a[i] - (i ? a[i-1] : 0) + (i > 1 ? pref[i-2] : 0);
    for (int i = n - 1; i >= 0; --i)
        suff[i] = (i + 1 == n ? m : a[i+1]) - a[i] + (i + 2 < n ? suff[i+2] : 0);

    int mx = a[0] + (n > 1 ? suff[1] : 0);
    if (n % 2)
        mx += m - a.back() - 1;
    if (a[0] > 1)
        mx = max(mx, a[0] - 1 + suff[0]);
    rep(i, n - 1) {
        if (a[i+1] - a[i] == 1)
            continue;
        int bef = i % 2 ? pref[i-1] : pref[i];
        int aft = i % 2 ? suff[i+1] + 1 : suff[i] - 1;
        mx = max(mx, bef + aft);
    }

    cout << mx << '\n';
    return 0;
}
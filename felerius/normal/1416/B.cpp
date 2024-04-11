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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        trav(ai, a) cin >> ai;
        int sum = accumulate(all(a), 0);
        if (sum % n) {
            cout << "-1\n";
            continue;
        }

        vector<array<int, 3>> ops;
        auto do_op = [&](int i, int j, int x) {
            a[i] -= x * (i + 1);
            a[j] += x * (i + 1);
            ops.push_back({i, j, x});
        };

        if (!a[0]) {
            int i = 0;
            while (i < n && a[i] <= i)
                ++i;
            if (i == n) {
                cout << "-1\n";
                continue;
            }

            do_op(i, 0, 1);
        }

        reps(i, 1, n) {
            int need = (i + 1 - a[i] % (i + 1)) % (i + 1);
            if (need)
                do_op(0, i, need);
            do_op(i, 0, a[i] / (i + 1));
        }

        reps(i, 1, n)
            do_op(0, i, sum / n);

        cout << sz(ops) << '\n';
        for (auto [i, j, x] : ops)
            cout << (i + 1) << ' ' << (j + 1) << ' ' << x << '\n';
    }

    return 0;
}
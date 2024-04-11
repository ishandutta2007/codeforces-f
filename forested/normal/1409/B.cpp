// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
void solve() {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    if (a - x + b - y <= n) {
        cout << x * y << "\n";
        return;
    }
    ll ans = INF;
    {
        ll a_ = max(x, a - n);
        ll b_ = max(y, b - (n - (a - a_)));
        chmin(ans, a_ * b_);
    }
    {
        ll b_ = max(y, b - n);
        ll a_ = max(x, a - (n - (b - b_)));
        chmin(ans, a_ * b_);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}
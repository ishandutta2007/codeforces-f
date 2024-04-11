/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                            \
    cerr << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
    }
typedef long long ll;
// #define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll dp[211][111][111];

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(2 * n, -1);
    vector<pii> uv(k);
    rep(i, k) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u] = v;
        a[v] = u;
        uv[i] = pii(u, v);
    }
    vi b;
    rep(i, 2 * n) {
        if (a[i] == -1) {
            b.push_back(i);
        }
    }
    int m = b.size();
    rep(i, m / 2) {
        int u = b[i], v = b[i + m / 2];
        uv.emplace_back(u, v);
    }
    assert(uv.size() == n);

    ll add = 0;
    rep(i, n) {
        REP(j, i + 1, n) {
            vector<pii> temp;
            temp.emplace_back(uv[i].first, i);
            temp.emplace_back(uv[i].second, i);
            temp.emplace_back(uv[j].first, j);
            temp.emplace_back(uv[j].second, j);
            sort(all(temp));

            bool flag = false;
            rep(i, 4) {
                int ni = (i + 1) % 4;
                if (temp[i].second == temp[ni].second) flag = true;
            }
            if (!flag) add++;
        }
    }
    cout << add << endl;

    // dp[0][0][0] = 0;
    // rep(i, 2 * n) {
    //     rep(j, n + 1) {
    //         rep(k, n + 1) {
    //             if (dp[i][j][k] < 0) continue;
    //             if (a[i] != -1) {
    //                 if (a[i] > i) {
    //                     chmax(dp[i + 1][j + 1][k], dp[i][j][k] - k);
    //                 } else {
    //                     chmax(dp[i + 1][j - 1][k], dp[i][j][k] + k);
    //                 }
    //             } else {
    //                 if (k < n) {
    //                     chmax(dp[i + 1][j][k + 1], dp[i][j][k]);
    //                 }
    //                 if (k > 0) {
    //                     chmax(dp[i + 1][j][k - 1], dp[i][j][k] + k - 1);
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << dp[2 * n][0][0] + add << endl;

    // rep(i, 2 * n + 5) rep(j, n + 5) rep(k, n + 5) dp[i][j][k] = -INF;
}

signed main() {
    int t = 1;
    cin >> t;
    int n = 100;
    rep(i, 2 * n + 5) rep(j, n + 5) rep(k, n + 5) dp[i][j][k] = -INF;
    while (t--)
        solve();
}
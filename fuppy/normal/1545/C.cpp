/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

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

class UnionFind {
  public:
    int n;
    vi par;
    vi ran;
    vi num;
    int g;

    UnionFind(int _n) {
        n = _n;
        g = n;
        par.resize(n);
        ran.resize(n);
        num.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            ran[i] = 0;
            num[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        int numsum = num[x] + num[y];
        if (x == y) {
            return;
        }
        if (ran[x] < ran[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (ran[x] == ran[y]) {
                ran[x]++;
            }
        }
        num[x] = num[y] = numsum;
        g--;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

const int MAXN = 555555;

vl fact(MAXN);
vl rfact(MAXN);

ll mod_pow(ll x, ll p, ll M = MOD) {
    if (p < 0) {
        x = mod_pow(x, M - 2, M);
        p = -p;
    }
    x %= M;
    ll a = 1;
    while (p) {
        if (p % 2)
            a = a * x % M;
        x = x * x % M;
        p /= 2;
    }
    return a;
}

ll mod_inverse(ll a, ll M = MOD) {
    return mod_pow(a, M - 2, M);
}

void set_fact(ll n, ll M = MOD) {
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1] % M;
    }
    rfact[n] = mod_inverse(fact[n], M);
    for (ll i = n - 1; i >= 0; i--) {
        rfact[i] = (i + 1) * rfact[i + 1] % M;
    }
}

//http://drken1215.hatenablog.com/entry/2018/06/08/210000
ll nCr(ll n, ll r, ll M = MOD) {
    if (r > n) return 0;
    assert(fact[2] == 2);
    ll ret = fact[n];
    if (rfact[r] == 0) {
        rfact[r] = mod_inverse(fact[r], M);
    }
    ret = (ret * rfact[r]) % M;
    if (rfact[n - r] == 0) {
        rfact[n - r] = mod_inverse(fact[n - r], M);
    }
    ret = (ret * rfact[n - r]) % M;
    return ret;
}

ll nHr(ll n, ll r) {
    return nCr(n + r - 1, r);
}

void solve() {
    int n;
    cin >> n;

    vii a(2 * n, vi(n));
    rep(i, 2 * n) {
        rep(j, n) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vi state(2 * n);
    vii num(n);
    bool updated = true;

    int kaku_num = 0;
    while (updated) {
        updated = false;
        int kaku = -1;
        rep(k, n) {
            rep(i, n) {
                num[i].clear();
            }
            rep(i, 2 * n) {
                if (state[i] != 0) continue;
                num[a[i][k]].push_back(i);
            }

            rep(i, n) {
                if (num[i].size() == 1) {
                    kaku = num[i][0];
                    updated = true;
                    break;
                }
            }
        }

        if (not updated) break;

        state[kaku] = 1;
        kaku_num++;

        rep(i, 2 * n) {
            if (state[i]) continue;
            rep(j, n) {
                if (a[i][j] == a[kaku][j]) {
                    state[i] = -1;
                    break;
                }
            }
        }
    }

    vii b;
    vi idx;
    rep(i, 2 * n) {
        if (!state[i]) {
            b.push_back(a[i]);
            idx.push_back(i);
        }
    }
    int m = b.size();

    UnionFind uf(2 * m);
    rep(i, m) {
        REP(j, i + 1, m) {
            rep(k, n) {
                if (b[i][k] == b[j][k]) {
                    uf.unite(i, j + m);
                    uf.unite(i + m, j);
                }
            }
        }
    }

    rep(i, m) {
        assert(!uf.same(i, i + m));
    }

    int g = uf.g / 2;
    cout << mod_pow(2, g) << endl;

    vi ans;
    rep(i, 2 * n) {
        if (state[i] == 1) ans.push_back(i);
    }

    set<int> use, non;
    rep(i, m) {
        int u = uf.find(i), v = uf.find(i + m);
        if (use.count(u) or non.count(u)) continue;
        use.insert(u);
        non.insert(v);
    }

    rep(i, m) {
        int u = uf.find(i);
        if (use.count(u)) {
            ans.push_back(idx[i]);
        }
    }
    sort(all(ans));
    for (int u : ans) {
        cout << u + 1 << " ";
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
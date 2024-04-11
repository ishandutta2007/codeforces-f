#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int n, m;
        cin >> n >> m;

        V <V <ii> > g(n + 1);
        vi ans(m);

        V <vi> en;

        rep (m) {
            int u, v;
            cin >> u >> v;
            en.app({u, v});
            g[u].app(mp(v, _)); g[v].app(mp(u, _));
        }

        vi used(n + 1), par(n + 1), paredge(n + 1), h(n + 1);
        vi e;
        function <void(int, int)> dfs = [&] (int u, int p) {
            par[u] = p;
            used[u] = 1;
            for (auto [v, i] : g[u]) {
                if (!used[v]) {
                    h[v] = h[u] + 1;
                    paredge[v] = i;
                    ans[i] = 1;
                    dfs(v, u);
                }
                else if (h[v] < h[u] - 1) {
                    e.app(i);
                }
            }
        };

        dfs(1, 1);

        assert((n - 1) + e.size() == m);

        auto get = [&] (int i) {
            return mp(min(h[en[i][0]], h[en[i][1]]), max(h[en[i][0]], h[en[i][1]]));
        };
        auto down = [&] (int i) {
            if (h[en[i][0]] > h[en[i][1]]) {
                return en[i][0];
            }
            else {
                return en[i][1];
            }
        };
        auto cmp = [&] (int i, int j) {
            return get(i) < get(j);
        };
        sort(all(e), cmp);
        debug(e);

        auto adj = [&] (int i, int j) {
            FOR (ti, 2) {
                FOR (tj, 2) {
                    if (en[i][ti] == en[j][tj]) {
                        return true;
                    }
                }
            }
            return false;
        };
        if (e.size() == 3) {
        bool all_adj = 1;
        FOR (i, 3) {
            FOR (j, i) {
                all_adj &= adj(e[i], e[j]);
            }
        }
        if (e.size() == 3 && all_adj) {
            assert(par[down(e[2])] != (down(e[2]) ^ en[e[2]][0] ^ en[e[2]][1]));
            ans[e[2]] ^= 1;
            ans[paredge[down(e[2])]] ^= 1;
        }            
        }

        FOR (i, m) {
            cout << ans[i];
        }
        cout << endl;
    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}
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
#else
#define debug(x)
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

map <int, int> rep;

struct Dsu {
int n;
vector <int> par, cnt;
Dsu (int n_) {
    n = n_;
    par.resize(n + 1);
    cnt.resize(n + 1, 1);
    FOR (i, n + 1)
        par[i] = i;
}   
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);                
}   
int get_cnt(int u) {
    return cnt[root(u)];
}   
bool merge(int u, int v, bool up) {
    u = root(u);
    v = root(v);
    if (u == v)
        return 0;

    if (up) {
        if (rep.find(u) != rep.end()) rep.erase(u);
    }

    par[u] = v;
    cnt[v] += cnt[u];
    return 1;
}
bool connected(int u, int v) {
    return root(u) == root(v);
}   
bool cut(int u, int v) {
    return root(u) != root(v);
}
};  

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, M1, M2;
    cin >> n >> M1 >> M2;
    V <vi> who(n + 1);
    Dsu le(n), ri(n);
    rep (M1) {
        int u, v;
        cin >> u >> v;
        le.merge(u, v, 0);
    }
    rep (M2) {
        int u, v;
        cin >> u >> v;
        ri.merge(u, v, 0);
    }
    FORN (i, n) {
        if (le.connected(i, 1)) {
            rep[ri.root(i)] = i;
        }
        who[le.root(i)].app(i);
    }
    cout << n - 1 - max(M1, M2) << endl;
    int d = 0;
    while (d < n - 1 - max(M1, M2)) {
        FORN (i, n) {
            if (le.connected(i, 1)) {
                continue;
            }
            int comp = ri.root(i);
            if (rep.begin()->x != comp) {
                int U = i, V = rep.begin()->y;
                cout << U << ' ' << V << endl;
                each (u, who[le.root(i)]) {
                    rep[ri.root(u)] = u;
                }
                d++;
                le.merge(U, V, 0);
                ri.merge(U, V, 1);
            }
            else if (rep.rbegin()->x != comp) {
                int U = i, V = rep.rbegin()->y;
                cout << U << ' ' << V << endl;
                each (u, who[le.root(i)]) {
                    rep[ri.root(u)] = u;
                }
                d++;
                le.merge(U, V, 0);
                ri.merge(U, V, 1);
            }
        }
    }
    assert(d == n - 1 - max(M1, M2));
}
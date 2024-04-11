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
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORN(i, n) for (int i = 1; i <= n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
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

const int LG = 18, N = 1 << LG;

struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i) {
    for (; i < N; i |= i + 1) 
        f[i] ^= 1;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans ^= f[i];
    return ans;
}   
int get(int l, int r) {
    //check r < l!
    return get(r) ^ get(l - 1);
}   
} f[LG];

V <ii> d[N];
int sum[N][LG];
int have[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    trav (e, a) {
        have[e] ^= 1;
    }

    int q;
    cin >> q;
    FOR (i, q) {
        int l, r;
        cin >> l >> r;
        d[l].app(mp(i, l));
        d[r].app(mp(i, l));
    }

    FOR (x, N) {
        if (have[x]) {
            FOR (bit, LG) {
                int pref = (1 << (bit + 1)) - 1;
                f[bit].add(x & pref);
            }
        }
        trav (e, d[x]) {
            int i = e.x, ex = e.y;
            FOR (bit, LG) {

                int mod = 1 << (bit + 1);
                int l = (ex + (1 << bit)) % mod;
                int r = (ex + mod - 1) % mod;

                if (l <= r) {
                    sum[i][bit] ^= f[bit].get(l, r);
                }
                else {
                    sum[i][bit] ^= f[bit].get(l, N - 1) ^ f[bit].get(0, r);
                }
            }
        }
    }

    FOR (i, q) {
        char ans = 'B';
        FOR (j, LG) {
            if (sum[i][j]) {
                ans = 'A';
            }
        }
        cout << ans;
    }
    cout << endl;
}
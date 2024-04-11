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

template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) { v = (int)((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend string ts(mint a) { return to_string(a.v); }

    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = (int)((ll)v*m.v%MOD); return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    mint & operator ^=(const int &p) { return (*this) = pow(this, p); }

    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    friend mint operator^(mint a, const int p) { return pow(a, p); }
};

const int MOD = 998244353;

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;

std::ostream& operator << (std::ostream& o, const mi& a)
{
    cout << a.v;
    return o;
}

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FORI(i,1,SZ) FOR(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
 
vmi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
    invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FORI(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FORI(i,1,SZ) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1]*invs[i];
    }
}
mi comb(int a, int b) {
    if (a < b || b < 0) return 0;
    assert(a < fac.size());
    return fac[a]*ifac[b]*ifac[a-b];
}
mi partNonNegative(int a, int b) {
    assert(a >= 0);
    if (a == 0 && b == 0) {
        return 1;
    }
    else {
        return comb(a + b - 1, b - 1);
    }
}
mi partPositive(int a, int b) {
    assert(a >= 0);
    if (a == 0 && b == 0) {
        return 1;
    }
    else {
        return comb(a - 1, b - 1);
    }
}

const int N = 2007;
mi dp[2007][2007][11];
mi od[11];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        int n;
        cin >> n;
        auto val = [&] (int a) {
            int ans = 0;
            int f = 1;
            while (a) {
                ans += (a%10) * f;
                ans %= 11;
                f = 11-f;
                a /= 10;
            }
            return ans;
        };  
        V <vi> d(2);
        rep (n) {
            int a;
            cin >> a;
            d[to_string(a).size()%2].app(val(a));
        }

        int sum = 0;
        each (e, d[1]) {
            sum +=e;
            sum%=11;
        }
        FOR (i, n + 1) FOR (j, n + 1) FOR (k, 11) dp[i][j][k] = 0;

        dp[0][0][0] = 1;
        FOR (i, (int)d[1].size()) {
            FOR (j, i + 1) {
                FOR (k, 11) {
                    dp[i + 1][j + 1][(k + d[1][i])%11] += dp[i][j][k];
                    dp[i + 1][j][k] += dp[i][j][k];
                }
            }
        }
        genFac(N * 2);

        int onp = (d[1].size() + 1)/2;
        int os = (int)d[1].size() - onp;
        FOR (i, 11) {
            od[i] = 0;
        }
        FOR (s, 11) {
            od[(s - (sum - s) + 11) % 11] += dp[d[1].size()][onp][s] * fac[onp] * fac[os];
        }

        FOR (i, n + 1) FOR (j, n + 1) FOR (k, 11) dp[i][j][k] = 0;
        dp[0][0][0] = 1;
        FOR (i, (int)d[0].size()) {
            FOR (j, i + 1) {
                FOR (k, 11) {
                    dp[i + 1][j + 1][(k + d[0][i])%11] += dp[i][j][k];
                    dp[i + 1][j][k] += dp[i][j][k];
                }
            }
        }


        int s0 = 0;
        each (e, d[0]) {
            s0 += e;
            s0 %= 11;
        }

        auto f = [&] (int n, int k) {
            return fac[n] * partNonNegative(n, k);
        };

        int pl = (int)d[1].size()/2+1;
        int mn = ((int)d[1].size()+1)-pl;

        mi ans = 0;
        FOR (h, (int)d[0].size() + 1) {
            int ost = (int)d[0].size() - h;
            mi sp = f(h, pl) * f(ost, mn);
            FOR (s, 11) {
                int va = (s - (s0 - s) + 11) % 11;
                int r = (11 - va)%11;
                debug3(s, va, r);
                debug(dp[d[0].size()][h][s]);
                debug(od[r]);
                debug2(h, ost);
                debug2(pl, mn);
                debug(sp);
                ans+= dp[d[0].size()][h][s] * sp * od[r];

            }
        }
        cout << ans << endl;        
    }

}
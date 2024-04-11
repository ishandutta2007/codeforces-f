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
#define debug(x) std::cerr << #x << ": " << x << '\n';

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

int n, MOD;

int sum(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}
int dif(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}
void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}
int mul(int a, int b) {
    return a * b % MOD;
}

const int N = 57;
int dp[N][N * N], pref[N][N * N];
int comb[N][N];
int fac[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> MOD;

    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    FOR (i, N) {
        comb[i][0] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            comb[i][j] = sum(comb[i - 1][j - 1], comb[i - 1][j]);
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i * i; ++j) {
            pref[i - 1][j + 1] = sum(pref[i - 1][j], dp[i - 1][j]);
        }
        for (int j = 0; j <= i * i; ++j) {
            if (j < i - 1) {
                dp[i][j] = pref[i - 1][j + 1];
            }
            else {
                dp[i][j] = dif(pref[i - 1][j + 1], pref[i - 1][j - (i - 1)]);    
            }
        }
    }

    //f(a, b) = number of permutations with length a and b inversions

    int ans = 0;
    for (int right = 1; right <= n; ++right) {
        int neu = 0;
        FORN (y, right) {
            FORN (x, y - 1) {
                int want = y - x;
                for (int rx = want + 1; rx <= right * right; ++rx) {
                    add(neu, mul(dp[right - 1][rx], pref[right - 1][rx - want]));
                }
            }
        }
        int left = n - right;
        add(ans, mul(mul(neu, comb[n][right]), fac[left]));
    }
    cout << ans << endl;
}
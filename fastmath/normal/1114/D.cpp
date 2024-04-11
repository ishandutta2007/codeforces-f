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
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
const int N = 5007;
int dp[N][N];
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vi a(n);
    re(a);

    vi c;
    FOR (i, n) {
        if (i == 0 || a[i] != a[i - 1])
            c.app(a[i]);
    }

    n = c.size();
    FOR (i, N)
        FOR (j, N)
            dp[i][j] = N;

    FOR (i, n)
        dp[i][i] = 0;

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            if (l) {
                ckmin(dp[l - 1][r], dp[l][r] + 1);
            }
            if (r + 1 < n) {
                ckmin(dp[l][r + 1], dp[l][r] + 1);
            }
            if (l && r + 1 < n && c[l - 1] == c[r + 1]) {
                ckmin(dp[l - 1][r + 1], dp[l][r] + 1);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}
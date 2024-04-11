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
const int N = 1007;
bool dp[N][N * 2];
char last[N][N * 2];
ii prv[N][N * 2];
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    V <pair <char, int> > c = { {'W', 1}, {'L', -1}, {'D', 0}};

    dp[0][N] = 1;
    FOR (i, n) {
        FOR (j, 2 * N) {

            if (j == k + N || j == -k + N)
                continue;

            if (dp[i][j]) {
                trav (e, c) {
                    if (e.x != s[i] && s[i] != '?')
                        continue;
                    dp[i + 1][j + e.y] = 1;
                    last[i + 1][j + e.y] = e.x;
                    prv[i + 1][j + e.y] = mp(i, j);
                }
            }   
        }
    }

    int cur = -1;
    if (dp[n][k + N]) {
        cur = k + N;
    }
    else if (dp[n][-k+N]) {
        cur = -k+N;
    }
    else {
        cout << "NO" << endl;
        exit(0);
    }

    string ans;
    int t = n;
    FOR (i, n) {
        ans += last[t][cur];
        tie(t, cur) = prv[t][cur];
    }
    reverse(all(ans));
    cout << ans << endl;
}
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
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    vi ref(10, -1);
    ref[0] = 0;
    ref[1] = 1;
    ref[2] = 5;
    ref[5] = 2;
    ref[8] = 8;
    int t;
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;

        string s;
        cin >> s;

        int ch = stoll(s.substr(0, 2));
        int cm = stoll(s.substr(3, 2));

        auto check = [&] () {
            vi di = {ch/10, ch%10, cm/10, cm%10};
            trav (e, di) {
                if (ref[e] == -1) {
                    return false;
                }
            }
            reverse(all(di));
            trav (e, di) {
                e = ref[e];
            }

            int ref_h = di[0] * 10 + di[1];
            int ref_m = di[2] * 10 + di[3];
            return ref_h < h && ref_m < m;
        };

        while (!check()) {
            cm++;
            if (cm == m) {
                cm = 0;
                ch++;
            }
            if (ch == h) {
                ch = 0;
            }
        }

        cout << ch/10 << ch%10 << ":" << cm/10 << cm%10 << endl;
    }
}
/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/
 
#include <bits/stdc++.h>
 
// #include <atcoder/all>
 
using namespace std;
// using namespace atcoder;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vi primes;

void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep (i, n) {
        cin >> a[i];
    }

    unordered_map<ll, int> mp;
    rep (i, n) {
        ll temp = 1;
        for (ll j: primes) {
            ll jj = j * j;
            if (jj > a[i]) break;
            while (a[i] % jj == 0) {
                a[i] /= jj;
            }
            if (a[i] % j == 0) {
                temp *= j;
                a[i] /= j;
            }
        }
        if (a[i] > 1) temp *= a[i];
        mp[temp]++;
    }

    int ans0 = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) chmax(ans0, itr->second);

    unordered_map<ll, int> mp2;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second % 2 == 1) {
            mp2[itr->first] += itr->second;
        }
        else {
            mp2[1] += itr->second;
        }
    }
    int ans1 = 0;
    for (auto itr = mp2.begin(); itr != mp2.end(); itr++) chmax(ans1, itr->second);

    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        if (w == 0) {
            cout << ans0 << '\n';
        }
        else {
            cout << ans1 << '\n';
        }
    }
}

signed main() {
    fio();

    int m = 1000111;
    vector<bool> is_prime(m, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < m; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2; i * j < m; j++) is_prime[i * j] = false;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
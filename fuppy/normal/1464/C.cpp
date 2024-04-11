//*
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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vl hon(26);
vl power(26);

bool solve(ll t, vl kouho, int idx) {
    if (idx == -1) {
        for (auto x: kouho) {
            if (x == t) return true;
        }
        return false;
    }
    vl kouho2;
    ll haba = power[idx];
    for (ll x: kouho) {
        if (x <= t) {
            ll diff = t - x;
            ll num = diff / haba;
            chmin(num, hon[idx]);
            num -= 3;
            if ((num % 2 == 0) != (hon[idx] % 2 == 0)) num--;
            rep (i, 5) {
                if (abs(num) <= hon[idx]) {
                    kouho2.push_back(x + num * haba);
                }
                num += 2;
            }
        }
        else {
            ll diff = x - t;
            ll num = diff / haba;
            chmin(num, hon[idx]);
            num -= 3;
            if ((num % 2 == 0) != (hon[idx] % 2 == 0)) num--;
            rep (i, 5) {
                if (abs(num) <= hon[idx]) {
                    kouho2.push_back(x - num * haba);
                }
                num += 2;
            }
        }
    }
    sort(all(kouho2));
    UNIQUE(kouho2);
    vl res;
    auto itr = lower_bound(all(kouho2), t);
    if (itr != kouho2.end()) res.push_back(*itr);
    if (itr != kouho2.begin()) {
        itr--;
        res.push_back(*itr);
    }
    return solve(t, res, idx - 1);
}

signed main() {
    ll n, t;
    cin >> n >> t;
    power[0] = 1;
    rep (i, 25) power[i + 1] = power[i] * 2;

    vi a(n);
    string s;
    cin >> s;
    rep (i, n) {
        a[i] = s[i] - 'a';
    }

    ll ans = 0;
    rep (i, a.size()) {
        ans += power[a[i]];
    }
    // DEBUG(ans);
    // return 0;

    if (n == 1) {
        if (t == power[a[0]]) {
            Yes();
        }
        else {
            No();
        }
        return 0;
    }
    else if (n == 2) {
        if (t == -power[a[0]] + power[a[1]]) {
            Yes();
        }
        else {
            No();
        }
        return 0;
    }

    ll add = -power[a[a.size() - 2]] + power[a[a.size() - 1]];
    t -= add;

    rep (i, n - 2) {
        hon[a[i]]++;
    }
    bool res = solve(t, vl(1, 0), 25);

    Yes(res);
}
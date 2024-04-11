#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


signed main() {
  fio();
  int n;
  cin >> n;
  vi m(n);
  rep (i, n) {
    cin >> m[i];
  }

  vector<pii> xi(n);
  rep (i, n) {
    xi[i].second = i;
    xi[i].first = i - m[i];
  }
  sort(all(xi));

  int xj = 0;
  int num = 0;
  int sub = 0;
  ll ans = 0;

  rep (i, n) {
    ans += num - m[i];
    while (xj < n and xi[xj].second <= i) xj++;
    if (xi[xj].first - sub == 0) num++;
    else sub++;
  }
  cout << ans << endl;
}

// signed main() {
//   fio();
//   ll n, u;
//   cin >> n >> u;
//   vl e(n);
//   rep (i, n) cin >> e[i];

//   bool flag = false;
//   rep (i, n - 2) {
//     if (e[i + 2] - e[i] <= u) flag = true;
//   }
//   if (not flag) {
//     cout << -1 << endl;
//     return 0;
//   }

//   double ok = 0, ng = 1;
//   rep (_, 100) {
//     double x = (ok + ng) / 2;
//     using P = pair<double, int>;
//     deque<P> deq;

//     bool flag = false;
//     rep (i, n) {
//       while (deq.size() > 0) {
//         int j = deq[0].second;
//         if (e[i] - e[j] > u) {
//           deq.pop_front();
//         }
//         else break;
//       }

//       if (deq.size() > 0) {
//         double ma = deq[0].first;
//         if (e[i] >= ma) {
//           flag = true;
//           break;
//         }
//       }

//       if (i >= 1) {
//         double add = (e[i] - x * e[i - 1]) / (1 - x);
//         while (deq.size() > 0) {
//           if (deq.back().first >= add) deq.pop_back();
//           else break;
//         }
//         deq.push_back(P(add, i - 1));
//       }
//     }

//     if (flag) ok = x;
//     else ng = x;
//   }

//   Sp(ok);
// }
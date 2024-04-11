#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
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
const ll INF = 1e18;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair



const int N = 201000;
const int M = 401000;
int n;

class UnionFind {
public:
  int n;
  vi par; //
  vi ran; //
  vi num; //

  UnionFind(int _n) {
    n = _n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
    }
  }

  //
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }

  //xy
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
  }

  //xy
  bool same(int x, int y) {
    return find(x) == find(y);
  }

};

vector< pair<ll, pll> > edges;
vector<bool> used(M, false);

ll kruskal() {
  sort(edges.begin(), edges.end());
  UnionFind uf(n);
  ll res = 0;
  for (int i = 0; i < edges.size(); i++) {
    if (!uf.same(edges[i].second.first, edges[i].second.second)) {
      uf.unite(edges[i].second.first, edges[i].second.second);
      res += edges[i].first;
      used[i] = true;
    }
  }
  return res;
}


int main() {
  fio();
  int m;
  cin >> n >> m;
  vl a(n);
  ll mi = INF, idx = -1;
  rep (i, n) {
    cin >> a[i];
    if (a[i] < mi) {
      mi = a[i];
      idx = i;
    }
  }
  rep (i, n) {
    if (i == idx) {
      continue;
    }
    edges.push_back(make_pair(a[idx] + a[i], pll(idx, i)));
  }
  rep (i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    edges.push_back(make_pair(w, pll(u, v)));
  }
  cout << kruskal() << endl;
}
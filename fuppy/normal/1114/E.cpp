#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cout<<v[i][j]<<" ";}cout<<endl;}


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
const ll INF = (ll)1e18 + 1;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

ll gcd(ll a, ll b) {
	if (b > a) {
		swap(a, b);
	}
	ll r = a%b;
	while (r != 0) {
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}


int main() {
  
  int n;
  cin >> n;
  int q = 60;
  int ok = n - 2, ng = 1000000000;
  while (ok + 1 < ng) {
    ll mid = (ng + ok) / 2;
    cout << "> " << mid << endl << flush;
    int res;
    cin >> res;
    if (res) ok = mid;
    else ng = mid;
    q--;
  }
  

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  vi idx(n);
  rep (i, n) {
    idx[i] = i + 1;
  }
  std::shuffle(idx.begin(), idx.end(), engine);

  vl a;
  rep (i, q) {
    cout << "? " << idx[min(i, n - 1)] << endl << flush;
    int res;
    cin >> res;
    a.push_back(res);
  }
  a.push_back(ok + 1);
  sort(all(a));
  UNIQUE(a);
  ll g = a[1] - a[0];
  rep (i, a.size()) {
    for (int j = i + 1; j < a.size(); j++) {
      g = gcd(g, a[j] - a[i]);
    }
  }
  cout << "! " << (ok + 1) - (n - 1) * g << " " << g << endl << flush;
  return 0;
}
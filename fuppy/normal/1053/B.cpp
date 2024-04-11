

#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl


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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep1(i,n) for(int i=n;i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


int main() {
	fio();
	int n;
	cin >> n;
	vl a(n);
	rep(i, n) {
		cin >> a[i];
		ll mask = 1LL << 62;
		int cnt = 0;
		while (mask >= 1) {
			if (a[i] & mask) {
				cnt++;
			}
			mask >>= 1;
		}
		a[i] = cnt;
	}
	//DEBUG_VEC(a);
	vi sum(n + 1), gu(n + 1), ki(n + 1);
	rep(i, n) {
		sum[i + 1] = sum[i] + a[i];
		if (sum[i + 1] % 2 == 0) {
			gu[i + 1] = gu[i] + 1;
			ki[i + 1] = ki[i];
		}
		else {
			gu[i + 1] = gu[i];
			ki[i + 1] = ki[i] + 1;
		}
	}
	/*
	DEBUG_VEC(sum);
	DEBUG_VEC(gu);
	DEBUG_VEC(ki);
	//*/
	ll ans = 0;
	rep(i, n) {
		int su = 0;
		int ma = 0;
		REP(j, i, n) {
			su += a[j];
			if (a[j] > ma) {
				ma = a[j];
			}
			int nokori = su - ma;
			if (su % 2 == 0 && ma <= nokori) {
				ans++;
			}
			if (su >= 130) {
				if (sum[i] % 2 == 0) {
					ans += gu[n] - gu[j + 1];
				}
				else {
					ans += ki[n] - ki[j + 1];
				}
				break;
			}
		}
	}
	cout << ans << endl;
}

/*
2
1 1

*/
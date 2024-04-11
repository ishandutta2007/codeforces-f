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
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


void solve() {
    int r, n;
    cin >> r >> n;

    vi ans(n + 1, -inf);
    ans[0] = 0;
    deque<int> times;
    times.push_back(0);
    vi t(n + 1), x(n + 1), y(n + 1);
    int ma = -inf;
    int ti = 0;
    rep1 (i, n) {
        cin >> t[i] >> x[i] >> y[i];
        x[i]--; y[i]--;
        while (times.size() > 0) {
            int tt = times[0];
            if (t[i] - tt > 2 * r) {
                chmax(ma, ans[ti]);
                ti++;
                times.pop_front();
            }
            else break;
        }
        // DEBUG_VEC(times);
        int ma2 = -inf;
        for (int j = i - 1; j >= i - (int)times.size(); j--) {
            int dist = abs(x[j] - x[i]) + abs(y[j] - y[i]);
            // DEBUG(dist);
            // DEBUG(t[i] - t[j]);
            if (dist <= t[i] - t[j]) {
                chmax(ma2, ans[j]);
            }
        }
        // DEBUG(pii(ma, ma2));
        ans[i] = max(ma, ma2) + 1;
        // DEBUG_VEC(ans);
        times.push_back(t[i]);
    }

    int res = 0;
    rep (i, ans.size()) chmax(res, ans[i]);
    cout << res << endl;
}

signed main() {
    fio();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
ll x, y;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= a / b * x; 
}
ll solve(ll x, ll y) {
	if(y < x) return x + y;
	else if(y % x == 0) return x;
	else return y - (y % x) / 2;
}
int main() {
	//freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		x = read(), y = read(); 
		int tmp = solve(x, y);
		cout << solve(x, y) << '\n';
	}
	return 0;
}
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e5;
int n, m, q, cnt[maxn + 5];
int ans;
int main() {
// 	freopen("in.txt", "r", stdin);
	n = read(), m = read(), ans = n;
	rep(i, 1, m) {
		int u = read(), v = read();
		if(u > v) swap(u, v);
		if(cnt[u] ++ == 0) ans --; 
	}
	q = read();
	rep(i, 1, q) {
		int opt = read();
		if(opt == 3) {cout << ans << '\n';continue;}
		int u = read(), v = read();
		if(u > v) swap(u, v);
		if(opt == 1) {
			if(cnt[u] ++ == 0) ans --;
		}
		else {
			if(-- cnt[u] == 0) ans ++;
		}
	}
	return 0;
}
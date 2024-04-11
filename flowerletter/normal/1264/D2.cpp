/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e6;
const int mod = 998244353; 
int n, ans, fac[maxn + 5], inv[maxn + 5], A[maxn + 5], B[maxn + 5], pre[maxn + 5][3];
char s[maxn + 5]; 
void init() {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	rep(i, 2, n) fac[i] = 1ll * fac[i - 1] * i % mod;
	rep(i, 2, n) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	rep(i, 2, n) inv[i] = 1ll * inv[i] * inv[i - 1] % mod;
}
inline int C(int n, int m) {
	if(n < m) return 0;
	if(m < 0) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
inline void upd(int &x) {x = (x >= mod) ? (x - mod) : x;}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%s", s + 1), n = strlen(s + 1), init();
	rep(i, 1, n) {
		pre[i][0] = pre[i - 1][0] + (s[i] == '?');
		pre[i][1] = pre[i - 1][1] + (s[i] == '(');
		pre[i][2] = pre[i - 1][2] + (s[i] == ')');
	}
	rep(i, 0, n) A[i] = pre[n][0] - pre[i][0], B[i] = i - pre[n][2] - pre[i][0] - pre[i][1], upd(B[i] += mod);
	rep(i, 0, n) {
		int S = pre[n][0], T = i - pre[n][2];
		upd(ans += 1ll * A[i] * C(S - 1, T - 1) % mod);
		upd(ans += mod - 1ll * B[i] * C(S, T) % mod);
	}
	printf("%d\n", ans);
	return 0;
}
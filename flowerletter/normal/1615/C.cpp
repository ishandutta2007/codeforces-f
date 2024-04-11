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
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 1e5;
char s[maxn + 5], t[maxn + 5];
int n;
int solve(int x) {
	int cnt[2] = {0, 0};
	rep(i, 1, n) if((s[i] != t[i]) != x) cnt[s[i] - '0'] ++;
	if(cnt[0] == cnt[1] - x) return cnt[0] + cnt[1];
	else return inf; 
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		cin >> s + 1 >> t + 1;
		int tmp = min(solve(0), solve(1));
		cout << (tmp == inf ? -1 : tmp) << '\n';
	}
	return 0;
}
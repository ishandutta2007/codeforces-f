#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif
 
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
 
const int maxn = (1 << 18) + 5;
const int mod = 1e9 + 7;
 
int rk[maxn], sa[maxn];
PI f[maxn];
 
int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	int n, m;
	string s;
	cin >> n >> s;
	
	m = 1 << n;
	for (int i = 0; i < m; i++) rk[i] = s[i] - 'a';
	for (int i = 0; i < m; i++) sa[i] = i;
	
	for (int i = 0; i <= n; i++) {
		int mark = (i > 0 ? (1 << (i - 1)) : 0);
		
		for (int j = 0; j < m; j++) f[j] = PI(rk[j], rk[j ^ mark]);
		sort(sa, sa + m, [&](int a, int b) {
			return f[a] < f[b];
		});
		
		for (int j = 0; j < m; j++) {
			rk[sa[j]] = j;
			if (j > 0 && f[sa[j]] == f[sa[j - 1]]) rk[sa[j]] = rk[sa[j - 1]];
		}
	}
	
	for (int i = 0; i < m; i++) cout << s[i ^ sa[0]];
    cout << endl;
 
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

char s[N];

int n;
 
int main() {
	int T; read(T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int c = 0;
		for (int i = 1; i <= n; i++) {
			int j = i;
			while (j < n && s[i] == s[j + 1]) ++j;
			if (s[i] == '0') c++;
			i = j;
		}
		if (!c) puts("0");
		else if (c == 1) puts("1");
		else puts("2");
	}
	return 0;
}
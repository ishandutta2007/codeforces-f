/*
				---~;;;;:~--,
			  :;;;;;;;;;;;;;;;:
		   ,:;;;;;;;;;;;;;;;;;;;-
		  ~;;;;;;;;;;;;;;;;;;;;;;:.
		 ;;;;;;;;;;;;;;;;;;;;;;;;;;.
		:;;;;;;;;;;;;;;;;;;;;;;;;;;;.
	   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;~
	 .:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;-
   ,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;~
   -;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;.
  ;;;;;;;;;;;;;;;:;:*;!;;;;;;;;:;;;;;;;~
 -;;;;;;;;;;;;;;;:==$$$;;;;;;;;=,;;;;;;~
 ~;;;;;;;;;;;;;;;;$$$$$;;;;;;;-$$=!;;;;~
 ~;;;;;;;;;;;;;;;!$$$$!;;;;;;;$$$$$-;;;,
.;;;;;;;;;;;;;;;;:*$$=!;;;;;;;;$$$$.;;;.
.;;;;;;;;;;;;;;;;;:**:;;;;;;;;~=$$*;;;;.
.;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;~~~;;;;:
,;;;;;;;;;;;;;;;;;;;;;;~:;;~;;;;;;;;;;~
-;;;;;;;;;;;;;;;;;;;;~===$$==:;;;;;;;;~
-;;;;;;;;;;;;;;;;;;;=$$$$$$$$$$:;;;;;;~
-;;;;;;;;;;;;;;;;;=$$$;!!!!:;$$$=:;;;;~
-;;;;;;;;;;;;;;;~$$$:;;;;;;;;~$$$=;;;;;.
.;;;;;;;;;;;;;;*$$;;;;;;;;;;;;;!==;;;;;.
.;;;;;;;;;;;;;!$$*;;;;;;;;;;;;;;,-;;;;;.
 :;;;;;;;;;;;;;!=;;;;;;;;;;;;;;;;;;;;;~
  ;;;;;;;;;;;;;:;;;;;;;;;;;;;;;;;;;;;;
   -;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;:,
	.,:;;;;;;;;;;;;;;;;;;;;;;;;;;:,
		~:;;;;;;;;;;;;;;;;;;;;:~
		   ,---~~;;;;;;~~---,
:blobsad:
*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 301010
#define MAXS 22
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

ll A[MAX], C[MAX]; //delta_C
ll sp[MAX][MAXS];

//1-based

void solve() {
	ll Q;
	cin >> Q;
	cin >> A[1] >> C[1];
	ll i, m;
	for (i = 1; i <= Q; i++) {
		cin >> m;
		if (m == 1) {
			ll v = i + 1;
			ll p;
			cin >> p >> A[v] >> C[v];
			p++;
			ll k;
			sp[v][0] = p;
			for (k = 1; k < MAXS; k++) sp[v][k] = sp[sp[v][k - 1]][k - 1];
		}
		else {
			ll v, w;
			cin >> v >> w;
			v++;
			ll k;
			ll sum = 0;
			ll w2 = w;
			while (w) {
				ll r = v;
				for (k = MAXS - 1; k >= 0; k--) {
					while (A[sp[r][k]]) {
						r = sp[r][k];
					}
				}
				ll buy = min(w, A[r]);
				if (buy == 0) break;
				sum += (buy * C[r]);
				w -= buy;
				A[r] -= buy;
			}
			cout << (w2 - w) << bb << sum << ln;
			cout.flush();
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		solve();
	}
}
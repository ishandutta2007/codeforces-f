#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb fflush(stdout)

using namespace std;

const int max_n = 100005;


const int mod = 998244353;
int n, k;

int dp[1015][2015][2];

int main() {
	read2(n, k);
	dp[0][1][0] = 2;
	dp[0][2][1] = 2;
	FOR(s,0,n) {
		FOR(u,0,k+1) {
			// dp[s][u][0] 
			// + A
			dp[s+1][u][0] += dp[s][u][0];
			if (dp[s+1][u][0] >= mod) dp[s+1][u][0] -= mod;
			dp[s+1][u+1][0] += dp[s][u][0];
			if (dp[s+1][u+1][0] >= mod) dp[s+1][u+1][0] -= mod;
			// + B
			dp[s+1][u+1][1] += dp[s][u][0];
			if (dp[s+1][u+1][1] >= mod) dp[s+1][u+1][1] -= mod;
			dp[s+1][u+1][1] += dp[s][u][0];
			if (dp[s+1][u+1][1] >= mod) dp[s+1][u+1][1] -= mod;

			//dp[s][u][1]
			// + A
			dp[s+1][u][0] += dp[s][u][1];
			if (dp[s+1][u][0] >= mod) dp[s+1][u][0] -= mod;
			dp[s+1][u][0] += dp[s][u][1];
			if (dp[s+1][u][0] >= mod) dp[s+1][u][0] -= mod;
			// + B
			dp[s+1][u][1] += dp[s][u][1];
			if (dp[s+1][u][1] >= mod) dp[s+1][u][1] -= mod;
			dp[s+1][u+2][1] += dp[s][u][1];
			if (dp[s+1][u+2][1] >= mod) dp[s+1][u+2][1] -= mod;
		}
	}
	printf("%d\n", (dp[n-1][k][0] + dp[n-1][k][1]) % mod);
}
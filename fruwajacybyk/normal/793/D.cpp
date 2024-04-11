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

int n, k;
int diff[85][85];
int dp[85][85][85];

int main() {
	read2(n, k);
	make(m);
	FOR(i,0,n) FOR(j,0,n) diff[i][j] = 1e9;
	FOR(i,0,m) {
		make3(a, b, c);
		a--; b--;
		diff[a][b] = min(diff[a][b], c);
	}
	FOR(i,0,n) diff[i][i] = 1e9;
	if (k == 1) {
		printf("0\n");
		return 0;
	}
	FOR(i,0,n) FOR(j,0,n) {
		dp[i][j][2] = 1e9;
		int a = min(i,j);
		int b = max(i,j);
		FOR(u,a,b+1) {
			dp[i][j][2] = min(dp[i][j][2], diff[i][u]);
		}
	}
	FOR(l,3,k+1) {
		FOR(i,0,n) FOR(j,0,n) dp[i][j][l] = 1e9;
		FOR(i,0,n) FOR(j,0,n) {
			if (i < j) {
				FOR(u,i+1,j+1) {
					dp[i][j][l] = min(dp[i][j][l], diff[i][u] + dp[u][i+1][l-1]);
					dp[i][j][l] = min(dp[i][j][l], diff[i][u] + dp[u][j][l-1]);
				}
			} 
			if (j < i) {
				FOR(u,j,i) {
					dp[i][j][l] = min(dp[i][j][l], diff[i][u] + dp[u][i-1][l-1]);
					dp[i][j][l] = min(dp[i][j][l], diff[i][u] + dp[u][j][l-1]);
				}
			}
		}
	}
	int best = 1e9;
	FOR(i,0,n) FOR(j,0,n) best = min(best, dp[i][j][k]);
	if (best == 1e9) printf("-1\n");
	else printf("%d\n", best);
}
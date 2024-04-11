#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

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

using namespace std;
#define max_n 100005

int dp[1005][105];
int dobre[1005];

int powers[1005];

int main(){
	make3(n,k,mod);
	FOR(i,0,n+1) FOR(j,0,k) dp[i][j] = 0;
	FOR(i,0,n+1) dobre[i] = 0;

	powers[0] = 1%k;
	FOR(i,1,n+1) powers[i] = (10*powers[i-1])%k;

	FOR(j,1,10) 
		if(j%k==0) dobre[1]++;
		else dp[1][j%k]++;

	dp[1][0] = 1;
	
	if(n==1){
		printf("%d\n",dobre[1]%mod);
		return 0;
	}

	FOR(dl,2,n){
		dobre[dl] = (dobre[dl-1]*10LL)%mod;
		FOR(r,0,k){
			FOR(j,0,10){
				if(r==0 && j==0) continue;
				if( (r+powers[dl-1]*j)%k==0) {
					dobre[dl] += dp[dl-1][r];
					dobre[dl] %= mod;
				}
				else{
					dp[dl][(r+powers[dl-1]*j)%k] += dp[dl-1][r];
					dp[dl][(r+powers[dl-1]*j)%k] %= mod;
				}
			}
		}
		dp[dl][0] = 1%mod;
	}
	{
		int dl = n;
		dobre[dl] = (dobre[dl-1]*9LL)%mod;
		FOR(r,0,k){
			FOR(j,1,10){
				if(r==0 && j==0) continue;
				if( (r+powers[dl-1]*j)%k==0) {
					dobre[dl] += dp[dl-1][r];
					dobre[dl] %= mod;
				}
				else{
					dp[dl][(r+powers[dl-1]*j)%k] += dp[dl-1][r];
					dp[dl][(r+powers[dl-1]*j)%k] %= mod;
				}
			}
		}
		dp[dl][0] = 1%mod;
	}

	printf("%d\n",dobre[n]%mod);
}
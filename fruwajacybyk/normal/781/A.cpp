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

#define max_n 200005

int ANS;
int n;
VI g[max_n];
int deg[max_n];
int kol[max_n];

void dfs(int v, int par, int k1, int k2) {
	int mycol = 1;
	FORE(i, g[v]) {
		int w = *i;
		if (w == par) continue;
		while (mycol == k1 || mycol == k2) mycol++;
		kol[w] = mycol;
		dfs(w, v, mycol, k1);
		mycol++;
	}
}

int main() {
	read(n);
	FOR(i,0,n) deg[i] = 0;
	FOR(i,0,n-1) {
		make2(a, b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	int maxdeg =0;
	ANS = maxdeg+1;
	int dla = -1;
	FOR(i,0,n) {
		if (deg[i] > maxdeg) {
			maxdeg = deg[i];
			dla = i;
		}
	}
	kol[dla] = 1;
	dfs(dla, dla, 1, 1);
	printf("%d\n", maxdeg+1);
	FOR(i,0,n) {
		printf("%d ", kol[i]);
	}
	printf("\n");
}
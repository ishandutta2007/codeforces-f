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
#define REP(i,n) FOR(i,0,(n))
 
using namespace std;

const int max_n = 1e6+5;

int nans[max_n];

int main() {
	make2(n, q);
	int even = 0;
	int odd = 0;
	while (q--) {
		make(t);
		if (t==2) {
			if (even%2==0) even--;
			else even++;
			if (odd%2==1) odd--;
			else odd++;
			even = (even + n)%n;
			odd = (odd+n)%n;
		}
		else {
			make(x); 
			even = (even+x+n)%n;
			even = (even+n)%n;
			odd = (odd+x+n)%n;
			odd = (odd + n)% n;
		}
	}
	FOR(i,1,n+1) {
		int ans;
		if (i%2==0) {
			ans = (i+even)%n;
		} else ans = (i+odd)%n;
		if (ans==0) ans = n;
		nans[ans] = i;
	}
	FOR(i,1,n+1) printf("%d ", nans[i]);	
	printf("\n");

	
	
}
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
#define max_n 205




int main(){
	make2(n,k);
	vector<PII> goscie;
	lint ans = (1LL<<55);
	FOR(i,0,n){
		make2(p,e); 
		goscie.pb(mp(-p,e));
	}
	if(k==n+1){
		printf("0\n");
		return 0;
	}
	sort(all(goscie));
	FOR(i,0,n) goscie[i].st = -goscie[i].st;
	FOR(case1,goscie[k-1].st,goscie[k-1].st+3){
		if(case1<=n){
			VI effs;
			VI bliscy;
			int lepsi = 0;
			lint myans = 0;
			FOR(i,0,n){
				if(goscie[i].st>case1){
					lepsi++; effs.pb(goscie[i].nd);
				}
				else if(goscie[i].st<case1-1){
					effs.pb(goscie[i].nd);
				}
				else{
					bliscy.pb(goscie[i].nd);
				}
			}
			int niemusze = max(k-lepsi-1,0);
			sort(all(bliscy));
			int mam = 0;
			FOR(i,0,bliscy.size()){
				if(i+niemusze<bliscy.size()){
					myans += bliscy[i]*1LL;
					mam++;
				}
				else{
					effs.pb(bliscy[i]);
				}
			}
			sort(all(effs));
			FOR(i,0,effs.size()){
				if(mam<case1){
					mam++;
					myans += effs[i]*1LL;
				}
			}
			ans = min(ans,myans);
		}
	}
	if(goscie[k-1].st>n) printf("-1\n");
	else printf("%I64d\n",ans);
}
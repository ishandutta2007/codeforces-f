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

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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
#define jeb() fflush(stdout);

using namespace std;

lint dp[5005][5005];
const lint INF = 1e15;

int main() {
    make3(n, k, x);
    makev(v, n);
    
    FOR(i,0,k) dp[i][1] = v[i];
    FOR(i,k,n) dp[i][1] = -INF;
    
    FOR(j,2,n+1) dp[0][j] = -INF;
    FOR(j,2,x+1) {
        HEAP<pair<lint, int> > kij;
        kij.push(mp(dp[0][j-1],0));
        FOR(i,1,n) {
            while (1) {
                if (kij.empty()) {
                    dp[i][j] = -INF;
                    break;
                }
                pair<lint,int> parka = kij.top();
                lint val = parka.st;
                int kto = parka.nd;
                if (kto < i-k) {
                    kij.pop();
                } else {
                    dp[i][j] = val + v[i]; 
                    break;
                }
            }
            kij.push(mp(dp[i][j-1], i));
        }
    }
    lint ans = -INF;
    FOR(i,0,n) {
        if (n-i>k) continue;   
        ans = max(ans, dp[i][x]);
    }
    if (ans < 0) printf("-1\n");
    else printf("%lld\n", ans);
}
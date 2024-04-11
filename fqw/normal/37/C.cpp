#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int main() {
    int n; scanf("%d", &n);
    VI len(n);
    map<int, VI> ws;
    repn(i, n) {
        scanf("%d", &len[i]);
        ws[len[i]].pb(i);
    }
    VS ans(n);

    string cur;
    const function<void(int)> dfs=[&](int dep) {
        if(ws.count(dep)) {
            int i=ws[dep].back();
            ws[dep].pop_back();
            if(ws[dep].empty()) {
                ws.erase(dep);
            }
            ans[i]=cur;
            return;
        }
        if(ws.lower_bound(dep)==ws.end()) {
            return;
        }
        for(char c='0'; c<='1'; ++c) {
            cur+=c;
            dfs(dep+1);
            cur.pop_back();
        }
    };
    dfs(0);
    if(ws.empty()) {
        printf("YES\n");
        for(const auto& s: ans) {
            printf("%s\n", s.c_str());
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
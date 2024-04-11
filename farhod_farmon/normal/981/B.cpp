#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 250500;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
map < int, int > d;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                d[x] = max(d[x], y);
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                d[x] = max(d[x], y);
        }
        long long ans = 0;
        for(auto p: d){
                ans += p.se;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5005;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
long double a, b, m, mn;

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a >> b;
                if(i == 1 || a / b < mn){
                        mn = a / b;
                }
        }
        cout << fixed << setprecision(9) << mn * m << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

lli ans, i, j, p[200002], x, n;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        p[x] = i;
    }
    p[0] = p[1];
    for( i = 1; i <= n; i++ )ans += abs(p[i - 1] - p[i]);
    cout << ans << endl;
}
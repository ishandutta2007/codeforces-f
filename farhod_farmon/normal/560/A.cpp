#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

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
int a, b, j, i, d[10001], mx = 10000;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b;
        for( j = 1; b * j <= mx; j++ )d[b * j] = 1;
    }
    for( i = 1; i <= 10000; i++ ){
        if( !d[i] ){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
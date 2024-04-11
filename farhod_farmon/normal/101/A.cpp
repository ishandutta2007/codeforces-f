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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int d[200], i, k, cnt;
bool used[200];
string s;

int main()
{
    cin >> s >> k;
    for( i = 0; i < s.size(); i++ ){
        d[s[i]]++;
        if( !used[s[i]] )cnt++;
        used[s[i]] = true;
    }
    for( i = 0; i < s.size(); i++ ){
        char mx = 'a';
        for( char c = 'a'; c <= 'z'; c++ ){
            if( (d[c] < d[mx] || !used[mx]) && used[c] )mx = c;
        }
        if( d[mx] > k || !used[mx] )break;
        k -= d[mx];
        cnt--;
        used[mx] = false;
    }
    cout << cnt << endl;
    for( i = 0; i < s.size(); i++ ){
        if( used[s[i]] )cout << s[i];
    }
}
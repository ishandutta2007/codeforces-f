#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        y = min(y, 2 * x);

        int ans = 0;

        vector <string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '.' && j + 1 < m && a[i][j + 1] == '.') {
                    ans += y;
                    ++j;
                }   
                else if (a[i][j] == '.') {
                    ans += x;
                }
            }   
        }   
        cout << ans << endl;
    }   
}
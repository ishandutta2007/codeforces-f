#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n % 2 == 0) {
        cout << "0\n";
        exit(0);
    }   
    const int INF = 1e9 + 7;
    int mn = INF;
    for (int i = 0; i < n; i += 2)
        mn = min(mn, a[i]);
    int ans = 0;
    int step = n / 2 + 1;
    cout << min((m / step) * k, mn) << endl;
}
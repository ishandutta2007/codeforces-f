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
#define debug(x) std::cout << #x << ": " << x << '\n';
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
        int n;
        cin >> n;
        vector <ii> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].f;
            a[i].s = i;
        }   
        sort(all(a));
        if (a[0].f + a[1].f <= a.back().f) {
            cout << a[0].s + 1 << ' ' << a[1].s + 1 << ' ' << a.back().s+1 << endl;
        }   
        else {
            cout << -1 << endl;
        }   
    }
}
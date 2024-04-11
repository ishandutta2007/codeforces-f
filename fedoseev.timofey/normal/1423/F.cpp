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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, k;
    cin >> n >> k;

    int sum = 0, tot = 0;
    for (int i = 0; i < k; ++i) {
        int pos, cnt;
        cin >> pos >> cnt;
        pos--;

        sum += pos * cnt;
        tot += cnt;
    }   
    
    int want = n * (n - 1) / 2;

    if (tot < n) {
        cout << 1 << endl;
    }   
    else if (tot > n) {
        cout << -1 << endl;
    }   
    else if (sum % n == want % n) {
        cout << 1 << endl;
    }   
    else {
        cout << -1 << endl;
    }   
}
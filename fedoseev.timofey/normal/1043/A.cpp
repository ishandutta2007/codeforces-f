#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
    for (int k = mx; ; ++k) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += a[i];
        for (int i = 0; i < n; ++i) cnt -= (k - a[i]);
        if (cnt < 0) {
            cout << k << '\n';
            return 0;
        }
    }
}
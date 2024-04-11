#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    bool has_one = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        has_one = true;
      }
    }
    if (!has_one) {
      cout << "YES\n";
      continue;
    }
    bool bad = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i] + 1 == a[i + 1]) {
        bad = true;
      }
    }
    cout << (!bad ? "YES" : "NO") << '\n';
  }
}
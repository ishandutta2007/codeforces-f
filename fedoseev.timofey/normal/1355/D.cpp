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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, s;
  cin >> n >> s;
  if (2 * n <= s) {
    cout << "YES\n";
    for (int i = 0; i + 1 < n; ++i) cout << "2 ";
    cout << s - 2 * (n - 1) << '\n';
    cout << "1\n";
  } else {
    cout << "NO\n";
  }
}
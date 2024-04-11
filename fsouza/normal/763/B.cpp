#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    int x1, y1;
    scanf("%d %d %*d %*d", &x1, &y1);
    printf("%d\n", (abs(x1) % 2) * 2 + (abs(y1) % 2) + 1);
  }
  return 0;
}
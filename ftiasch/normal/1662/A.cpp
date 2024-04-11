#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-30989EzAYLZO0THF5.cpp"

#line 4 "/tmp/tmp-30989EzAYLZO0THF5.cpp"

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    std::vector<int> max_beauty(10);
    for (int i = 0; i < n; ++i) {
      int b = read();
      int d = read() - 1;
      max_beauty[d] = std::max(max_beauty[d], b);
    }
    if (std::ranges::find(max_beauty, 0) == max_beauty.end()) {
      std::cout << std::accumulate(ALL(max_beauty), 0) << "\n";
    } else {
      std::cout << "MOREPROBLEMS\n";
    }
  }
}
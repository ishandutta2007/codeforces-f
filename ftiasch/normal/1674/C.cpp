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

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T> std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-266413PNILbh7hliFK.cpp"

#line 4 "/tmp/tmp-266413PNILbh7hliFK.cpp"

Long solve(int a, const std::string &b) {
  if (b == "a") {
    return 1;
  }
  if (b.find("a") != std::string::npos) {
    return -1;
  }
  return 1LL << a;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int a = read<std::string>().size();
    auto b = read<std::string>();
    std::cout << solve(a, b) << "\n";
  }
}
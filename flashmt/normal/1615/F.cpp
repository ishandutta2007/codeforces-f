#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

template<int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  using ll = long long;

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

public:

  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template<typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template<int M> string to_string(modnum<M> x) {
  return to_string(int(x));
}

using num = modnum<int(1e9) + 7>;

const int N = 2000;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<vector<num>> f(n + 1, vector<num>(N * 2 + 1));
    vector<vector<num>> ways(n + 1, vector<num>(N * 2 + 1));
    f[0][N] = 0;
    ways[0][N] = 1;
    for (int i = 0; i < n; i++)
      for (int d = -i; d <= i; d++)
        for (int x : {0, 1})
          for (int y : {0, 1})
          {
            if (s[i] != '?' && s[i] - '0' != x)
              continue;
            if (t[i] != '?' && t[i] - '0' != y)
              continue;
            if (x == y)
            {
              f[i + 1][d + N] += f[i][d + N];
              ways[i + 1][d + N] += ways[i][d + N];
            }
            else
            {
              int dd = d;
              if (x)
                dd += (i % 2 ? 1 : -1);
              if (y)
                dd -= (i % 2 ? 1 : -1);

              f[i + 1][dd + N] += f[i][d + N] + (abs(dd) > abs(d) ? -i : i) * ways[i][d + N];
              ways[i + 1][dd + N] += ways[i][d + N];
            }
          }

    cout << f[n][N] << endl;
  }
}
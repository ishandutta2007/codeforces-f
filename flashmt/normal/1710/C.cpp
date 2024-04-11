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

using num = modnum<998244353>;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin >> n;

  // compute the map from a value to a bit pattern
  vector<int> m(8, -1);
  for (int v = 0; v < 8; v++)
  {
    vector<int> b(3);
    for (int i = 0; i < 3; i++)
      b[i] = v >> i & 1;
    vector<int> edges = {b[1] ^ b[2], b[0] ^ b[2], b[0] ^ b[1]};
    if (*max_element(begin(edges), end(edges)))
      for (int i = 0; i < 3; i++)
        if (!edges[i])
          m[v] = i;
  }

  // i is the mask of whether a/b/c is less than the current prefix
  // j is the mask of whether the bit pattern 011/101/110 has appeared in the edges
  vector<vector<num>> f(8, vector<num>(8));
  f[0][0] = 1;
  for (char c : n)
  {
    vector<vector<num>> newF(8, vector<num>(8));
    int bitN = c - '0';
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        for (int v = 0; v < 8; v++) // loop through the current bits of a/b/c
        {
          int ii = 0, isBad = 0;
          for (int k = 0; k < 3; k++)
          {
            int isSmall = i >> k & 1;
            int bit = v >> k & 1;
            if (!isSmall && bit > bitN)
            {
              isBad = 1;
              break;
            }
            int newIsSmall = isSmall | (bit < bitN);
            ii |= newIsSmall << k;
          }

          if (isBad)
            continue;

          int jj = j;
          if (m[v] >= 0)
            jj |= 1 << m[v];

          newF[ii][jj] += f[i][j];
        }

    swap(f, newF);
  }

  num ans;
  for (int i = 0; i < 8; i++)
    ans += f[i][7];

  cout << ans << endl;
}
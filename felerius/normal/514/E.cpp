// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (62) Darth Vader and Tree (Difficulty: 6) (http://codeforces.com/problemset/problem/514/E)


// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

namespace snippets_modular {
    template <class C>
    struct Modular {
        using I = decltype(C::m());
        I val = 0;

    private:
#ifdef __SIZEOF_INT128__
        using Mul = conditional_t<sizeof(I) >= 5, unsigned __int128, uint64_t>;
#else
        static_assert(sizeof(I) <= 4, "cannot multiply larger than 64-bit");
        using Mul = uint64_t;
#endif

        struct Unchecked {};
        constexpr Modular(I _val, Unchecked) : val(_val) {}
        static constexpr array<I, 3> ext_gcd(I a, I b) {
            if (!a) return {b,0,1};
            auto ar = ext_gcd(b % a, a);
            return {ar[0], ar[2] - (b / a) * ar[1], ar[1]};
        }
    public:

        constexpr Modular() = default;
        template <class T>
        constexpr Modular(T _val) { _val %= C::m(); if (_val < 0) _val += C::m(); val = static_cast<I>(_val); }

        template <class T>
        constexpr explicit operator T() const { return static_cast<T>(val); }

#define DEFINE_CMP(op) constexpr bool operator op (Modular r) const { return val op r.val; }
        DEFINE_CMP(==) DEFINE_CMP(!=) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

        constexpr Modular& operator+=(Modular r) { if ((val += r.val) >= C::m()) val -= C::m(); return *this; }
        constexpr Modular& operator-=(Modular r) { if (r.val > val) val += C::m(); val -= r.val; return *this; }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator+=(T r) { return *this += Modular(r); }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator-=(T r) { return *this -= Modular(r); }
        constexpr Modular operator+(Modular r) const { return Modular(*this) += r; }
        constexpr Modular operator-(Modular r) const { return Modular(*this) -= r; }

        constexpr Modular operator*(Modular r) const { return Modular(static_cast<Mul>(val) * static_cast<Mul>(r.val)); }
        constexpr Modular& operator*=(Modular r) { return *this = *this * r; }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator*=(T r) { return *this *= Modular(r); }

        template <class T> constexpr Modular pow(T e) const {
            Modular a = 1, b = *this;
            for (; e > 0; b *= b, e /= 2)
                if (e % 2) a *= b;
            return a;
        }
        constexpr Modular inv() const { I x = ext_gcd(val, C::m())[1]; return Modular(x < 0 ? x + C::m() : x, Unchecked{}); }

        constexpr Modular& operator/=(Modular r) { return *this *= r.inv(); }
        template <class T> constexpr enable_if_t<is_integral<T>::value, Modular&> operator/=(T r) { return *this /= Modular(r); }
        constexpr Modular operator/(Modular r) const { return Modular(*this) /= r; }

        constexpr Modular operator+() const { return *this; }
        constexpr Modular operator-() const { return Modular(val ? -val + C::m() : val, Unchecked{}); }
        constexpr Modular& operator++() { return *this += 1; }
        constexpr Modular& operator--() { return *this -= 1; }
        constexpr Modular operator++(int) { auto r = *this; *this += 1; return r; }
        constexpr Modular operator--(int) { auto r = *this; *this -= 1; return r; }
    };

#define DEFINE_OPS(op) \
        template <class C, class T, class = enable_if_t<is_integral<T>::value>> \
        constexpr auto operator op (Modular<C> l, T r) { return Modular<C>(l) op Modular<C>(r); } \
        template <class C, class T, class = enable_if_t<is_integral<T>::value>> \
        constexpr auto operator op (T l, Modular<C> r) { return Modular<C>(l) op Modular<C>(r); }
    DEFINE_OPS(==) DEFINE_OPS(!=) DEFINE_OPS(<) DEFINE_OPS(<=) DEFINE_OPS(>) DEFINE_OPS(>=)
    DEFINE_OPS(+) DEFINE_OPS(-) DEFINE_OPS(*) DEFINE_OPS(/)
#undef DEFINE_OPS

    template<class C> std::ostream& operator<<(std::ostream& out, Modular<C> m) { return out << m.val; }
    template <class C> std::istream& operator>>(std::istream& in, Modular<C>& m) {
        // Avoid reading character types
        using I = typename Modular<C>::I;
        using T = conditional_t<is_same<I, signed char>::value || is_same<I, unsigned char>::value || is_same<I, char>::value, int, I>;

        T val{};
        in >> val;
        m = Modular<C>(val);
        return in;
    }
    template<class C> string to_string(Modular<C> m) { return ::to_string(m.val); }

    template <class I, I M> struct ConstMod { static constexpr I m() { return M; } };
    using MI = Modular<ConstMod<int, (int)1e9 + 7>>;
    using vMI = vector<MI>;
}
using namespace snippets_modular;
namespace std {
    template <class C> struct hash<Modular<C>> {
        size_t operator()(Modular<C> m) const { return hash<typename Modular<C>::I>()(m.val); }
    };
}

namespace snippets_matrix {
    template <class C> struct Matrix : private C {
        using typename C::T; using C::N; using C::ZERO; using C::ONE; using C::addmul;

        using Vec = array<T, N>;
        static Vec vec() { Vec v; v.fill(ZERO); return v; }

        array<T, N * N> d;

        Matrix(bool identity = false) {
            d.fill(ZERO);
            if (identity)
                rep(i, N)
                    (*this)(i, i) = ONE;
        }
        T& operator()(int i, int j) { return d[i * N + j]; }
        const T& operator()(int i, int j) const { return d[i * N + j]; }

        Matrix operator*(const Matrix& o) const {
            Matrix res;
            rep(i, N) rep(j, N) rep(k, N)
                addmul(res(i, j), (*this)(i, k), o(k, j));
            return res;
        }
        Matrix& operator*=(const Matrix& o) {
            *this = *this * o;
            return *this;
        }

        Vec operator*(const Vec& v) const {
            auto res = vec();
            rep(i, N) rep(j, N)
                addmul(res[i], (*this)(i, j), v[j]);
            return res;
        }

        Matrix pow(ll e) const {
            Matrix res(true), exp = *this;
            for (; e > 0; exp *= exp, e /= 2)
                if (e % 2) res *= exp;
            return res;
        }
    };

    struct MatrixConf {
        using T = MI;
        static constexpr int N = 101;

        static constexpr T ZERO = 0;
        static constexpr T ONE = 1;
        static void addmul(T& l, const T& a, const T& b) { l += a * b; }
    };

    using Mat = Matrix<MatrixConf>;
    using Vec = Mat::Vec;
} using namespace snippets_matrix;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Mat m;
    rep(i, 99)
        m(i + 1, i) = 1;
    m(100, 0) = m(100, 100) = 1;

    int n, x; cin >> n >> x;
    rep(i, n) {
        int di; cin >> di;
        m(0, di - 1)++;
    }

    auto v = Mat::vec();
    v[0] = 1;
    cout << (m.pow(x + 1) * v).back() << '\n';

    return 0;
}
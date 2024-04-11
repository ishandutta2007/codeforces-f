
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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
// endregion

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
} using namespace snippets_modular;
namespace std {
    template <class C> struct hash<Modular<C>> {
        size_t operator()(Modular<C> m) const { return hash<typename Modular<C>::I>()(m.val); }
    };
}

namespace snippets_hashing {
    namespace {
        constexpr static array<int, 20> PRIMES = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403};
        static array<int, PRIMES.size()> idx{};
        static bool idx_init = false;

        template <template<size_t...> class T, size_t... Idx> T<Idx...> with_idx_seq(index_sequence<Idx...>);

        template <size_t I> struct HashMod { static int m() { return PRIMES[idx[I]]; } };

        // c_0 * a^0 + c_1 * a^1 + c_2 * a^2 + ...
        template <size_t... Idx> struct IdxHasher {
            static_assert(sizeof...(Idx) <= PRIMES.size(), "Not enough hash modulo primes");
            using Result = tuple<Modular<HashMod<Idx>>...>;

            Result h{}, ae{};
            int a;

            explicit IdxHasher(int a) : a(a) {
                if (!idx_init)
                    iota(all(idx), 0), shuffle(all(idx), rng), idx_init = true;
                ((get<Idx>(ae) = 1), ...);
            }

            template <class T> void feed(T val) {
                ((get<Idx>(h) += get<Idx>(ae) * val), ...);
                ((get<Idx>(ae) *= a), ...);
            }
        };

        template <size_t... Idx> struct IdxRangeHash {
            using Result = typename IdxHasher<Idx...>::Result;
            vector<Result> pref, ae;

            template <class It, class F> IdxRangeHash(int a, It it, It it_end, F f) {
                IdxHasher<Idx...> h(a);
                while (it != it_end)
                    ae.push_back(h.ae), h.feed(f(*it++)), pref.push_back(h.h);
            }
            template <class It> IdxRangeHash(int a, It it, It it_end) : IdxRangeHash(a, it, it_end, [](auto v) { return v; }) {}
            IdxRangeHash(int a, string_view s) : IdxRangeHash(a, all(s), [](char c) { return c - 'a' + 1; }) {}

            Result query(int l, int r) {  // [l, r)
                if (r <= l) return {};
                auto res = pref[r - 1];
                if (l)
                    ((get<Idx>(res) -= get<Idx>(pref[l - 1])), ...);
                ((get<Idx>(res) *= get<Idx>(ae[sz(ae) - r])), ...);
                return res;
            }
        };
    }

    template <int C> using Hasher_ = decltype(with_idx_seq<IdxHasher>(make_index_sequence<C>{}));
    template <int C> using RangeHash_ = decltype(with_idx_seq<IdxRangeHash>(make_index_sequence<C>{}));

    static constexpr int HASH_COUNT = 2;
    using Hasher = Hasher_<HASH_COUNT>;
    using RangeHash = RangeHash_<HASH_COUNT>;
} using namespace snippets_hashing;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    using H = Hasher::Result;
    set<pair<int, H>> known;
    string s;
    rep(i, n) {
        cin >> s;
        RangeHash h(5, s);
        rep(j, sz(s)) {
            H pref = j ? h.pref[j - 1] : H{};
            H suff = h.query(j + 1, sz(s));
            rep(k, 3) {
                if (k == s[j] - 'a')
                    continue;
                H ha = pref;
                get<0>(ha) += (k + 1) * get<0>(h.ae[j]) + get<0>(suff);
                get<1>(ha) += (k + 1) * get<1>(h.ae[j]) + get<1>(suff);
                known.emplace(sz(s), ha);
            }
        }
    }

    rep(i, m) {
        cin >> s;
        RangeHash h(5, s);
        cout << (known.count(pair(sz(s), h.query(0, sz(s)))) ? "YES\n" : "NO\n");
    }

    return 0;
}
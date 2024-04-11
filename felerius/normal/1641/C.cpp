// Anonymity Is Important (https://codeforces.com/contest/1641/problem/C)
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>
#if __has_include("dbg.h")
#  include "dbg.h"
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }



#if __cpp_lib_remove_cvref < 201711L
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
#endif
#if __cplusplus < 202002L
struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using iter_value_t = typename iterator_traits<remove_cvref_t<T>>::value_type;
#endif

namespace cp_lib_type_meta {
    template <class T, class = void> constexpr bool is_tuple_like = false;
    template <class T> constexpr bool is_tuple_like<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }
template <class T> constexpr bool IsModInt = is_base_of_v<cp_lib_modint::ModIntTag, T>;
#include <unistd.h>

namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    constexpr array<array<char, 4>, 10'000> DIGITS = []{
        array<array<char, 4>, 10'000> digits{};
        for (int i = 3, d = 1; i >= 0; --i, d *= 10)
            rep(j, 10'000)
                digits[j][i] = char('0' + j / d % 10);
        return digits;
    }();
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> constexpr bool is_std_array = false;
    template <class T, size_t I> constexpr bool is_std_array<array<T, I>> = true;

    void flush() {
        for (auto* p = begin(obuf); p != optr; p += write(STDOUT_FILENO, p, optr - p));
        optr = begin(obuf);
    }
    int _flush_atexit = []{ atexit(flush); return 0; }();

    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - 1 - iend);
        *iend = '\0';
    }

    template <class T, class T2 = remove_cvref_t<T>>
    void print(T&& val) {
        if (end(obuf) - optr < 64)
            flush();

        if constexpr (is_same_v<T2, char>)
            *optr++ = val;
        else if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
            return print(int(val));
        else if constexpr (is_integral_v<T2> && is_signed_v<T2>) {
            if (val < 0)
                *optr++ = '-';
            using U = make_unsigned_t<T2>;
            return print(U(val < 0 ? -U(val) : U(val)));
        } else if constexpr (is_integral_v<T2> && is_unsigned_v<T2>) {
            T2 val2 = val;
            array<char, 64> tmp;
            char* tptr = end(tmp);
            while (val2 >= 10'000)
                tptr -= 4, memcpy(tptr, &DIGITS[val2 % 10'000][0], 4), val2 /= T2(10'000);
            int d = (val2 >= 100 ? (val2 >= 1000 ? 4 : 3) : (val2 >= 10 ? 2 : 1));
            memcpy(optr, &DIGITS[val2][4 - d], d);
            memcpy(optr + d, tptr, end(tmp) - tptr);
            optr += d + int(end(tmp) - tptr);
        } else if constexpr (is_floating_point_v<T2>)
            optr += sprintf(optr, "%.30Lf", (long double)val);
        else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else {
                flush();
                for (auto *p = data(sv), *pe = p + sz(sv); p != pe; p += write(STDOUT_FILENO, p, pe - p));
            }
        } else if constexpr (IsModInt<T2>)
            return print(typename T2::Int(val));
        else if constexpr (cp_lib_type_meta::is_tuple_like<T2> && !is_std_array<T2>)
            return apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
        else {
            trav(item, val)
                print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        auto skip_ws = [] {
            do {
                for (; iptr != iend && *iptr <= ' '; ++iptr);
                if (iend - iptr < 64)
                    refill();
            } while (*iptr <= ' ');
        };
        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            skip_ws(), val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (IsModInt<T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            skip_ws();
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            skip_ws(), val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
            skip_ws();
            val.clear();
            do {
                auto* after = find_if(iptr, iend, [](char c) { return c <= ' '; });
                val.append(iptr, after);
                if ((iptr = after) != iend)
                    break;
                refill();
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::is_tuple_like<T> && !is_std_array<T>)
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val)
                read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args))
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        print('\n'), --cp_lib_io::optr;
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }


template <class T> constexpr inline bool is_pow2(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int floor_log2(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int ceil_log2(T n) { return n ? floor_log2(n) + !is_pow2(n) : 0; }

template <class T, class Add = plus<>, class Sub = minus<>>
class FenwickTree {
    T identity;
    Add add;
    Sub sub;
    vector<T> d;

 public:
    FenwickTree(int n, T identity_, Add add_ = Add(), Sub sub_ = Sub())
        : identity(move(identity_)), add(move(add_)), sub(move(sub_)), d(n, identity) {}

    FenwickTree(vector<T> a, T identity_ = T(), Add add_ = Add(), Sub sub_ = Sub())
        : identity(move(identity_)), add(move(add_)), sub(move(sub_)), d(move(a)) {
        partial_sum(all(d), begin(d), add);
        repr(i, sz(d), 1)
            if (i & (i - 1))
                d[i - 1] = sub(d[i - 1], d[(i & (i - 1)) - 1]);
    }

    template <class It, enable_if_t<!is_same_v<It, int>, int> = 0>
    FenwickTree(It it, It it_end, T identity_ = T(), Add add_ = Add(), Sub sub_ = Sub())
        : FenwickTree(vector(it, it_end), move(identity_), move(add_), move(sub_)) {}

    T query(int r) const {
        T res = identity;
        for (; r; r &= r - 1)
            res = add(res, d[r - 1]);
        return res;
    }
    T query(int l, int r) const { return sub(query(r), query(l)); }

    template <class F>
    int lower_bound(F&& f) const {
        int i = 0, j = (1 << floor_log2(sz(d)));
        for (T pref = identity, pref2; j; j >>= 1)
            if (i + j <= sz(d) && !f(pref2 = add(pref, d[i + j - 1])))
                pref = move(pref2), i += j;
        return i;
    }

    void update(int i, T v) {
        for (; i < sz(d); i |= i + 1)
            d[i] = add(d[i], v);
    }
};

template <class It>
FenwickTree(It, It) -> FenwickTree<iter_value_t<It>, plus<>, minus<>>;



namespace cp_lib_segtree {
    template <class Derived, class Conf>
    struct SegmentTreeImpl {
     private:
        using T = typename Conf::T;

        void push(int i) { ((Derived*)this)->push(i); }

     protected:
        int n, k;
        vector<T> d;

        void push_path(int i) { repr(s, __builtin_ctz(k), 1) push(i >> s); }
        void recalc(int i) { d[i] = Conf::combine(d[2*i], d[2*i+1]); }

     public:
        explicit SegmentTreeImpl(int n_) : n(n_), k(1 << ceil_log2(n)), d(2 * k, Conf::UNIT) {}

        template <class It>
        SegmentTreeImpl(It it, It end) : n(int(end - it)), k(1 << ceil_log2(n)), d(2 * k, Conf::UNIT) {
            copy(it, end, begin(d) + k);
            build();
        }

        T& root() { return d[1]; }
        T& leaf(int i) { return d[k + i]; }

        // Width of the range represented by a node
        int width(int i) { return min(k >> floor_log2(i), n); }

        // Build the entire tree from the leaves up
        void build() { repr(i, k - 1, 1) recalc(i); }

        // Aggregate for [l, r)
        T query(int l, int r) {
            push_path(l + k);
            push_path(r + k - 1);
            T rl = Conf::UNIT, rr = Conf::UNIT;
            for (l += k, r += k; l < r; l /= 2, r /= 2) {
                if (l % 2) rl = Conf::combine(rl, d[l++]);
                if (r % 2) rr = Conf::combine(d[--r], rr);
            }
            return Conf::combine(rl, rr);
        }

        // Update single leaf value
        template <class F>
        void point_update(int i, F f) {
            push_path(i += k);
            f(d[i]);
            while (i /= 2) recalc(i);
        }

        // First position s.t. prefix matches pred
        template <class Pred>
        int lower_bound(Pred pred) {
            if (!pred(d[1])) return n;
            T pref = Conf::UNIT;
            int i = 1;
            while (i < k)
                if (push(i); !pred(Conf::combine(pref, d[i *= 2])))
                    pref = Conf::combine(pref, d[i++]);
            return i - k;
        }
    };
}

template <class Conf>
struct SegmentTree : cp_lib_segtree::SegmentTreeImpl<SegmentTree<Conf>, Conf> {
 private:
    using Base = cp_lib_segtree::SegmentTreeImpl<SegmentTree<Conf>, Conf>;
    friend Base;

    void push(int) {}

 public:
    using Base::Base;
};

struct SegTreeConf {
    using T = array<array<int, 2>, 2>;
    static constexpr T UNIT = {array{-INF, -1}, array{-INF, -1}};
    static T combine(const T& a, const T& b) {
        array full = {a[0], a[1], b[0], b[1]};
        sort(all(full));
        return {full[3], full[2]};
    }
};
using SegTree = SegmentTree<SegTreeConf>;

int main() {
    int n, q; read(n, q);
    vector<array<int, 4>> evt(q);
    for (auto& [ty, a, b, c] : evt) {
        read(ty);
        if (ty)
            read(a), --a;
        else
            read(a, b, c), --a;
    }

    FenwickTree ft(vector(n, 1));
    vector known(n, pair(0, INF));
    rep(i, q) {
        auto& [ty, l, r, x] = evt[i];
        if (ty || x)
            continue;
        int bef = ft.query(l), j;
        while ((j = ft.lower_bound([&](int pref) { return pref > bef; })) < r)
            known[j] = {0, i}, ft.update(j, -1);
    }

    SegTree st(n);
    rep(i, n)
        st.leaf(i)[0] = {known[i].second, i};
    st.build();
    rep(i, q) {
        auto& [ty, l, r, x] = evt[i];
        if (ty || !x)
            continue;
        auto [last, last2] = st.query(l, r);
        if (last[0] == INF && last2[0] < INF)
            known[last[1]] = {1, min(known[last[1]].second, max(i, last2[0]))};
    }

    rep(i, q) {
        auto& [ty, l, r, x] = evt[i];
        if (!ty)
            continue;
        auto [kty, kt] = known[l];
        println(i < kt ? "N/A" : (kty ? "YES" : "NO"));
    }
}
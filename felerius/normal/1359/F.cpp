// Contest: Educational Codeforces Round 88 (Rated for Div. 2) (https://codeforces.com/contest/1359)
// Problem: F: RC Kaboom Show (https://codeforces.com/contest/1359/problem/F)


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

// region geometry
template <class T>
struct Point2D {
    T x = 0, y = 0;
    constexpr Point2D() = default;
    constexpr Point2D(T x, T y) : x(x), y(y) {}

#define DEFINE_CMP(op) constexpr bool operator op(const Point2D& o) const { return tie(x, y) op tie(o.x, o.y); }
    DEFINE_CMP(==) DEFINE_CMP(!=) DEFINE_CMP(<) DEFINE_CMP(<=) DEFINE_CMP(>) DEFINE_CMP(>=)
#undef DEFINE_CMP

    constexpr Point2D& operator+=(const Point2D& r) { x += r.x; y += r.y; return *this; }
    constexpr Point2D& operator-=(const Point2D& r) { x -= r.x; y -= r.y; return *this; }
    constexpr Point2D& operator*=(const T& f) { x *= f; y *= f; return *this; }
    constexpr Point2D& operator/=(const T& f) { x /= f; y /= f; return *this; }

    constexpr Point2D operator+(const Point2D& r) const { return Point2D(*this) += r; }
    constexpr Point2D operator-(const Point2D& r) const { return Point2D(*this) -= r; }
    constexpr Point2D operator*(const T& f) const { return Point2D(*this) *= f; }
    constexpr Point2D operator/(const T& f) const { return Point2D(*this) /= f; }

#define REQUIRE_FLOAT template <class U = T> constexpr enable_if_t<is_floating_point<U>::value, T>
    constexpr T dot(const Point2D& o) const { return x * o.x + y * o.y; }
    constexpr T norm() const { return dot(*this); }
    REQUIRE_FLOAT len() const { return sqrt(norm()); }
    // Project onto another line (result is distance across onto vector)
    REQUIRE_FLOAT proj(const Point2D& onto) const { return dot(onto) / onto.len(); }
    REQUIRE_FLOAT angle(const Point2D& o) const { return acos(dot(o) / len() / o.len()); }
#undef REQUIRE_FLOAT

    // |a  b| is area of parallelogram spanned up by a and b
    // a  b = |a| * |b| * sin(angle)
    // Thus, rotating from a to b takes us clockwise, if a  b is negative, or counterclockwise,
    // if a  b is positive. If a  b = 0, the vectors are collinear.
    constexpr T cross(const Point2D& o) const { return x * o.y - y * o.x; }
};
template <class T> constexpr Point2D<T> operator*(const T& f, const Point2D<T>& p) { return p * f; }

using Point = Point2D<ld>;
constexpr ld PI = 3.141592653589793238462643383279502884L;
// endregion

struct Event {
    Point p;
    int idx;
    bool start;

    bool operator<(const Event& e) const {
        return tuple(p.x, p.y, idx, !start) < tuple(e.p.x, e.p.y, e.idx, e.start);
    }
};

Point eval(pair<Point, Point>& l, ld x) {
    auto& [start, dir] = l;
    ld f = (x - start.x) / dir.x;
    return start + f * dir;
}

constexpr ld EPS = 0.000000001;

int sgn(ld x) { return x >= 0 ? abs(x) < EPS ? 1 : 0 : -1; }

bool inter1(ld a, ld b, ld c, ld d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool inter(pair<Point, Point>& l1, pair<Point, Point>& l2) {
    auto& [a, b] = l1;
    auto& [c, d] = l2;
    if ((a - c).cross(d - c) < EPS && (b - c).cross(d - c) < EPS)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn((b - a).cross(c - a)) != sgn((b - a).cross(d - a)) && sgn((d - c).cross(a - c)) != sgn((d - c).cross(b - c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<Point, Point>> li(n);
    rep(i, n) {
        int x, y, dx, dy, s; cin >> x >> y >> dx >> dy >> s;
        li[i].first = Point(x, y);
        li[i].second = Point(dx, dy);
        li[i].second /= li[i].second.len();
        li[i].second *= s;
    }

    ld init_r = 100000000000.0;
    ld l = 0.0, r = init_r;
    while (r - l > 0.000000001) {
        ld m = (r + l) / 2;
        vector<Event> evt(2 * n);
        vector<pair<Point, Point>> seg(n);
        rep(i, n) {
            auto [start, dir] = li[i];
            auto end = start + m * dir;
            if (pair(end.x, end.y) < pair(start.x, start.y))
                swap(start, end);
            seg[i] = {start, end};
            evt[2 * i] = Event{start, i, true};
            evt[2 * i + 1] = Event{end, i, false};
        }
        sort(all(evt));

        ld cur_x = -init_r;
        auto comparator = [&](int i, int j) {
            auto p1 = eval(li[i], cur_x);
            auto p2 = eval(li[j], cur_x);
            return pair(p1.y, i) < pair(p2.y, j);
        };
        set<int, decltype(comparator)> active(comparator);
        bool found = false;

        for (auto& e : evt) {
            cur_x = e.p.x;
            if (e.start) {
                auto it = active.emplace(e.idx).first;
                if (it != begin(active) && inter(seg[*prev(it)], seg[e.idx])) {
                    found = true;
                    break;
                }
                if (next(it) != end(active) && inter(seg[e.idx], seg[*next(it)])) {
                    found = true;
                    break;
                }
            } else {
                auto it = active.find(e.idx);
                if (it != begin(active) && next(it) != end(active) && inter(seg[*prev(it)], seg[*next(it)])) {
                    found = true;
                    break;
                }
                active.erase(it);
            }
        }

        if (found)
            r = m;
        else
            l = m;
    }

    cout.precision(20);
    if (abs(r - init_r) <= EPS)
        cout << "No show :(\n";
    else
        cout << r << '\n';

    return 0;
}
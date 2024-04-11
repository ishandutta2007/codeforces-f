#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

int n;
const int L = 30;

bool can_make(vi a, int x) {
    FOR (i, L) {
        if (Bit(x, i)) {
            if (!a[i]) {
                return 0;
            }
            x ^= a[i];
        }
    }
    assert(x == 0);
    return 1;
}

pair <vi, V<ii> > get(vi &a) {
    vi ans(L, -1);
    V <ii> op;
    FOR (i, n) {
        FOR (bit, L) {
            if (Bit(a[i], bit)) {
                if (ans[bit] == -1) {
                    ans[bit] = i;
                    break;
                }
                else {
                    op.app(mp(i, ans[bit]));
                    a[i] ^= a[ans[bit]];
                }
            }
        }
    }
    return mp(ans, op);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    vi a(n), b(n);
    cin >> a >> b;

    vi who_a, who_b;
    V <ii> l, r;

    tie(who_a, l) = get(a);
    tie(who_b, r) = get(b);

    vi A_basis(L);
    FOR (i, L) {
        if (who_a[i] != -1) {
            A_basis[i] = a[who_a[i]];
        }
    }

    //debug(A_basis);

    each (e, b) {
        if (!can_make(A_basis, e)) {
            cout << -1 << endl;
            exit(0);
        }
    }

    auto get_bit = [&] (int pos) {
        FOR (i, L) {
            if (who_a[i] == pos) {
                return i;
            }
        }
        return -1ll;
    };  

    V <ii> ans = l;
    auto make_swap = [&] (int i, int j) {
        swap(a[i], a[j]);
        ans.app(mp(i, j));
        ans.app(mp(j, i));
        ans.app(mp(i, j));
    };

    vi need(n);
    FOR (bit, L) {
        //debug(bit);
        if (who_b[bit] != -1) {
            assert(who_a[bit] != -1);

            int pos = who_b[bit];
            need[pos] = 1;

            //debug(pos);

            if (get_bit(pos) == bit) {
                //debug("a");
            }
            else if (get_bit(pos) == -1) {
                //debug("b");
                make_swap(pos, who_a[bit]);
                who_a[bit] = pos;
            }
            else {
                //debug("c");
                //debug(mp(pos, who_a[bit]));
                make_swap(pos, who_a[bit]);
                swap(who_a[get_bit(pos)], who_a[bit]);
            }
            
            //debug(a);
            //debug(who_a);

            int want = b[pos]^a[pos];
            for (int i = bit + 1; i < L; ++i) {
                if (Bit(want, i)) {
                    assert(who_a[i]!=-1);
                    want ^= a[who_a[i]];
                    ans.app(mp(pos, who_a[i]));
                }
            }           
            assert(want == 0);
        }
    }

    FOR (i, n) {
        if (!need[i]) {
            ans.app(mp(i, i));
        }
    }

    reverse(all(r));
    each (e, r) {
        ans.app(e);
    }

    cout << ans.size() << endl;
    each (e, ans) {
        cout << e.x + 1 << ' ' << e.y + 1 << endl;
    }
}
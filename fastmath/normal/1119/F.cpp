#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

mt19937 rnd(2007);
struct DD {
    //check overflow
    struct Node {
        int cnt, x, y, sum;
        Node *l, *r;
        Node (int x_) {
            x = sum = x_;
            cnt = 1;
            y = rnd();
            l = r = NULL;
        }   
    } *root;  
    void print_tree(Node *t) {
        if (!t)
            return;

        cout << t->x << ", ";
        if (t->l)
            cout << "l : " << t->l->x << ", ";
        else
            cout << "l : NULL, ";
        if (t->r)
            cout << "r : " << t->r->x;
        else
            cout << "r : NULL";
        cout << '\n';

        print_tree(t->l);
        print_tree(t->r);
    }   
    void print_list(Node *t) {
        if (!t)
            return;
        print_list(t->l);
        cout << t->x << ' ';
        print_list(t->r);
    }   
    int sum(Node *t) {
        if (!t)
            return 0;
        else
            return t->sum;
    }   
    int cnt(Node *t) {
        if (!t)
            return 0;
        else
            return t->cnt;
    }   
    void relax(Node *t) {
        t->sum = sum(t->l) + sum(t->r) + t->x;
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
    }   
    Node *merge(Node *l, Node *r) {
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->y < r->y) {
            l->r = merge(l->r, r);
            relax(l);
            return l;
        }   
        else {
            r->l = merge(l, r->l);
            relax(r);
            return r;
        }       
    }   
    pair <Node*, Node*> split(Node *t, int x) {
        if (!t)
            return {NULL, NULL};
        if (t->x < x) {
            auto tmp = split(t->r, x);
            t->r = tmp.f;
            relax(t);
            return mp(t, tmp.s);
        }   
        else {
            auto tmp = split(t->l, x);
            t->l = tmp.s;
            relax(t);
            return mp(tmp.f, t);
        }   
    }   
    pair <Node*, Node*> splitcnt(Node *t, int k) {
        if (!t)
            return {NULL, NULL};
        if (k <= cnt(t->l)) {
            auto tmp = splitcnt(t->l, k);
            t->l = tmp.s;
            relax(t);
            return mp(tmp.f, t);
        }   
        else {
            auto tmp = splitcnt(t->r, k - cnt(t->l) - 1);
            t->r = tmp.f;
            relax(t);
            return mp(t, tmp.s);
        }   
    }   
    void init() {
        root = NULL;
    }
    void add(int x) {
        auto t = split(root, x);
        root = merge(merge(t.f, new Node(x)), t.s);        
    }   
    void del(int x) {
        auto t1 = split(root, x);
        auto t2 = split(t1.s, x + 1);
        root = merge(merge(t1.f, merge(t2.f->l, t2.f->r)), t2.s);
    }   
    int sum_less(int x) {
        auto t = split(root, x);
        int ans = sum(t.f);
        root = merge(t.f, t.s);
        return ans;
    }   
    int sum_pref(int k) {
        auto t = splitcnt(root, k);
        int ans = sum(t.f);
        root = merge(t.f, t.s);
        return ans;
    }   
    int cnt() {
        return cnt(root);
    }   
    void print_tree() {
        print_tree(root);
        cout << '\n';
    }   
    void print_list() {
        print_list(root);
        cout << '\n';
    }   
};  

const int N = 3e5, INF = 1e18;
vector <ii> g[N], cur[N];
int par[N], up[N];
DD a[N];
void dfs(int u, int p) {
    par[u] = p;
    for (auto e : g[u])
        if (e.f != p) {
            up[e.f] = e.s;
            a[u].add(e.s);
            dfs(e.f, u);
        }
}   
vector <int> v[N];
bool used[N];

int dp[N][2];
//0 - delete up, 1 - not delete
void solve(int u, int x) {
    vector <int> c;
    int sum1 = 0;
    for (auto e : cur[u]) {
        solve(e.f, x);
        c.app(dp[e.f][0] + e.s - dp[e.f][1]);
        sum1 += dp[e.f][1];
    }
    int w = (int)g[u].size() - x - 1;
    sort(all(c));
    int sum = 0;
    dp[u][0] = dp[u][1] = INF;
    for (int i = 0; i <= c.size(); ++i) {
        for (int j = 0; j < 2; ++j)
            if (w - i + j <= a[u].cnt()) {
                dp[u][j] = min(dp[u][j], sum1 + sum + a[u].sum_pref(max(0ll, w - i + j)));
            }
        if (i < c.size())
            sum += c[i];
    }   
}   

int print[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i)
        a[i].init();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].app(mp(v, c));
        g[v].app(mp(u, c));
    }   
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        v[g[i].size()].app(i);
    vector <int> in;
    for (int x = n - 1; x >= 0; --x) {
        for (int u : v[x + 1]) {
            if (par[u])
                a[par[u]].del(up[u]);
            in.app(u);
            used[u] = 1;
        }
        for (int u : in)
            cur[u].clear();
        for (int u : in) 
            if (used[par[u]]) {                
                cur[par[u]].app(mp(u, up[u]));
            }
        for (int u : in)
            if (!used[par[u]]) {
                solve(u, x);
                int add = 0;
                if (u == 1)
                    add = dp[u][1];
                else
                    add = min(dp[u][1], dp[u][0] + up[u]);
                print[x] += add;
            }
    }   
    for (int i = 0; i < n; ++i)
        cout << print[i] << ' ';
    cout << '\n';
}
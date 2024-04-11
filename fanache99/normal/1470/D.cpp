#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <unordered_set>

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
    inline InputReader &operator >>(long long &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 300000;

vector<int> g[1 + MAXN];
bool seen[1 + MAXN], in[1 + MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int reached = 0;
        vector<int> sol;
        queue<int> q;
        q.push(1);
        seen[1] = true;
        sol.push_back(1);
        in[1] = true;
        while (!q.empty()) {
            reached++;
            int node = q.front();
            q.pop();
            for (auto it : g[node]) {
                if (!seen[it]) {
                    seen[it] = true;
                    q.push(it);
                    bool found = false;
                    for (auto jt : g[it]) {
                        if (in[jt]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        in[it] = true;
                        sol.push_back(it);
                    }
                }
            }
        }
        if (reached != n) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << sol.size() << "\n";
            for (auto it : sol) {
                cout << it << " ";
            }
            cout << "\n";
        }
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            seen[i] = in[i] = false;
        }
    }
    return 0;
}
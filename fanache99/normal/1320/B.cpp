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
#include <bitset>
#include <unordered_map>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
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

const int MAXN = 200000;

vector<int> g[1 + MAXN], gt[1 + MAXN];
int p[1 + MAXN], d[1 + MAXN];

void BFS(int destination, int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = n + 1;
    }
    queue<int> q;
    q.push(destination);
    d[destination] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto other : gt[node]) {
            if (d[other] == n + 1) {
                d[other] = d[node] + 1;
                q.push(other);
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }
    BFS(p[k], n);
    int smallest = 0, biggest = 0;
    for (int i = 1; i < k; i++) {
        if (d[p[i]] != d[p[i + 1]] + 1) {
            smallest++;
        }
        bool found = false;
        for (auto it : g[p[i]]) {
            if (it != p[i + 1] && d[p[i]] == d[it] + 1) {
                found = true;
                break;
            }
        }
        if (found) {
            biggest++;
        }
    }
    cout << smallest << " " << biggest << "\n";
    //timeDuration();
    return 0;
}
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
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>
#include <random>

using namespace std;
using namespace std::chrono;

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

    inline InputReader &operator>>(char *s) {
        while (!isalpha(buffer[cursor])) {
            advance();
        }
        int len = 0;
        while (isalpha(buffer[cursor])) {
            s[len] = buffer[cursor];
            len++;
            advance();
        }
        s[len] = 0;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int SIGMA = 26;

int main() {
    // ifstream cin("input.txt");
//    ofstream cout("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        vector<int> freq(SIGMA);
        string s;
        cin >> s;
        for (auto ch : s) {
            freq[ch - 'a']++;
        }
        string sol;
        for (int i = 1; i <= k; i++) {
            char ch = 'a';
            int l = 0;
            while (freq[ch - 'a'] > 0 && l < n / k) {
                freq[ch - 'a']--;
                ch++;
                l++;
            }
            sol.push_back(ch);
        }
        cout << sol << "\n";
    }

    auto stopTime = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int main(){
    int a1, a2, a3, b1, b2, b3, a, b, n;
    scanf("%d%d%d", &a1, &a2, &a3);
    scanf("%d%d%d", &b1, &b2, &b3);
    scanf("%d", &n);
    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    n -= a / 5 + (a % 5 != 0);
    n -= b / 10 + (b % 10 != 0);
    if (n >= 0) puts("YES"); else puts("NO");
}
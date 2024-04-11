/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int a[MAXN];

int main(int argc, char *argv[]){
  int N; 
  scanf("%d", &N);
  if((long long)N*(N-1)%N != (long long)N*(N-1)/2%N) { printf("-1\n"); return 0; }
  REP(i, N) printf("%d ", i); printf("\n");
  REP(i, N) a[((long long)i * (N-2)) % N] = i;
  REP(i, N) printf("%d ", a[i]); printf("\n");
  REP(i, N) printf("%d ", (a[i] + i) % N); printf("\n");
  return 0;
  }
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

bool u(char x) {return x>='A'&&x<='Z';}

int main()
{
    char b[107];
    cin>>b;
    int n = strlen(b);
    bool first = u(b[0]);
    int cnt = 0;
    REP(i,n) if (u(b[i])) ++cnt;
    //cout<<cnt<<endl;
    if (cnt==n||(cnt==n-1&&!first))
        REP(i,n) if(u(b[i])) b[i] = b[i]-'A'+'a'; else b[i] = b[i]-'a'+'A';
    cout<<b<<endl;
    return 0;
}
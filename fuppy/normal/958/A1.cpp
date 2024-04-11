//#include "stdafx.h";


#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int n;
vector<vector<char> > rotate(vector<vector<char> > a) {
	vector<vector<char> > b(n, vector<char>(n));
	rep(i, n) {
		rep(j, n) {
			b[j][n - i - 1] = a[i][j];
		}
	}
	return b;
}


int main() {
	cin >> n;
	vector<vector<char> > a(n, vector<char>(n)), b(n, vector<char>(n));
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}
	rep(i, n) {
		rep(j, n) {
			cin >> b[i][j];
		}
	}
	bool flag = false;
	rep(i, 4) {
		if (a == b) {
			flag = true;
		}
		a = rotate(a);
	}
	rep(i, n) {
		reverse(a[i].begin(), a[i].end());
	}
	rep(i, 4) {
		if (a == b) {
			flag = true;
		}
		a = rotate(a);
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
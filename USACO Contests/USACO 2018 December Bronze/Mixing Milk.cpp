#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

void pour(ll &x, ll &x1, ll &y, ll &y1){
	//1 is for the v. of milk
	ll cur = y - y1;
	y1 += min(cur, x1);
	x1 = max(0LL, x1 - cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	ll a, a1, b, b1, c, c1;
	//the ones that have a 1 are actual v. of milk
	cin >> a >> a1 >> b >> b1 >> c >> c1;
	rep(i, 33){
		pour(a, a1, b, b1);
		pour(b, b1, c, c1);
		pour(c, c1, a, a1);
	}
	pour(a, a1, b, b1);
	cout << a1 << endl << b1 << endl << c1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

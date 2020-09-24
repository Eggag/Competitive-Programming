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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int d, sum;
	cin >> d >> sum;
	vector<pi> m(d);
	int mx = 0, mn = 0;
	rep(i, d){
		cin >> m[i].fi >> m[i].se;
		mn += m[i].fi, mx += m[i].se;
	}
	if(mn > sum || mx < sum){
		cout << "NO" << endl;
		return 0;
	}
	//mn has the minumum, we are going to add times one by one
	//sum is the limit
	int ind = 0;
	while(mn < sum){
		while(mn < sum && m[ind].fi < m[ind].se){
			m[ind].fi++;
			mn++;
		}
		ind++;
	}
	cout << "YES" << endl;
	rep(i, d){
		cout << m[i].fi << " \n"[i == d - 1];
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

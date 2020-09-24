#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll a, b, c;
ll ans = 0;

void solve(int st){
	ll a1 = a, b1 = b, c1 = c;
	ll cur = 0;
	repn(i, st, 7){
		if(!i || i == 3 || i == 6){
			if(!a1) break;
			a1--;
		}
		else if(i == 1 || i == 5){
			if(!b1) break;
			b1--;
		}
		else{
			if(!c1) break;
			c1--;
		}
		cur++;
	}
	ll add = min({(a1 / 3), (b1 / 2), (c1 / 2)});
	cur += add * 7;
	a1 -= add * 3;
	b1 -= add * 2;
	c1 -= add * 2;
	rep(i, 7){
		if(!i || i == 3 || i == 6){
			if(!a1) break;
			a1--;
		}
		else if(i == 1 || i == 5){
			if(!b1) break;
			b1--;
		}
		else{
			if(!c1) break;
			c1--;
		}
		cur++;
	}
	ans = max(ans, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> a >> b >> c;
	solve(0);
	solve(1);
	solve(2);
	solve(3);
	solve(4);
	solve(5);
	solve(6);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

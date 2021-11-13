#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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

int AND(int i, int j){
	cout << "and " << i + 1 << ' ' << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}

int OR(int i, int j){
	cout << "or " << i + 1 << ' ' << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}

int XOR(int i, int j, int val){
	return val ^ (AND(i, j) ^ OR(i, j));
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi ans(n, 0);
	int a = AND(0, 1), b = AND(1, 2), c = AND(0, 2);
	ans[0] = a | c;
	ans[1] = a | b;
	ans[2] = b | c;
	int a1 = OR(0, 1), b1 = OR(1, 2), c1 = OR(0, 2);
	rep(i, 31) if(!(ans[0] & (1 << i)) && !(ans[1] & (1 << i)) && !(ans[2] & (1 << i))){
		if((a1 & (1 << i)) && (c1 & (1 << i))) ans[0] |= (1 << i);
		if((a1 & (1 << i)) && (b1 & (1 << i))) ans[1] |= (1 << i);
		if((b1 & (1 << i)) && (c1 & (1 << i))) ans[2] |= (1 << i);
	}
	repn(i, 3, n) ans[i] = XOR(i - 1, i, ans[i - 1]);
	sort(all(ans));
	cout << "finish " << ans[k - 1] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

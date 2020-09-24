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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int query(int a, int b){
	a++, b++;
	cout << "Q 2 " << a << " " << b << endl;
	int res;
	cin >> res;
	return res;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a = query(0, 1);
	int b = query(1, 2);
	int c = query(0, 2);
	vi ans(n);
	if(a > b){
		ans[0] = (c - (a - b)) / 2 + (a - b);
		ans[1] = a - ans[0];
		ans[2] = (c - (a - b)) / 2;
	}
	else{
		ans[0] = (c - (b - a)) / 2;
		ans[1] = a - ans[0];
		ans[2] = (c - (b - a)) / 2 + (b - a);
	}
	repn(i, 3, n){
		int cur = query(i, i - 1);
		ans[i] = cur - ans[i - 1];
	}
	cout << "A";
	rep(i, n) cout << " " << ans[i];
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

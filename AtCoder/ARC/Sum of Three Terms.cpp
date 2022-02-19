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

bool ok(vi a, vi s){
	int n = (int)(s.size());
	rep(i, n) if(s[i] != (a[i] + a[i + 1] + a[i + 2])) return 0;
	rep(i, n + 2) if(a[i] < 0) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi s(n);
	rep(i, n) cin >> s[i];
	vi a(n + 2, 0);
	rep(i, 2){
		a[i] = 0;
		int mn = 0;
		for(int j = i + 3; j < (n + 2); j += 3){
			a[j] = a[j - 3] + (s[j - 2] - s[j - 3]);
			mn = min(a[j], mn);
		}
		for(int j = i; j < (n + 2); j += 3) a[j] -= mn;
	}
	int f = 1;
	for(int j = 2; j < (n + 2); j += 3){
		a[j] = s[j - 2] - (a[j - 2] + a[j - 1]);
		if(a[j] < 0) f = 0;
	}
	if(f && ok(a, s)){
		cout << "Yes\n";
		rep(j, n + 2) cout << a[j] << ' ';
		cout << '\n';
		return 0;
	}
	rep(i, n + 2) a[i] = 0;
	repn(i, 1, 3){
		a[i] = 0;
		int mn = 0;
		for(int j = i + 3; j < (n + 2); j += 3){
			a[j] = a[j - 3] + (s[j - 2] - s[j - 3]);
			mn = min(a[j], mn);
		}
		for(int j = i; j < (n + 2); j += 3) a[j] -= mn;
	}
	f = 1;
	for(int j = 0; j < (n + 2); j += 3){
		a[j] = s[j] - (a[j + 2] + a[j + 1]);
		if(a[j] < 0) f = 0;
	}
	if(f && ok(a, s)){
		cout << "Yes\n";
		rep(j, n + 2) cout << a[j] << ' ';
		cout << '\n';
		return 0;
	}
	rep(i, n + 2) a[i] = 0;
	rep(i, 3) if(i != 1){
		a[i] = 0;
		int mn = 0;
		for(int j = i + 3; j < (n + 2); j += 3){
			a[j] = a[j - 3] + (s[j - 2] - s[j - 3]);
			mn = min(a[j], mn);
		}
		for(int j = i; j < (n + 2); j += 3) a[j] -= mn;
	}
	f = 1;
	for(int j = 1; j < (n + 2); j += 3){
		a[j] = s[j - 1] - (a[j - 1] + a[j + 1]);
		if(a[j] < 0) f = 0;
	}
	if(f && ok(a, s)){
		cout << "Yes\n";
		rep(j, n + 2) cout << a[j] << ' ';
		cout << '\n';
		return 0;
	}
	cout << "No\n";
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

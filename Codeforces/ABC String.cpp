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

void solve(){
	string a;
	cin >> a;
	int n = (int)(a.size());
	vector<char> f = {'.', '.', '.'};
	if(a[0] == a[n - 1]){
		cout << "NO\n";
		return;
	}
	f[a[0] - 'A'] = '(';
	f[a[n - 1] - 'A'] = ')';
	int ind = -1;
	rep(i, 3) if(f[i] == '.') ind = i;
	rep(i, 2){
		if(!i) f[ind] = '(';
		else f[ind] = ')';
		int bal = 0, f1 = 1;
		rep(j, n){
			if(f[a[j] - 'A'] == '(') bal++;
			else bal--;
			if(bal < 0) f1 = 0;
		}
		if(!f1 || bal) continue;
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

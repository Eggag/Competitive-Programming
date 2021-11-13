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

int n;

int askMin(int i, int j){
	cout << "? 2 " << i + 1 << " " << j + 1 << " " << 1 << endl;
	int res;
	cin >> res;
	if(res == 2){
		cout << "? 2 " << j + 1 << " " << i + 1 << " " << 1 << endl;
		int res1;
		cin >> res1;
		res = min(res, res1);
	}
	return res;
}

int askMax(int i, int j){
	cout << "? 1 " << i + 1 << " " << j + 1 << " " << n - 1 << endl;
	int res;
	cin >> res;
	if(res == (n - 1)){
		cout << "? 1 " << j + 1 << " " << i + 1 << " " << n - 1 << endl;
		int res1;
		cin >> res1;
		res = max(res, res1);
	}
	return res;
}

void solve(){
	cin >> n;
	vi ans(n, 0);
	for(int i = 0; i < n; i += 3){
		vi cr;
		rep(j, 3) if((i + j) < n) cr.pb(i + j);
		if((int)(cr.size()) == 1){
			cr.pb(i - 2);
			cr.pb(i - 1);
		}
		if((int)(cr.size()) == 2) cr.pb(i - 1);
		int mn = askMin(cr[0], cr[1]);
		int mn1 = askMin(cr[1], cr[2]);
		if(mn == mn1){
			ans[cr[1]] = mn;
			if(!ans[cr[0]]) ans[cr[0]] = askMax(cr[0], cr[1]);
			if(!ans[cr[2]]) ans[cr[2]] = askMax(cr[1], cr[2]);
		}
		else{
			int mx = askMax(cr[0], cr[1]);
			if(mx == mn1){
				ans[cr[0]] = mn;
				ans[cr[1]] = mx;
				if(!ans[cr[2]]) ans[cr[2]] = askMax(cr[1], cr[2]);
				continue;
			}
			int mx1 = askMax(cr[1], cr[2]);
			if(mx1 == mn){
				ans[cr[0]] = mx;
				ans[cr[1]] = mx1;
				ans[cr[2]] = mn1;
				continue;
			}
			if(mx == mx1){
				ans[cr[0]] = mn;
				ans[cr[1]] = mx;
				ans[cr[2]] = mn1;
				continue;
			}
		}
	}
	cout << '!';
	for(int x : ans) cout << ' ' << x;
	cout << endl;
}

int main(){
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

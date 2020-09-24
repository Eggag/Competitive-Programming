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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	int pos = 0, neg = 0;
	int mx = -1e9, mn = 1e9;
	int mxInd = -1, mnInd = -1; 
	rep(i, n){
		cin >> a[i];
		if(a[i] < 0) neg++;
		else pos++;
		if(a[i] > mx){
			mx = a[i];
			mxInd = i;
		}
		if(a[i] < mn){
			mn = a[i];
			mnInd = i;
		}
	}
	vector<pi> ans;
	if(!neg){
		for(int i = 1; i < n; i++) ans.pb(mp(i - 1, i));
	}
	else if(!pos){
		for(int i = n - 2; i >= 0; i--) ans.pb(mp(i + 1, i));
	}
	else{
		if(mx > abs(mn)){
			rep(i, n) if(a[i] != mx) ans.pb(mp(mxInd, i));
			for(int i = 1; i < n; i++) ans.pb(mp(i - 1, i));
		}
		else{
			rep(i, n) if(a[i] != mn) ans.pb(mp(mnInd, i));
			for(int i = n - 2; i >= 0; i--) ans.pb(mp(i + 1, i));
		}
	}
	cout << ans.size() << endl;
	for(pi x : ans) cout << x.fi + 1 << " " << x.se + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

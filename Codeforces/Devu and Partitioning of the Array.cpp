#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi ans[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, p;
	cin >> n >> k >> p;
	vi a(n), odd, even;
	rep(i, n){
		cin >> a[i];
		if(a[i] & 1) odd.pb(a[i]);
		else even.pb(a[i]);
	}
	int sz = odd.size();
	rep(i, k - p){
		if(i == sz){
			cout << "NO" << endl;
			return 0;
		}
		ans[i].pb(odd[(int)odd.size() - 1]);
		odd.pop_back();
		if(!p && (i == (k - p - 1))){
			if(odd.size() & 1){
				cout << "NO" << endl;
				return 0;
			}
			while(odd.size()) ans[i].pb(odd[(int)odd.size() - 1]), odd.pop_back();
			while(even.size()) ans[i].pb(even[(int)even.size() - 1]), even.pop_back();
		}
	}
	if(odd.size() & 1){
		cout << "NO" << endl;
	}
	else{
		repn(i, k - p, k){
			if(odd.size() >= 2){
				ans[i].pb(odd[(int)odd.size() - 1]);
				odd.pop_back();
				ans[i].pb(odd[(int)odd.size() - 1]);
				odd.pop_back();
			}
			else if(even.size()){
				ans[i].pb(even[(int)even.size() - 1]);
				even.pop_back();
			}
			else{
				cout << "NO" << endl;
				return 0;
			}
			if(i == (k - 1)){
				while(odd.size()) ans[i].pb(odd[(int)odd.size() - 1]), odd.pop_back();
				while(even.size()) ans[i].pb(even[(int)even.size() - 1]), even.pop_back();
			}
		}
		cout << "YES" << endl;
		rep(i, k){
			cout << ans[i].size();
			rep(j, ans[i].size()) cout << " " << ans[i][j];
			cout << '\n';
		}
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

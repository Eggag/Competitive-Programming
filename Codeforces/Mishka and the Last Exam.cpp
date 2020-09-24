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
	vector<ll> b(n / 2);
	rep(i, n / 2) cin >> b[i];
	vector<ll> ans(n);
	ans[0] = 0LL;
	ans[n - 1] = b[0];
	ll lastl = 0;
	ll lastr = b[0];
	repn(i, 1, n / 2){
		if(b[i] == b[i - 1]){
			ans[i] = lastl;
			ans[n - i - 1] = lastr;
		}	
		if(b[i] > b[i - 1]){
			if((lastr * 2) < (b[i] / 2)){
				//debug(lastr);
				//debug(b[i]);
				//debug(i);
				assert(0); //too large, shouldn't happen
			}
			ans[i] = b[i] - lastr;
			ans[n - i - 1] = lastr;
			lastl = ans[i];
			lastr = ans[n - i - 1];
		}
		if(b[i] < b[i - 1]){
			ans[i] = lastl;
			ans[n - i - 1] = b[i] - lastl;
			lastl = ans[i];
			lastr = ans[n - i - 1];
		}
	}
	for(auto x : ans) cout << x << " ";
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

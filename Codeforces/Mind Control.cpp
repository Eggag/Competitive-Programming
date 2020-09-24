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

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	if(k >= (m - 1)){
		//can take the max of the ones that are within m - 1 of the endpoints
		//there is always a way, so that's good
		int ans = 0;
		rep(i, m) ans = max(ans, a[i]);
		for(int i = n - 1; i > (n - m - 1); i--) ans = max(ans, a[i]);
		cout << ans << endl;
	}
	else{
		int ans1 = 0;
		int nm = (n - k);
		//debug(nm);
		rep(i, (n - nm) + 1){
			vi a1;
			repn(j, i, i + (n - k)) a1.pb(a[j]);
			//for(int x : a1) cout << x << " ";
			//cout << endl;
			//cout << "-----" << endl;
			//think worst-case on this interval, that is the most we can expect
			int num = (m - 1) - k; //how many left
			int num1 = (int)a1.size() - num;
			int ans = 1e9;
			rep(i1, a1.size() - num1 + 1){
				int one = a1[i1], two = a1[i1 + num1 - 1];
				//debug2(i1, i1 + num1 - 1);
				ans = min(ans, max(one, two));
			}
			//debug(ans);
			if(ans == 1e9) ans = *min_element(all(a1));
			ans1 = max(ans1, ans);
		}
		cout << ans1 << endl;
	}
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
	- Array bounds
	- Special cases
Be careful!
*/

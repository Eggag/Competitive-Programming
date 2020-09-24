#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool sqr(int a){
	int tmp = sqrt(a);
	if(tmp * tmp == a) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int g = 0, b = 0;
	rep(i, n){
		if(sqr(a[i])) g++;
		else b++;
	}
	if(g == b){
		cout << 0 << endl;
		return 0;
	}
	if(g > b){
		vi best;
		rep(i, n) if(sqr(a[i])){
			if(a[i] == 0) best.pb(2);
			else best.pb(1);
		}	
		sort(all(best));
		ll ans = 0;
		rep(i, n / 2 - b) ans += best[i];
		cout << ans << endl;
	}
	else{
		vi best;
		rep(i, n) if(!sqr(a[i])){
			//int cur = a[i];
			//while(!sqr(cur)) cur++;
			int near = sqrt(a[i]) + 1;
			near *= near;
			int ans1 = near - a[i];
			//cur = a[i];
			//while(!sqr(cur) && cur > 1) cur--;
			near = sqrt(a[i]);
			near *= near;
			int ans2 = a[i] - near;
			best.pb(min(ans1, ans2));
		}
		sort(all(best));
		ll ans = 0;
		rep(i, n / 2 - g){
			ans += best[i];
		}
		cout << ans << endl;
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

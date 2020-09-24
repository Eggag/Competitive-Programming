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
	int sum = 0;
	rep(i, n) cin >> a[i], sum += a[i];;
	if(sum == 1){
		cout << -1 << endl;
		return 0;
	}
	vi divs;
	for(int i = 1; (i * i) <= sum; i++){
		if(sum % i == 0){
			divs.pb(i);
			if((sum / i) != i) divs.pb(sum / i);
		}
	}
	sort(all(divs));
	ll ans1 = 1e18;
	for(int j = 1; j < 100 && j < divs.size(); j++){
		int num = divs[j];
		vi pos;
		rep(i, n) if(a[i]) pos.pb(i);
		vector<ll> av((sum / num) + 10);
		rep(i, pos.size()){
			if((i + 1) % num == 0){
				av[i / num] = pos[i - (num / 2)];
			}
		}
		ll ans = 0;
		rep(i, (sum / num)){
			ll ret = 0;
			repn(j, i * num, (i * num) + num) ret += abs(pos[j] - av[i]);
			ans += ret;
		}
		ans1 = min(ans1, ans);
	}
	cout << ans1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

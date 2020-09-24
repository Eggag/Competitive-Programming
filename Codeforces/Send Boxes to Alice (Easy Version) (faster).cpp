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
	vector<bool> prime;
	vector<int> primes;
	prime.assign(sum + 1, 1);
	prime[1] = false;
	for(int i = 2; i <= sum; i++){
		if(prime[i]){
			if(sum % i == 0) primes.pb(i);
			for(int j = i * 2; j <= sum; j += i){
				prime[j] = false;
			}
		}
	}
	ll ans1 = 1e18;
	rep(j, primes.size()){
		int num = primes[j];
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

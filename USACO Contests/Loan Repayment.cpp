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

ll n, k, m;

bool check(ll num){
	ll sum = 0;
	//the question is, for every stage, how fast will we lose it?
	ll cnt = 0;	
	while(cnt < k){
		if(sum >= n) return 1;
		ll nm = (n - sum) / num;
		ll nm1 = max(m, nm);
		if(nm1 == m){
			sum += (k - cnt) * m;
			break;
		}
		else{
			ll md = ((((n - sum) % num) + nm1) / nm1);
			cnt += min(md, k - cnt);
			sum += min(md, k - cnt) * nm1;
		}
	}
	return (sum >= n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
	cin >> n >> k >> m;
	ll l = 1, r = 1e13;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

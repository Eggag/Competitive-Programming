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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, K;

bool check(ll v){
	ll res = v;
	ll k = K;
	while((v / k) >= 1){
		res += (v / k);
		k *= K;
	}
	//debug2(res, n);
	if(res >= n) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> K;
	ll l = 0, r = n;
	while(l < r){
		//debug2(l, r);
		ll mid = (l + r) / 2;
		//debug(mid);
		if(check(mid)) r = mid;
		else l = mid + 1;
		//cout << "----" << endl;
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

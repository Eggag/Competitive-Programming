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

ll k;

ll to10(ll n){
	ll cur = n;
	rep(i, 9){
		if(k / cur < n) return 1e18;
		cur *= n;
	}
	return cur;
}

ll mult(vector<ll> v){
	ll cur = 1LL;
	rep(i, v.size()) cur *= v[i];
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> k;
	ll mx = -1;
	for(ll i = 1; i < 100; i++){
		//debug(to10(i));
		if(to10(i) > k){
			mx = i;
			break;
		}
	}
	vector<ll> cnt(10, mx);
	rep(i, 10){
		cnt[i]--;
		if(mult(cnt) < k){
			cnt[i]++;
			break;
		}
	}
	string s = "codeforces";
	rep(i, s.size()) rep(j, cnt[i]) cout << s[i];
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

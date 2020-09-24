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
	ll a, b;
	cin >> a >> b;
	vector<ll> num(50, 0LL);
	rep(i, 45){
		ll cur = (b / (1LL << (i + 1))) * (1LL << i) + max(0LL, (b % ((1LL << (i + 1))) - (1LL << i)) + 1) * ((b / (1LL << i) ? 1LL : 0));
		num[i] += cur;
	}
	ll ans = 0;
	rep(i, 45){
		int f = 1;
		if(!num[i]) f = 0;
		ll cur = ((a - 1) / (1LL << (i + 1))) * (1LL << i) + max(0LL, ((a - 1) % ((1LL << (i + 1))) - (1LL << i)) + 1) * (((a - 1) / (1LL << i) ? 1LL : 0));
		num[i] -= cur;
		if(f && (num[i] & 1)) ans |= (1LL << i);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
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
const int MAXN = 1e5 + 1;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, k;
ll a[MAXN];

bool check(ll cur){
	return (((cur * (cur + 1)) / 2) >= k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> a[i];
	ll l = 1, r = n + 1;
	while(l < r){
		//debug2(l, r);
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	ll ans = ((l * (l + 1)) / 2) - k;
	cout << a[(n - 1) - ans - (n - l)] << endl;;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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

ll n, a, b;
ll h[100005];

bool check(ll num){
	ll used = 0;
	rep(i, n){
		//do another binary search
		ll l = 0, r = num - used; //how many turns on this one
		while(l < r){
			ll mid = (l + r) / 2;
			if(h[i] - ((a * mid) + (b * (num - mid))) <= 0) r = mid;
			else l = mid + 1;
		}
		if((h[i] - ((a * l) + (b * (num - l)))) > 0) return 0;
		used += l;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> a >> b;
	rep(i, n) cin >> h[i];
	sort(h, h + n);
	reverse(h, h + n);
	ll l = 1, r = 1e9;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
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

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
	vector<ll> a(n), b;
	rep(i, n){
		cin >> a[i];
		if(a[i] > 0) b.pb(a[i]);
	}
	if(!b.size()){
		ll mx = -1e18;
		rep(i, n) if(a[i] < 0 && abs(a[i]) % 2 == 1) mx = max(mx, a[i]);
		cout << mx << endl;
	}
	else{
		ll sum = 0;
		vector<ll> odd;
		rep(i, b.size()){
			if(b[i] & 1) odd.pb(b[i]);
			else sum += b[i];
		}
		ll mx = -1e18;
		rep(i, n) if(a[i] < 0 && abs(a[i]) % 2 == 1) mx = max(mx, a[i]);
		if(!odd.size()){
			cout << sum + mx << endl;
			return 0;
		}
		sort(all(odd));
		reverse(all(odd));
		int m = odd.size();
		rep(i, m - (1 - (m & 1))) sum += odd[i];
		if(m % 2 == 0 && odd[m - 1] > abs(mx)) sum += odd[m - 1] + mx;
		cout << sum << endl;
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

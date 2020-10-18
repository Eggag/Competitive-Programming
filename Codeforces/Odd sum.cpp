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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> odd;
	rep(i, n){
		cin >> a[i];
		if(a[i] % 2 != 0){
			odd.pb(a[i]);
		}
	}
	//no DP lol
	sort(all(odd));
	reverse(all(odd));
	//need to have an odd num of odds
	ll prev = 0;
	ll sum = -1e18;
	for(int i = 0; i < odd.size(); i += 2){
		prev += odd[i];
		if(i) prev += odd[i - 1];
		sum = max(sum, prev);
	}
	rep(i, n){
		if(a[i] > 0 && a[i] % 2 == 0) sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
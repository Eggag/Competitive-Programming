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

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n) cin >> a[i], sum += a[i];
	ll num = a[0];
	repn(i, 1, n) num ^= a[i];
	/*
	if(sum == num){
		cout << 0 << endl;
		return;
	}
	*/
	ll mx = 0LL;
	mx |= (1LL << 53); //make num > sum
	if(sum & 1) mx |= 1LL; //now the parity is the same, so the difference is div by 2
	//debug(mx);
	sum += mx;
	num ^= mx;
	num *= 2;
	assert(num > sum);
	cout << "3" << endl;
	cout << mx << " " << ((num - sum) / 2) << " " << ((num - sum) / 2) << endl;
	/*
	num /= 2;
	num ^= ((num - sum) / 2);
	num ^= ((num - sum) / 2);
	num *= 2;
	sum += (num - sum);
	assert(sum == num);
	*/
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
	int n, s;
	cin >> n >> s;
	vi a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	int mx = 0;
	int ind = 0;
	rep(i, n){
		if(a[i] > mx) ind = i, mx = a[i];
		sum += a[i];
		if(sum > s){
			//we select the mx
			sum -= mx;
			int j = i + 1;
			if(sum > s){
				cout << 0 << endl;
				return;
			}
			while(j < n && sum < s){
				j++;
				sum += a[j];
			}
			if(j == (i + 1) && sum > s){
				cout << 0 << endl;
				return;
			}
			cout << ind + 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
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

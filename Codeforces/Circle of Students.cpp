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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, n){
		//start from i
		int ind = i + 1;
		ind %= n;
		int prev = i;
		int cnt = 1;
		int f = 1;
		while(cnt < n){
			if((a[ind] - a[prev]) == 1){
				prev = ind;
				ind++;
				ind %= n;
			}
			else{
				f = 0;
			}
			cnt++;
		}
		if(f){
			cout << "YES" << endl;
			return;
		}
	}
	rep(i, n){
		//start from i
		int ind = i - 1;
		if(ind < 0) ind = n - 1;
		int prev = i;
		int cnt = 1;
		int f = 1;
		while(cnt < n){
			if((a[ind] - a[prev]) == 1){
				prev = ind;
				ind--;
				if(ind < 0) ind = n - 1;
			}
			else{
				f = 0;
			}
			cnt++;
		}
		if(f){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

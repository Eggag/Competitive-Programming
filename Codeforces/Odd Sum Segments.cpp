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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	int odd = 0;
	rep(i, n){
		cin >> a[i];
		if(a[i] % 2 == 1) odd++;
	}
	if(odd < k){
		cout << "NO" << endl;
		return;
	}
	if(k == 1){
		if(odd % 2 == 1){
			cout << "YES" << endl;
			cout << n << endl;
		}
		else{
			cout << "NO" << endl;
		}
		return;
	}
	int rem = odd - (k - 1);
	if(rem % 2 == 0){
		cout << "NO" << endl;
		return;
	}
	int cnt = 0;
	cout << "YES" << endl;
	rep(i, n){
		if(a[i] % 2 == 1){
			cout << (i + 1) << " ";
			cnt++;
		}
		if(cnt == (k - 1)) break;
	}
	cout << n << endl;
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

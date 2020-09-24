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

int md(int a, int b){
	if(a > 0){
		return a % b;
	}
	else{
		int ret = a % b;
		if(ret < 0) ret += b;
		return ret;
	}
}

int cnt[200005];

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cnt[i] = 0;
	rep(i, n) cin >> a[i];
	for(int j = 0; j < n; j++){
		cnt[md(j + a[md(j, n)], n)]++;
	}
	rep(i, n) if(cnt[i] > 1){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
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

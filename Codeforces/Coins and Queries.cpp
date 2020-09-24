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
	int n, q;
	cin >> n >> q;
	vi cnt(32, 0);
	vi a(n);
	rep(i, n){
		cin >> a[i];
		rep(j, 32) if(a[i] & (1 << j)){
			cnt[j]++;
			break;
		}
	}
	rep(i, q){
		int b;
		cin >> b;
		int ans = 0;
		for(int j = 31; j >= 0; j--){
			int num = cnt[j];
			int mx = b / (1 << j);
			if(mx >= num) b -= num * (1 << j), ans += num;
			else b -= min(num, mx) * (1 << j), ans += min(num, mx);
		}
		if(b) ans = -1;
		cout << ans << endl;
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

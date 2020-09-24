#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi a(m);
	memset(cnt, 0, sizeof(cnt));
	rep(i, m){
		cin >> a[i];
		cnt[a[i]]++;
	}
	if(m < n){
		cout << 0 << endl;
		return 0;
	}
	int l = 1, r = 100;
	int ans = 0;
	while(l <= r){
		int mid = (r + l) / 2;
		int cur = 0;
		rep(i, 105) if(cnt[i]){
			cur += cnt[i] / mid;
		}
		if(cur >= n){
			ans = mid;
			l = mid + 1;
		}
		if(cur < n){
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

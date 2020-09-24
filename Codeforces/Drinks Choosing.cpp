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
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n);
	vi cnt(k, 0);
	rep(i, n) cin >> a[i], cnt[a[i] - 1]++;
	int ans = 0;
	int num = 0;
	rep(i, k){
		if(cnt[i] >= 2){
			int cur = cnt[i] / 2;
			ans += cur * 2;
			num += cur;
		}
	}
	int x = n / 2;
	if(n % 2 != 0) x++;
	cout << ans + (x - num) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

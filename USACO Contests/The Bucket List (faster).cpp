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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int n;
	cin >> n;
	vi cnt(1005, 0);
	rep(i, n){
		int a, b, c;
		cin >> a >> b >> c;
		cnt[a] += c;
		cnt[b + 1] -= c;
	}
	partial_sum(all(cnt), cnt.begin());
	int mx = 0;
	rep(i, 1005) mx = max(mx, cnt[i]);
	cout << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

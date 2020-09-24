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

int v[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b;
	memset(v, 0, sizeof(v));
	rep(i, n){
		cin >> a[i];
		v[a[i]] = 1;
	}
	repn(i, 1, (2 * n) + 1) if(!v[i]) b.pb(i);
	sort(all(a));
	//b is sorted already
	int ind = 0;
	int ans = 0;
	rep(i, n){
		while(ind < n && b[ind] < a[i]) ind++;
		if(ind == n) break;
		ans++;
		ind++;
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

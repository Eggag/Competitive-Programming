#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
	int n, d;
	cin >> n >> d;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi tot(n, 0);
	tot[0] = a[0];
	repn(i, 1, n) tot[i] = tot[i - 1] + a[i];
	vi mx(n, 1e9);
	mx[n - 1] = tot[n - 1];
	for(int i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], tot[i]);
	if(mx[0] > d){
		cout << -1 << endl;
		return 0;
	}
	int add = 0, ans = 0;
	rep(i, n) if(!a[i]){
		if((tot[i] + add) < 0){
			int need = -(tot[i] + add);
			int mx1 = d - (mx[i] + add);
			if(need > mx1){
				cout << -1 << endl;
				return 0;
			}
			ans++;
			add += mx1;
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

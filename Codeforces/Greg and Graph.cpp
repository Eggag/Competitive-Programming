#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int d[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n + 1) repn(j, 1, n + 1) cin >> d[i][j];
	int a[n];
	rep(i, n) cin >> a[i];
	reverse(a, a + n);
	vector<ll> ans;
	rep(i, n){
		rep(j, n) rep(k, n){
			d[a[j]][a[k]] = min(d[a[j]][a[k]], d[a[j]][a[i]] + d[a[i]][a[k]]);
		}
		ll ret = 0;
		rep(j, i + 1) rep(k, i + 1){
			ret += d[a[j]][a[k]];
		}
		ans.pb(ret);
	}
	reverse(all(ans));
	rep(i, n){
		cout << ans[i];
		if(i == n - 1) cout << endl;
		else cout << " ";
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

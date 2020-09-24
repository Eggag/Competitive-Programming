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

int v[1000005];
int d[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ll sum = 0;
	vi a(n), b(n);
	rep(i, n) cin >> a[i], b[i] = a[i], sum += a[i];
	sort(all(b));
	int mx = b[n - 1];
	int mx2 = b[n - 2];
	vi ans;
	memset(v, 0, sizeof(v));
	memset(d, 0, sizeof(d));
	//use v to not check the same number twice
	rep(i, n){
		if(!v[a[i]]){
			int mx1 = mx;
			if(a[i] == mx) mx1 = mx2;
			if(mx1 == (sum - a[i] - mx1)){
				ans.pb(i + 1);
				d[a[i]] = 1;
				v[a[i]] = 1;
			}
		}
		else{
			if(d[a[i]]) ans.pb(i + 1);
		}
	}
	//how could I have struggled with this problem a month ago???
	//guess I really improved)
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << " \n"[i == ans.size() - 1];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

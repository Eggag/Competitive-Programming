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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	ll sum = (n * (n + 1)) / 2;
	if(sum % 2 == 0) cout << 0 << endl;
	else cout << 1 << endl;
	ll cur = 0;
	ll tmp = n;
	vi ans;
	while(cur < (sum / 2)){
		if(cur + tmp <= (sum / 2)){
			cur += tmp;
			ans.pb(tmp);
		}
		tmp--;
	}
	cout << ans.size() << " ";
	rep(i, ans.size()){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

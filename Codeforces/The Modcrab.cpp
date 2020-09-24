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
	int h1, a1, c1;
	cin >> h1 >> a1 >> c1;
	int h2, a2;
	cin >> h2 >> a2;
	if(a1 >= h2){
		cout << 1 << endl;
		cout << "STRIKE" << endl;
		return 0;
	}
	int nm = (h2 - 1) / a1;
	vector<string> ans;
	while(h1 <= (a2 * nm)) h1 += c1 - a2, ans.pb("HEAL");
	int nm1 = h2 - a1;
	while(nm1 > 0) nm1 -= a1, ans.pb("STRIKE");
	ans.pb("STRIKE");
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
	int n;
	cin >> n;
	vi d(n), s(n);
	rep(i, n) cin >> d[i], s[i] = d[i];
	sort(all(s));
	vector<array<string, 3>> ans;
	vi l, r;
	rep(i, n) l.pb(d[i]);
	reverse(all(l));
	rep(i, n){
		int mx = s[n - i - 1];
		int f = 0;
		for(int j = (int)(l.size()) - 1; j >= 0; j--){
			if(l[j] == mx && !f){
				f = 1;
				array<string, 3> ar = {"UZMI", "D", "L"};
				ans.pb(ar);
			}
			else{
				array<string, 3> ar = {"UZMI", "L", "L"};
				ans.pb(ar);
				ar = {"STAVI", "L", "D"};
				r.pb(l[j]);
				ans.pb(ar);
			}
		}
		array<string, 3> ar = {"STAVI", "D", "L"};
		ans.pb(ar);
		l.clear();
		for(int j = (int)(r.size()) - 1; j >= 0; j--){
			array<string, 3> ar1 = {"UZMI", "L", "D"};
			ans.pb(ar1);
			ar1 = {"STAVI", "L", "L"};
			l.pb(r[j]);
			ans.pb(ar1);
		}
		r.clear();
	}
	cout << ans.size() << '\n';
	rep(i, ans.size()) cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

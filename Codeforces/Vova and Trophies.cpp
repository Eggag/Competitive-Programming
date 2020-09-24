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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = 0;
	vi st, en;
	vi ans;
	rep(i, n){
		if(s[i] == 'G'){
			if(len == 0){
				st.pb(i);
			}
			len++;
		}
		else{
			if(len){
				en.pb(i);
				ans.pb(len);
				len = 0;
			}
		}
	}
	if(len){
		ans.pb(len);
		en.pb(n - 1);
	}
	int ret = 0;
	rep(i, ans.size()) ret = max(ret, ans[i]);
	int mx = ret;
	//look at ones next to each other, separated by one s
	repn(i, 1, st.size()){
		if((st[i] - 1) == en[i - 1]){
			ret = max(ret, ans[i] + ans[i - 1] + (ans.size() > 2));
		}
	}
	if(ans.size() >= 2) ret = max(ret, mx + 1);
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

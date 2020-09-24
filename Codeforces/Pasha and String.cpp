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
	string s;
	cin >> s;
	int n = s.size();
	int m;
	cin >> m;
	vector<char> ans(n);
	vi cnt(300005, 0);
	rep(i, m){
		int a;
		cin >> a;
		cnt[a - 1]++;
	}
	int tot = 0;
	rep(i, s.size() / 2){
		tot += cnt[i];
		if(tot % 2 == 0) ans[i] = s[i], ans[n - 1 - i] = s[n - 1 - i];
		else ans[n - 1 - i] = s[i], ans[i] = s[n - 1 - i];
	}
	if(n & 1) ans[n / 2] = s[n / 2];
	for(char x : ans) cout << x;
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


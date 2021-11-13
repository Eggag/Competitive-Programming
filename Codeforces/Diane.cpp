#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

bool check(string s){
	map<string, int> cnt;
	int n = (int)(s.size());
	rep(i, n) repn(j, i, n){
		string s1 = s.substr(i, j - i + 1);
		cnt[s1]++;
	}
	for(pair<string, int> x : cnt) if(x.se % 2 == 0) return 0;
	return 1;
}

void solve(){
	int n;
	cin >> n;
	if(n % 2 == 0){
		string s = "";
		rep(i, n / 2) s += 'b';
		s += 'a';
		rep(i, (n / 2) - 1) s += 'b';
		//assert(check(s));
		cout << s << '\n';
	}
	else{
		if(n == 1){
			cout << "a\n";
			return;
		}
		string s = "";
		rep(i, n / 2) s += 'b';
		s += 'a';
		s += 'c';
		rep(i, (n / 2) - 1) s += 'b';
		//assert(check(s));
		cout << s << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

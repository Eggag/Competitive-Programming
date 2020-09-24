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

void solve(){
	string s;
	cin >> s;
	int num = 0, f = 0;
	vi comp;
	rep(i, s.size()){
		if(s[i] == '1' && !f){
			num = 0;
			f = 1;
		}
		if(f){
			if(s[i] == '0'){
				comp.pb(num);
				num = 0;
			}
			else num++;
		}
	}
	if(f){
		comp.pb(num);
	}
	sort(all(comp));
	reverse(all(comp));
	int tot = 0;
	for(int i = 0; i < comp.size(); i += 2) tot += comp[i];
	cout << tot << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/

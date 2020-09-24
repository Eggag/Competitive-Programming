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
	string s1;
	cin >> s1;
	//try to make them all white
	string s = s1;
	vi ans;
	int pos = 1;
	rep(i, n - 1){
		if(i == (n - 2)){
			if(s[i] == 'B' && s[i + 1] == 'B'){
				ans.pb(i);
			}
			else if(!(s[i] == 'W' && s[i + 1] == 'W')){
				pos = 0;
			}
		}
		else{
			if(s[i] == 'B'){
				ans.pb(i);
				if(s[i + 1] == 'W') s[i + 1] = 'B';
				else s[i + 1] = 'W';
			}
		}
	}
	if(pos){
		cout << ans.size() << endl;
		rep(i, ans.size()) cout << ans[i] + 1 << " ";
		cout << endl;
		return 0;
	}
	s = s1;
	ans.clear();
	pos = 1;
	rep(i, n - 1){
		if(i == (n - 2)){
			if(s[i] == 'W' && s[i + 1] == 'W'){
				ans.pb(i);
			}
			else if(!(s[i] == 'B' && s[i + 1] == 'B')){
				pos = 0;
			}
		}
		else{
			if(s[i] == 'W'){
				ans.pb(i);
				if(s[i + 1] == 'B') s[i + 1] = 'W';
				else s[i + 1] = 'B';
			}
		}
	}
	if(pos){
		cout << ans.size() << endl;
		rep(i, ans.size()) cout << ans[i] + 1 << " ";
		cout << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

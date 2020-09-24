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

void solve(){
	string t;
	cin >> t;
	//if t is all the same chars, then just output it
	//otherwise, we can keep inserting chars to variate
	int o = 0, z = 0;
	rep(i, t.size()){
		if(t[i] == '1') o++;
		else z++;
	}
	if(!o || !z){
		//period of 1
		cout << t << endl;
		return;
	}
	//make period 2
	string s = "";
	s += t[0];
	repn(i, 1, t.size()){
		if(t[i] == t[i - 1]){
			if(t[i - 1] == '1'){
				s += '0';
				s += '1';
			}
			else{
				s += '1';
				s += '0';
			}
		}
		else s += t[i];
	}
	cout << s << endl;
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

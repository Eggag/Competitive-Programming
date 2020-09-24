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
	freopen("clumsy.in", "r", stdin);
	freopen("clumsy.out", "w", stdout);
	string s;
	cin >> s;
	int op = 0, cl = 0;
	int ans = 0;
	rep(i, s.size()){
		if(s[i] == ')') cl++;
		else op++;
		if(cl > op){
			ans++;
			cl--, op++;
			s[i] = '(';
		}
	}
	if(cl < op){
		int diff = (op - cl) / 2;
		for(int i = s.size() - 1; i >= 0; i--){
			if(s[i] == '('){
				s[i] = ')';
				diff--;
				ans++;
				if(!diff) break;
			}

		}	
	}
	else if(cl > op){
		int diff = (cl - op) / 2;
		rep(i, s.size()){
			if(s[i] == ')'){
				s[i] = ')';
				ans++;
				diff--;
				if(!diff) break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

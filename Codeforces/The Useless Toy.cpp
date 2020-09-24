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
	char c, c1;
	cin >> c >> c1;
	string s = "";
	s += c;
	s += c1;
	int n;
	cin >> n;
	if(s[0] == '>'){
		if(s[1] == '>'){
			cout << "undefined" << endl;
			return 0;
		}
		if(s[1] == '<'){
			cout << "undefined" << endl;
			return 0;
		}
		if(s[1] == '^'){
			if(n % 4 == 1) cout << "ccw" << endl;
			if(n % 4 == 3) cout << "cw" << endl;
			return 0;
		}
		if(s[1] == 'v'){
			if(n % 4 == 1) cout << "cw" << endl;
			if(n % 4 == 3) cout << "ccw" << endl;
			return 0;
		}
	}
	if(s[0] == '<'){
		if(s[1] == '>'){
			cout << "undefined" << endl;
			return 0;
		}
		if(s[1] == '<'){
			cout << "undefined" << endl;
			return 0;
		}
		if(s[1] == '^'){
			if(n % 4 == 1) cout << "cw" << endl;
			if(n % 4 == 3) cout << "ccw" << endl;
			return 0;
		}
		if(s[1] == 'v'){
			if(n % 4 == 1) cout << "ccw" << endl;
			if(n % 4 == 3) cout << "cw" << endl;
			return 0;
		}
	}
	if(s[0] == '^'){
		if(s[1] == '>'){
			if(n % 4 == 1) cout << "cw" << endl;
			if(n % 4 == 3) cout << "ccw" << endl;
			return 0;
		}
		if(s[1] == '<'){
			if(n % 4 == 1) cout << "ccw" << endl;
			if(n % 4 == 3) cout << "cw" << endl;
			return 0;
		}
		if(s[1] == '^'){
			cout << "undefined" << endl;
			return 0;
		}
		if(s[1] == 'v'){
			cout << "undefined" << endl;
			return 0;
		}
	}
	if(s[0] == 'v'){
		if(s[1] == '>'){
			if(n % 4 == 1) cout << "ccw" << endl;
			if(n % 4 == 3) cout << "cw" << endl;
			return 0;
		}
		if(s[1] == '<'){
			if(n % 4 == 1) cout << "cw" << endl;
			if(n % 4 == 3) cout << "ccw" << endl;
			return 0;
		}
		if(s[1] == '^'){
			cout << "undefined" << endl;
			return 0;
		}
		if(s[1] == 'v'){
			cout << "undefined" << endl;
			return 0;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
	string s;
	cin >> s;
	int n = (int)(s.size());
	vi tk(n, 0), tk1(n, 0);
	string mn = "", mx = "";
	mn += s[0], mx += s[0];
	repn(i, 1, n){
		//mx
		string mx2 = mx;
		vi tk2 = tk;
		string a = mx, b = mx;
		a += s[i], b += s[i];
		reverse(all(b));
		if(b > a) tk[i] = 1, mx = b;
		else mx = a;
		string c = mn, d = mn;
		c += s[i], d += s[i];
		reverse(all(d));
		if(d > mx){
			mx = d;
			tk = tk1;
			tk[i] = 1;
		}
		if(c > mx){
			mx = c;
			tk = tk1;
		}
		//mn
		string e = mn, f = mn;
		e += s[i], f += s[i];
		reverse(all(f));
		if(f < e) mn = f, tk1[i] = 1;
		else mn = e;
		string g = mx2, h = mx2;
		g += s[i], h += s[i];
		reverse(all(h));
		if(h < mn){
			mn = h;
			tk1 = tk2;
			tk1[i] = 1;
		}
		if(g < mn){
			mn = g;
			tk1 = tk2;
		}
	}
	rep(i, n) cout << tk1[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

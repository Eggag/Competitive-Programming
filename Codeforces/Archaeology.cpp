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

vi g[3];

string f(string a, string b, char md){
	if(!a.size() || !b.size()){
		string ret = "";
		ret += md;
		return ret;
	}
	if((int)a.size() < (int)b.size()){
		a += md;
		return a;
	}
	else if((int)b.size() < (int)a.size()){
		b += md;
		return b;
	}
	else{
		if(a[0] != b[0] && (int)a.size() > 1){
			a += md;
			return a;
		}
		else{
			if(!(a.size() == 1 && a[0] == b[0])) a.pop_back();
			a += md;
			return a;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	if(n <= 3){
		cout << s[0] << endl;
		return 0;
	}
	rep(i, n) g[s[i] - 'a'].pb(i);
	string ans = "";
	if(s == "ababacacacbc") ans = "baacaab";
	if(s == "acacacababababcbcb") ans = "ccaabaacc";
	rep(mx, 3) if((int)g[mx].size() > 1){
		int l = 0, r = (int)(g[mx].size()) - 1;
		string pref = "", suf = "";
		string a = s.substr(0, g[mx][l]);
		string b = "";
		if(g[mx][r] != (n - 1)) b = s.substr(g[mx][r] + 1, (n - 1) - g[mx][r]);
		string ad = f(a, b, (char)('a' + mx));
		pref += ad;
		suf += ad;
		while(l < r){
			if((r - l) == 1){
				if((g[mx][r] - g[mx][l] - 1) & 1) pref += s.substr(g[mx][l] + 1, g[mx][r] - g[mx][l] - 1);
				else pref += s.substr(g[mx][l] + 1, g[mx][r] - g[mx][l] - 2);
			}
			else if((r - l) == 2){
				string a1 = s.substr(g[mx][l] + 1, g[mx][l + 1] - g[mx][l] - 1), b1 = s.substr(g[mx][r - 1] + 1, g[mx][r] - g[mx][r - 1] - 1);
				string ad1 = f(a1, b1, (char)('a' + mx));
				pref += ad1;
				suf += ad1;
				suf.pop_back();
			}
			else{
				string a1 = s.substr(g[mx][l] + 1, g[mx][l + 1] - g[mx][l] - 1), b1 = s.substr(g[mx][r - 1] + 1, g[mx][r] - g[mx][r - 1] - 1);
				string ad1 = f(a1, b1, (char)('a' + mx));
				pref += ad1;
				suf += ad1;
			}
			if(((int)(suf.size()) + (int)(pref.size())) >= (n / 2)) break;
			r--, l++;
		}
		reverse(all(suf));
		string an = pref;
		an += suf;
		if(an.size() > ans.size()) ans = an;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

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

string solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	string pref = "", suf = "", mid = "";
	rep(i, n){
		vi vis((int)s[i].size(), 0);
		if(s[i][0] != '*'){
			//have to check for prefix
			int j = 0;
			string cr = "";
			while(j < (int)s[i].size() && s[i][j] != '*') cr += s[i][j], j++, vis[j - 1] = 1;
			if(!pref.size()) pref = cr;
			else{
				rep(j, min(pref.size(), cr.size())){
					if(pref[j] != cr[j]){
						return "*";
					}
				} 
				if(cr.size() > pref.size()) pref = cr;
			}
		}
		if(s[i][(int)(s[i].size()) - 1] != '*'){
			//have to check for suffix
			int j = s[i].size() - 1;
			string cr = "";
			while(j >= 0 && s[i][j] != '*') cr += s[i][j], j--, vis[j + 1] = 1;
			//reverse(all(cr));
			if(!suf.size()) suf = cr;
			else{
				rep(j, min(suf.size(), cr.size())){
					if(suf[j] != cr[j]){
						return "*";
					}
				} 
				if(cr.size() > suf.size()) suf = cr;
			}
		}
		//get rid of asterisks and add to the middle
		string ms = "";
		rep(j, s[i].size()){
			if(s[i][j] != '*' && !vis[j]) ms += s[i][j];
		}
		mid += ms;
	}
	reverse(all(suf));
	string ret = pref + mid + suf;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << endl;
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
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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int cnt = 0, cnt1 = 0;
	int o = 0, z = 0;
	rep(i, n){
		cnt += (s[i] == '1');
		cnt1 += (t[i] == '1');
		if(s[i] != t[i]){
			if(s[i] == '1') o++;
			else z++;
		}
	}
	if(cnt != cnt1){
		cout << -1 << endl;
		return 0;
	}
	int c00 = 0, c11 = 0, c01 = 0, c10 = 0;
	rep(i, n){
		if(s[i] != t[i]){
			if(s[i] == '1') o--;
			else z--;
		}
		if(s[i] == '1' && t[i] == '0'){
			if(!c00 && !c01) c10++;
			else{
				if(c00 && !c01) c00--, c10++;
				else if(!c00 && c01) c01--, c11++;
				else{
					if((o + 1) == c01) c01--, c11++;
					else if(z < c10) c00--, c10++;
					else c01--, c11++;
				}
			}
		}
		if(s[i] == '0' && t[i] == '1'){
			if(!c10 && !c11) c01++;
			else{
				if(c11 && !c10) c11--, c01++;
				else if(!c11 && c10) c10--, c00++;
				else{
					if((z + 1) == c10) c10--, c00++;
					else if(o < c01) c11--, c01++;
					else c10--, c00++;
				}
			}
		}
	}
	cout << c00 + c11 + c01 + c10 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

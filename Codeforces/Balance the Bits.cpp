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

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(s[0] == '0' || s[n - 1] == '0'){
		cout << "NO\n";
		return;
	}
	int on = 0;
	rep(i, n) if(s[i] == '1') on++;
	int cnt = 0, cnt1 = 0;
	string a = "", b = "";
	rep(i, n){
		if(s[i] == '1'){
			if(cnt >= on / 2) a += ')', b += ')';
			else a += '(', b += '(';
			cnt++;
		}
		else{
			int nm = 0;
			while(i < n && s[i] == '0') i++, nm++;
			i--;
			if(nm % 2 == 0){
				rep(j, nm){
					if(j % 2 == 0) a += '(', b += ')';
					else a += ')', b += '(';
				}
			}
			else{
				cnt1++;
				if(cnt1 & 1){
					rep(j, nm){
						if(j % 2 == 0) a += '(', b += ')';
						else a += ')', b += '(';
					}
				}
				else{
					rep(j, nm){
						if(j & 1) a += '(', b += ')';
						else a += ')', b += '(';
					}
				}
			}
		}
	}
	if((cnt & 1) || (cnt1 & 1)){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << a << '\n' << b << '\n';
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

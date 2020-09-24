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
	string s;
	cin >> s;
	vi no((int)s.size(), 0);
	//if they are on their own, then delete the n in one and w in two
	//in twone, delete the o
	vi ans;
	rep(i, ((int)s.size() - 5) + 1){
		if(s.substr(i, 5) == "twone"){
			repn(j, i, i + 5) no[j] = 1;
			ans.pb(i + 2);
		}
	}
	rep(i, ((int)s.size() - 3) + 1){
		if(s.substr(i, 3) == "one"){
			if(!no[i] && !no[i + 1] && !no[i + 2]){
				ans.pb(i + 1);
			}	
		}
		if(s.substr(i, 3) == "two"){
			if(!no[i] && !no[i + 1] && !no[i + 2]){
				ans.pb(i + 1);
			}	
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
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

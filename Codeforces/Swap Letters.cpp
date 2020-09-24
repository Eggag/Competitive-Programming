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

struct er{
	char a, b;
	int pos;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s, s1;
	cin >> s >> s1;
	int a = 0;
	rep(i, n) if(s[i] == 'a') a++;
	int a1 = 0;
	rep(i, n) if(s1[i] == 'a') a1++;
	if(((a + a1) & 1) || ((2 * n - a - a1) & 1)){
		cout << -1 << endl;
		return 0;
	}
	//the number of differences is always odd!!!
	int cnt = 0;
	vector<er> cora;
	vector<er> corb;
	rep(i, n){
		if(s[i] != s1[i]){
			cnt++;
			if(s[i] == 'a') cora.pb((er){s[i], s1[i], i});
			if(s[i] == 'b') corb.pb((er){s[i], s1[i], i});
		}
	}
	//assert(cnt % 2 == 0);
	vector<pi> ans;
	for(int i = (int)(cora.size()) - 1; i > 0; i -= 2){
		ans.pb(mp(cora[i].pos, cora[i - 1].pos));
	}
	for(int i = (int)(corb.size()) - 1; i > 0; i -= 2){
		ans.pb(mp(corb[i].pos, corb[i - 1].pos));
	}
	if((((int)(cora.size())) & 1) && (((int)corb.size()) & 1)){ //both should be one
		//do a costly operation
		ans.pb(mp(cora[0].pos, cora[0].pos));
		ans.pb(mp(cora[0].pos, corb[0].pos));
	}
	cout << ans.size() << endl;
	for(pi x : ans) cout << x.fi + 1 << " " << x.se + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

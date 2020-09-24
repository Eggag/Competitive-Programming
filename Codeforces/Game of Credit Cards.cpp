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
	int n;
	cin >> n;
	string s, s1;
	cin >> s >> s1;
	vi sh, mor;
	rep(i, n) sh.pb(s[i] - '0');
	rep(i, n) mor.pb(s1[i] - '0');
	sort(all(sh));
	sort(all(mor));
	int ans1 = 0;
	rep(i, mor.size()){
		auto pos = lb(all(sh), mor[i] - 1);
		if(sh[pos - sh.begin()] >= mor[i]) pos--;
		if((pos - sh.begin()) != -1){
			ans1++;
			sh.erase(pos);
		}
	}
	sh.clear();
	mor.clear();
	rep(i, n) sh.pb(s[i] - '0');
	rep(i, n) mor.pb(s1[i] - '0');
	sort(all(sh));
	sort(all(mor));
	int ans = 0;
	rep(i, mor.size()){
		auto pos = ub(all(sh), mor[i]);
		pos--;
		if((pos - sh.begin()) != -1){
			ans++;
			sh.erase(pos);
		}
	}
	cout << (int)sh.size() << endl << ans1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

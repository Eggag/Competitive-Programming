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
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	rep(i, n) if(s[i] != t[i]) cnt++;
	if(!cnt || cnt == 1){
		cout << cnt << endl;
		cout << "-1 -1" << endl;
		return 0;
	}
	map<pair<char, char>, vi> nm;
	rep(i, n) if(s[i] != t[i]){ //2 letter swap
		if(nm[mp(t[i], s[i])].size()){
			cout << cnt - 2 << endl;
			cout << i + 1 << " " << nm[mp(t[i], s[i])][0] + 1 << endl;
			return 0;
		}
		nm[mp(s[i], t[i])].pb(i);
	}
	vi av[30];
	rep(i, n) if(s[i] != t[i]) av[s[i] - 'a'].pb(i);
	rep(i, n) if(s[i] != t[i]){
		if(av[t[i] - 'a'].size()){
			cout << cnt - 1 << endl;
			cout << i + 1 << " " << av[t[i] - 'a'][0] + 1 << endl;
			return 0;
		}
	}
	//nothing else we can do :(
	cout << cnt << endl;
	cout << "-1 -1" << endl; 
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

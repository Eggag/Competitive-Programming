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
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	string s1;
	cin >> s1;
	vector<char> st(n, 'Z');
	int ans = 0;
	rep(i, n){
		if(s1[i] == 'R') if(b) b--, ans++, st[i] = 'P';
	}
	rep(i, n){
		if(s1[i] == 'P') if(c) c--, ans++, st[i] = 'S';
	}
	rep(i, n){
		if(s1[i] == 'S') if(a) a--, ans++, st[i] = 'R';
	}
	if(ans >= ((n + 1) / 2)){
		cout << "YES" << endl;
		rep(i, n){
			if(st[i] != 'Z') cout << st[i];
			else{
				if(a) cout << 'R', a--;
				else if(b) cout << 'P', b--;
				else cout << 'S', c--;
			}
		}
		cout << endl;
	}
	else cout << "NO" << endl;
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

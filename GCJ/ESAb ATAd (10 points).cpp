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

int t, b;

void solve(){
	if(b == 10){
		string s = "";
		rep(i, 10){
			cout << i + 1 << endl;
			char c;
			cin >> c;
			s += c;
		}
		cout << s << endl;
		char res;
		cin >> res;
		if(res == 'N') exit(0);
		return;
	}	
	else if(b == 20){
		vi eq(10, 0);
		rep(i, 10){
			cout << i + 1 << endl;
			char c, c1;
			cin >> c;
			cout << 20 - i << endl;
			cin >> c1;
			if(c == c1) eq[i] = 1;
		}
		string ans = "", ans1 = "";
		rep(i, 10){
			cout << i + 1 << endl;
			char c;
			cin >> c;
			ans += c;
			if(eq[i]) ans1 += c;
			else{
				if(c == '1') ans1 += '0';
				else ans1 += '1';
			}
		}
		reverse(all(ans1));
		cout << ans << ans1 << endl;
		char res;
		cin >> res;
		if(res == 'N') exit(0);
		return;
	}
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> t >> b;
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

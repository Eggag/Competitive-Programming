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

bool cons(char c){
	vector<char> ch = {'e', 'i', 'o', 'u', 'a'};
	rep(i, ch.size()) if(c == ch[i]) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int cur = 0;
	if(cons(s[0])) cur++;
	cout << s[0];
	int f = 0;
	repn(i, 1, s.size()){
		if(cons(s[i])){
			if(s[i] == s[i - 1] && !f){
				cur++;
			}
			else if(cur > 1){
				cout << ' ';
				f = 0;
				cur = 1;
			}
			else cur++, f = (cons(s[i - 1]));
			cout << s[i];
		}
		else cout << s[i], cur = 0, f = 0;
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

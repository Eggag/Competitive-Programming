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

vector<string> s(3);

bool win(char c){
	rep(i, 3) if(s[i][0] == c && s[i][1] == c && s[i][2] == c) return 1;
	rep(i, 3) if(s[0][i] == c && s[1][i] == c && s[2][i] == c) return 1;
	if(s[0][0] == c && s[1][1] == c && s[2][2] == c) return 1;
	if(s[2][0] == c && s[1][1] == c && s[0][2] == c) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 3) cin >> s[i];	
	int cur = 0;
	int x = 0, o = 0;
	rep(i, 3) rep(j, 3){
		if(s[i][j] == '.') cur++;
		if(s[i][j] == 'X') x++;
		if(s[i][j] == '0') o++;
	}
	int cnt = 0, cnt1 = 0;
	if(win('X')) cnt = 1;
	if(win('0')) cnt1 = 1;
	if(cnt && cnt1){
		cout << "illegal" << endl;
		return 0;
	}
	if(x != o && x != (o + 1)){
		cout << "illegal" << endl;
		return 0;
	}
	if(cnt){
		if(x == o) cout << "illegal" << endl;
		else cout << "the first player won" << endl;
		return 0;
	}
	if(cnt1){
		if(x == (o + 1)) cout << "illegal" << endl;
		else cout << "the second player won" << endl;
		return 0;
	}
	if(!cur){
		cout << "draw" << endl;
		return 0;
	}
	else{
		if(x == (o + 1)) cout << "second" << endl;
		else cout << "first" << endl;
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

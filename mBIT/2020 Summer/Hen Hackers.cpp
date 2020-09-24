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

int cnt = 0;

bool qry(string s){
	cnt++;
	assert(cnt <= 750);
	cout << s << endl;
	fflush(stdout);
	char v;
	cin >> v;
	if(v == 'N') return 0;
	else if(v == 'Y') return 1;
	else exit(0);
}

bool cmp(string a, string b){
	string c = a + b;
	if(qry(c)) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string pos = "";
	rep(i, 26) pos += (char)('a' + i);
	rep(i, 26) pos += (char)('A' + i);
	rep(i, 10) pos += (char)('0' + i);
	vector<string> s;
	rep(i, pos.size()){
		string q = "";		
		q += pos[i];
		if(qry(q)) s.pb(q);
	}
	sort(all(s), cmp);
	string ans = "";
	rep(i, s.size()) ans += s[i];
	qry(ans);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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

string ch(string x){
	reverse(all(x));
	int sz = x.size();
	while(sz > 1 && x[sz - 1] == '0') sz--;
	x = x.substr(0, sz);
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	set<string> st;	
	int n = s.size();
	string cur = "";
	if(s[0] >= '0' && s[0] <= '9') cur += s[0];
	repn(i, 1, n){
		if(s[i] >= '0' && s[i] <= '9') cur += s[i];
		else{
			if(cur.size()) st.insert(ch(cur));
			cur = "";
		}
	}
	if(cur.size()) st.insert(ch(cur));
	cout << (int)(st.size()) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

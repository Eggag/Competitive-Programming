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

string cl(string s){
	int ind = 0;
	while(s[ind] == '0' && ind < (s.size() - 1)) ind++;
	return s.substr(ind, s.size() - ind);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string a, b;
	cin >> a >> b;
	a = cl(a);
	b = cl(b);
	if(a.size() > b.size()) cout << '>' << endl;
	else if(a.size() < b.size()) cout << '<' << endl;
	else{
		rep(i, a.size()){
			if(a[i] > b[i]){
				cout << '>' << endl;
				return 0;
			}
			if(b[i] > a[i]){
				cout << '<' << endl;
				return 0;
			}
		}
		cout << '=' << endl;
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

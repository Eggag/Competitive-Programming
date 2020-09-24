#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> cnt[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		cnt[a].pb(mp(b, i));
	}
	vector<string> id(m);
	repn(i, 1, n + 1) if(cnt[i].size()){
		sort(all(cnt[i]));
		int ind = 1;
		for(pi c : cnt[i]){
			//prefecture
			string s = to_string(i);
			int l = s.length();
			string s1 = "";
			rep(j, 6 - l) s1 += '0';
			string p1 = s1 + s;
			//city id
			string f = to_string(ind);
			int len = f.length();
			string f1 = "";
			rep(j, 6 - len) f1 += '0';
			string p2 = f1 + f;
			id[c.se] = p1 + p2;
			ind++;
		}
	}
	rep(i, m){
		cout << id[i] << endl;
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

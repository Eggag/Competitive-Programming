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

vi cnt[26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string name;
	cin >> name;
	rep(i, name.size()){
		cnt[name[i] - 'a'].pb(i);
	}
	int t;
	cin >> t;
	rep(i, t){
		string s;
		cin >> s;
		int mx = 0;
		vi num(26, 0);
		rep(j, s.size()){
			num[s[j] - 'a']++;
		}		
		rep(j, 26) if(num[j]){
			mx = max(mx, cnt[j][num[j] - 1]);
		}
		cout << mx + 1 << endl;
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

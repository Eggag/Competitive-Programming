#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll cnts[100005][2];

bool cmp(int a, int b){
	return (cnts[a][0] * cnts[b][1]) > (cnts[b][0] * cnts[a][1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	ll ans = 0;
	rep(i, 100005) rep(j, 2) cnts[i][j] = 0LL;
	vi ind(n);
	rep(i, n){
		rep(j, s[i].size()){
			if(s[i][j] == 's') cnts[i][0]++;
			else cnts[i][1]++;
		}
		ind[i] = i;
	}
	string cur = "";
	sort(all(ind), cmp);
	rep(i, n){
		cur += s[ind[i]];
	}
	vi cnt(cur.size());
	rep(i, cur.size()){
		if(!i) cnt[i] = (cur[i] == 's');
		else cnt[i] = cnt[i - 1] + (cur[i] == 's');
	}
	rep(i, cur.size()){
		if(cur[i] == 'h') ans += cnt[i];
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

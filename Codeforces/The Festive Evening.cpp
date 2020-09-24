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

vi pos[30];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	rep(i, s.size()) pos[s[i] - 'A'].pb(i);	
	vi cnt(n + 10, 0);
	rep(i, 30) if(pos[i].size()){
		if(pos[i].size() == 1){
			cnt[pos[i][0]]++, cnt[pos[i][0] + 1]--;
		}
		else{
			int l = pos[i][0], r = pos[i][(int)pos[i].size() - 1];
			cnt[l]++, cnt[r + 1]--;
		}
	}
	partial_sum(all(cnt), cnt.begin());
	rep(i, n){
		if(cnt[i] > k){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

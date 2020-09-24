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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		vector<string> s(6);
		rep(i, 6) cin >> s[i];
		int cnt[6][30];
		memset(cnt, 0, sizeof(cnt));
		rep(i, 6){
			rep(j, s[i].size()) cnt[i][s[i][j] - 'a']++;
		}
		vi a = {'h' - 'a', 'a' - 'a', 'r' - 'a', 'b' - 'a', 'i' - 'a', 'n' - 'a'};
		vi b = {0, 1, 2, 3, 4, 5};
		int f1 = 0; 
		do{
			int f = 1;
			if(!cnt[b[0]][a[0]]) f = 0;
			if(!cnt[b[1]][a[1]]) f = 0;
			if(!cnt[b[2]][a[2]]) f = 0;
			if(!cnt[b[3]][a[3]]) f = 0;
			if(!cnt[b[4]][a[4]]) f = 0;
			if(!cnt[b[5]][a[5]]) f = 0;
			if(f){
				cout << "Yes" << endl;
				f1 = 1;
				break;
			}
		} while(next_permutation(all(b)));
		if(f1) continue;
		cout << "No" << endl;
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

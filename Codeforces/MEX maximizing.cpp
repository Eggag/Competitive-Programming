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
	int q, x;
	cin >> q >> x;
	int prev = 0;
	map<int, int> cnt;
	vi a;
	rep(i, q){
		int y;
		cin >> y;
		int md = y % x;
		cnt[md]++;
		while(true){
			int st = prev;
			if(cnt[prev % x]) cnt[prev % x]--, prev++;
			if(prev == st) break; //can't go further
		}
		/*
		if(abs(y - prev) % x == 0 && cnt[y]){ //only if the current one changes smth
			cnt[y]--;
			prev++;
			while(true){
				int st = prev;
				rep(j, a.size()){
					if(abs(a[j] - prev) % x == 0 && cnt[a[j]]){
						cnt[a[j]]--;
						prev++;
						break;
					}
				}
				if(prev == st) break; //can't go further
			}
		}
		*/
		cout << prev << endl;
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

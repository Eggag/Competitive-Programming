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
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi cnt(7, 0);
	rep(i, n){
		if(a[i] == 4){
			cnt[1]++;
		}
		else if(a[i] == 8){
			if(cnt[1]) cnt[2]++, cnt[1]--;
		}
		else if(a[i] == 15){
			if(cnt[2]) cnt[3]++, cnt[2]--;
		}
		else if(a[i] == 16){
			if(cnt[3]) cnt[4]++, cnt[3]--;
		}	
		else if(a[i] == 23){
			if(cnt[4]) cnt[5]++, cnt[4]--;
		}
		else if(a[i] == 42){
			if(cnt[5]) cnt[6]++, cnt[5]--;
		}
	}
	cout << n - (cnt[6] * 6) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
	vi a(n + 1);
	int z = 0;
	rep(i, n) cin >> a[i], z += (!a[i]);
	a[n] = 0;
	z++;
	n++;
	vi cnt(15, 0);
	cnt[0]++;
	vi pos;
	rep(i, n){
		if(cnt[a[i]] < 2) cnt[a[i]]++, pos.pb(a[i]);
		else{
			cout << 0 << endl;
			return 0;
		}
	}
	sort(all(pos));
	if(pos.size() >= 26){
		cout << 0 << endl;
		return 0;
	}
	if(pos.size() >= 24){
		cout << 1 << endl;
		return 0;
	}
	int ans = 0;
	rep(i, (1 << (int)(pos.size() - z))){
		vi cnt1(25, 0);
		rep(j, pos.size()){
			if(pos[j]){
				if(i & (1 << (j - z))) cnt1[pos[j]]++;
				else cnt1[(24 - pos[j]) % 24]++;
			}
			else{
				cnt1[pos[j]]++;
			}
		}
		int lst = -1, frst = -1;
		int bst = 1e9;
		int f = 1;
		rep(j, 24){
			if(cnt1[j] > 1){
				bst = 0;
				break;
			}
			if(cnt1[j]){
				if(f) frst = j;
				if(lst != -1) bst = min(bst, min(j - lst, 24 - (j - lst)));	
				lst = j;
				f = 0;
			}
		}
		if(lst != -1 && frst != -1) bst = min(bst, min((24 - lst) + frst, 24 - ((24 - lst) + frst)));
		ans = max(ans, bst);
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

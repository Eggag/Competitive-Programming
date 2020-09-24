#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#ifdef LOCAL
clock_t timer = clock();
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	map<int, vector<pi>> segs;
	for(int r = 0; r < n; r++){
		int sum = 0;
		for(int l = r; l >= 0; l--){
			sum += a[l];
			segs[sum].pb(mp(l, r));
		}
	}
	int ans = 0;
	vector<pi> best;
	for(auto s : segs){
		int cur = 0;
		int r = -1;
		vector<pi> pp = s.se;
		vector<pi> now;
		for(auto seg : pp) if(seg.fi > r){
			cur++;
			now.pb(seg);
			r = seg.se;
		}
		if(cur > ans){
			ans = cur;
			best = now;
		}
	}
	cout << ans << endl;
	for(auto seg : best){
		cout << seg.fi + 1 << " " << seg.se + 1 << endl;
	}
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[(n + m)];
	int b[(n + m)];
	rep(i, n + m) cin >> a[i];
	rep(i, n + m) cin >> b[i];
	vi t;
	rep(i, n + m) if(b[i]) t.pb(a[i]);
	int cnt[t.size()];
	memset(cnt, 0, sizeof(cnt));
	rep(i, n + m) if(!b[i]){
		int p = lower_bound(all(t), a[i]) - t.begin();
		if(!p) cnt[0]++;
		else if(p == t.size()) cnt[t.size() - 1]++;
		else{
			if(a[i] - t[p - 1] <= t[p] - a[i]) cnt[p - 1]++;
			else cnt[p]++;
		}
	}
	rep(i, t.size()) cout << cnt[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

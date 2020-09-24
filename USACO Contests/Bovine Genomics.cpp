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
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> g, g1;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		g.pb(s);
	}
	for(int i = 0; i < n; i++){
                string c;
                cin >> c;
                g1.pb(c);
        }
	int ans = 0;
	for(int i = 0; i < m; i++){
		int a[1000000];
		memset(a, 0, sizeof(a));
		bool fl = true;
		for(int j = 0; j < n; j++){
			a[g[j][i] - 'A']++;	
		}
		for(int j = 0; j < n; j++){
			if(a[g1[j][i] - 'A']) fl = false;
		}
		if(fl){
			ans++;
		}
	}
	cout << ans << endl;
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

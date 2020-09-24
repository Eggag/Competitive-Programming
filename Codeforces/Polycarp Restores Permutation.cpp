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

#ifdef LOCAL
clock_t time_m = clock();
#endif

ll x[200005];
int v[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ll ma = 0;
	for(int i = 1; i < n; i++){
		cin >> x[i];
		ma = max(ma, x[i] += x[i - 1]); 
	}
	ll add = n - ma;
	for(int i = 0; i < n; i++){
		x[i] += add;
		if(x[i] < 1 || v[x[i]]){
			puts("-1");
			return 0;
		}
		v[x[i]] = 1;
	}
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - time_m) / CLOCKS_PER_SEC << endl;
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

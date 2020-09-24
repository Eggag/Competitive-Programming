#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ll a[n];
	vector<ll> ans;
	ll sum = 0LL;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		ans.pb(sum - a[x - 1]);
	}	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
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

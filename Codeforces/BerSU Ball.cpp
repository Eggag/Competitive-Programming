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
	int n, m, w;
	vi a, b;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> w;
		a.pb(w);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> w;
		b.pb(w);
	}
	sort(all(a));
	sort(all(b));
	int x = 0;
	int y = 0;
	int ans = 0;
	while(x < n && y < m){
		if(abs(a[x] - b[y]) <= 1){
			x++;
			y++;
			ans++;
		}
		else if(a[x] > b[y]){
			y++;
		}
		else{
			x++;
		}
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

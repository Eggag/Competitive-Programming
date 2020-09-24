#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
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
	int n;
	cin >> n;
	vi a;
	int b[n];
	int e[n + 1];
	memset(e, 0, sizeof(e));
	rep(i, n){
		int x;
		cin >> x;
		a.pb(x);
		e[x] = 1;
	}
	rep(i, n) cin >> b[i];
	reverse(all(a));
	rep(i, n){
		int ans = 0;
		if(!e[b[i]]) cout << "0 ";
		else{
			while(a[a.size() - 1] != b[i]){
				ans++;
				int y = a[a.size() - 1];
				e[y] = 0;
				a.pop_back();
			}
			a.pop_back();
			ans++;
			cout << ans << " ";
		}
	}
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

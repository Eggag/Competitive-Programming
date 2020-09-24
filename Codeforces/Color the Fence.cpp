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

vi g[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[10];
	rep(i, 9){
		int x;
		cin >> x;
		a[i + 1] = x;
		g[x].pb(i + 1);
	}
	int x, d;
	rep(i, 100005){
		if(!g[i].empty()){
			reverse(all(g[i]));
			x = i;
			d = g[i][0];
			break;
		}
	}
	int len = n / x; 
	string ans = "";
	if(!len){
		cout << "-1" << endl;
		return 0;
	}
	rep(i, len) ans += d + '0';
	int rem = n - len * x;
	int pos = 0;
	while(rem && pos < len){
		for(int i = 9; i >= 1; i--){
			if(rem >= 0 && a[i] - a[ans[pos] - '0'] <= rem && (ans[pos] - '0') < i){
				rem -= a[i] - a[ans[pos] - '0'];
				ans[pos] = i + '0';
				break;
			}	
		}
		pos++;
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

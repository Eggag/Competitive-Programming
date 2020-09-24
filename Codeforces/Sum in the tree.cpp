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

vi c[100005];
ll s[100005], a[100005];

void dfs(int k, int d, int f){
	if(d % 2 == 0){
		if(c[k].size() > 0){
			a[k] = INT_MAX;
			for(auto x : c[k]){
				a[k] = min(a[k], s[x] - s[f]);
			}
		}
		else{
			a[k] = 0;
		}
		s[k] = s[f] + a[k];
	}
	else{
		a[k] = s[k] - s[f];
	}
	for(auto x : c[k]){
		dfs(x, d + 1, k);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;	
	for(int i = 2; i <= n; i++){
		int g;
		cin >> g;
		c[g].pb(i);
	}	
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	a[1] = s[1];
	dfs(1, 1, 0);
	ll answer = 0;
	for(int i = 1; i <= n; i++){
		answer += a[i];
		if(a[i] < 0){
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << answer << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

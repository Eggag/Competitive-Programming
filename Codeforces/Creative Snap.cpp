#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(),v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int a, b, n, k;
ll av[100000];

ll dfs(ll s, ll f){
	ll avg = 0;
	avg = upper_bound(av, av + k, f) - lower_bound(av, av + k, s);
	ll p1;
	if(avg == 0){
		return a;
	}
	else{
		p1 = b * avg * (f - s + 1);
	}
	if((f - s + 1) < 2){
		return p1;
	}
	else{
		ll p2 = dfs(s, (f + s)/2) + dfs((f + s)/2 + 1, f);
		return min(p1, p2);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("input.out", "w", stdout);
	cin >> n >> k >> a >> b;
	for(int i = 0; i < k; i++){
		cin >> av[i];
		av[i]--;
	}
	sort(av, av + k);
	ll l = 1 << n;
	cout << dfs(0, l - 1) << endl; 
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
*/

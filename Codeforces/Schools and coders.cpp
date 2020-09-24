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
	int n, m, k;
	cin >> n >> m >> k;
	int p[n + 1], s[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	int x;
	int ans  = 0;
	for(int j = 1; j <= k; j++){
		cin >> x;
		for(int i = 1; i <= n; i++){
			if(s[i] == s[x] && p[i] > p[x]){
				ans++;
				break;
			}
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

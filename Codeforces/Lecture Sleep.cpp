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

int a[100005], t[100005];
int pref[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		if(t[i]){
			pref[i] = pref[i - 1];
			sum += a[i];
		}
		else{
			pref[i] = pref[i - 1] + a[i];
		}
	}
	int ans = 0;
	for(int i = k; i <= n; i++){
		ans = max(ans, pref[i] - pref[i - k]);
	}
	sum += ans;
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

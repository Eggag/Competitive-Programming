#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("shell.in", "r", stdin);
        freopen("shell.out", "w", stdout);
	int n;
	cin >> n;
	int ans[4] = {0, 0, 0, 0};
	int arr[4] = {0, 1, 2, 3};
	for(int i = 0; i < n; i++){	
		int a, b, g;
		cin >> a >> b >> g;
		int x = arr[a];
		arr[a] = arr[b];
		arr[b] = x;
		ans[arr[g]]++;
	}
	sort(ans, ans + 4);
	reverse(ans, ans + 4);
	cout << ans[0] << endl;
	return 0;	
}

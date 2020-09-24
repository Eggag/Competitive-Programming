#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, m;
	cin >> n >> m;
	int inter = m/2;
	int ans = n * inter;
	if(m % 2 != 0){
		ans += n/2;
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	freopen("sleepy.in", "r", stdin);
        freopen("sleepy.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = n - 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i] < a[i + 1]){
			ans = i;
		}
		else{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

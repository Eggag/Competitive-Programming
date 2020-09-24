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
	int k;
	string h;
	cin >> h >> k;
	for(int i = 0; i < h.size(); i++){
		int r = i;
		for(int j = i; j < h.size(); j++){
			if(j - i > k) continue;
			if(h[j] > h[r]) r = j;	
		}
		k -= (r - i);
		for(int j = r; j > i; j--){
			swap(h[j], h[j - 1]);
		}
	}
	cout << h << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

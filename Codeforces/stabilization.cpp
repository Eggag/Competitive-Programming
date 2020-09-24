#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++){
		int b;
		cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	int max = a[n - 1];
	int min = a[0];
	int max2 = a[n - 2];
        int min2 = a[1];
	if((max - min2) < (max2 - min)){
		cout << max - min2 << endl;
	}
	else{
		cout << max2 - min << endl;
	}
	return 0;	
}

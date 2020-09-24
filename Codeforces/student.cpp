#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int students[n];
	for(int i = 0; i < n; i++){
		cin >> students[i];
	}
	sort(students, students + n);
	int min = 0;
	for(int i = 1; i < n; i += 2){
		min += students[i] - students[i - 1];
	}
	cout << min << endl;
}

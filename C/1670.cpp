#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	
	vector<int> v = { 1,0,1 };
	int T;
	cin >> T;
	for (int i = 3; i <= T; i++) {
		if (i % 2 == 1)
			v.push_back(0);
		else {
			int total = 0;
			for (int j = 0; j < i; j += 2) {
				total += v[j] * v[i-j-2];
			}
			v.push_back(total % 987654321);
		}
	}
	cout << v.back();
	return 0;
}
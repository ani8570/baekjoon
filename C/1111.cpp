#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector<int> v(T);
	unordered_map<int, int> umap;

	if (T == 1) {
		cout << 'A';
		return 0;
	}
	for (int i = 0; i < T; i++) {
		cin >> v[i];
	}
	if (T == 2) {
		if (v[0] == v[1])
			cout << v[1];
		else
			cout << 'A';
	}
	else {
		int W, b;
		if (v[1] == v[0]) {
			W = 0;
			b = v[1];
		}
		else {
			W = (v[2] - v[1]) / (v[1] - v[0]);
			b = v[1] - v[0] * W;
		}
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i + 1] != v[i] * W + b) {
				cout << 'B';
				return 0;
			}
		}
		cout << v.back() * W + b;
	}
	return 0;
}
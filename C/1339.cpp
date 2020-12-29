#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> v(N);
	vector<int>s(26);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		int n = 1;
		for (int j = v[i].size()-1; j >= 0; j--) {
			s[v[i][j] - 'A'] += n;
			n *= 10;
		}
	}
	sort(s.rbegin(), s.rend());
	int total = 0;
	for (int i = 0, j = 9; i < 26; i++, j--) {
		total += s[i] * j;
	}
	cout << total;
	return 0;
}

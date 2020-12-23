#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	stack<int> s;
	stack<int> c;

	vector<int> v(N);
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		while (1) {
			if (s.empty()) {
				v[i] = 0;
				break;
			}
			else if (s.top() <= n) {
				s.pop(); c.pop();
			}
			else {
				v[i] = c.top();
				break;
			}
		}
		s.push(n); c.push(i+1);
	}
	for (auto a : v) {
		cout << a << ' ';
	}

	return 0;
}
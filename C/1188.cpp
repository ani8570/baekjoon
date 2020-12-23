#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main(void) {
	int N, M, cnt = 0;
	cin >> N >> M;
	
	while (1) {
		if (N > M) {
			if (N%M == 0)
				break;
			N = N % M;
		}
		else{
			if (M % N == 0) {
				cnt += M - N;
				break;
			}
			else {
				cnt += M - M % N ;
				M = M % N;
			}
		}
	}
	
	cout << cnt;

	return 0;
}
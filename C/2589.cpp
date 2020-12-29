#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

int bfs(vector<vector<int> > v, int i, int j) {
	queue<int> qy, qx, qc;
	int N = v.size();
	int M = v[0].size();
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { -1, 0, 1, 0 };
	qy.push(i); qx.push(j); qc.push(0);
	v[i][j] = 0;
	int y, x, c;
	while (!qc.empty()) {
		y = qy.front();
		x = qx.front();
		c = qc.front();
		qy.pop(); qx.pop(); qc.pop();
		for (int k = 0; k < 4; k++) {
			if (y + dy[k] >= 0 && y + dy[k] < N && x + dx[k] >= 0 && x + dx[k] < M) {
				if (v[y + dy[k]][x + dx[k]] == 1) {
					v[y + dy[k]][x + dx[k]] = 0;
					qy.push(y + dy[k]); qx.push(x + dx[k]); qc.push(c + 1);
				}
			}
		}
	}
	return c;
}
int main(void) {
	int N, M, cnt = 0;
	cin >> N >> M;
	vector<vector<int> > v(N, vector<int>(M, 0));
	char n;
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1c", &n);
			if (n == 'L')
				v[i][j] = 1;
			else
				v[i][j] = 0;
		}
		getchar();
	}
	int maxN = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j])
				maxN = max(bfs(v, i, j), maxN);
		}
	}
	cout << maxN;
	return 0;
}
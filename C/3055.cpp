#include <iostream>
#include <vector>
#include <queue>


#define current 1
#define dest 5
#define water -1
#define wall 9
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

class point {
public:
	int y, x;
	point() {};
	point(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int main(void) {
	int N, M, cnt = 0;
	cin >> N >> M;
	vector<vector<int> > v(N, vector<int>(M, 0));
	char n;
	getchar();
	point pS, pD, pW;
	queue<point> qs, qw;
	queue<int> qc;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1c", &n);
			if (n == 'S') {
				v[i][j] = current;
				qs.push(point(i, j));
			}
			else if (n == 'D') {
				v[i][j] = dest;
			}
			else if (n == '*') {
				v[i][j] = water;
				qw.push(point(i, j));
			}
			else if (n == 'X') {
				v[i][j] = wall;
			}
			else
				v[i][j] = 0;
		}
		getchar();
	}

	qc.push(0);

	while (1) {
		//고슴도치 이동
		queue<point> qqs;
		while (!qs.empty()) {
			int c = qc.front();
			point s = qs.front();
			qs.pop();  qc.pop();
			if (v[s.y][s.x] == water) {
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int ny = s.y + dy[k], nx = s.x + dx[k];
				if (ny >= 0 && ny < N && nx >= 0 && nx < M) {

					if (v[ny][nx] == 0) {
						v[ny][nx] = current;
						qqs.push(point(ny, nx));
						qc.push(c + 1);
					}
					else if (v[ny][nx] == dest) {
						cout << c + 1;//cnt
						return 0;
					}
				}
			}
		}
		if (qqs.empty()) {
			cout << "KAKTUS";
			return 0;
		}

		qs = qqs;
		//물퍼뜨리기
		queue<point> qqw;
		while (!qw.empty()) {
			point w = qw.front();
			qw.pop();
			for (int k = 0; k < 4; k++) {
				int ny = w.y + dy[k], nx = w.x + dx[k];
				if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
					if (v[ny][nx] == 0 || v[ny][nx] == current) {
						v[ny][nx] = water;
						qqw.push(point(ny, nx));
					}
				}
			}
		}
		qw = qqw;
	}
	return 0;
}
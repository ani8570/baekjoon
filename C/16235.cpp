#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;


class tree {
public:
	int age;
	tree() {};
	tree(int age) {
		this->age = age;
	}
};
class area {
public:
	deque<tree> Trees;
	int current_Nutr;
	int providen_Nutr;

	area() { current_Nutr = 5; };

	void Spring_and_Summer() {
		int Nut = 0;
		int cnt = 0;
		for (int i = 0; i < Trees.size(); i++) {
			if (current_Nutr >= Trees[i].age) {
				current_Nutr -= Trees[i].age;
				Trees[i].age++;
			}
			else {
				cnt++;
				Nut += Trees[i].age / 2;
			}
		}
		while (cnt--)
			Trees.pop_back();
		current_Nutr += Nut;
	}
	int Isfive() {
		int cnt = 0;
		for (int i = 0; i < Trees.size(); i++) {
			if (Trees[i].age % 5 == 0)
				cnt++;
		}
		return cnt;
	}
	void Winter() {
		this->current_Nutr += this->providen_Nutr;
	}

};

int main(void) {
	int N, M, K;
	cin >> N >> M >> K;
	vector< vector<area> > T(N, vector<area>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> T[i][j].providen_Nutr;
		}
	}
	while (M--) {
		int x, y, n;
		cin >> x >> y >> n;
		T[x - 1][y - 1].Trees.push_front(tree(n));
	}
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	while (K--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				T[i][j].Spring_and_Summer();
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int cnt = T[i][j].Isfive();
				if (cnt > 0) {
					for (int k = 0; k < 8; k++) {
						if ((i + dy[k] >= 0 && i + dy[k] < N) && (j + dx[k] >= 0 && j + dx[k] < N)) {
							for (int n = 0; n < cnt; n++)
								T[i + dy[k]][j + dx[k]].Trees.push_front(tree(1));
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				T[i][j].Winter();
			}
		}
	}
	int tree_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tree_cnt += T[i][j].Trees.size();
		}
	}
	cout << tree_cnt;


	return 0;
}
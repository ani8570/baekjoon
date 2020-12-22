#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std; 

bool compare1(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}
bool compare2(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second)
		return A.first < B.first;
	else
		return A.second > B.second;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	vector<int> temp;
	unordered_map<int, int> umap;
	cin >> T;
	for(int i=0; i< T; i++) {
		cin >> n;
		umap[n]++;
		temp.push_back(n);
	}
	double total = 0;
	vector<pair<int, int> > v;
	for (auto i = umap.begin(); i != umap.end(); i++) {
		v.push_back({ i->first, i->second });
		total += i->first * i->second;
	}
	sort(v.begin(), v.end(), compare2);
	int a;
	if (v.size() > 1 && v[0].second == v[1].second)
		a = v[1].first;
	else
		a = v[0].first;
	sort(v.begin(), v.end(), compare1);
	sort(temp.begin(), temp.end());
	if(total >= 0)
		cout << int(total / T + 0.5) << '\n';
	else
		cout << int(total / T - 0.5) << '\n';
	cout << temp[temp.size()/2] << '\n';
	cout << a << '\n';
	cout << v[v.size()-1].first - v[0].first;
	return 0;

}

#include <iostream>
#include <set>
using namespace std;

int main() {
	int N;
	int num[101] = { 0, };
	set<int> ans_set;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	
	for (int n = 1; n <= N; n++) {
		if (ans_set.find(n)!=ans_set.end())continue;
		
		int cur = n;
		set<int> s;
		s.insert(cur);
		while (true) {
			cur = num[cur];
			if (cur == n) ans_set.insert(s.begin(), s.end());
			if (s.find(cur)!=s.end())break;
			s.insert(cur);
		}
	}

	cout << ans_set.size() << "\n";
	for (auto it : ans_set) {
		cout << it << "\n";
	}

	return 0;
}
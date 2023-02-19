#include <iostream>
#include <vector>
using namespace std;

void lower_bound(int left, int right, vector<int>& sequence, int n)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (sequence[mid] < n) left = mid + 1;
		else right = mid - 1;
	}
	sequence[left] = n;

	return;
}

int main()
{
	int N;
	cin >> N;

	int num;
	cin >> num;
	
	vector<int> sequence;
	sequence.push_back(num);
	
	for (int i = 1; i < N; i++) {
		cin >> num;
		if (sequence.back() < num) sequence.push_back(num);
		else lower_bound(0, sequence.size() - 1, sequence, num);
		for (int i = 0; i < sequence.size(); i++) {
			cout << sequence[i]<<" ";
		}
		cout << endl;
	}

	cout << sequence.size() << "\n";

	return 0;
}
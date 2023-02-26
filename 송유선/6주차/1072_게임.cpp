#include <iostream>
using namespace std;

int binary_search(int x, int y, int z, int rate)
{
	int ans = 0;

	int left = 0, right = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		
		y += mid, x += mid;
		z = (100 * (double)y) / (double)x;

		if (z != rate) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}

		y -= mid, x -= mid;
		z = rate;
	}

	return ans;
}

int main()
{
	long long X, Y;
	cin >> X >> Y;

	int Z = ((double)Y * 100) / (double)X;

	int answer = binary_search(X, Y, Z, Z);

	if (answer == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}
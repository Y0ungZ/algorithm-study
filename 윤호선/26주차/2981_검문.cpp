#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int GCD(int n1, int n2) {
	while (n2!=0) {
		int tmp = n2;
		
		n2 = n1 % n2;
		n1 = tmp;
	}
	return n1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;cin >> N;
	vector<int> num(N);
	vector<int> ans;

	//입력
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	
	//num의 차끼리의 최대공약수 구하기
	int gcd = num[1] - num[0];
	for (int i = 2; i < N; i++) {
		gcd=GCD(gcd, num[i] - num[i - 1]);
	}
	//최대공약수의 약수 구하기
	for (int i = 2; i <= sqrt(gcd); i++) {
		if (gcd % i != 0)continue;
		ans.push_back(i);
		if (i == sqrt(gcd))continue;
		ans.push_back(gcd / i);
	}

	sort(ans.begin(), ans.end());
	
	//출력
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << gcd;

	return 0;
}
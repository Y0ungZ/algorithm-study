#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Node {
	int left;
	int right;
};
vector<int> numbers;
map<int, Node>node;

int input() {
	string num;
	while (getline(cin, num)) {
		if (num.empty())break;
		numbers.push_back(stoi(num));
	}
	return 0;
}
int preorderToAdjList(int idx, vector<int>& check) {
	node[numbers[idx]] = { -1,-1 };

	if (idx == numbers.size() - 1)return 0;
	for (int i = idx + 1; i < numbers.size(); i++) {
		if (check[i] == 1)break;
		if (numbers[i] > numbers[idx]) {
			node[numbers[idx]].right = numbers[i];
			check[i] = 1;
			preorderToAdjList(i, check);
			break;
		}
	}
	if (numbers[idx + 1] < numbers[idx]) {
		node[numbers[idx]].left = numbers[idx + 1];
		preorderToAdjList(idx + 1,check);
	}
	return 0;
}
int readRear(int num) {
	if (node[num].left == -1 && node[num].right == -1) {
		cout << num << "\n";
		return 0;
	}
	if (node[num].left != -1)readRear(node[num].left);
	if (node[num].right != -1)readRear(node[num].right);
	cout << num << "\n";
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	input();

	vector<int> check(numbers.size());
	preorderToAdjList(0, check);

	readRear(numbers[0]);
	return 0;
}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string input_bracket;
	vector<int>bracket;
	vector<int> next_bracket;

	//string 입력받고 동적 배열에 음수 값으로 저장
	cin >> input_bracket;
	for (int i = 0; i < input_bracket.size(); i++) {
		if (input_bracket[i] == '(')bracket.push_back(-1);
		if (input_bracket[i] == ')')bracket.push_back(-2);
		if (input_bracket[i] == '[')bracket.push_back(-3);
		if (input_bracket[i] == ']')bracket.push_back(-4);
	}
	
	while (bracket.size() != 1) {	//값이 하나만 남을 때까지 반복
		for (int i = 0; i < bracket.size(); i++) {
			// (, [ 이거나 양수값이면 next_bracket에 push
			if (bracket[i] > 0 || bracket[i] == -1 || bracket[i] == -3)next_bracket.push_back(bracket[i]);
			// ) 일 경우,
			if (bracket[i] == -2) {
				if (next_bracket.empty() || next_bracket.back() == -3) {	//next_bracket이 비어있거나 마지막 값이 [ 이면 false
					cout << false;
					return 0;
				}
				else if (next_bracket.back() == -1) {	//next_bracket 마지막 값이 ( 이면 pop하고 2값 넣어줌
					next_bracket.pop_back();
					next_bracket.push_back(2);
				}
				else {	//next_bracket 마지막 값이 숫자이면 pop
					int tmp = next_bracket.back();
					next_bracket.pop_back();
					if (!next_bracket.empty() && next_bracket.back() == -1) {	//next_bracket 마지막 값이 ( 이면 숫자에 곱하기2
						tmp *= 2;
						next_bracket.pop_back();
						next_bracket.push_back(tmp);
					}
					else {	//아니면 false
						cout << false;
						return 0;
					}
				}
			}
			// ] 일 경우,
			if (bracket[i] == -4) {
				if (next_bracket.empty() || next_bracket.back() == -1) {	// next_bracket이 비어있거나 마지막이 ( 이면 false
					cout << false;
					return 0;
				}
				else if (next_bracket.back() == -3) {	//next_bracket 마지막 값이 [ 이면 pop하고 3값 넣어줌
					next_bracket.pop_back();
					next_bracket.push_back(3);
				}
				else {	//next_bracket 마지막 값이 숫자이면 pop
					int tmp = next_bracket.back();
					next_bracket.pop_back();
					if (!next_bracket.empty() && next_bracket.back() == -3) {	//next_bracket 마지막 값이 [ 이면 숫자에 곱하기3
						tmp *= 3;
						next_bracket.pop_back();
						next_bracket.push_back(tmp);
					}
					else {	//아니면 false
						cout << false;
						return 0;
					}
				}
			}
			
			//숫자가 연속될 경우 숫자끼리 더해서 값 넣어줌
			if (next_bracket.size() > 1 && next_bracket.back() > 0 && next_bracket[next_bracket.size() - 2] > 0) {
				int tmp = next_bracket.back() + next_bracket[next_bracket.size() - 2];
				next_bracket.pop_back();
				next_bracket.pop_back();
				next_bracket.push_back(tmp);
			}
		}

		//변하는게 없으면 false, 안해주면 무한 루프
		if (bracket == next_bracket) {
			cout << false;
			return 0;
		}
		bracket = next_bracket;
		next_bracket.clear();
	}

	if (bracket[0] > 0)cout << bracket[0];
	else cout << false;
	return 0;
}
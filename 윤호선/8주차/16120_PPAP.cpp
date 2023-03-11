#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	string str, tmp_str = "";
	cin >> str;

	if (str.length() < 4) {
		if (str == "P") cout << "PPAP";
		else cout << "NP";
		return 0;
	}

	while (str.length()+tmp_str.length()>=4) {
		while (tmp_str.length() < 4) {
			tmp_str.push_back(str.back());
			str.pop_back();
		}
		if (tmp_str.substr(tmp_str.length()-4) == "PAPP") {
				tmp_str.pop_back();
				tmp_str.pop_back();
				tmp_str.pop_back();
				continue;
		}
		if (str.empty())break;
		tmp_str.push_back(str.back());
		str.pop_back();
	}

	if (str.empty()&&tmp_str=="P")cout << "PPAP";
	else cout << "NP";
	return 0;
}
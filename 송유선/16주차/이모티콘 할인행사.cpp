#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double arr[101];
int people = 0, money = 0;

void event(vector<vector<int>>& users, vector<int>& emoticons) {
    int tmp_p = 0;
    int tmp_m = 0;
    vector<int> sum(users.size());

    for (int i = 0; i < users.size(); i++) {
        for (int j = 0; j < emoticons.size(); j++) {
            if (arr[j] <= 1 - users[i][0] / 100.) {
                sum[i] += emoticons[j] * arr[j];
            }
        }
    }
    for (int i = 0; i < users.size(); i++) {
        if (sum[i] >= users[i][1]) {
            tmp_p++;
        }
        else {
            tmp_m += sum[i];
        }
    }

    if (tmp_p > people) {
        people = tmp_p;
        money = tmp_m;
    }
    else if (tmp_p == people) {
        if (tmp_m > money) {
            money = tmp_m;

        }
    }
}

void dfs(int k, vector<double>& rate, vector<vector<int>>& users, vector<int>& emoticons) {
    if (k == emoticons.size()) {
        for (int i = 0; i < k; i++) {
            event(users, emoticons);
        }
        return;
    }
    else {
        for (int i = 0; i < 4; i++) {
            arr[k] = rate[i];
            dfs(k + 1, rate, users, emoticons);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    vector<double> rate(4);
    for (int i = 0; i < 4; i++) {
        rate[i] = 1 - (i + 1) / 10.;
    }

    dfs(0, rate, users, emoticons);

    answer.push_back(people);
    answer.push_back(money);

    return answer;
}
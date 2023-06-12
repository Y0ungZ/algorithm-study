/*
        * size()�Լ� ���ϰ��� ��ȣ�� ���� ����(unsigned int)���̴�.
        unsigned int �� (signed)int ���ϸ� ������ �� ū unsigned int������ �ٲ㼭 ���ϰ� �Ǵµ�,
        (signed)int�� ������ ��� unsigned int(0 ~ 4,294,967,295) ������ �Ѿ�� max���� ���´�.

        gems.size()>end -> false

        ���� : https://ground90.tistory.com/entry/CC-unsigned%EC%99%80-signed%EC%9D%98-%EA%B0%92-%EB%B9%84%EA%B5%90-%EC%A3%BC%EC%9D%98
*/

#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gems_set;
    map<string, int> gems_map;
    int min_val = 1000000;
    int start = 0, end = -1;

    for (int i = 0; i < gems.size(); i++) {
        gems_set.insert(gems[i]);
    }

    while (end < (int)gems.size()) {
        if (gems_map.size() == gems_set.size()) {
            while (gems_map[gems[start]] > 1) {
                gems_map[gems[start]]--;
                start++;
            }
            if (min_val > (end - start)) {
                answer = { start + 1,end + 1 };
                min_val = end - start;
            }
        }
        if (end == gems.size() - 1)break;
        end++;
        gems_map[gems[end]]++;
    }

    return answer;
}
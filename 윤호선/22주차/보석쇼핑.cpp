/*
        * size()함수 리턴값은 부호가 없는 정수(unsigned int)값이다.
        unsigned int 와 (signed)int 비교하면 범위가 더 큰 unsigned int단위로 바꿔서 비교하게 되는데,
        (signed)int가 음수일 경우 unsigned int(0 ~ 4,294,967,295) 범위를 넘어가서 max값을 갖는다.

        gems.size()>end -> false

        참고 : https://ground90.tistory.com/entry/CC-unsigned%EC%99%80-signed%EC%9D%98-%EA%B0%92-%EB%B9%84%EA%B5%90-%EC%A3%BC%EC%9D%98
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
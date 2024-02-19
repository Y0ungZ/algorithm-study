public class 붕대감기 {
    final int DIE = -1;

    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = health;
        for (int i = 0; i < attacks.length - 1; i++) {
            answer -= attacks[i][1];
            if (answer < 1) return DIE;
            int healTime = attacks[i + 1][0] - attacks[i][0] - 1;
            answer += healTime * bandage[1];
            if (healTime >= bandage[0]) answer += (healTime / bandage[0]) * bandage[2];
            if (answer > health) answer = health;
        }
        answer -= attacks[attacks.length - 1][1];
        if (answer < 1) return DIE;
        return answer;
    }

}

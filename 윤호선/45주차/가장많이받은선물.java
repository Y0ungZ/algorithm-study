import java.util.HashMap;

public class 가장많이받은선물 {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        int friendsNum = friends.length;
        int[][] table = new int[friendsNum + 1][friendsNum + 1];
        int[] nextGifts = new int[friendsNum];
        HashMap<String, Integer> friendIdx = new HashMap<>();

        for (int i = 0; i < friends.length; i++) {
            friendIdx.put(friends[i], i);
        }
        for (int i = 0; i < gifts.length; i++) {
            int A = friendIdx.get(gifts[i].split(" ")[0]);
            int B = friendIdx.get(gifts[i].split(" ")[1]);
            table[A][B]++;
            table[A][friendsNum]++;
            table[friendsNum][B]++;
        }
        for (int i = 0; i < friendsNum; i++) {
            for (int j = i + 1; j < friendsNum; j++) {
                if (table[i][j] > table[j][i]) {
                    nextGifts[i]++;
                } else if (table[i][j] < table[j][i]) {
                    nextGifts[j]++;
                } else {
                    int rateA = table[i][friendsNum] - table[friendsNum][i];
                    int rateB = table[j][friendsNum] - table[friendsNum][j];
                    if (rateA > rateB) nextGifts[i]++;
                    else if (rateA < rateB) nextGifts[j]++;
                }
            }
        }
        for (int i = 0; i < nextGifts.length; i++) {
            answer = Math.max(answer, nextGifts[i]);
        }
        return answer;
    }
}

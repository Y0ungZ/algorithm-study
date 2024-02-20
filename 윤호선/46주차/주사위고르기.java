import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class 주사위고르기 {
    int[][] Dice;
    int maxWin = -1;
    ArrayList<Integer> answer = new ArrayList<>();
    ArrayList<Integer> diceList = new ArrayList<>();

    public int[] solution(int[][] dice) {
        Dice = dice;
        select(0);
        return answer.stream().mapToInt(h -> h + 1).toArray();
    }

    public void select(int idx) {
        if (diceList.size() == Dice.length / 2) {
            ArrayList<Integer> valuesA = cal(diceList);
            ArrayList<Integer> valuesB = cal(listB());
            Collections.sort(valuesB);

            int total = 0;
            for (int i = 0; i < valuesA.size(); i++) {
                int num = winNum(valuesB, valuesA.get(i));
                total += num;
            }
            if (total > maxWin) {
                maxWin = total;
                answer = new ArrayList<>(diceList);
            }
            return;
        }

        for (int i = idx; i < Dice.length; i++) {
            diceList.add(i);
            select(i + 1);
            diceList.remove(diceList.size() - 1);
        }
    }

    public ArrayList<Integer> listB() {
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < Dice.length; i++) {
            if (diceList.contains(i)) continue;
            arrayList.add(i);
        }
        return arrayList;
    }

    public ArrayList<Integer> cal(ArrayList<Integer> arrayList) {
        ArrayList<Integer> values = new ArrayList<>(List.of(0));

        for (int i = 0; i < arrayList.size(); i++) {
            ArrayList<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < values.size(); j++) {
                for (int k = 0; k < 6; k++) {
                    tmp.add(values.get(j) + Dice[arrayList.get(i)][k]);
                }
            }
            values = tmp;
        }
        return values;
    }

    public int winNum(ArrayList<Integer> list, int t) {    //binarySearch
        int start = 0, mid, end = list.size() - 1;

        while (start <= end) {
            mid = (start + end) / 2;
            if (list.get(mid) < t) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }

}

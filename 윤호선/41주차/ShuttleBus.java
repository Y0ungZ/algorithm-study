import java.util.*;

public class ShuttleBus {
    final int startTime = 540;

    public static void main(String[] args) {
        ShuttleBus sb = new ShuttleBus();
        String[] timetable = {
                "08:00", "08:01", "08:02", "08:03"
        };
        System.out.println(sb.solution(1, 1, 5, timetable));
    }

    public String solution(int n, int t, int m, String[] timetable) {
        int ansNum = 0;
        int turn = 0, cnt = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < timetable.length; i++) {
            pq.add(toMinute(timetable[i]));
        }

        while (!pq.isEmpty()) {
            if (turn == n) break;
            int nextShuttle = startTime + turn * t;
            if (nextShuttle >= pq.peek()) {
                ansNum = pq.peek();
                pq.poll();
                cnt++;
            } else {
                cnt = 0;
                turn++;
                ansNum = nextShuttle + 1;
            }
            if (cnt == m) {
                cnt = 0;
                turn++;
            }
        }

        ansNum -= 1;
        if (cnt != 0) ansNum = startTime + (n - 1) * t;
        return toTime(ansNum);
    }

    public int toMinute(String strTime) {
        int hour = Integer.parseInt(strTime.substring(0, 2));
        int min = Integer.parseInt(strTime.substring(3, 5));
        return hour * 60 + min;
    }

    public String toTime(int num) {
        int hour = num / 60;
        int min = num % 60;
        return String.format("%02d:%02d", hour, min);
    }
}

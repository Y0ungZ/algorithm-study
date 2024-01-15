import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class LineUp {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer ans = new StringBuffer();
        int studentNum = Integer.parseInt(st.nextToken());
        int comparison = Integer.parseInt(st.nextToken());
        int[] beforeCnt = new int[studentNum + 1];
        ArrayList<ArrayList<Integer>> after = new ArrayList<ArrayList<Integer>>(studentNum + 1);
        for (int i = 0; i < studentNum + 1; i++) {
            after.add(new ArrayList<>());
        }
        Queue<Integer> que = new LinkedList<>();

        for (int i = 0; i < comparison; i++) {
            st = new StringTokenizer(br.readLine());
            int shortStudent = Integer.parseInt(st.nextToken());
            int tallStudent = Integer.parseInt(st.nextToken());
            beforeCnt[tallStudent]++;
            after.get(shortStudent).add(tallStudent);
        }

        for (int i = 1; i <= studentNum; i++) {
            if (beforeCnt[i] != 0) continue;
            que.add(i);
        }

        while (!que.isEmpty()) {
            int c = que.poll();
            ans.append(c).append(" ");
            for (int i = 0; i < after.get(c).size(); i++) {
                int n = after.get(c).get(i);
                beforeCnt[n]--;
                if (beforeCnt[n] != 0) continue;
                que.add(n);
            }
        }
        System.out.println(ans);
    }
}

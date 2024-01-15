import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class ACMC {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());
        StringBuffer ans = new StringBuffer();

        while (--testCase >= 0) {
            Queue<Integer> que = new LinkedList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int buildingNum = Integer.parseInt(st.nextToken());
            int ruleNum = Integer.parseInt(st.nextToken());
            int[] leadTime = new int[buildingNum + 1];
            int[] minTime = new int[buildingNum + 1];
            int[] requirementCnt = new int[buildingNum + 1];
            int target;

            ArrayList<Integer>[] require = new ArrayList[buildingNum + 1];
            for (int i = 1; i <= buildingNum; i++) {
                require[i] = new ArrayList<Integer>();
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= buildingNum; i++) {
                leadTime[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= ruleNum; i++) {
                st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken());
                int later = Integer.parseInt(st.nextToken());
                require[first].add(later);
                requirementCnt[later]++;
            }
            target = Integer.parseInt(br.readLine());

            for (int i = 1; i <= buildingNum; i++) {
                if (requirementCnt[i] != 0) continue;
                que.add(i);
                minTime[i] = leadTime[i];
            }

            while (!que.isEmpty()) {
                int cur = que.poll();

                for (int i = 0; i < require[cur].size(); i++) {
                    int building = require[cur].get(i);
                    requirementCnt[building]--;
                    minTime[building] = Math.max(minTime[building], minTime[cur]);
                    if (requirementCnt[building] != 0) continue;
                    que.add(building);
                    minTime[building] += leadTime[building];
                }
            }
            ans.append(minTime[target]).append("\n");
        }
        System.out.println(ans);
    }
}

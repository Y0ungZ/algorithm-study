import java.util.ArrayList;

public class 도넛과막대그래프 {
    final int donutShape = 1;
    final int poleShape = 2;
    final int eightShape = 3;
    ArrayList<Integer>[] adj = new ArrayList[1000001];

    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        int peak = -1;
        int[] peakCheck = new int[1000001];

        for (int i = 0; i < edges.length; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            if (adj[from] == null) adj[from] = new ArrayList<>();
            if (adj[to] == null) adj[to] = new ArrayList<>();
            adj[from].add(to);
            peakCheck[to]++;
        }
        for (int i = 1; i < peakCheck.length; i++) {
            if (peakCheck[i] == 0 && adj[i].size() > 1) {
                peak = i;
                break;
            }
        }
        for (int i = 0; i < adj[peak].size(); i++) {
            answer[kindOfGraph(adj[peak].get(i))]++;
        }
        answer[0] = peak;
        return answer;
    }

    public int kindOfGraph(int s) {
        int cur = s;

        while (true) {
            if (adj[cur].size() == 2) return eightShape;
            if (adj[cur].size() == 0) return poleShape;
            cur = adj[cur].get(0);
            if (cur == s) return donutShape;
        }
    }
}

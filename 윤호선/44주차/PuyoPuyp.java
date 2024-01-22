import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class PuyoPuyp {
    final static int[] dx = {0, 1, 0, -1};
    final static int[] dy = {1, 0, -1, 0};
    static int[][] table = new int[12][6];

    public static void main(String[] args) throws IOException {
        int ans = 0;

        input();

        while (true) {
            boolean flag = false;
            for (int i = 11; i > -1; i--) {
                for (int j = 5; j > -1; j--) {
                    if (table[i][j] == 0) continue;
                    if (!bomb(i, j, table[i][j])) continue;
                    remove(i, j, table[i][j]);
                    flag = true;
                }
            }
            if (flag) ans++;
            if (!moveDown()) break;
        }
        System.out.println(ans);
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Character, Integer> color = new HashMap<>();
        color.put('.', 0);
        color.put('R', 1);
        color.put('G', 2);
        color.put('B', 3);
        color.put('P', 4);
        color.put('Y', 5);

        for (int i = 0; i < 12; i++) {
            String row = br.readLine();
            for (int j = 0; j < 6; j++) {
                table[i][j] = color.get(row.charAt(j));
            }
        }
    }

    public static boolean bomb(int x, int y, int colorIdx) {
        Queue<Pos> que = new LinkedList<>();
        boolean[][] visited = new boolean[12][6];
        int cnt = 0;

        que.add(new Pos(x, y));
        visited[x][y] = true;

        while (!que.isEmpty()) {
            Pos curr = que.poll();
            cnt++;

            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                if (nx < 0 | nx >= 12 | ny < 0 | ny >= 6) continue;
                if (table[nx][ny] != colorIdx) continue;
                if (visited[nx][ny]) continue;

                que.add(new Pos(nx, ny));
                visited[nx][ny] = true;
            }
        }
        return cnt > 3;
    }

    public static void remove(int x, int y, int colorIdx) {
        Queue<Pos> que = new LinkedList<>();
        boolean[][] visited = new boolean[12][6];

        que.add(new Pos(x, y));
        visited[x][y] = true;
        table[x][y] = 0;

        while (!que.isEmpty()) {
            Pos curr = que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                if (nx < 0 | nx >= 12 | ny < 0 | ny >= 6) continue;
                if (table[nx][ny] != colorIdx) continue;
                if (visited[nx][ny]) continue;

                que.add(new Pos(nx, ny));
                visited[nx][ny] = true;
                table[nx][ny] = 0;
            }
        }
    }

    public static boolean moveDown() {
        boolean flag = false;
        for (int i = 11; i > -1; i--) {
            for (int j = 5; j > -1; j--) {
                if (table[i][j] != 0) continue;
                for (int k = 0; k <= i; k++) {
                    if (table[i - k][j] == 0) continue;
                    table[i][j] = table[i - k][j];
                    table[i - k][j] = 0;
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
}/*
class Pos {
    int x;
    int y;

    Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}*/
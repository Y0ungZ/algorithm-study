import java.util.LinkedList;
import java.util.Queue;

public class LockAndKey {
    static int[][] inputKey, inputLock;
    static int[][] tempKey;

    public boolean solution(int[][] key, int[][] lock) {
        int grooveMinX = 100, grooveMaxX = -1;
        int grooveMinY = 100, grooveMaxY = -1;
        inputLock = lock.clone();
        inputKey = key.clone();
        tempKey = key.clone();

        for (int i = 0; i < lock.length; i++) {
            for (int j = 0; j < lock[i].length; j++) {
                if (lock[i][j] == 0) {
                    grooveMinX = Math.min(grooveMinX, i);
                    grooveMaxX = Math.max(grooveMaxX, i);
                    grooveMinY = Math.min(grooveMinY, j);
                    grooveMaxY = Math.max(grooveMaxY, j);
                }
            }
        }
        if (grooveMinX == 100) return true;
        if (grooveMaxX - grooveMinX + 1 > key.length || grooveMaxY - grooveMinY + 1 > key.length) return false;

        int startX = grooveMaxX - key.length + 1, endX = grooveMinX + 1;
        int startY = grooveMaxY - key.length + 1, endY = grooveMinY + 1;

        for (int r = 0; r < 4; r++) {
            rotate();
            for (int sx = startX; sx < endX; sx++) {
                for (int sy = startY; sy < endY; sy++) {
                    if (isCorrectKey(sx, sy)) return true;
                }
            }
        }
        return false;
    }

    public void rotate() {
        int N = tempKey.length / 2;
        Queue<Integer> que = new LinkedList<>();

        for (int n = 0; n < N; n++) {
            for (int i = n; i < tempKey.length - n - 1; i++) que.add(tempKey[n][i]);
            for (int i = n; i < tempKey.length - n - 1; i++) que.add(tempKey[i][tempKey.length - n - 1]);
            for (int i = tempKey.length - n - 1; i > n; i--) que.add(tempKey[tempKey.length - n - 1][i]);
            for (int i = tempKey.length - n - 1; i > n; i--) que.add(tempKey[i][n]);

            for (int i = n; i < tempKey.length - n - 1; i++) que.add(que.poll());

            for (int i = n; i < tempKey.length - n - 1; i++) tempKey[n][i] = que.poll();
            for (int i = n; i < tempKey.length - n - 1; i++) tempKey[i][tempKey.length - n - 1] = que.poll();
            for (int i = tempKey.length - n - 1; i > n; i--) tempKey[tempKey.length - n - 1][i] = que.poll();
            for (int i = tempKey.length - n - 1; i > n; i--) tempKey[i][n] = que.poll();
        }
    }

    public boolean isCorrectKey(int sx, int sy) {
        for (int x = 0; x < inputKey.length; x++) {
            for (int y = 0; y < inputKey.length; y++) {
                int cx = sx + x;
                int cy = sy + y;
                if (cx < 0 || cx >= inputLock.length || cy < 0 || cy >= inputLock.length) continue;
                if (inputLock[cx][cy] == inputKey[x][y]) return false;
            }
        }
        return true;
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Auuaauauau {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int x = -1000000001, y = -1000000001;
        int ans = 0;

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            if (y < start) {
                ans += (y - x);
                x = start;
                y = end;
            } else {
                if (end < y) continue;
                y = end;
            }
        }
        ans += (y - x);
        System.out.println(ans);
    }
}

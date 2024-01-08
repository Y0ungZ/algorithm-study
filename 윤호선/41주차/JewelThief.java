import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class JewelThief {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long ans = 0;
        int jewelNum = Integer.parseInt(st.nextToken());
        int bagNum = Integer.parseInt(st.nextToken());

        ArrayList<Jewel> jewels = new ArrayList<>();
        ArrayList<Integer> bags = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < jewelNum; i++) {
            st = new StringTokenizer(br.readLine());
            jewels.add(new Jewel(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        for (int i = 0; i < bagNum; i++) {
            bags.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(jewels);
        Collections.sort(bags);

        int idxJewel = 0;
        for (int bag : bags) {
            while (idxJewel < jewelNum) {
                if (bag < jewels.get(idxJewel).getWeight()) break;
                pq.add(jewels.get(idxJewel).getPrice());
                idxJewel++;
            }
            if (!pq.isEmpty()) ans += pq.poll();
        }
        System.out.println(ans);
    }
}
class Jewel implements Comparable<Jewel> {
    private int weight;
    private int price;

    Jewel(int w, int p) {
        this.weight = w;
        this.price = p;
    }

    public int getWeight() {
        return weight;
    }

    public int getPrice() {
        return price;
    }

    @Override
    public int compareTo(Jewel o) {
        return this.weight - o.weight;
    }
}

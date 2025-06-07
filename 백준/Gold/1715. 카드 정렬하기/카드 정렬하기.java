import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Queue<Integer> cards = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            cards.offer(Integer.parseInt(br.readLine()));
        }
        int result = 0;
        while (cards.size() > 1) {
            int var1 = cards.poll();
            int var2 = cards.poll();
            int frontSum = var1 + var2;
            result += frontSum;
            cards.offer(frontSum);
        }

        System.out.println(result);
    }
}

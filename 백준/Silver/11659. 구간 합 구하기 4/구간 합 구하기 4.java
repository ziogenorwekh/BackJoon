import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];
        int[] S = new int[N + 1];
        int[] result = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < N + 1; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            S[i] += arr[i] + S[i - 1];
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int oneZone = Integer.parseInt(st.nextToken());
            int twoZone = Integer.parseInt(st.nextToken());
            result[i] = S[twoZone] - S[oneZone-1];
        }

        for (int i = 0; i < M; i++) {
            System.out.println(result[i]);
        }
    }
}
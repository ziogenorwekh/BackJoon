import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Map<Integer,Integer> essN;

    static int M;

    static int[] essM;

    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        essN = new HashMap<>();
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            essN.put(Integer.parseInt(st.nextToken()), 0);
        }

        M = Integer.parseInt(br.readLine());
        essM = new int[M];
        st = new StringTokenizer(br.readLine(), " ");
        int[] answer = new int[M];
        for (int i = 0; i < M; i++) {
            int search = Integer.parseInt(st.nextToken());
            if (essN.containsKey(search)) {
                answer[i] = 1;
            }
        }


        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int ans : answer) {
            bw.write(ans + "\n");
        }
        bw.close();
    }
}

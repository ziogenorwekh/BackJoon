import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int m;
    static String yes = "YES";
    static String no = "NO";
    static StringTokenizer st;

    static int[] union;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        union = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            union[i] = i;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int cal = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (cal == 0) {
                union(a, b);
            } else if (cal == 1) {
                int c1 = find(a);
                int c2 = find(b);
                if (c1 == c2) {
                    bw.append(yes).append("\n");
                } else {
                    bw.append(no).append("\n");
                }
            }
        }
        bw.close();
    }


    private static int find(int x) {
        if (union[x] != x) {
            union[x] = find(union[x]);
        }
        return union[x];
    }

    private static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            union[y] = x;
        }
    }
}

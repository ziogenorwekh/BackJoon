import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuffer sb = new StringBuffer();        
        int[][] pattern = new int[][] {
            {0},
            {1},
            {2,4,8,6},
            {3,9,7,1},
            {4,6},
            {5},
            {6},
            {7,9,3,1},
            {8,4,2,6},
            {9,1},
            {10},
        };

        int N = Integer.parseInt(br.readLine());
        int inputArry[][] = new int[N+1][2];
        for (int i = 1; i < N+1; i++) {
            String inputNumString = br.readLine();
            StringTokenizer st = new StringTokenizer(inputNumString," ");
            inputArry[i][0] = Integer.parseInt(st.nextToken());
            inputArry[i][1] = Integer.parseInt(st.nextToken());
        }
        

        for (int i = 1; i < N+1; i++) {
            int patternResult = 0;
            int a = inputArry[i][0];
            int b = inputArry[i][1];
            int aRm = a % 10;
            if (aRm == 0) {
                sb.append(10 + "\n");
                continue;
            }
            int len = pattern[aRm].length;
            patternResult = b % len == 0 ? len -1 : (b % len) -1;
            sb.append(pattern[aRm][patternResult]+"\n");
        }

        bw.write(sb.toString());
        
        bw.close();
        br.close();

    }
}
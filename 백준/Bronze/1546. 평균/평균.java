
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws Exception{
        int N;
        String storeString;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        N = Integer.parseInt(br.readLine());
        storeString = br.readLine();
        StringTokenizer st = new StringTokenizer(storeString, " ");
        int[] scores = new int[N];
        for (int i = 0; i < scores.length; i++) {
            scores[i] = Integer.parseInt(st.nextToken());
        }

        int max = 0;
        for (int i = 0; i < scores.length; i++) {
            if (max < scores[i]) {
                max = scores[i];
            }
        }
        double totalSum = 0;
        for (int i = 0; i < scores.length; i++) {
            double newScore = (double) scores[i] / max * 100;
            totalSum += newScore;
        }
        double average = totalSum/N;
        bw.write(""+average);

        bw.flush();
        bw.close();
        br.close();

    }
}
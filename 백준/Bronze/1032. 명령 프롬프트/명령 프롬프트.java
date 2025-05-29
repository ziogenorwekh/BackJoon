import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        
        String[] inputString = new String[N];
        
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            inputString[i] = input;
        }
        
        StringBuilder sb = new StringBuilder();
        int len = inputString[0].length();
        int pointer = 0;
        if(N == 1) {
            bw.write(inputString[0]);
            bw.flush();
            return;
        }


        for (int i = 1; i < N; i++) {
            if (pointer > len - 1) {
                break;
            }
            char firstChar = inputString[0].charAt(pointer);
            char checkupChar = inputString[i].charAt(pointer);

            if (firstChar != checkupChar) {
                sb.append("?");
                pointer++;
                i = 0;
                continue;
            } 
            if (i == N -1) {
                sb.append(firstChar);
                pointer++;
                i = 0;
            }
        }
        
        bw.write(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

public class Main {

    static int N;

    static int index = 0;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        if (N == 1 || N == 2) {
            System.out.println(1);
            return;
        }
        System.out.println(Fibonacci(0L, 1L));
    }

    private static long Fibonacci(long n1, long n2) {
        if (N == index) {
            return n1;
        }
        index++;
        long var1 = n1;
        long var2 = n2;
        long nextFibonacci = var1 + var2;

        return Fibonacci(nextFibonacci, var1);
    }
}

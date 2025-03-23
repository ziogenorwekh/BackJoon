import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] sequence = new int[N];
        for (int i = 0; i < N; i++) {
            sequence[i] = Integer.parseInt(br.readLine());
        }

        Stack<Integer> stack = new Stack<>();
        List<String> list = new ArrayList<>();
        int index = 1;
        int sIndex = 0;
        stack.push(index);
        list.add("+");

        while (sIndex != sequence.length) {
            if (stack.empty()) {
                list.add("+");
                index++;
                stack.push(index);
            } if (stack.peek() > sequence[sIndex]) {
                list.clear();
                list.add("NO");
                break;
            }
            else if (stack.peek() != sequence[sIndex]) {
                list.add("+");
                index++;
                stack.push(index);
            } else if (stack.peek() == sequence[sIndex]) {
                stack.pop();
                list.add("-");
                sIndex++;
            }
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

        br.close();
    }
}

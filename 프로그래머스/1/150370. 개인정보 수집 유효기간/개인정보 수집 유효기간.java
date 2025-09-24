import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> list = new ArrayList<>();
        LocalDate tdy = LocalDate.parse(today, DateTimeFormatter.ofPattern("yyyy.MM.dd"));
        Map<String, Integer> termMap = new HashMap<>();
        for (String term : terms) {
            StringTokenizer st = new StringTokenizer(term, " ");
            while (st.hasMoreTokens()) {
                String termA = st.nextToken();
                Integer period = Integer.valueOf(st.nextToken());
                termMap.put(termA, period);
            }
        }
        for (int i = 0; i < privacies.length; i++) {
            StringTokenizer st = new StringTokenizer(privacies[i], " ");
            while (st.hasMoreTokens()) {
                LocalDate agree = LocalDate.parse(st.nextToken(),DateTimeFormatter.ofPattern("yyyy.MM.dd"));
                String term = st.nextToken();
                Integer period = termMap.get(term);
                if (tdy.isAfter(agree.plusMonths(period)) || tdy.isEqual(agree.plusMonths(period))) {
                    list.add(i+1);
                }
            }
        }
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
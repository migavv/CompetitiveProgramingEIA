
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int rfp = 1;
        while(true) {
            st = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(st.nextToken()); //Total requirements
            if(n == 0) break;
            if(rfp > 1) System.out.println();
            int p = Integer.parseInt(st.nextToken()); //Total proposals
            for (int i = 0; i < n; i++)
                reader.readLine();
            String best = "", name; double min = Double.MAX_VALUE, price; int maxR = -1, reqs;
            for (int i = 0; i < p; i++) {
                name = reader.readLine();
                st = new StringTokenizer(reader.readLine());
                price = Double.parseDouble(st.nextToken());
                reqs = Integer.parseInt(st.nextToken());
                if(reqs > maxR || (reqs == maxR && price < min)) {
                    best = name; min = price; maxR = reqs;
                }
                for (int j = 0; j < reqs; j++)
                    reader.readLine();
            }
            System.out.println("RFP #" + rfp + "\n" + best);
            rfp++;
        }
    }
}

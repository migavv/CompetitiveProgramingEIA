
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= cases ; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            if(a > b) {
                if(a < c) System.out.println("Case " + i + ": " + a);
                else System.out.println("Case " + i + ": " + Math.max(b, c));
            } else {
                if(a > c) System.out.println("Case " + i + ": " + a);
                else System.out.println("Case " + i + ": " + Math.min(b, c));
            }
        }
    }
}




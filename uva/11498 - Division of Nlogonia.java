
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int queries = Integer.parseInt(reader.readLine());
        while(queries != 0) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            for (int i = 0; i < queries; i++) {
                st = new StringTokenizer(reader.readLine());
                int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
                if(x == n || y == m)
                    System.out.println("divisa");
                else if(y > m) {
                    if(x < n)
                        System.out.println("NO");
                    else
                        System.out.println("NE");
                } else {
                    if(x < n)
                        System.out.println("SO");
                    else
                        System.out.println("SE");
                }
            }
            queries = Integer.parseInt(reader.readLine());
        }
    }
}

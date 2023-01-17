
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        while(true) {
            double h = Integer.parseInt(st.nextToken());
            if(h == 0)
                break;
            double u = Double.parseDouble(st.nextToken()), d = Double.parseDouble(st.nextToken()),
                    f = u * Double.parseDouble(st.nextToken()) / 100.0, distance = 0;
            int day = 1;
            while(true) {
                distance += Math.max(u, 0);
                if(distance > h) break;
                distance -= d;
                if(distance < 0) break;
                u -= f;
                day++;
            }
            System.out.println((distance > 0 ? "success": "failure") + " on day " + day);
            st = new StringTokenizer(reader.readLine());
        }
    }
}

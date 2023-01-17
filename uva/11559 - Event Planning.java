
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int n, b, h, w, p, beds, min;
        while(st.hasMoreTokens()) {
            min = Integer.MAX_VALUE;
            n = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(reader.readLine());
                p = Integer.parseInt(st.nextToken());
                st = new StringTokenizer(reader.readLine());
                int j = 0;
                while(j++ < w) {
                    beds = Integer.parseInt(st.nextToken());
                    if(beds >= n) {
                        min = Math.min(min, n * p);
                        break;
                    }
                }
            }
            System.out.println(min > b ? "stay home" : min);
            st = new StringTokenizer(reader.readLine());
        }
    }
}

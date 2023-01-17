
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());
        String[] input = new String[2];
        for (int i = 0; i < cases; i++) {
            input = reader.readLine().split(" ");
            int k = Integer.parseInt(input[1]);
            System.out.println(k ^ (k >> 1));
        }
    }
}

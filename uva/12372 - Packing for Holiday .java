
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int cases = read.nextInt();
        for (int i = 1; i <= cases; i++) {
            boolean good = true;
            for (int j = 0; j < 3; j++)
                good &= read.nextInt() <= 20;
            System.out.println("Case " + i + ": " + (good ? "good" : "bad"));
        }
    }
}

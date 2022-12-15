
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int cases = read.nextInt(), students, max;
        for (int i = 1; i <= cases; i++) {
            students = read.nextInt();
            max = read.nextInt();
            for (int j = 1; j < students; j++)
                max = Math.max(max, read.nextInt());
            System.out.println("Case " + i + ": " + max);
        }
    }
}

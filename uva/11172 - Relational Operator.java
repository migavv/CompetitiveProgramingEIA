
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int cases = read.nextInt();
        for (int i = 0; i < cases; i++) {
            int x = read.nextInt(), y = read.nextInt();
            if(x > y) System.out.println(">");
            else if(x < y) System.out.println("<");
            else System.out.println("=");
        }
    }
}

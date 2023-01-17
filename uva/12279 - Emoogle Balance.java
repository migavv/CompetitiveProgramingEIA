
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int events = read.nextInt();
        int i = 1;
        while(events != 0) {
            int balance = 0;
            for (int j = 0; j < events; j++) {
                int event = read.nextInt();
                if(event != 0) balance++;
                else balance--;
            }
            System.out.println("Case " + i++ + ": " + balance);
            events = read.nextInt();
        }
    }
}

package uva11044;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int cases = read.nextInt();
        for (int i = 0; i < cases; i++) {
            int height = read.nextInt();
            int width = read.nextInt();
            System.out.println((int)(Math.ceil((height - 2)/3.0) * Math.ceil((width - 2)/3.0)));
        }
    }
}

package uva11547;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int cases = read.nextInt();
        for (int i = 0; i < cases; i++) {
            int n = read.nextInt();
            n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
            String res = "" + n;
            System.out.println(res.charAt(res.length() - 2));
        }
    }
}

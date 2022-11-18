package uva10071;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public int solve(int v, int t) {
        return v * 2 * t;
    }

    public static void main(String[] args) throws IOException {
        Scanner read = new Scanner(System.in);
        Main solution = new Main();
        while(read.hasNext()) {
            int v = read.nextInt();
            int t = read.nextInt();
            System.out.println(solution.solve(v, t));
        }
    }
}

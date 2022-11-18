package uva11764;

import java.util.Scanner;

public class Main {
    public String solve(int[] blocks) {
        int high = 0, low = 0;
        for (int i = 1; i < blocks.length; i++) {
            if(blocks[i - 1] < blocks[i])
                high++;
            else if(blocks[i - 1] > blocks[i])
                low++;
        }
        return "" + high + " " + low;
    }

    public static void main(String[] args) {
        Main solution = new Main();
        Scanner read = new Scanner(System.in);
        int cases = read.nextInt();
        for(int i = 1; i <= cases; i++) {
            int size = read.nextInt();
            int[] blocks = new int[size];
            for(int j = 0; j < size; j++)
                blocks[j] = read.nextInt();
            System.out.println("Case " + i + ": " + solution.solve(blocks));
        }
    }
}

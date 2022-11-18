package uva1709;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        while(read.hasNext()) {
            int p = read.nextInt(), a = read.nextInt(), b = read.nextInt(),
                    c = read.nextInt(), d = read.nextInt(), n = read.nextInt();
            double max = 0, aux = 0;
            double prev = p * (Math.sin(a + b) + Math.cos(c + d) + 2);
            for(int k = 2; k <= n - 1; k++) {
                double curr = p * (Math.sin(a * k + b) + Math.cos(c * k + d) + 2);
                aux += prev - curr;
                if(aux < 0) aux = 0;
                else max = Math.max(max, aux);
                prev = curr;
            }
            System.out.println(max);
        }
    }
}

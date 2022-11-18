package uva10456;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int m, n, t;
        int[] aux;
        String input;
        while(true) {
            input = reader.readLine();
            if(input == null)
                break;
            st = new StringTokenizer(input);
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());
            if(m > t && n > t) {
                System.out.println(0 + " " + t);
                continue;
            }
            aux = new int[t + 1];
            for(int i = 0; i <  Math.min(m, n); i++)
                aux[i] = 0;
            if(m <= t)
                aux[m] = 1;
            if(n <= t)
                aux[n] = 1;
            for (int i = Math.min(m, n); i <= t; i++) {
                int v = Math.max(i > m ? aux[i - m] : 0, i > n ? aux[i - n] : 0);
                if(v > 0) {
                    if(aux[i] == 0)
                        aux[i] += v + 1;
                    else aux[i] += v;
                }
            }
            int j = t;
            while(j >= 0 && aux[j] == 0)
                j--;
            System.out.print(aux[j]);
            System.out.println(t - j == 0 ? "" : " " + (t - j));
        }
    }
}

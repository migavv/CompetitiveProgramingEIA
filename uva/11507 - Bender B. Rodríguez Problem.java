
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int l = Integer.parseInt(st.nextToken());
            if(l == 0) break;
            st = new StringTokenizer(reader.readLine());
            int dir = 1; boolean y = true;
            for (int i = 0; i < l - 1; i++) {
                String d = st.nextToken();
                switch(d) {
                    case "+y":
                        if(y)
                            dir = dir == 4 ? 1 : dir + 1;
                        else if(dir == 1 || dir == 3) {
                            dir++;
                            y = true;
                        }
                        break;
                    case "-y":
                        if(y)
                            dir = dir - 1  == 0 ? 4 : dir - 1;
                        else if(dir == 1 || dir == 3) {
                            dir = dir - 1  == 0 ? 4 : dir - 1;
                            y = true;
                        }
                        break;
                    case "+z":
                        if(!y)
                            dir = dir == 4 ? 1 : dir + 1;
                        else if(dir == 1 || dir == 3) {
                            dir++;
                            y = false;
                        }
                        break;
                    case "-z":
                        if(!y)
                            dir = dir - 1 == 0 ? 4 : dir - 1;
                        else if(dir == 1 || dir == 3) {
                            dir = dir - 1 == 0 ? 4 : dir - 1;
                            y = false;
                        }
                        break;
                }
            }
            switch (dir) {
                case 1: System.out.println("+x"); break;
                case 2: System.out.println(y ? "+y" : "+z"); break;
                case 3: System.out.println("-x"); break;
                case 4: System.out.println(y ? "-y" : "-z"); break;
            }
        }

    }
}

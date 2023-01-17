
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        HashMap<String, String> dict = new HashMap<>();
        dict.put("HELLO", "ENGLISH");
        dict.put("HOLA", "SPANISH");
        dict.put("HALLO", "GERMAN");
        dict.put("BONJOUR", "FRENCH");
        dict.put("CIAO", "ITALIAN");
        dict.put("ZDRAVSTVUJTE", "RUSSIAN");
        int cont = 1;
        String word = read.nextLine(), res;
        while(!word.equals("#")) {
            res = dict.get(word);
            System.out.println("Case " + cont++ + ": " + (res == null ? "UNKNOWN" : res));
            word = read.nextLine();
        }
    }
}

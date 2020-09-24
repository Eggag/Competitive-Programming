import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            int x = scan.nextInt();
            if(x % 2 == 0) even++;
            else odd++;
        }
        System.out.println(Math.min(even, odd));
    }
}

import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for(int q = 0; q < t; q++){
           int n = scan.nextInt();
           int[] a = new int[n];
           for(int i = 0; i < n; i++){
               a[i] = scan.nextInt();
           }
           int mn = Integer.MAX_VALUE;
           int ans = 0;
           for(int i = n - 1; i >= 0; i--){
               if(a[i] > mn) ans++;
               mn = Math.min(a[i], mn);
           }
           System.out.println(ans);
        }
    }
}

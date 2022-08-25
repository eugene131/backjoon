import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;


public class backjoon2839 {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int n = 0, m = 0, k;
    k = sc.nextInt();
    if (k % 5 == 0)
      n = k / 5;
    else {
      n = k / 5 + 1;

      for (int i = 0;; i++) {
        if (k != (5 * n) + (3 * m)) {
          // System.out.println("5: " + n + " 3:  " + m);
          n--;
          m++;
          for (;;) {
            if (k > (5 * n) + (3 * m)) {
              //  System.out.println("5: " + n + " 3:  " + m);
              m++;
            } else
              break;
          }
        } else
          break;
        if (n == 0 && 3 * m > k)
          break;
      }
    }
    // n = n + m;
    if (k == (5 * n) + (3 * m)) {
      System.out.println(n + m);
    }
    else
      System.out.println("-1");
  }
}

import java.util.Scanner;
import java.lang.Math;

public class backjoon1463 {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int N,cunt=0;
    N = sc.nextInt();
    int[] dp = new int[N + 4],dp_cunt=new int[3];
    for(int i=0;i<3;i++){
      dp_cunt[i] = 9999999;;
    }
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; i++) {
      
        if (i % 3 == 0) {
        dp_cunt[0] = dp[i / 3];
      }
      if (i % 2 == 0) {
        dp_cunt[1] = dp[i / 2];
      }
      dp_cunt[2] = dp[i - 1];
      
      int MinNum = 99999999;
      for (int r : dp_cunt)
        MinNum = Math.min(r, MinNum);
      dp[i] = MinNum + 1;
      for(int k=0;k<3;k++){
        dp_cunt[k] = 9999999;;
      }

    }
    System.out.println(dp[N]);

  }

}

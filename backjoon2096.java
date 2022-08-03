import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;

//ㅈ***********************중간중간 print주석들은 확인용 print임**********//
public class backjoon2096 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int i, j, N,temp,k,MaxNum=0,MinNum=9999999;
        int[][] dpMax = new int[2][3], dpMin = new int[2][3];
        int[] input_Num = new int[3];
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                dpMax[i][j] = 0;
                dpMin[i][j] = 0;
            }
        }

        N = sc.nextInt();
        if (N == 1) {
            for (j = 0; j < 3; j++)
                input_Num[j] = sc.nextInt();
            MaxNum = 0;
            for (int r : input_Num)
                MaxNum = Math.max(r, MaxNum);
            MinNum = 9999999;
            for (int r : input_Num)
                MinNum = Math.min(r, MinNum);
            System.out.println(MaxNum + " " + MinNum);
        }
        else {
            for (i = 0; i < N; i++) {
                for (j = 0; j < 3; j++)
                    input_Num[j] = sc.nextInt();//입력 받으면
                //System.out.println("check i: " + i);
                if (i == 0) {
                    dpMax[0][0] = input_Num[0];//첫 번째 경우 앞쪽의 dp데이터가 없기 때문에 인풋 데이터로만 0,1,2 값 결정 
                    dpMax[0][1] = input_Num[1];
                    dpMax[0][2] = input_Num[2];

                    /***********************Max min 나누는 구간********************/
                    dpMin[0][0] = input_Num[0];
                    dpMin[0][1] = input_Num[1];
                    dpMin[0][2] = input_Num[2];

                    //    System.out.printf("\nMin : %d %d %d \n", dpMin[0][0], dpMin[0][1], dpMin[0][2]);//값 확인용 print
                    //    System.out.printf("\nMax : %d %d %d", dpMax[0][0], dpMax[0][1], dpMax[0][2]);

                } else {
                    // System.out.println("check dp[0]: " + dpMax[0][0] + " " + dpMax[0][1] + " " + dpMax[0][2]);
                    dpMax[1][0] = Max_Num_2(dpMax[0][0], dpMax[0][1]) + input_Num[0];//앞에 값중 더 큰값 혹은 작은 값과 input값을 더해서 min or max 결정 
                    MaxNum = 0;
                    for (int r : dpMax[0])
                        MaxNum = Math.max(r, MaxNum);
                    dpMax[1][1] = MaxNum + input_Num[1];
                    dpMax[1][2] = Max_Num_2(dpMax[0][2], dpMax[0][1]) + input_Num[2];
                    //************************************Min Max 구분 *******************/
                
                    dpMin[1][0] = Min_Num_2(dpMin[0][0], dpMin[0][1]) + input_Num[0];
                    // System.out.println(dpMin[0][0]+" "+dpMin[0][1]+" "+input_Num[0]);
                    MinNum = 9999999;
                    for (int r : dpMin[0])
                        MinNum = Math.min(r, MinNum);
                    dpMin[1][1] = MinNum + input_Num[1];
                    dpMin[1][2] = Min_Num_2(dpMin[0][2], dpMin[0][1]) + input_Num[2];

                    //  System.out.printf("\nMin : %d %d %d \n", dpMin[1][0], dpMin[1][1], dpMin[1][2]);
                    // System.out.printf("\nMax : %d %d %d ", dpMax[1][0], dpMax[1][1], dpMax[1][2]);

                    for (j = 0; j < 3; j++) {
                        dpMax[0][j] = dpMax[1][j];
                        dpMin[0][j] = dpMin[1][j];
                    }
                }
            }
            MaxNum = 0;
            for (int r : dpMax[1])
                MaxNum = Math.max(r, MaxNum);
            MinNum = 9999999;
            for (int r : dpMin[1])
                MinNum = Math.min(r, MinNum);
            System.out.println(MaxNum + " " + MinNum);
            //Search_Sum_Max(input_Num,N);
            //Search_Sum_Min(input_Num, N);
        }
    }
/*     ********************************메모리 신경쓰지 않고 전부다 계산하는 방법********************
    public static void Search_Sum_Max(int[][] input,int N) {//가장 큰 수를 탐색하는 함수
        int[][] dpMax = new int[100000][3];
        int i;
        dpMax[0][0]=Max_Num_2(input[0][0],input[0][1]);
        dpMax[0][1] = Arrays.stream(input[0]).max().getAsInt();
        dpMax[0][2]=Max_Num_2(input[0][1],input[0][2]);
        for (i = 1; i < N; i++) {
            dpMax[i][0]=Max_Num_2(dpMax[i-1][0],dpMax[i-1][1])+input[i][0];
            dpMax[i][1] = Arrays.stream(dpMax[i-1]).max().getAsInt() + input[i][1];
            dpMax[i][2]=Max_Num_2(dpMax[i-1][2],dpMax[i-1][1])+input[i][2];
        }
        System.out.printf("%d ",Arrays.stream(dpMax[N-1]).max().getAsInt());
        
    }
    
    public static void Search_Sum_Min(int[][] input,int N) {
        int[][] dpmin = new int[100000][3];
        int i;
        dpmin[0][0] = Min_Num_2(input[0][0], input[0][1]);
        dpmin[0][1] = Arrays.stream(input[0]).min().getAsInt();
        dpmin[0][2] = Min_Num_2(input[0][1], input[0][2]);
        for (i = 1; i < N; i++) {
            dpmin[i][0] = Min_Num_2(dpmin[i - 1][0], dpmin[i - 1][1]) + input[i][0];
            dpmin[i][1] = Arrays.stream(dpmin[i - 1]).min().getAsInt() + input[i][1];
            dpmin[i][2] = Min_Num_2(dpmin[i - 1][2], dpmin[i - 1][1]) + input[i][2];
        }
        //printdp(dpmin, N);
        System.out.printf("%d\n",Arrays.stream(dpmin[N-1]).min().getAsInt());
    }
    */
    public static int Min_Num_2(int a, int b) {
        if (a>b)
            return b;
        else
            return a;
    }
    public static int Max_Num_2(int a, int b) {
        if (a>b)
            return a;
        else
            return b;
    }
/**************리스트 확인용*******************/
    public static void printdp(int[][] a, int n) {
        int i;
        for (i = 0; i < n; i++) {

            System.out.println(a[i][0] + " " + a[i][1] + " " + a[i][2]);

        }
    } 
    
}

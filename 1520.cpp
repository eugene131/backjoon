#include<iostream>

int Ch_Map[500][500];
int Map[500][500];
int dp[2][500];
int dp_ch_map[500][500];
int dp_num;
int cunt = 0;
int M, N;

void dp_append(int vali,int valj){
  dp[0][dp_num] = vali;
  dp[1][dp_num] = valj;
  dp_num++;
//  std::cout << "dp append\n";
}
void dp_delete(){
  dp[0][dp_num] = 0;
  dp[1][dp_num] = 0;
  if(dp_num>0)
    dp_num--;
//  std::cout << "dp delete\n";
}
void change_dp(int num){
//  std::cout << "use change_dp\n";
  for (int r = 0; r < dp_num; r++)
  {
    dp_ch_map[dp[0][r]][dp[1][r]] += num;
    
  }
      dp_num = 0;
}

/*void print_dp(){
  for (int i = 0; i < 2;i++){
    for (int j = 0; j < dp_num;j++){
      printf("%5d",dp[i][j]);
    }
    std::cout << "\n";
  }
}*/

void search_Map(int i, int j)
{
  std::cout << "i: " << i << "j: " << j << "\n";
  for (int k = 0;k<M;k++){
    for (int r = 0; r < N;r++){
      printf("%4d",dp_ch_map[k][r]);
    }
    std::cout << "\n";
  }
  std::cout << "cunt: " << cunt << "\n";
  if (i == M - 1 && j == N - 1)
  {
    //  print_dp();
      cunt++;
      change_dp(1);
      return;
    }

  if(dp_ch_map[i][j]>=1){
  //  print_dp();
    cunt++;
    change_dp(dp_ch_map[i][j]+1);
    return;
  }

  if(dp_ch_map[i][j]==0){
  //  std::cout << "dpchmap=0\n";
    dp_num = 0;
    return;
  }

  dp_ch_map[i][j] = 0;
  
  dp_append(i, j);

  //Ch_Map[i][j] = 0;

  if (Map[i - 1][j] /*&& Ch_Map[i-1][j]==0*/){
    if(Map[i-1][j]<Map[i][j]){
      search_Map(i - 1, j);
    }
  }
  
  if (Map[i + 1][j] /*&& Ch_Map[i+1][j]==0*/){
    if(Map[i+1][j]<Map[i][j]){
      search_Map(i + 1, j);
    }
  }
  
  if (Map[i][j-1] /*&& Ch_Map[i][j-1]==0*/){
    if(Map[i][j-1]<Map[i][j]){
      search_Map(i, j-1);
    }
  }

  if (Map[i][j+1] /*&& Ch_Map[i][j+1]==0*/)
  {
    if(Map[i][j+1]<Map[i][j]){
      search_Map(i, j+1);
    }
  }
  
  Ch_Map[i][j] = -1;
  dp_delete();

  return;
}

int main(void)
{
  int i;
  std::cin >> M >> N;
  for (i=0;i<M;i++){
    for (int j = 0; j < N;j++){
      std::cin >> Map[i][j];
      dp_ch_map[i][j] = -1;
    }
  }

  search_Map(0, 0);
  std::cout <<cunt;

  return 0;
}
#include<iostream>

int Ch_Map[500][500];
int Map[500][500];
int dp[2][500];
int dp_num;
int cunt = 0;
int M, N;

void dp_append(int vali,int valj){
  dp[0][dp_num] = vali;
  dp[1][dp_num] = valj;
  dp_num++;
}
void search_Map(int i, int j)
{
  if (Ch_Map[i][j]==1)
    return;
  if(Ch_Map[i][j]==-1){
    cunt++;
    return;
  }
  //dp_append(i, j);
  if (i == M - 1 & j == N - 1)
  {
    cunt++;
    }
  Ch_Map[i][j] = 1;

  if (Map[i - 1][j] && Ch_Map[i-1][j]==0)
  {
    if(Map[i-1][j]<Map[i][j]){
      search_Map(i - 1, j);
    }
  }
  if (Map[i + 1][j] && Ch_Map[i+1][j]==0)
  {
    if(Map[i+1][j]<Map[i][j]){
      search_Map(i + 1, j);
    }
  }
  if (Map[i][j-1] && Ch_Map[i][j-1]==0)
  {
    if(Map[i][j-1]<Map[i][j]){
      search_Map(i, j-1);
    }
  }
  if (Map[i][j+1] && Ch_Map[i][j+1]==0)
  {
    if(Map[i][j+1]<Map[i][j]){
      search_Map(i, j+1);
    }
  }

  Ch_Map[i][j] = 0;

  return;
}

int main(void)
{
  int i;
  std::cin >> M >> N;
  for (i=0;i<M;i++){
    for (int j = 0; j < N;j++){
      std::cin >> Map[i][j];
    }
  }
  search_Map(0, 0);
  std::cout << cunt;

  return 0;
}
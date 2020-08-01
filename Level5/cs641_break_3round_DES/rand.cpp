#include <bits/stdc++.h>
using namespace std;
time_t t;
int main()
{
  long long int rand_no,j=0;
  char a[65], af[65];
  char b[65], bf[65];
  //long long int a1[64],b1[64];
  FILE *fr;
  FILE *fo;
  fr = fopen("random.txt","w+");
  fo = fopen("random_binary.txt","w+");
  char  s1[17],s2[17];
  long long int t1,t2;
  int ipinv_in[64] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
  //int  s[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
  while(j < 1000)
  {
    for (int i = 0; i < 64; i++)
    {
      rand_no = rand()%2;
      rand_no += 48;
      a[i] = rand_no;
      if(i >= 32) {
        b[i] = a[i];
      }
    }
    
    for (int i = 0; i < 32; i++){
        //cout << "t2 = =" << t2  << " " << s[j] << " " << a[j]<< "\n";
        b[i] = rand()%2+48;
    }
    for(int k = 0;k<64;k++)
    {
      af[k] = a[ipinv_in[k]-1];
      bf[k] = b[ipinv_in[k]-1];
    }

    int l;
    for(l = 0 ; l < 16 ; l++)
    {
      int h1,h2;
      h1 = (af[l*4]-48)*8+(af[l*4+1]-48)*4+(af[l*4+2]-48)*2+(af[l*4+3]-48);
      h2 = (bf[l*4]-48)*8+(bf[l*4+1]-48)*4+(bf[l*4+2]-48)*2+(bf[l*4+3]-48);
      h1 += 102;
      h2 += 102;
      s1[l] = h1;
      s2[l] = h2;
    }
    s1[l] = '\0';
    s2[l] = '\0';
    fprintf(fr, "%s\n",s1);
    fprintf(fr, "%s\n",s2);
    af[64] = bf[64] = '\0';
    fprintf(fo,"%s\n",af);
    fprintf(fo,"%s\n",bf);
    
    j++;
  }
}
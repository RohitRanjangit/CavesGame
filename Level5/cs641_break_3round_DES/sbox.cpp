#include<bits/stdc++.h>

int S[8][64]=
{
14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13 ,

15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9,

10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,

7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4,
3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,

2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,

12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11,
10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,

4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,

13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7,
1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
};

int ipinv[64] = {57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7, 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8};

int ex[48] = {
32, 1, 2, 3, 4, 5,
4, 5,6, 7, 8, 9,
8, 9, 10, 11, 12, 13,
12, 13, 14, 15, 16, 17,
16, 17, 18, 19, 20, 21,
20, 21, 22, 23, 24, 25,
24, 25, 26, 27, 28, 29,
28, 29, 30, 31, 32, 1
};

int iperm[32] = {9, 17, 23, 31, 
13, 28, 2, 18, 
24, 16, 30, 6, 
26, 20, 10, 1, 
8, 14, 25, 3, 
4, 29, 11, 19, 
32, 12, 22, 7, 
5, 27, 15, 21};

int ip[64] = {58,50,42,34,26,18,10,2,
      60,52,44,36,28,20,12,4,
      62,54,46,38,30,22,14,6,
      64,56,48,40,32,24,16,8,
      57,49,41,33,25,17,9,1,
      59,51,43,35,27,19,11,3,
      61,53,45,37,29,21,13,5,
      63,55,47,39,31,23,15,7};

int main()
{
    FILE *finput, *foutput, *fkey;
    finput = fopen("random_binary.txt","r+");
    foutput = fopen("binary_output.txt","r+");
    fkey = fopen("key_3round.txt","w+");
    char input1[65],input2[65],output1[65],output2[65];
    int output1_temp[64],output2_temp[64];
    int inputxor[32], outputxor[32], lxor[32],input3_1[32],input3_2[32];
    // int rxor[32];
    int sbox_out_xor[32],sbox_in_xor[48];
    int input1_exp[48], input2_exp[48];
    int input1_temp[64], input2_temp[64];
    int l1,l2;
    int a,s1,s2,b,i1,i2;

    int key[8][64];
    for(int k = 0;k < 8; k++) 
        for(int j = 0;j<64;j++) key[k][j] = 0;

    for(int i = 0;i<10;i++)
    {
        // if(i < 17) continue;
        fscanf(finput,"%s\n",input1);
        fscanf(finput,"%s\n",input2);
        fscanf(foutput,"%s\n",output1);
        fscanf(foutput,"%s\n",output2);
        // std :: cout << output1 << std::endl;
        //  std :: cout << output2 << std::endl;
        
        for(int k = 0;k<64;k++)
        {
            input1_temp[k] = input1[ip[k]-1] -48;
            input2_temp[k] = input2[ip[k]-1] -48;
            output1_temp[k] = output1[ipinv[k]-1] - 48;
            output2_temp[k] = output2[ipinv[k]-1] - 48;
        //    std::cout<<input1_temp[k]<<" "<<input2_temp[k]<<"\n";
        }
        for(int k = 0;k<32;k++)
        {
            lxor[k] = (input1_temp[k]^input2_temp[k]);
            // rxor[k] = input1_temp[k+32]^input2_temp[k+32];
            // printf("%d",rxor[k]);
        }
        // printf("\n");
        // for(int k = 0;k<32;k++)
        // {
        //     outputxor[k] = ((output1_temp[k]^output2_temp[k])^lxor[k]);
        //     inputxor[k] = output2_temp[k+32]^output1_temp[k+32];
        //     input3_1[k] = output1_temp[k+32];
        //     input3_2[k] = output2_temp[k+32];
        // }
        for(int k = 0;k<32;k++)
        {
            outputxor[k] = ((output1_temp[k+32]^output2_temp[k+32])^lxor[k]);
            inputxor[k] = output2_temp[k]^output1_temp[k];
            input3_1[k] = output1_temp[k];
            input3_2[k] = output2_temp[k];
        }
        for(int k = 0;k<48;k++)
        {
            sbox_in_xor[k] = inputxor[ex[k]-1];
            input1_exp[k] = input3_1[ex[k]-1];
            input2_exp[k] = input3_2[ex[k]-1];
        }

        for(int k = 0;k<32;k++)
        {
            sbox_out_xor[k] = outputxor[iperm[k]-1];
        }
        // for(int k = 0;k < 48;k++) printf("%d",input1_exp[k]);
        // printf("\n");
        for(int j = 0;j<8;j++)
        {
            
            
            s1 = s2 = a = b = i1 = i2 = 0;
            int a1,a2;
            for(int k = 0; k<6 ; k++){
                a+= (int)pow(2,5-k)*sbox_in_xor[j*6+k];
                i1+= (int)pow(2,5-k)*input1_exp[j*6+k];
                i2+= (int)pow(2,5-k)*input2_exp[j*6+k];
            }
            for(int k = 0;k<4; k++)
            {
                b += (int)pow(2,3-k)*sbox_out_xor[j*4+k];
            }
            // printf("%d ",a);
            for(int k = 0;k<64;k++)
            {
                a1 = a^k;
                a2 = k;
                s1 = S[j][(16*(2*(a1/32)+a1%2))+(a1/2)%16];
                s2 = S[j][(16*(2*(a2/32)+a2%2))+(a2/2)%16];
                // std::cout<<i1<<" "<<i2<<" "<<a<<"\n";
                if((s1^s2) == b)
                {
                        key[j][(k^i1)]++;
                }   
            }
        }
        // printf("\n");
    }
    int max = 0, key1 = 0, no = 0,count;
    for(int i = 0;i < 8; i++)
    {
        count = 0, no = 0,key1 = 0, max = 0;
        std::cout<<"sbox : "<<i+1<<"\n";
        for(int j = 0;j<64; j++){
            // 
            count += key[i][j];
            if(max < key[i][j])
            {
                key1 = j;
                max = key[i][j];
                no = 1;
            }
            else if(max == key[i][j])
            {
                no++;
            }
        }    
        printf("key: %d,freq: %d,confidence: %lf%%,no: %d,count :%d\n",key1,max,max*100.0/count,no,count);
    }
    for(int i = 0;i < 8; i++)
    {
        fprintf(fkey,"sbox : %d\n",i+1);
        for(int j = 0; j < 64; j++)
        {
            fprintf(fkey,"key: %d, freq: %d\n",j,key[i][j]);
        }
    }
}
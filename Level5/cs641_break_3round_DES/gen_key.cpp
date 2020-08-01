#include <iostream>
#include <stdio.h>

using namespace std;

FILE *p_keys;

int pc2[48] = {14,17,11,24,1,5,
       3,28,15,6,21,10,
       23,19,12,4,26,8,
       16,7,27,20,13,2,
       41,52,31,37,47,55,
       30,40,51,45,33,48,
       44,49,39,56,34,53,
       46,42,50,36,29,32};
int pc1[56] = {57,49,41,33,25,17,9,
       1,58,50,42,34,26,18,
       10,2,59,51,43,35,27,
       19,11,3,60,52,44,36,
       63,55,47,39,31,23,15,
       7,62,54,46,38,30,22,
       14,6,61,53,45,37,29,
       21,13,5,28,20,12,4};

void generate_key(int * keys){
    int bkeys [48],key[56];
    for(int i=0;i<56;i++){
        key[i] = -1;
    }
    for(int i=0;i<8;i++){
        int num =5,n = keys[i];
        while(num >=0){
            bkeys[6*i + num] = n%2;
            n /= 2;
            num--;
        }
    }
    for(int i=0;i<48;i++){
        key[pc2[i]-1] = bkeys[i];
        if(i%6==0) std :: cout << " ";
        std::cout << bkeys[i];
        
    }

    std ::cout << std::endl;
    int left[28],right[28],l_temp[28],r_temp[28];
    for(int i=0;i<28;i++){
        l_temp[i] = key[i];
        r_temp[i] =  key[i+28];
    }
    for(int i=0;i<28;i++){
        left[i] = l_temp[(i+24)%28];
        right[i] = r_temp[(i+24)%28];
    }
    for(int i=0;i<56;i++){
        if(i<28)key[i] = left[i];
        else key[i] = right[i-28];
    }
    int idxs[8],c=0;
    for(int i=0;i<56;i++){   
        if(key[i]==-1)idxs[c++] = i;
    }
    for(int i=0;i<256;i++){
        int num = i,cn =7;
        while(cn >=0){
            key[idxs[cn]] = num %2;
            num /= 2;
            cn--;
        }
        int original_key[64];
        for(int i=0;i<64;i++)original_key[i] =-1;
        for(int j=0;j<56;j++){
            original_key[pc1[j]-1] = key[j];
        }
        int sum =0;
        for(int i=0;i<64;i++){
            if((i-7)%8==0){
                original_key[i] = sum%2;
                sum =0;
                continue;
            }
            sum += original_key[i];
            
        }

        for(int i=0;i<64;i++){
            //if(i > 0 &&  i%8 ==0  )fprintf(p_keys," ");
            if(original_key[i]==-1){
                fprintf(p_keys,"x");
            }
            else{
                fprintf(p_keys,"%d",original_key[i]);
            }   
        }
        fprintf(p_keys,"\n");
    }
    

}

int main(){
    p_keys = fopen("key_out.txt","w+");
    // int sbox1[4] ={20,23,36,39} ;
    // int sbox2[15] ={0,4,5,6,21,22,23,33,36,37,39,50,52,54,55} ;
    // int sbox3[4] ={28,29,60,61} ;
    // int sbox4[64] ={} ;
    // int sbox5[64] ={} ;
    // int sbox6[64] ={} ;
    // int sbox7[4] ={28,31,44,47} ;
    // int sbox8[3] ={2,13,33} ;
    int keys[8]={51,23,12,4,15,1,22,21};
    generate_key(keys);
    // for(int i1=0;i1<4;i1++){
    //     for(int i2=0;i2<15;i2++){
    //         for(int i3=0;i3<4;i3++){
    //             for(int i4=0;i4<64;i4++){
    //                 for(int i5=0;i5<64;i5++){
    //                     for(int i6=0;i6<64;i6++){
    //                         for(int i7=0;i7<4;i7++){
    //                             for(int i8=0;i8<3;i8++){
    //                                 keys[0] = sbox1[i1];
    //                                 keys[1] = sbox2[i2];
    //                                 keys[2] = sbox3[i3];
    //                                 keys[3] = sbox4[i4];
    //                                 keys[4] = sbox5[i5];
    //                                 keys[5] = sbox6[i6];
    //                                 keys[6] = sbox7[i7];
    //                                 keys[7] = sbox8[i8];
    //                                 generate_key(keys);
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    
    
    return 0;
}
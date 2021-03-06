#include <stdio.h>
#include <stdlib.h>

void block_display(FILE* cipher,int n);
int* matrix_multiply(int** key,int* block,int n);
void matrix_op(int** key,FILE* cipher,int n);

int main(){
	FILE* cipher;
	cipher = fopen("cipher3.txt","r");  //cipher3.txt file with the cipher text
	char key[1000];
	float frequency[1000];
	int keysize=0;
	char a;
	int count = 0;
	while(!feof(cipher)){
		fscanf(cipher,"%c",&a);
		fprintf(stdout,"%c",a);
		
		if (a!=' ' && a!='\n' && a!=',' && a!='.' && a!= '_' && a!='"' && a!='!' && a!=':'){
			count+=1;
			if (int(a)<='Z' && int(a)>='A'){  //Handling capital letters
					a = a + 'a' - 'A';
				}
			if (keysize == 0){
				key[keysize] = a;
				frequency[keysize] = 1.0;
				keysize++;
			}
			
			else{
				int truth = 1;
				int i;
				for (i=0; i<keysize; i++){
					if (key[i]==a){
						truth =0;
						frequency[i] += 1.0;
					}
				}
					if(truth==1){
						key[keysize] = a;
						frequency[keysize] = 1.0;
						keysize++;
					}
					
			}
			
		}
		
	}
	int i;
	printf("\n%d  %d\n",count,keysize);
	// Calculating the relative frequencies
	for (i=0; i<keysize; i++){
		frequency[i] /= count;
		frequency[i] *=100;
	}
	 
	// Sorting the Frequencies
    int j;  
    for (i = 0; i < keysize-1; i++){  
    for (j = 0; j < keysize-i-1; j++){
        if (frequency[j] < frequency[j+1]){
			float temp1 = frequency[j];
			frequency[j] = frequency[j+1];
			frequency[j+1] = temp1;
			char temp2 = key[j];
			key[j] = key[j+1];
			key[j+1] = temp2; 
        }
    }
}	
	
	//Printing the frequencies
	
	for (i=0;i<keysize;i++){
		printf("Frequency of %c is %.3f\n",key[i],frequency[i]);
	}
	

	fclose(cipher);
	cipher = fopen("cipher3.txt","r");
	block_display(cipher,5);  //To see the all the blocks of data during cryptanalysis
	fclose(cipher);
	int m=5;
	int** key1 = (int**)malloc(m*sizeof(int*));
	for (i=0;i<m;i++){
		key1[i] = (int*)malloc(m*sizeof(int));
	}
	
	//Permutation Matrix
	key1[0][0]= 0;
	key1[0][1]= 1;
	key1[0][2]= 0;
	key1[0][3]= 0;
	key1[0][4]= 0;
	
	key1[1][0]= 0;
	key1[1][1]= 0;
	key1[1][2]= 1;
	key1[1][3]= 0;
	key1[1][4]= 0;
	
	key1[2][0] = 0;
	key1[2][1] = 0;
	key1[2][2] = 0;
	key1[2][3] = 0;
	key1[2][4] = 1;
	
	key1[3][0] = 1;
	key1[3][1] = 0;
	key1[3][2] = 0;
	key1[3][3] = 0;
	key1[3][4] = 0;
	
	key1[4][0] = 0;
	key1[4][1] = 0;
	key1[4][2] = 0;
	key1[4][3] = 1;
	key1[4][4] = 0;
	
	cipher = fopen("cipher3.txt","r");
	matrix_op(key1,cipher,m); // To solve the permutation part of the cipher.
	printf("\n");
	cipher = fopen("op1.txt","r"); //op1.txt contains the cipher where the effect of permutation is removed.
	while(!(feof(cipher))){
		fscanf(cipher,"%c",&a);
		if (int(a)<='Z' && int(a)>='A'){
			a = a + 'a' - 'A';
		}
		
		//The key is given below for the substitution part of the cipher and decryption taking place simultaneously. Found the key by playing Hangman
		
		switch(a){
			case 's' :			
				printf("s");
				break;
			case 'b' :			
				printf("e");
				break;
			case 'o' :			
				printf("p");
				break;
			case 'w':
				printf("o");
				break;
			case 'f':
				printf("a");
				break;
			case 'p':
				printf("r");
				break;
			case 'a':
				printf("w");
				break;
			case 'x':
				printf("d");
				break;
			case 'e':
				printf("k");
				break;
			case 'i':
				printf("t");
				break;
			case 'c':
				printf("h");
				break;
			case 'u':
				printf("g");
				break;
			case 't':
				printf("u");
				break;
			case 'd':
				printf("i");
				break;
			case 'v':
				printf("l");
				break;
			case 'z':
				printf("f");
				break;
			case 'j':
				printf("b");
				break;
			case 'g':
				printf("c");
				break;
			case 'm':
				printf("y");
				break;
			case 'r':
				printf("q");
				break;
			case 'q':
				printf("n");
				break;
			case 'l':
				printf("m");
				break;
			case 'y':
				printf("v");
				break;
			case 'h':
				printf("j");
				break;
			case 'n':
				printf("x");
				break;
			case '\n':
				printf("\n");
				break;
			case ' ':
				printf(" ");
				break;
			case '.':
				printf(".");
				break;
			case ',':
				printf(",");
				break;
			case '_':
				printf("_");
				break;
			case':':
				printf(":");
				break;
			case '!':
				printf("!");
				break;
			default :
				printf("X");
				
		}
	}
	fclose(cipher);
	
		
}

void block_display(FILE* cipher,int n){
	printf("(");
	int count =0;
	char a;
	while(!feof(cipher)){
		fscanf(cipher,"%c",&a);
		if (a!=' ' && a!='\n' && a!=',' && a!='.' && a!= '_' && a!='"' && a!='!'&& a!=':'){
			if(count%n!=n-1){
				printf("%c",a);
			}
			else{
				printf("%c)(",a);
			}
			count++;
		}
		else{
			printf("%c",a);
		}
	}
	printf("\nThe no. of blocks is %d",(count/n)+1);
}

int* matrix_multiply(int** key,int* block,int n){ //Does matrix multiplication(mod 26)
	int* sol;
	sol = (int*)malloc(n*sizeof(int));
	int i,j;
	for (i=0;i<n;i++){
		sol[i] =0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			sol[i] += key[i][j]*block[j];
		}
		sol[i] %=26;
	}
	return sol;
}

void matrix_op(int** key,FILE* cipher,int n){ //To remove effect of permutation during encryption.
	FILE* solved = fopen("op1.txt","w"); //op1.txt has the data when the effect of permutation during encryption is removed.
	int count =0;
	char block[50];
	int query[n];
	int* sol = (int*)malloc(n*sizeof(int));
	char a;
	printf("\n");
	while(!feof(cipher)){
		int init =0;
		while(count!=n && !feof(cipher)){
			fscanf(cipher,"%c",&a);
			block[init++] = a;
			if (a!=' ' && a!='\n' && a!=',' && a!='.' && a!= '_' && a!='"' && a!='!'&& a!=':'){
				query[count++] = a - 'a';
			}
			if (count==n){
				sol = matrix_multiply(key,query,n);
				int counter=0;
				int j;
				for(j=0;j<init;j++){
					char b = block[j];
					if (b!=' ' && b!='\n' && b!=',' && b!='.' && b!= '_' && b!='"' && b!='!'&& b!=':'){
						printf("%c",sol[counter++]+'a');
						fprintf(solved,"%c",sol[counter-1]+'a');
					}
					else{ 
						printf("%c",b);
						fprintf(solved,"%c",b);	
					}
				}
				count=0;
				init =0;
				break;
			}
			
		}
	}
	fclose(solved);
	
}


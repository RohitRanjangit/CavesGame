#include <stdio.h>
#include <stdlib.h>

void coincidence(FILE* output,int i);
void decrypt(FILE* cipher,char* key,int key_length);

int main(){
	FILE* cipher;
	cipher = fopen("cipher2.txt","r");  //cipher2.txt file with the cipher text
	char key[1000];
	float frequency[1000];
	int keysize=0;
	char a;
	int count = 0;
	while(!feof(cipher)){
		fscanf(cipher,"%c",&a);
		fprintf(stdout,"%c",a);
		
		if (a!=' ' && a!='\n' && a!=',' && a!='.' && a!= '_' && a!='"'){
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
	
	float ic =0;
	for (i=0;i<keysize;i++){
		ic+= (frequency[i]*(frequency[i]-1)/count)/(count-1);
	}
	ic*=100;
	printf("\nThe coincidence ratio for keysize 1 is %.3f%%\n",ic);
	
	for (i=0; i<keysize; i++){
		frequency[i] /= count;
		frequency[i] *=100;
	}
	fclose(cipher);
	
	//CHecks the coincidence ratio of all possible key sizes
	for(i=2;i<keysize;i++){
		cipher = fopen("cipher2.txt","r");
		coincidence(stdout,i);
		fclose(cipher);
	}
	
	cipher = fopen("cipher2.txt","r");
	coincidence(stdout,6);
	printf("\n\n");
	fclose(cipher);	
	cipher = fopen("cipher2.txt","r");
	char key1[] ={'k','c','g','c','d','f','c','c','b'};  //Array containig the key
	printf("\n");
	for(i=0;i<8;i++){
		printf("%c",key1[i]);
	}
	printf("\n");
	decrypt(cipher,key1,9);

}

void coincidence(FILE* output, int n){
	char key[1000];
	float frequency[1000];
	int keysize = 0;
	int length =0;
	int count =0;
	char a;
	int j;
	FILE* cipher;
	cipher = fopen("cipher2.txt","r");
	for(j=1;j<2;j++){
	while(!feof(cipher)){
		fscanf(cipher,"%c",&a);
		if (a!=' ' && a!='\n' && a!=',' && a!='.' && a!= '_' && a!='"'){
			length++;
			if((length-1)%n==j){
				count++;
				if (int(a)<='Z' && int(a)>='A'){
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
	}
	float ic =0;
	int i;
	for (i=0;i<keysize;i++){
		ic+= (frequency[i]*(frequency[i]-1)/count)/(count-1);
	}
	ic *=100;
	printf("\nThe coincidence ratio for keysize %d is %.3f%%\n",n,ic);
	
	//Prints the letter frequency of the subsequences
	for(i=0;i<keysize;i++){
		frequency[i] = (frequency[i]/count)*100;
		printf("the frequency of %c is %.3f\n",key[i],frequency[i]);
	}	
	fclose(cipher);
	}
cipher = fopen("cipher2.txt","r");	
}

//Decryption done use sybtraction mod 26 with the key.

void decrypt(FILE* cipher,char* key,int key_length){ 
	int length =0;
	while(!feof(cipher)){
		char c;
		fscanf(cipher,"%c",&c);
		if (c!=' ' && c!='\n' && c!=',' && c!='.' && c!= '_' && c!='"'){
			if (int(c)<='Z' && int(c)>='A'){
						c = c + 'a' - 'A';
					}
			length++;
			int k = (length-1)%key_length;
			int d = c - key[k];
			if(d < 0) d += 26;
			c = 'a'+d;
			printf("%c",c);
		}
		else{printf("%c",c);
		}
			
	}
}

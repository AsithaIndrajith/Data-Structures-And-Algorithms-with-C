#include<stdio.h>
#include<string.h>
#include<stdlib.h>//include exit function
#include<math.h>
#define base 256
void rabinCarp(char Text[],char Pattern[],int prime);

void main(argc,argv)
	int argc;
	char *argv[];
	{
		if(argc==4){
			rabinCarp(argv[1],argv[2],atoi(argv[3]));	
		}
		else{
			fprintf(stderr,"Input Format: rabinCarp.exe \"abcd\" \"bc\" 101");	
		}
}

void rabinCarp(char Text[],char Pattern[],int prime){//Note:base should be the size of alphabet.prime should be big as possible
	int i,j,k,s;
	int n=strlen(Text),m=strlen(Pattern);//sizes of pattern and text
	int hashPattern=0,hashText=0;//variables store hash values
	
	/*for (s = 0; s < m-1; s++){
		h = (h*base)%prime;//we take power(256,7) using loop or we can use fmod to take mod between float and int
	}*/	
	int h=fmod(pow(base,m-1),prime);//h value need to hash generatin equation
	
	for(i=0;i<m;i++){//generate hash value of pattern and first part of text equal to pattern's length get the relevent number and multiply it with powers of base(ex:if pattern is
		hashText=(base*hashText+Text[i])%prime;//"ab" and in number format is 12.We multiply first number 2 with 10 to power 0 and //add it to 1 times 10 to power 1
		hashPattern=(base*hashPattern+Pattern[i])%prime;
	}
	
	hashPattern=hashPattern%prime;//then get hash value by getting mod of value.NOte:we can choose prime as any.But larger.
	hashText=hashText%prime;
	
	for(j=0;j<n-m+1;j++){
		if(hashPattern==hashText){//first we check generated hash values are equal
			int k=0;//if hash values equal we double check the pattern is same
			while((k<m)&&(Text[j+k]==Pattern[k])){
				k++;
			}
			if(k==m){
				printf("Matched At: %d\n",j);
				exit(0);	
			}
		}
		hashText=((hashText-Text[j]*h)*base+Text[j+m])%prime;//if not we regenarate next part of text hash value
		if (hashText < 0){
			hashText = (hashText + prime);
		}	
	}//loop goes until pattern reach to end of text
	printf("No Match!!!");
}
//Input in cmd: rabinCarp.exe "Text" "Pattern" primeNumber

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 256
int* lastOcurences(char Pattern[]);//generate last ocurences of each character in pattern and not in pattern
int* lastOcurences_version_2(char Pattern[]);

void booyerMoore(char Text[],char Pattern[]);

void main(argc,argv)
	int argc;
	char* argv[];
	{
		if(argc==3){
			booyerMoore(argv[1],argv[2]);	
		}
		else{
			fprintf(stderr,"Input Format: booyerMoore.exe \"Text\" \"Pattern\"");	
		}
	}

int* lastOcurences(char Pattern[]){
	char *P=Pattern;
	
	int i,j,lengthOfPattern=strlen(Pattern)-1;
	static int last[size];//we return this array so we need to define it as static
	
	for(i=0;i<size;i++){
		for(j=lengthOfPattern;j>-1;j--){
			if((char)i==*(P+j)){
				last[i]=j;
				break;
			}
			last[i]=-1;
		}
	}
	return last;
}

//Second version of last ocurences finding method(Efficient one)
int* lastOcurences_version_2(char Pattern[]){
	char *P=Pattern;
	
	int i,j,k,lengthOfPattern=strlen(Pattern)-1;
	static int last[size];
	for(i=0;i<size;i++){//assign every character as -1->T.C=O(sizeof alphabet)
		last[i]=-1;
	}
	for(j=0;j<lengthOfPattern+1;j++){//in pattern we assign each character's place again in that table->T.C=O(sizeof pattern)
		last[*(P+j)]=j;
	}
	return last;
}

void booyerMoore(char Text[],char Pattern[]){
	printf("Text: %s\nPattern: %s\n",Text,Pattern);
	
	int i,n=strlen(Text),m=strlen(Pattern),s=0;
	int *last=lastOcurences(Pattern);//create a pointer and assign lastOcurences table to it
	
	char *P=Pattern,*T=Text;//create two char pointers to access Pattern and Text
	
	for(i=0;i<n-m+1;i++){
		
		int j=m-1;
		while((*(P+j)==*(T+s+j))&&(j>0)){//loop works until characters match(from right->left) each other
			j--;
		}
		if(j==0){//if loop ends we check whether j came to end of pattern.It means that pattern matched.
			printf("Match At: %d",s+1);
			exit(0);
		}
		else{
			if(*(last+*(T+j))<j){
				s+=j-*(last+*(T+j));
			}	
			else if((*(last+*(T+j))>j)||(*(last+*(T+j))==-1)){
				s++;
			}
		}
	}
	printf("No Match!!!");
}
//pre-condition: Before excuting move to folder contain exe file
//Input in cmd: naiveMatch.exe "Text" "Pattern"

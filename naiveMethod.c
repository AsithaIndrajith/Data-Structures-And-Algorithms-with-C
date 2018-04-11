#include<stdio.h>
#include<string.h>
#include<ctype.h>//Include exit

void naiveStringMatch(char Text[],char Pattern[]);

void main(argc,argv)
	int argc;
	char *argv[];
	{
		if(argc==3){
			naiveStringMatch(argv[1],argv[2]);	
		}
		else{
			fprintf(stderr,"Input Format: naiveMethod.exe \"Text\" \"Pattern\"");	
		}
}
void naiveStringMatch(char Text[],char Pattern[]){
	printf("Text: %s\nPattern: %s\n",Text,Pattern);//print original text and pattern
	int i,j,n=strlen(Text),m=strlen(Pattern);//assign string's lengths
	char *P=Pattern,*T=Text;//create two pointers to access string and assign them to first character
	
	for(i=0;i<n-m+2;i++){
		for(j=0;j<m;j++){
			if(*(P+j)!=*(T+i+j)){//checking each pointer's content and if mismatch break the loop and jump to next
				break;
			}
		}
		if(j==m){//if j goes untill equal to m pattern is match
			printf("Match Found At: %d",i);
			exit(0);//then we end process
		}
	}
	printf("No Match!!!");	
}
//Input in cmd: naiveMatch.exe "Text" "Pattern"

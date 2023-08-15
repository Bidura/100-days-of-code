/*Given a string . For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.



S = aabb 
ab 
'a' at 2nd position is
appearing 2nd time consecutively. A similar explanation for b at the 4th position


S = aabaa 
aba 
'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.*/

#include<stdio.h>
#include<stdlib.h>
char *word;
int len;
void transform(char *word,int len)
{   int i,j,k=len-1;
	for(i=0;i<len-1;i++)
	{
		while(word[i]==word[i+1] && word[i]!='\0')
		{
			for(j=i+1;j<len;j++)
			word[j-1]=word[j];
			word[k--]='\0';
		
		}
		
	}
 printf("%s\n",word);	
}
int main()
{  
  printf("enter the length of the word \n");
  scanf("%d",&len);
  word=(char*)calloc(sizeof(char),len);
  printf("enter the word \n");
  fflush(stdin);
  scanf("%[^\n]s",word);
 transform(word,len);
  return 0;
	
}

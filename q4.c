#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int maxProfit(int* prices, int pricesSize){
//Sliding window approach
int i,min=prices[0],max=0;
for(i=1;i<pricesSize;i++)
{  if(prices[i]<min)
     min=prices[i];
   else 
   { if(prices[i]-min > max)
       max = prices[i]-min;
   }
    
}
return max;
}
int main()
{ 

int *prices,pricesSize,i;
scanf("%d",&pricesSize);
prices=(int*)malloc(sizeof(int)*pricesSize);
for(i=0;i<pricesSize;i++)
{ scanf("%d",&i[prices]);
}
printf("%d",maxProfit(prices,pricesSize));
return 0;
    
}

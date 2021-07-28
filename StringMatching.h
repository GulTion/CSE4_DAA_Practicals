#include<string.h>
#include<stdio.h>

int StringMatching(char * super, char * sub){
    int superLength = strlen(super);
    int subLength = strlen(sub);

    int isMatched=0;
    int start=-1,i,j;
    i=j=0;

    while(j<subLength&&i<superLength){
        if(super[i]==sub[j]){
            if(!isMatched){
                start=i;
                isMatched=1;
            }
            j++;
        }else{
            if(isMatched){
                isMatched=0;  
            }
        }
        i++;

    }

    if(isMatched){
        return start;
    }
    


    return -1;
}
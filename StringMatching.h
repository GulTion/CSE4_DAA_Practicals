#include<string.h>
#include<stdio.h>

int StringMatching(char * super, char * sub){
    int n = strlen(super);
    int m = strlen(sub);
    // printf("%d %d", n,m);
    int con=!!0;
    int start=-1,i,j;
    i=j=0;

    while(i<=m&&j<=n){
        if(super[i]==sub[j]){
            if(!con){
                start=i;
                con=!!1;
            }
            j++;
        }else{
            if(con){
                con=!!0;
                break;
            }
        }
        i++;

    }

    if(con){
        return start;
    }
    


    return -1;
}
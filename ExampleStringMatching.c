#include "./StringMatching.h"

int main(){
    char *SuperString = "Quick Brown Fox Jumps over the Lazy dog";
    char *SubString = "Foi";


    int res = StringMatching(SuperString,SubString);

    if(res==-1) printf("NOT FOUND");
    else printf("FOUND AT INDEX %d", res);
}

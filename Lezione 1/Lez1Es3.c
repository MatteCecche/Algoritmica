#include <stdio.h>

int main(){
    
    int x;
    int somma=0;
    int ok=1;
    while(ok){
        scanf("%d",&x);
        if(x>0) somma+=x;
        else ok=0;
    }
    printf("%d",somma);
    
    
    return 0;
    
}
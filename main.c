#include <stdio.h>

void funk(int no1, int no2, int no3){
    int sto;
    int hi;
    int lo;
    if (no1 > no2) {   
        sto = no1;    
        lo = no2;   
    } 
    else {
    sto = no2;  
    lo = no1;  
    } 
    
    if (sto > no3) { 
        hi = sto;    
        if(lo > no3) {         
            sto = lo;                
            lo = no3;
        }
        else {
        sto = no3;      
        }         
    }
    else hi = no3;
    
    printf("%d %d %d", lo, sto, hi);
};

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    funk(a, b, c);
    return 0;
}



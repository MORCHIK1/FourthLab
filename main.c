#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct sectors{
    float x, y, R, angle, S;
};
typedef struct sectors cir;

#include "input.c"
#include "binary.c"
#include "output.c"

float getS(int, cir*);
float sort_arr(int, cir*);


int main(){
    remove("output.txt");

    int n,i;
    float S;
    cir* ci;

    create_struct(&ci, &n);
    if (ci) {
        input_arr(ci, n);
        arrToBinary(ci, n);
        readBinary(ci, n);
        sort_arr(n, ci);
        resToTxt(ci,n,S);
        outputInCmd();
        free(ci);
    }
    else printf("Memory allocation failed");
}

float getS(int k, cir* ci){
    return ci[k].R*ci[k].R*ci[k].angle/M_PI;
}

float sort_arr(int n, cir* ci){
    int i,j;
    float temp;
    for(i=0; i<n; i++)ci[i].S=getS(i,ci);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(ci[i].S<ci[j].S){
                temp=ci[i].S;
                ci[i].S=ci[j].S;
                ci[j].S=temp;
            }
        }
    }
}
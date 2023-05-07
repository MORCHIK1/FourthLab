void resToTxt(cir *ci, int n, float S) {
    FILE *f_out = fopen("output.txt", "a");
    if(f_out){
        int i;
            for(i=0; i<n; i++)fprintf(f_out,"%f\n",ci[i].S);
        fclose(f_out);
    }
    else printf("Error in writing result .txt file");
}
void outputInCmd(){
    char str[10000];
    FILE *f_out = fopen("output.txt", "r");
    if(f_out){
        while(fgets(str, 10000, f_out) != NULL) {
            printf("%s", str);
        }
        fclose(f_out);
    }
    else printf("Error in reading result .txt file");
}
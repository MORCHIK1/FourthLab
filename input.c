int findN() {
    char ch[1000];
    int counter = 0;
    FILE *f_in = fopen("inputstruct.txt", "r");
    while(fgets(ch, sizeof(ch), f_in) != NULL){
        counter++;
    }
    fclose(f_in);
    return counter;
}

void create_struct(cir **ci, int *n) {
    (*n) = findN();
    *ci = (cir *)malloc((*n) * sizeof(cir));
}

void input_arr(cir* ci, int n) {
    FILE *f_in = fopen("inputstruct.txt", "r");
    if(f_in){
            int i;
            for(i=0; i<n; i++){
            fscanf(f_in, "%f %f %f %f",&ci[i].x, &ci[i].y,&ci[i].R,&ci[i].angle);
        }
        fclose(f_in);
    }
    else printf("Error in reading inputstruct.txt");
}
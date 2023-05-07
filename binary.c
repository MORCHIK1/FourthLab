void arrToBinary(cir* ci, int n){
    FILE *f_bin = fopen("bin.bin", "wb");
    if(f_bin){
        fwrite(&ci, sizeof(cir), n, f_bin);
        fclose(f_bin);
    }
    else printf("Error in writing bin.bin file");
}

void readBinary(cir* ci, int n){
    FILE *f_bin = fopen("bin.bin", "rb");
    if(f_bin){
        fread(&ci, sizeof(cir), n, f_bin);
    }
    else printf("Error in reading bin.bin file");
}
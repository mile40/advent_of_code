#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(int argc, char** argv){

    
    file = fopen("./inputs.txt", "r");
    if(file == NULL)
        exit(EXIT_FAILURE);
    int cpt=0;
    while(read = getline(&line, &len, file) != -1){
    }

    fclose(file);
    if(line)
        free(line);
    return 0;
}
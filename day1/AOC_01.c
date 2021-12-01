#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
    FILE* file;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    int cpt = 0;
    int nbSup = 0;
    int previousValue = -1;
    int tab[2000];
    file = fopen("./inputs.txt", "r");
    if(file == NULL)
        exit(EXIT_FAILURE);

    cpt = 0;
    while(read = getline(&line, &len, file) != -1){
        tab[cpt] = atoi(line);
        cpt++;
    }

    for(int i = 0; i < 2000; i++){
        printf("%d\n", tab[i]);
    }

    for(int i = 0; i < 1998; i++){
        int sum = tab[i]+ tab[i+1] + tab[i+2];

        if(previousValue == -1){
            printf("%d (N/A - no previous sum)\n",  sum);
            previousValue = sum;
            continue;
        }
        
        if(sum > previousValue){
            printf("%d (increased)\n", sum);
            nbSup ++;
        }else{
            printf("%d (decreased)\n", sum);
        }
        previousValue = sum;
        sum = 0;
    }


    fclose(file);
    if(line)
        free(line);
    printf("result: %d\n", nbSup);
    return 0;
}
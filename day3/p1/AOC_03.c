#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct t_ct{
    int nb0s;
    int nb1s;
} cpt;

typedef struct t_res{
    char gamma[13];
    char epsilon[13];
}res;

int main(int argc, char** argv){
    FILE* file;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    cpt tab[12];
    res r;
    r.gamma[12] = '\0';
    r.epsilon[12] = '\0';

    for(int i = 0; i <12; i++){
        tab[i].nb0s=0;
        tab[i].nb1s=0;
    }
    file = fopen("./inputs.txt", "r");
    if(file == NULL)
        exit(EXIT_FAILURE);

    while(read = getline(&line, &len, file) != -1){
        for(int i = 0; i<12; i++){
            if(line[i] == '1'){
                tab[i].nb1s++;
            }else{
                tab[i].nb0s++;
            }
        }
    }

    for(int i = 0; i<12; i++){
        if(tab[i].nb0s > tab[i].nb1s){
            r.gamma[i] = '1';
            r.epsilon[i] = '0';
        }else{
            r.gamma[i] = '0';
            r.epsilon[i] = '1';
        }
    }
    printf("gamma: %s (%d)\nepsilon: %s (%d)\nconsumption: %d\n", r.gamma, (int)strtol(r.gamma, NULL, 2), r.epsilon, (int) strtol(r.epsilon, NULL, 2), (int) strtol(r.gamma, NULL, 2)* (int) strtol(r.epsilon, NULL, 2));
    fclose(file);
    if(line)
        free(line);
    return 0;
}
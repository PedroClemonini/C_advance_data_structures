#include "studant.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct studant{
    int id;
    char name[30];
    double score; 
};

typedef struct studant STU;

STUDANT newStudant(){
    STUDANT st = (STUDANT) malloc(sizeof(STU));

    if(st != NULL){
        st->id = 0;
        st->name[29] = '\0';
        st->score = 0;
    }

    return st;

}

int addData(STUDANT st, int id, char name[], double score){
    if(st == NULL) return 0;

    st->id = id;
    strcpy(st->name,name);
    st->score = score;
    
    return 1;
}

void printStudant(STUDANT st){
    printf("\nID: %d\n", st->id); 

    printf("\nNAME: %s\n", st->name);

    printf("\nSCORE: %f\n", st->score);

}

int getID(STUDANT st){
    return st->id;
}




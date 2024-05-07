#ifndef STUDANT_H
#define STUDANT_H

typedef struct studant *STUDANT;

STUDANT newStudant();

int addData(STUDANT st, int id, char name[], double score);

void printStudant(STUDANT st);

int getID(STUDANT st);

#endif
;
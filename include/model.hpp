#ifndef MODEL_HPP
#define MODEL_HPP 

#define FILENAME "data/data.txt"
#define MAX_ARR  200000

#include <string.h>
#include <stdio.h>
#include <algorithm>

struct Word
{
    char key[50];
    char type[50];
    char meaning[500];
};

/* TIM VA TRA VE DANH SACH TU PHU HOP VOI KEY */
Word* Search(Word *arrWord, int length, char *key, int &length_arrResult);

/* TIM VI TRI TU */
int SearchIndex(Word *arrWord, int length, char *key);

/* CHINH SUA TU */
void Update(Word *arrWord, int length, Word newWord);

/* SAP XEP DANH SACH TU */
void Sort(Word *arrWord, int length);

/* XOA TU TRONG DANH SACH */
void Delete(Word *arrWord, int length, char *key);

/* DOC DU LIEU TU FILE */
Word* ReadData();

/* LUU DU LIEU TU FILE */
int SaveData(Word arrWord[]);

#include "../src/model.cpp"
#endif // !MODEL_HPP

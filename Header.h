#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

enum key { FISH, BIRD };

struct fish {
	key k;
	char name[256];
	enum habitat { RIVER, SEA, LAKE };; // место проживания
	habitat h;
};

void InFish(fish* &f, ifstream &ifst);
void OutFish(fish* &f, ofstream &ofst);
int LengthOfNameFish(fish *f);

struct bird {
	key k;
	char name[256];
	bool migratory; // перелетные или нет
};

void InBird(bird* &b, ifstream &ifst);
void OutBird(bird* &b, ofstream &ofst);
int LengthOfNameBird(bird *b);

struct animal {
	// значения ключей для каждого вида животных
	key k; // ключ
		   // используемые альтернативы
};

animal* In(ifstream &ifst);
void Out(animal *a, ofstream &ofst);
int LengthOfName(animal *a);

//-----------------------------------------------------
// Cравнение ключей двух программных объектов
bool Compare(animal *first, animal *second);
// Простейший контейнер на основе одномерного массива
struct container {
	enum { max_len = 100 }; // максимальная длина
	int len; 			 // текущая длина
	animal *cont[max_len];
};

void Init(container &c);
void Clear(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);
void Sort(container &c);
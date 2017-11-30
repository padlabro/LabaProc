#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

enum key { FISH, BIRD, BEAST };

struct fish 
{
	key k;
	char name[256];
	int age;
	enum habitat { RIVER, SEA, LAKE };; // место проживани€
	habitat h;
};

void InFish(fish* &f, ifstream &ifst);

void OutFish(fish* &f, ostream &ofst);

int LengthOfNameFish(fish *f);

struct bird 
{
	key k;
	char name[256];
	int age;
	bool migratory; // перелетные или нет
};

void InBird(bird* &b, ifstream &ifst);

void OutBird(bird* &b, ostream &ofst);

int LengthOfNameBird(bird *b);

struct beast 
{
	key k;
	char name[256];
	int age;
	enum type { PREDATOR, HERBIVORE, INSECTIVORE };; // тип звер€ (хищник, траво€дный, насекомо€дный)
	type t;
};

void InBeast(beast* &b, ifstream &ifst);

void OutBeast(beast* &b, ostream &ofst);

int LengthOfNameBeast(beast *b);

struct animal 
{
	// значени€ ключей дл€ каждого вида животных
	key k; // ключ
		   // используемые альтернативы
};

animal* In(ifstream &ifst);
void Out(animal *a, ostream &ofst);
int LengthOfName(animal *a);

// ѕростейший контейнер на основе одномерного массива
struct container 
{
	enum { max_len = 100 }; // максимальна€ длина
	int len; 			 // текуща€ длина
	animal *cont[max_len];
};

void Init(container &c);
void Clear(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ostream &ofst);
bool Compare(animal *first, animal *second);
void Sort(container &c, int d);
void OutFish(container &c, ostream &ofst);
void OutBird(container &c, ostream &ofst);
void OutBeast(container &c, ostream &ofst);
void Multimethod(container &c, ostream &ofst);
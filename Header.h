#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

enum key { FISH, BIRD, BEAST };

struct fish {
	key k;
	char name[256];
	enum habitat { RIVER, SEA, LAKE };; // ����� ����������
	habitat h;
};

void InFish(fish* &f, ifstream &ifst);

void OutFish(fish* &f, ofstream &ofst);

struct bird {
	key k;
	char name[256];
	bool migratory; // ���������� ��� ���
};

void InBird(bird* &b, ifstream &ifst);

void OutBird(bird* &b, ofstream &ofst);

struct beast {
	key k;
	char name[256];
	enum type { PREDATOR, HERBIVORE, INSECTIVORE };; // ��� ����� (������, ����������, �������������)
	type t;
};

void InBeast(beast* &b, ifstream &ifst);

void OutBeast(beast* &b, ofstream &ofst);

struct animal {
	// �������� ������ ��� ������� ���� ��������
	key k; // ����
		   // ������������ ������������
};

animal* In(ifstream &ifst);
void Out(animal *a, ofstream &ofst);

// ���������� ��������� �� ������ ����������� �������
struct container {
	enum { max_len = 100 }; // ������������ �����
	int len; 			 // ������� �����
	animal *cont[max_len];
};

void Init(container &c);
void Clear(container &c);
void In(container &c, ifstream &ifst);
void Out(container &c, ofstream &ofst);
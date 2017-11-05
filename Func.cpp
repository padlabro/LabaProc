#include "Header.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void Init(container &c) {
	c.len = 0;
}

void Clear(container &c) {
	for (int i = 0; i < c.len; i++) {
		delete c.cont[i];
	}
	c.len = 0;
}

void In(container &c, ifstream &ifst) {
	while (!ifst.eof() && container::max_len != c.len) {
		if ((c.cont[c.len] = In(ifst)) != 0) {
			c.len++;
		}
	}
}

void Out(container &c, ofstream &ofst) {
	ofst << "Container contains " << c.len << " elements." << endl;
	for (int i = 0; i < c.len; i++) {
		ofst << i + 1 << ": ";
		Out((c.cont[i]), ofst);
		ofst << "Length of name = " << LengthOfName(c.cont[i]) << "." << endl;
	}
}

//-----------------------------------------------------
// Сортировка содержимого контейнера
void Sort(container &c) {
	for (int i = 0; i < c.len - 1; i++) {
		for (int j = i + 1; j < c.len; j++) {
			if (Compare(c.cont[i], c.cont[j])) {
				animal *tmp = c.cont[i];
				c.cont[i] = c.cont[j];
				c.cont[j] = tmp;
			}
		}
	}
}
void InFish(fish* &f, ifstream &ifst) {
	ifst.getline(f->name, 256);
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		f->h = fish::habitat::RIVER;
		break;
	case 2:
		f->h = fish::habitat::SEA;
		break;
	case 3:
		f->h = fish::habitat::LAKE;
		break;
	}
}

void OutFish(fish* &f, ofstream &ofst) {
	ofst << "It is fish. It is ";
	ofst << f->name << ". It lives in ";
	switch (f->h) {
	case fish::habitat::RIVER:
		ofst << "river." << endl;
		break;
	case fish::habitat::SEA:
		ofst << "sea." << endl;
		break;
	case fish::habitat::LAKE:
		ofst << "lake." << endl;
		break;
	}
}

int LengthOfNameFish(fish *f) {
	return strlen(f->name);
}

void InBird(bird* &b,ifstream &ifst)
{
	ifst.getline(b->name, 256);
	int k;
	ifst >> k;
	switch (k) {
	case 0:
		b->migratory = false;
		break;
	case 1:
		b->migratory = true;
		break;
	}
}

void OutBird(bird* &b, ofstream &ofst) {
	ofst << "It is bird. It is ";
	ofst << b->name << ". It is ";
	switch (b->migratory) {
	case false:
		ofst << "not ";
		break;
	case true:
		break;
	}
	ofst << "migratory." << endl;
}

int LengthOfNameBird(bird *b) {
	return strlen(b->name);
}

animal* In(ifstream &ifst) {
	animal *a;
	fish *f;
	bird *b;
	int k1;
	ifst >> k1;
	char t[256];
	ifst.getline(t, 256);
	switch (k1) {
	case 1:
		f = new fish;
		f->k = FISH;
		InFish(f, ifst);
		return (animal*)f;
	case 2:
		b = new bird;
		b->k = BIRD;
		InBird(b, ifst);
		return (animal*)b;
	default:
		return 0;
	}
}

void Out(animal *a, ofstream &ofst) {
	fish *f;
	bird *b;
	switch (a->k) {
	case FISH:
		f = (fish*)a;
		OutFish(f, ofst);
		break;
	case BIRD:
		b = (bird*)a;
		OutBird(b, ofst);
		break;
	default:
		ofst << "Incorrect animal!" << endl;
	}
}

int LengthOfName(animal *a) {
	fish *f;
	bird *b;
	switch (a->k) {
	case FISH:
		f = (fish*)a;
		return LengthOfNameFish(f);
	case BIRD:
		b = (bird*)a;
		return LengthOfNameBird(b);
	}
}

bool Compare(animal *first, animal *second) {
	return LengthOfName(first) < LengthOfName(second);
}
#include "Header.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Protect.h"

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
	CheckInputFile(ifst);
	while (!ifst.eof() && container::max_len != c.len) {
		if ((c.cont[c.len] = In(ifst)) != 0) {
			c.len++;
		}
	}
}

void Out(container &c, ofstream &ofst) {
	CheckOutputFile(ofst);
	if (c.len) 
		ofst << "Container contains " << c.len << " elements." << endl;
	else 
		ofst << "Container is empty:\n";

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

//-----------------------------------------------------
// Вывод только рыб
void OutFish(container &c, ofstream &ofst) {
	CheckOutputFile(ofst);
	if (c.len) {
		ofst << "Container contains " << c.len << " elements." << endl;
		ofst << "Only fishes." << endl;
	}
	else
		ofst << "Container is empty:\n";

	for (int i = 0; i < c.len; i++) {
		if (c.cont[i]->k == key::FISH) {
			ofst << i + 1 << ": ";
			Out((c.cont[i]), ofst);
			ofst << "Length of name = " << LengthOfName(c.cont[i]) << "." << endl;
		}
		else
			ofst << endl;
	}
}

//-----------------------------------------------------
// Вывод только птиц
void OutBird(container &c, ofstream &ofst) {
	CheckOutputFile(ofst);
	if (c.len) {
		ofst << "Container contains " << c.len << " elements." << endl;
		ofst << "Only birds." << endl;
	}
	else
		ofst << "Container is empty:\n";
	
	for (int i = 0; i < c.len; i++) {
		if (c.cont[i]->k == key::BIRD) {
			ofst << i + 1 << ": ";
			Out((c.cont[i]), ofst);
			ofst << "Length of name = " << LengthOfName(c.cont[i]) << "." << endl;
		}
		else
			ofst << endl;
	}
}

//-----------------------------------------------------
// Вывод только зверей
void OutBeast(container &c, ofstream &ofst) {
	CheckOutputFile(ofst);
	if (c.len) {
		ofst << "Container contains " << c.len << " elements." << endl;
		ofst << "Only beasts." << endl;
	}
	else
		ofst << "Container is empty:\n";

	for (int i = 0; i < c.len; i++) {
		if (c.cont[i]->k == key::BEAST) {
			ofst << i + 1 << ": ";
			Out((c.cont[i]), ofst);
			ofst << "Length of name = " << LengthOfName(c.cont[i]) << "." << endl;
		}
		else
			ofst << endl;
	}
}

void InFish(fish* &f, ifstream &ifst) {
	CheckInputFile(ifst);
	ifst.getline(f->name, 256);
	CheckWrongInput(ifst);
	ifst >> f->age;
	CheckWrongInput(ifst);
	CheckAge(f->age);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(1 <= k && k <= 3))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
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
	default:
		cout << "Error! Unknown habitat!" << endl;
		break;
	}
}

void OutFish(fish* &f, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << "It is fish. It is ";
	ofst << f->name << "." << endl;
	ofst << "It is " << f->age << " years old." << endl << "It lives in ";
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
	default:
		cout << "Error! Unknown habitat!" << endl;
		break;
	}
}

void InBird(bird* &b,ifstream &ifst){
	CheckInputFile(ifst);
	ifst.getline(b->name, 256);
	CheckWrongInput(ifst);
	ifst >> b->age;
	CheckWrongInput(ifst);
	CheckAge(b->age);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(0 <= k && k <= 1))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	switch (k) {
	case 0:
		b->migratory = false;
		break;
	case 1:
		b->migratory = true;
		break;
	default:
		cout << "Error! Unknown migratory!" << endl;
		break;
	}
}

void OutBird(bird* &b, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << "It is bird. It is ";
	ofst << b->name << "." << endl;
	ofst << "It is " << b->age << " years old." << endl << "It is ";
	switch (b->migratory) {
	case false:
		ofst << "not ";
		break;
	case true:
		break;
	}
	ofst << "migratory." << endl;
}

void InBeast(beast* &b, ifstream &ifst){
	CheckInputFile(ifst);
	ifst.getline(b->name, 256);
	CheckWrongInput(ifst);
	ifst >> b->age;
	CheckWrongInput(ifst);
	CheckAge(b->age);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	if (!(1 <= k && k <= 3))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	switch (k) {
	case 1:
		b->t = beast::type::PREDATOR;
		break;
	case 2:
		b->t = beast::type::HERBIVORE;
		break;
	case 3:
		b->t = beast::type::INSECTIVORE;
		break;
	default:
		cout << "Error! Unknown type!" << endl;
		break;
	}
}

void OutBeast(beast* &b, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << "It is beast. It is ";
	ofst << b->name << "." << endl;
	ofst << "It is " << b->age << " years old." << endl << "It is ";
	switch (b->t) {
	case beast::type::PREDATOR:
		ofst << "predator." << endl;
		break;
	case beast::type::HERBIVORE:
		ofst << "herbivore." << endl;
		break;
	case beast::type::INSECTIVORE:
		ofst << "insectivore." << endl;
		break;
	default:
		cout << "Error! Unknown type!" << endl;
		break;
	}
}

animal* In(ifstream &ifst) {
	CheckInputFile(ifst);
	animal *a;
	fish *f;
	bird *b;
	beast *be;
	int k1;
	ifst >> k1;
	CheckWrongInput(ifst);
	if (!(1 <= k1 && k1 <= 3))
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	char t[256];
	ifst.getline(t, 256);
	CheckWrongInput(ifst);
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
	case 3:
		be = new beast;
		be->k = BEAST;
		InBeast(be, ifst);
		return (animal*)be;
	default:
		return 0;
	}
}

void Out(animal *a, ofstream &ofst) {
	CheckOutputFile(ofst);
	fish *f;
	bird *b;
	beast *be;
	switch (a->k) {
	case FISH:
		f = (fish*)a;
		OutFish(f, ofst);
		break;
	case BIRD:
		b = (bird*)a;
		OutBird(b, ofst);
		break;
	case BEAST:
		be = (beast*)a;
		OutBeast(be, ofst);
		break;
	default:
		ofst << "Incorrect animal!" << endl;
		break;
	}
}

int LengthOfNameFish(fish *f) {
	return strlen(f->name);
}

int LengthOfNameBird(bird *b) {
	return strlen(b->name);
}

int LengthOfNameBeast(beast *b) {
	return strlen(b->name);
}

int LengthOfName(animal *a) {
	fish *f;
	bird *b;
	beast *be;
	switch (a->k) {
	case FISH:
		f = (fish*)a;
		return LengthOfNameFish(f);
	case BIRD:
		b = (bird*)a;
		return LengthOfNameBird(b);
	case BEAST:
		be = (beast*)a;
		return LengthOfNameBeast(be);
	default:
		cout << "Error! Unknown type!" << endl;
		return 0;
	}
}

bool Compare(animal *first, animal *second) {
	return LengthOfName(first) < LengthOfName(second);
}
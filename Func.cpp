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
	}
}

void InFish(fish* &f, ifstream &ifst) {
	ifst.getline(f->name, 256);
	ifst >> f->age;
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
	}
}

void InBird(bird* &b,ifstream &ifst)
{
	ifst.getline(b->name, 256);
	ifst >> b->age;
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

void InBeast(beast* &b, ifstream &ifst)
{
	ifst.getline(b->name, 256);
	ifst >> b->age;
	int k;
	ifst >> k;
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
	}
}

void OutBeast(beast* &b, ofstream &ofst) {
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
	}
}

animal* In(ifstream &ifst) {
	animal *a;
	fish *f;
	bird *b;
	beast *be;
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
	}
}
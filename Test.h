#include <iostream>
#include <fstream>
#include "Header.h"
#include "FilesCmp.h"

using namespace std;

class FishTest : public ::testing::Test {	
};

TEST_F(FishTest, CheckZeroLength) {
	fish f;
	strcpy_s(f.name,"");
	int expected = 0;
	ASSERT_EQ(expected, LengthOfNameFish(&f));
}

TEST_F(FishTest, CheckLength) {
	fish f;
	strcpy_s(f.name, "Okun");
	int expected = 4;
	ASSERT_EQ(expected, LengthOfNameFish(&f));
}


TEST_F(FishTest, CheckInput) {
	ifstream ifst("InFish.txt");
	fish* actual;
	actual = new fish;
	actual->k = FISH;
	InFish(actual, ifst);
	fish f;
	strcpy_s(f.name, "Okun");
	f.age = 4;
	f.h = fish::habitat::RIVER;
	
	ASSERT_STREQ(actual->name, f.name);
	ASSERT_EQ(actual->age, f.age);
	ASSERT_EQ(actual->h, f.h);
}

TEST_F(FishTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	fish *f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	OutFish(f, ofst);
	ofst.close();
	
	ifstream expected("OutFish.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


//##########################################################################################################
//##########################################################################################################

class BirdTest : public ::testing::Test {
};

TEST_F(BirdTest, CheckZeroLength) {
	bird b;
	strcpy_s(b.name, "");
	int expected = 0;
	ASSERT_EQ(expected, LengthOfNameBird(&b));
}

TEST_F(BirdTest, CheckLength) {
	bird b;
	strcpy_s(b.name, "Sinica");
	int expected = 6;
	ASSERT_EQ(expected, LengthOfNameBird(&b));
}


TEST_F(BirdTest, CheckInput) {
	ifstream ifst("InBird.txt");
	bird* actual;
	actual = new bird;
	actual->k = BIRD;
	InBird(actual, ifst);
	bird b;
	strcpy_s(b.name, "Sinica");
	b.age = 4;
	b.migratory = false;

	ASSERT_STREQ(actual->name, b.name);
	ASSERT_EQ(actual->age, b.age);
	ASSERT_EQ(actual->migratory, b.migratory);
}

TEST_F(BirdTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	bird* b = new bird;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;
	OutBird(b, ofst);
	ofst.close();

	ifstream expected("OutBird.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

class BeastTest : public ::testing::Test {
};

TEST_F(BeastTest, CheckZeroLength) {
	beast be;
	strcpy_s(be.name, "");
	int expected = 0;
	ASSERT_EQ(expected, LengthOfNameBeast(&be));
}

TEST_F(BeastTest, CheckLength) {
	beast be;
	strcpy_s(be.name, "Tiger");
	int expected = 5;
	ASSERT_EQ(expected, LengthOfNameBeast(&be));
}


TEST_F(BeastTest, CheckInput) {
	ifstream ifst("InBeast.txt");
	beast* actual;
	actual = new beast;
	actual->k = BEAST;
	InBeast(actual, ifst);
	beast be;
	strcpy_s(be.name, "Tiger");
	be.age = 4;
	be.t = beast::type::PREDATOR;

	ASSERT_STREQ(actual->name, be.name);
	ASSERT_EQ(actual->age, be.age);
	ASSERT_EQ(actual->t, be.t);
}

TEST_F(BeastTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	beast* be = new beast;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	OutBeast(be, ofst);
	ofst.close();

	ifstream expected("OutBeast.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

class AnimalTest : public ::testing::Test {
};

TEST_F(AnimalTest, CheckInputFish) {
	ifstream ifst("AnimalInFish.txt");
	fish* actual = (fish *)In(ifst);

	fish* expected;
	expected = new fish;
	expected->k = key::FISH;
	strcpy_s(expected->name,"Okun");
	expected->age = 4;
	expected->h = fish::habitat::RIVER;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_STREQ(expected->name, actual->name);
	ASSERT_EQ(expected->age, actual->age);
	ASSERT_EQ(expected->h, actual->h);
}

TEST_F(AnimalTest, CheckInputBird) {
	ifstream ifst("AnimalInBird.txt");
	bird* actual = (bird *)In(ifst);

	bird* expected;
	expected = new bird;
	expected->k = key::BIRD;
	strcpy_s(expected->name, "Sinica");
	expected->age = 4;
	expected->migratory = false;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_STREQ(expected->name, actual->name);
	ASSERT_EQ(expected->age, actual->age);
	ASSERT_EQ(expected->migratory, actual->migratory);
}

TEST_F(AnimalTest, CheckInputBeast) {
	ifstream ifst("AnimalInBeast.txt");
	beast* actual = (beast *)In(ifst);

	beast* expected;
	expected = new beast;
	expected->k = key::BEAST;
	strcpy_s(expected->name, "Tiger");
	expected->age = 4;
	expected->t = beast::type::PREDATOR;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_STREQ(expected->name, actual->name);
	ASSERT_EQ(expected->age, actual->age);
	ASSERT_EQ(expected->t, actual->t);
}

TEST_F(AnimalTest, CheckOutputFish) {
	ofstream ofst("OutTest.txt");

	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;

	Out((animal *)f, ofst);
	ofst.close();

	ifstream expected("AnimalOutFish.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(AnimalTest, CheckOutputBird) {
	ofstream ofst("OutTest.txt");

	bird* b = new bird;
	b->k = key::BIRD;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;

	Out((animal *)b, ofst);
	ofst.close();

	ifstream expected("AnimalOutBird.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(AnimalTest, CheckOutputBeast) {
	ofstream ofst("OutTest.txt");

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;

	Out((animal *)be, ofst);
	ofst.close();

	ifstream expected("AnimalOutBeast.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(AnimalTest, CheckCompare) {
	fish* a1 = new fish;
	a1->k = key::FISH;
	strcpy_s(a1->name, "Okun");

	fish* a2 = new fish;
	a2->k = key::FISH;
	strcpy_s(a2->name, "Shark");

	ASSERT_TRUE(Compare((animal* )a1,(animal *)a2));
}

//#############################################################################################
//#############################################################################################

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckInitContainer) {

	container c;
	Init(c);

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckClearEmptyContainer) {

	container c;
	c.len = 0;
	Clear(c);

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckClearContainer) {

	container c;
	c.len = 0;
	fish* f = new fish;
	c.cont[c.len] = (animal *)f;
	++c.len;
	Clear(c);

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckOutFish) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;
	
	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	c.cont[c.len] = (animal *)f;
	++c.len;

	bird* b = new bird;
	b->k = key::BIRD;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;
	c.cont[c.len] = (animal *)b;
	++c.len;

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	c.cont[c.len] = (animal *)be;
	++c.len;

	OutFish(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutFish.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutBird) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	c.cont[c.len] = (animal *)f;
	++c.len;

	bird* b = new bird;
	b->k = key::BIRD;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;
	c.cont[c.len] = (animal *)b;
	++c.len;

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	c.cont[c.len] = (animal *)be;
	++c.len;

	OutBird(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutBird.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutBeast) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	c.cont[c.len] = (animal *)f;
	++c.len;

	bird* b = new bird;
	b->k = key::BIRD;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;
	c.cont[c.len] = (animal *)b;
	++c.len;

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	c.cont[c.len] = (animal *)be;
	++c.len;

	OutBeast(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutBeast.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	c.cont[c.len] = (animal *)f;
	++c.len;

	bird* b = new bird;
	b->k = key::BIRD;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;
	c.cont[c.len] = (animal *)b;
	++c.len;

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	c.cont[c.len] = (animal *)be;
	++c.len;

	Sort(c);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSort.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEmpty) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	Sort(c);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEmpty.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEqual) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	c.cont[c.len] = (animal *)f;
	++c.len;

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Lion");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	c.cont[c.len] = (animal *)be;
	++c.len;

	Sort(c);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOut) {
	ofstream ofst("OutTest.txt");

	container c;
	c.len = 0;

	fish* f = new fish;
	f->k = key::FISH;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	f->h = fish::habitat::RIVER;
	c.cont[c.len] = (animal *)f;
	++c.len;

	bird* b = new bird;
	b->k = key::BIRD;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	b->migratory = false;
	c.cont[c.len] = (animal *)b;
	++c.len;

	beast* be = new beast;
	be->k = key::BEAST;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	be->t = beast::type::PREDATOR;
	c.cont[c.len] = (animal *)be;
	++c.len;

	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOut.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}
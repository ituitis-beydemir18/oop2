/*
* Student Name: Mertcan YASAKÇI
* Student ID: 150140051
* Date: 22/04/2016
*/

#include <iostream>

using namespace std;

enum outcome
{
	Lose = 0,
	Tie = 1,
	Win = 2
};

///////////////////////////////////////////////////////////
//	BASE CLASS
//
//	ABSTRACT CLASS
//
//	Constructor	->	sets its next pointer to NULL
//	setNext		->	sets its next pointer according to given parameter
//	getNext		->	returns its next pointer
//	setResult	->	sets its result according to given parameter
//	getResult	->	returns its result
///////////////////////////////////////////////////////////
class Base
{
public:
	Base();
	virtual ~Base();
	virtual void compare(Base*) = 0;
	virtual char getType() = 0;
	void setNext(Base*);
	Base* getNext();
	void setResult(outcome);
	outcome getResult();
private:
	outcome result;
	Base* next;
};

Base::Base()
{
	//cout << "Base constructor" << endl;
	next = NULL;
}

Base::~Base()
{
	//cout << "Base destructor" << endl;
}

void Base::setNext(Base* t){
	next = t;
}

Base* Base::getNext(){
	return next;
}

void Base::setResult(outcome o){
	result = o;
}

outcome Base::getResult(){
	return result;
}

///////////////////////////////////////////////////////////
//	RED CLASS DERIVED FROM BASE CLASS
//
//	compare	->	takes a parameter compares them and then set the results of both object
//	getType	->	return character 'R'
//
///////////////////////////////////////////////////////////

class Red: public Base
{
public:
	Red();
	~Red();
	void compare(Base*);
	char getType();
private:
	
};

Red::Red()
{
	//cout << "Red constructor" << endl;
}

Red::~Red()
{
	//cout << "Red destructor" << endl;
}

void Red::compare(Base* t){
	if (t->getType() == 'R'){
		setResult(Tie);
		t->setResult(Tie);
	}
	else if (t->getType() == 'D' || t->getType() == 'B'){
		setResult(Lose);
		t->setResult(Win);
	}
	else if (t->getType() == 'G'){
		setResult(Win);
		t->setResult(Lose);
	}
}

char Red::getType(){
	return 'R';
}

///////////////////////////////////////////////////////////
//	DARK RED CLASS DERIVED FROM RED CLASS
//
//	compare	->	takes a parameter compares them and then set the results of both object
//	getType	->	return character 'D'
//
///////////////////////////////////////////////////////////

class DarkRed: public Red
{
public:
	DarkRed();
	~DarkRed();
	void compare(Base*);
	char getType();
private:
	
};

DarkRed::DarkRed()
{
	//cout << "Dark Red constructor" << endl;
}

DarkRed::~DarkRed()
{
	//cout << "Dark Red destructor" << endl;
}

void DarkRed::compare(Base* t){
	if (t->getType() == 'D'){
		setResult(Tie);
		t->setResult(Tie);
	}
	else if (t->getType() == 'G'){
		setResult(Lose);
		t->setResult(Win);
	}
	else if (t->getType() == 'R' || t->getType() == 'B'){
		setResult(Win);
		t->setResult(Lose);
	}
}

char DarkRed::getType(){
	return 'D';
}

///////////////////////////////////////////////////////////
//	BLUE CLASS DERIVED FROM BASE CLASS
//
//	compare	->	takes a parameter compares them and then set the results of both object
//	getType	->	return character 'B'
//
///////////////////////////////////////////////////////////

class Blue : public Base
{
public:
	Blue();
	~Blue();
	void compare(Base*);
	char getType();
private:
	
};

Blue::Blue()
{
	//cout << "Blue constructor" << endl;
}

Blue::~Blue()
{
	//cout << "Blue destructor" << endl;
}

void Blue::compare(Base* t){
	if (t->getType() == 'B'){
		setResult(Tie);
		t->setResult(Tie);
	}
	else if (t->getType() == 'D' || t->getType() == 'G'){
		setResult(Lose);
		t->setResult(Win);
	}
	else if (t->getType() == 'R'){
		setResult(Win);
		t->setResult(Lose);
	}
}

char Blue::getType(){
	return 'B';
}

///////////////////////////////////////////////////////////
//	GREEN CLASS DERIVED FROM BASE CLASS
//
//	compare	->	takes a parameter compares them and then set the results of both object
//	getType	->	return character 'G'
//
///////////////////////////////////////////////////////////

class Green : public Base
{
public:
	Green();
	~Green();
	void compare(Base*);
	char getType();
private:
	
};

Green::Green()
{
	//cout << "Green constructor" << endl;
}

Green::~Green()
{
	//cout << "Green destructor" << endl;
}

void Green::compare(Base* t){
	if (t->getType() == 'G'){
		setResult(Tie);
		t->setResult(Tie);
	}
	else if (t->getType() == 'R'){
		setResult(Lose);
		t->setResult(Win);
	}
	else if (t->getType() == 'D' || t->getType() == 'B'){
		setResult(Win);
		t->setResult(Lose);
	}
}

char Green::getType(){
	return 'G';
}

///////////////////////////////////////////////////////////
//	HETLIST CLASS
//
//	Constructor	->	sets list's head pointer to NULL
//	Destructor	->	deletes the nodes while traversing the list
//	insert		->	takes a parameter and then places it to the head of the list
//	getHead		->	returns list's head pointer
//	compare		->	starts from head of list and compares all card while traversing the list
//
///////////////////////////////////////////////////////////

class HetList
{
public:
	HetList();
	~HetList();
	void insert(Base*);
	Base* getHead();
	void compare(HetList&);
private:
	Base* head;
};

HetList::HetList()
{
	head = NULL;
	//cout << "HetList consctructor" << endl;
}

HetList::~HetList()
{
	//cout << "HetList desctructor - Start" << endl;
	if (head){
		Base* temp;
		temp = head;
		while (head){
			temp = head;
			head = head->getNext();
			delete temp;
		}
	}
	//cout << "HetList desctructor - Finish" << endl;
}

void HetList::insert(Base* t){
	if (head){
		Base* temp;
		temp = head;
		head = t;
		head->setNext(temp);
	}
	else{
		head = t;
		head->setNext(NULL);
	}
}

Base* HetList::getHead(){
	return head;
}

void HetList::compare(HetList&otherPlayer){
	Base *i, *j;
	for (i = head, j = otherPlayer.getHead(); i != NULL, j != NULL; i = i->getNext(), j = j->getNext()){
		i->compare(j);
	}
}
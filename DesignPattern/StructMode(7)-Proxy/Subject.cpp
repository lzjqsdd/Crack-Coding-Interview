#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject(){}
Subject::~Subject(){}
void Subject::Operation(){}

ConcreteSubject::ConcreteSubject(){}
ConcreteSubject::~ConcreteSubject(){}
void ConcreteSubject::Operation()
{
    cout << "ConcreteSubject Operation ..." << endl;
}
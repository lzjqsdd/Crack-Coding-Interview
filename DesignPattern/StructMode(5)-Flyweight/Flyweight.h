#ifndef _FLYWEIGHT_H
#define _FLYWEIGHT_H
#include <string>
using namespace std;

class Flyweight
{
  public:
    virtual ~Flyweight();
    virtual void Operation(const string &extrinsicState);
    string GetIntrinsicState();

  protected:
    Flyweight(string intrinsicState);

  private:
    string _intrinsicState;
};

class ConcreteFlyweight : public Flyweight
{
  public:
    ConcreteFlyweight(string intrinsicState);
    ~ConcreteFlyweight();
    void Operation(const string &extrinsicState);

  protected:
  private:
};

#endif
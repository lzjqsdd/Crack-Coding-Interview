#include <iostream>
#include <string>
using namespace std;


int age = 10;

class Person
{
public:
  typedef std::string::size_type H;
  Person(H height,unsigned int age = 20,string name = "Alice"):
    age(age),
    name(name)
  {
    ::age = 20;
  }

  Person(int agee)
  {
    age = agee;
  }

  Person(string name)
  {
  }

  Person() = default;
  inline void show()
  {
    cout << ::age << endl;
    cout << name << endl;
  }

  Person& add(const Person &p)
  {
    age += p.age;
    this->name = p.name;
    return *this;
  }
private:
  unsigned int age;
  string name;
};


int main()
{ 
  Person person;

  int agee = 24;
  string name = "lzjqsdd";
  person.add(name);
  person.show();
  return 0;
}

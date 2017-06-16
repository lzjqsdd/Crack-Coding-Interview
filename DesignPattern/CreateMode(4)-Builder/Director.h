#ifndef _DIRECTOR_H_
#define _DIRECTOR_H

class Builder;
class Director
{
public:
    Director(Builder* bld);
    ~Director();
    void Construct();
protected:
private:
    Builder* _bld; //设计师管理者建筑师（工人）
};


#endif
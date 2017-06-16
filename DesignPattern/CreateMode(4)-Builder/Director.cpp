#include "Director.h"
#include "Builder.h"

Director::Director(Builder *bld)
{
    _bld = bld;
}

Director::~Director()
{

}

void Director::Construct() //设计师来指定每层的建筑风格
{
    _bld->BuilderPartA("user-defined");
    _bld->BuilderPartB("user-defined");
    _bld->BuilderPartC("user-defined");
    _bld->BuilderPartD("user-defined");
}
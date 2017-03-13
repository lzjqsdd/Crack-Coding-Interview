#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
//Product类
class Product
{
    vector<string> parts;
public:
    void Add(const string part)
    {
        parts.push_back(part);
    }
    void Show()const
    {
        for(int i = 0 ; i < parts.size() ; i++)
        {
            cout<<parts[i]<<endl;
        }
    }
};
//抽象builder类
class Builder
{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildHand() = 0;
    virtual void BuildFeet() = 0;
    virtual Product GetResult() = 0; 
};
//具体胖人创建类
class FatPersonBuilder :public Builder
{
private:
    Product product;
public:
    virtual void BuildHead()
    {
        product.Add("胖人头");//创建瘦人的头
    }
    virtual void BuildBody()
    {
        product.Add("胖人身体");//创建瘦人的身体
    }
    virtual void BuildHand()
    {
        product.Add("胖人手");//创建瘦人的手
    }
    virtual void BuildFeet()
    {
        product.Add("胖人脚");//创建瘦人的脚
    }
    virtual Product GetResult()
    {
        return product;
    }
};
//具体瘦人人创建类
class ThinPersonBuilder :public Builder
{
private:
    Product product;
public:
    virtual void BuildHead()
    {
        product.Add("瘦人人头");//创建瘦人的头
    }
    virtual void BuildBody()
    {
        product.Add("瘦人身体");//创建瘦人的身体
    }
    virtual void BuildHand()
    {
        product.Add("瘦人手");//创建瘦人的手
    }
    virtual void BuildFeet()
    {
        product.Add("瘦人脚");//创建瘦人的脚
    }
    virtual Product GetResult()
    {
        return product;
    }
};
//Director类
class Director
{
public:
    void Construct(Builder &builder)
    {
        builder.BuildHead();
        builder.BuildBody();
        builder.BuildHand();
        builder.BuildFeet();
    }
};

int main()
{
    Director *director = new Director();
    Builder *b1 = new FatPersonBuilder();
    Builder *b2 = new ThinPersonBuilder();

    director->Construct(*b1);
    Product p1 = b1->GetResult();
    p1.Show(); 
    return 0;
}
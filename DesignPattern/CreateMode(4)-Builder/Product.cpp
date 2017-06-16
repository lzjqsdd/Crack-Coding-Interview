//Product.cpp
#include "Product.h"
#include <iostream>
using namespace std;

Product::Product()
{
    ProductPart();
    cout << "return a product" << endl;
}

Product::~Product()
{

}

void Product::ProducePart()
{
    cout << "build part of product..." << endl;
}

ProductPart::ProductPart()
{
    
}

ProductPart::~ProductPart()
{

}

ProductPart* ProductPart::BuildPart()
{
    return new ProductPart;
}
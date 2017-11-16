//不要对数组使用多态
#include <iostream>
using namespace std;

class BST
{
public:
	int a;
	BST(){a = N;N++;}
	friend ostream& operator<<(ostream &os,const BST& bst)
	{
		os << bst.a << ",";
		return os;
	}
	~BST(){cout << "dtor BST ... "<<  a  << endl;}
	static int N;
};

int BST::N = 0;

class BalancedBST:public BST
{
public:
	BalancedBST(){b = 2;}
	~BalancedBST(){cout << "dtor BalancedBST ... " << endl;}
private:
	int b;
};



void PrintBSTArray(ostream& s,const BST array[],int numElements)
{
	for(int i=0;i<numElements;++i)
		s << array[i];
}

void DeleteBST(ostream&os,BST array[])
{
	os << "Deleting array at address " << static_cast<void*>(array) << endl;	
	delete[] array; //这里每个array[i]对应的地址对么？
}

void DeleteBSTP(ostream&os,BST *array)
{
	os << "Deleting array at address " << static_cast<void*>(array) << endl;	
	delete[] array; //这里每个array[i]对应的地址对么？
}

int main()
{
	BST Array[10];
	PrintBSTArray(cout,Array,10);
	cout << endl;
	//如果数组是子类
	BalancedBST bArray[10];
	PrintBSTArray(cout,bArray,10); //这个时候输出就不对了
	cout << endl;

	//如果删除数组呢？
	//DeleteBST(cout,Array);
	//DeleteBST(cout,bArray); //死循环掉了


	BST *parray = new BalancedBST[10];
	DeleteBSTP(cout,parray);
	//DeleteBSTP(cout,bArray);
	//DeleteBST(cout,parray);
	
}

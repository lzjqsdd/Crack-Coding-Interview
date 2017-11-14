//Traits是为了解决模板类型中因类型差异而导致的算法的部分处理逻辑发生变化。
//然而我们在封装泛型算法时又不希望用户察觉到类型带来的差异，所以需要在算法
//内部处理这些差异。

//如下例子

//#include <iostream>
//using namespace std;

//比如某个算法需要判断类型是不是指针类型
//template<typename T,bool isPointer>
//class Test{

//};

//但是这种方式需要用户来传递isPointer,显然给用户带来了负担

/*
template <typename T>
struct TraitsHelper{
	static const bool isPointer = false;
};

template<typename T>
struct TraitsHelper<T*>{
	static const bool isPointer = true;
};

template<typename T>
class Test{
public:
	void printValue(T a);
};

template<typename T>
void Test<T>::printValue(T a)
{
	if(TraitsHelper<T>::isPointer) cout << *a << endl;	
	else cout << a << endl;
}
*/

template<typename T>
struct TraitsHelper{
	typedef T ret_type;
	typedef T par_type;
};

template<>
struct TraitsHelper<int>{
	typedef int ret_type;
	typedef int par_type;
};

template<>
struct TraitsHelper<float>{
	typedef float ret_type;
	typedef float par_type;
};

template<typename T>
class Test{
public:
	typename TraitsHelper<T>::ret_type Compuate(typename TraitsHelper<T>::par_type d);
private:
	T mData;
};

TraitsHelper<int>::ret_type Compuate(TraitsHelper<int>::par_type d)
{
	return d;
}

int main()
{
	Test<double> tt;
	tt.Compuate(20.0);
}

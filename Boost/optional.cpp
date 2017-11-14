#include <iostream>
#include <string>
#include <sstream>

#include <boost/optional.hpp>

using namespace std;

boost::optional<int> convert(const std::string& text)
{
    std::stringstream s(text);
    int i;
    if((s >> i) && s.get() == std::char_traits<char>::eof())
        return i;
    else
        return boost::none;
}


int main()
{
    //optional用于接收返回值不在取值范围内的数据，比如EOF,NULL等
    //const std::string& text = "123a4";
    const std::string& text = "123";
    boost::optional<int> oi = convert(text);
    //optional 是UB-Safe的
    //if(oi) cout << *oi << endl;
    int k = oi.value_or(0);
    cout << k << endl;


    //关于is_initialized
    boost::optional<int> xx;
    assert(x.is_initialized());
}

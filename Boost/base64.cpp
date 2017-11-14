#include <iostream>
#include <string>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

std::string EncodeBase64(const std::string &val)
{
    using namespace boost::archive::iterators;
    typedef base64_from_binary<transform_width<std::string::const_iterator,6,8>> It;
    auto tmp = std::string(It(val.begin()),It(val.end()));
    return tmp.append((3 - val.size() % 3) % 3,'=');
}

int main()
{
    std::string s;
    while(std::cin >> s)
    {
        std::string res = EncodeBase64(s);
        std::cout << res << std::endl;
    }
    return 0;
}

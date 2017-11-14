#include <openssl/md5.h>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// Print the MD5 sum as hex-digits.
void print_md5_sum(unsigned char* md) {
    for(unsigned i=0; i <MD5_DIGEST_LENGTH; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(md[i]);
    }
    std::cout << std::endl;
}

std::string to_string(unsigned char*md){

    string as;
    std::ostringstream ss;
    
    for(unsigned i=0; i <MD5_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(md[i]);
    }
    as = std::move(string(ss.str()));
    return as;
}

#include <string>
#include <vector>
#include <fstream>

int main(int argc, char *argv[]) {
    using namespace std;
    vector<string> const args(argv+1, argv+argc);

    MD5_CTX ctx;
    MD5_Init(&ctx);
    unsigned char digest[MD5_DIGEST_LENGTH] = {};
    char file_buffer[4096];
    for (auto& fname : args) {
        ifstream ifs(fname, std::ios::binary);

        while (ifs.read(file_buffer, sizeof(file_buffer)) || ifs.gcount()) {
            MD5_Update(&ctx, file_buffer, ifs.gcount());
        }
    }
    MD5_Final(digest, &ctx);
    //print_md5_sum(digest);
    //std::cout << string(digest) << std::endl;
    //std::cout << "\t" << fname << "\n";
    std::cout << to_string(digest) << endl;
}

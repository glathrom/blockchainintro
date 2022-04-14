#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <openssl/sha.h>


int main(){
    std::string buf = "this is my message";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    std::stringstream out;

    SHA256_CTX  sha256;
   
    SHA256_Init(&sha256);  
   
    SHA256_Update(&sha256, buf.c_str(), buf.size());

    SHA256_Final(hash, &sha256);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++ )
        out << std::hex << (int) hash[i];

    std::cout << out.str() << std::endl;

    return 0;
}

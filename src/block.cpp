#include <string>
#include <iostream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include "block.hpp"


Block::Block(uint32_t nIndexIn, const std::string &sDataIn){
    _nIndex = nIndexIn;
    _sData = sDataIn;
    _nNonce  = -1;
    _tTime = time(NULL);    
}


std::string Block::GetHash(){
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty){
    char cstr[nDifficulty+1];

    for( uint32_t i = 0; i < nDifficulty; i++ )
        cstr[i] = '0';
    cstr[nDifficulty] = '\0';

    std::string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while( _sHash.substr(0, nDifficulty) != str);
    
    std::cout << "Block mined: " << _sHash << std::endl;
    std::cout << "Time: " << _tTime << std::endl;
    std::cout << "Nonce: " << _nNonce << std::endl;
}

std::string Block::_CalculateHash() const {
    std::stringstream ss; 
    std::stringstream out;
    SHA256_CTX sha256;
    unsigned char hash[SHA256_DIGEST_LENGTH];

    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, ss.str().c_str(), ss.str().size());
    SHA256_Final(hash, &sha256);

    for( int i = 0; i < SHA256_DIGEST_LENGTH; i++ )
       out << std::hex << std::setw(2) << std::setfill('0') << (int) hash[i];


   return out.str(); 
}

#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include <openssl/sha.h>
#include "block.hpp"



class Blockchain {
    public:
        Blockchain();
        void AddBlock(Block bNew);

    private:
        uint32_t _nDifficulty;
        std::vector<Block> _vChain;

        Block _GetLastBlock() const;
};



#endif 

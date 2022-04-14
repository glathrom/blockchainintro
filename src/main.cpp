#include <iostream>
#include "blockchain.hpp"



int main(void)
{
    Blockchain bChain = Blockchain();

    std::cout << "Mining block 1..." << std::endl;
    bChain.AddBlock(Block(1, "Block 1 Data"));
    
    std::cout << "Mining block 2..." << std::endl;
    bChain.AddBlock(Block(1, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    bChain.AddBlock(Block(1, "Block 3 Data"));


    return 0;
}

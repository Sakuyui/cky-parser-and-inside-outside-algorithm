#include "printer.hpp"


void print_grammar(pcfg* grammar){
    int N = grammar->N();
    for(std::tuple<uint32_t, uint32_t, uint32_t, float, uint32_t> item : 
        PCFGItemIterator(N, (uint32_t*) grammar->grammar_index, (uint32_t*) grammar->grammar_table)){
        uint32_t sym_A = std::get<0>(item);
        uint32_t sym_B = std::get<1>(item);
        uint32_t sym_C = std::get<2>(item);
        float possibility = std::get<3>(item);
        uint32_t gid = std::get<4>(item);
        std::cout << "[" << gid << "] " << SYMBOL_STR(grammar, sym_A, N) << " -> " << SYMBOL_STR(grammar, sym_B, N) << " " <<
            SYMBOL_STR(grammar, sym_C, N)  << " [" << possibility << "]" << std::endl;
    }
}
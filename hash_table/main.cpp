#include "hash_table.hpp"

int main() {
    Hash_table<int,std::string> ht(2);
    ht.insert(2, "asd");
    ht.insert(22, "sadads");
    ht.emplace(211, "ASDa");
    Hash_table<int,std::string> ht2(std::move(ht));
    

}

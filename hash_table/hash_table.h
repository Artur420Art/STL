#include <iostream>
#include <vector>
#include <list>

template <typename Key, typename Value>
class Hash_table {
private: 
    std::vector<std::list<std::pair<Key, Value>>> buckets;
    size_t num_buckets;
    size_t num_elem;
    size_t hashFunction(const Key& key);
public:
    void insert(Key key, Value value);
    void emplace(Key key, Value value);
    Hash_table(const Hash_table& obj);
    void erase_(Key key);
    void print();
    bool contains(Key key);
    Value find(Key key);
    Hash_table(size_t num_buck);
    Value operator[](const Key& key);
    Value operator =(const Hash_table& obj);

};
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
    Hash_table(size_t num_buck = 1);
    Hash_table(Hash_table&&);
    void clear();
    Value operator[](const Key& key);
    Hash_table& operator =(const Hash_table& obj);
    Hash_table& operator =(Hash_table&& obj);
    friend std::ostream& operator<<(std::ostream& os, const Hash_table& obj) {
        for (int i = 0; i < obj.buckets.size(); i++) {
            for (auto it : obj.buckets[i]) {
                os << '[' << it.first << ']' << ' =  ' << it.second << '\n';
            }
        }
        return os;
    }
};

#include "hash_table.h"
template <typename Key, typename Value>
size_t Hash_table<Key, Value>::hashFunction(const Key& key) {
    return key % this->num_buckets;
}

template <typename Key, typename Value>
bool Hash_table<Key, Value>::contains(Key key) {
    size_t index = hashFunction(key);
    auto& buck = buckets[index];
    for(auto it : buck) {
        if (it.first == key) {
            return true;
        }
    }
    return false;
}

template <typename Key, typename Value>
void Hash_table<Key, Value>::emplace(Key key, Value value) {
  size_t bucket_index = hashFunction(key);
    auto& bucket = buckets[bucket_index];
    for (auto& kv : bucket) {
        if (kv.first == key) {
            kv.second = value;
            return;
        }
    }
    bucket.emplace_back(key, value);
    ++num_elem;
}
template <typename Key, typename Value>
void Hash_table<Key, Value>::insert(Key key, Value val) {
    size_t index = hashFunction(key);
        auto buck = buckets[index];
        for (auto it : buck) {
            if(it.first == key) {
                it.second = val;
            }
        
    }
    buckets[index].push_back(std::make_pair(key, val));
}
template <typename Key, typename Value>
void Hash_table<Key, Value>::print() {
        for (size_t i = 0; i < buckets.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& element : buckets[i]) {
                std::cout << "(" << element.first << ", " << element.second << ") ";
            }
            std::cout << std::endl;
        }
    }
template <typename Key, typename Value>
Hash_table<Key, Value>::Hash_table(size_t numBuckets) : num_buckets(numBuckets), num_elem(0) {
        buckets.resize(numBuckets);
}
 
template <typename Key, typename Value>
void Hash_table<Key, Value>::erase_(Key key) {
    int index = hashFunction(key);
    auto& buck = buckets[index];
    for (auto it = buck.begin(); it != buck.end(); ++it) {
        if(it->first == key) {
            buck.erase(it);
            num_elem--;
            return;
        }
    }
}

template <typename Key, typename Value>
Value Hash_table<Key, Value>::find(Key key) {
    int index = hashFunction(key);
    auto buck = buckets[index];
        for (auto it : buck) {
            if(it.first == key) {
                return it.second;
            }  
    }
    throw std::invalid_argument("404");
}

template<typename Key, typename Value>
Value Hash_table<Key, Value>::operator[](const Key& key) {
    int index = hashFunction(key);
    auto buck = buckets[index];
    for(auto it  : buck) {
        if (key == it.first) {
            return it.second;
        }
    }
    throw std::invalid_argument("404");
}

template<typename Key, typename Value>
Hash_table<Key, Value>::Hash_table(const Hash_table& obj) {
    this->buckets.resize(obj.buckets.size());
    for (int i = 0; i < obj.buckets.size(); i++) {
        this->buckets[i] = obj.buckets[i];
    }
    this->num_buckets = obj.num_buckets;
    this->num_elem = obj.num_elem;
};

template<typename Key, typename Value>
Value Hash_table<Key, Value>::operator=(const Hash_table& obj) {
  this->buckets.resize(obj.buckets.size());
    for (int i = 0; i < obj.buckets.size(); i++) {
        this->buckets[i] = obj.buckets[i];
    }
    this->num_buckets = obj.num_buckets;
    this->num_elem = obj.num_elem;
}

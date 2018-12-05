#include <iostream>
#include "cheaters.h"
#include <vector>
#include <fstream>
#include <map>

using namespace std;
int main() {
    //std::cout << "Hello, World!" << std::endl;


    ifstream file("test.txt");
    map<const char *, int> plagFile;
    map<string, int>       strPlagFile;

    string temp_str;
    int counter = 0;
    while (!file.eof())
    {
        file >> temp_str;
        cout << "PARSED:    " << temp_str << "\n";
        cout << "INSERTING: " << (unsigned long) temp_str.c_str() << "\n";
        plagFile.insert(make_pair(temp_str.c_str(), counter));
        strPlagFile.insert(make_pair(temp_str, counter));
        counter++;
    }

    cout << "Amount of Files: " << plagFile.size() << "\n";
    cout << "Str File Size: " << strPlagFile.size() << "\n";

    for (map<const char*, int>::const_iterator iter = plagFile.begin();
         iter != plagFile.end();
         ++iter)
    {
        cout << "CHAR * DICTINARY: " << iter->first << " -> " << iter->second << "\n";
    }

    for (map<string, int>::const_iterator iter = strPlagFile.begin();
         iter != strPlagFile.end();
         ++iter)
    {
        cout << "STR DICTIONARY: " << iter->first << " -> " << iter->second << "\n";
    }
    //return 1;

    // Hash map class template

    HashMap<int, int> *h = new HashMap<int, int>;
    h->insertNode(2, 1);
    h->insertNode(2,2);
    h->insertNode(2,3);
    h->display();
    cout << h->sizeofMap() <<endl;
    cout << h->deleteNode(2) << endl;
    cout << h->sizeofMap() <<endl;
    cout << h->isEmpty() << endl;
    cout << h->get(2);

    /*template<typename K, typename V, typename F = KeyHash<K>>
    class HashMap {
    public:
        HashMap() {
            // construct zero initialized hash table of size
            table = new HashNode<K, V> *[TABLE_SIZE]();
        }

        ~HashMap() {
            // destroy all buckets one by one
            for (int i = 0; i < TABLE_SIZE; ++i) {
                HashNode<K, V> *entry = table[i];
                while (entry != NULL) {
                    HashNode<K, V> *prev = entry;
                    entry = entry->getNext();
                    delete prev;
                }
                table[i] = NULL;
            }
            // destroy the hash table
            delete [] table;
        }

        bool get(const K &key, V &value) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *entry = table[hashValue];

            while (entry != NULL) {
                if (entry->getKey() == key) {
                    value = entry->getValue();
                    return true;
                }
                entry = entry->getNext();
            }
            return false;
        }

        void put(const K &key, const V &value) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *prev = NULL;
            HashNode<K, V> *entry = table[hashValue];

            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }

            if (entry == NULL) {
                entry = new HashNode<K, V>(key, value);
                if (prev == NULL) {
                    // insert as first bucket
                    table[hashValue] = entry;
                } else {
                    prev->setNext(entry);
                }
            } else {
                // just update the value
                entry->setValue(value);
            }
        }

        void remove(const K &key) {
            unsigned long hashValue = hashFunc(key);
            HashNode<K, V> *prev = NULL;
            HashNode<K, V> *entry = table[hashValue];

            while (entry != NULL && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }

            if (entry == NULL) {
                // key not found
                return;
            }
            else {
                if (prev == NULL) {
                    // remove first bucket of the list
                    table[hashValue] = entry->getNext();
                } else {
                    prev->setNext(entry->getNext());
                }
                delete entry;
            }
        }

    private:
        // hash table
        HashNode<K, V> **table;
        F hashFunc;
    };*/


    return 0;
}
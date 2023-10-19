#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTableDouble {
private:
    std::vector<std::vector<std::list<std::pair<int, std::string>>> > first_level;
    int n;

    int first_level_hash(int key) {
        return key % 10;  // Função de hash para o primeiro nível
    }

    int second_level_hash(int key) {
        return key % (n / 10);  // Função de hash para o segundo nível
    }

public:
    HashTableDouble(int n) {
        this->n = n;
        first_level.resize(10);
    }

    void insert(int key, const std::string& value) {
        int first_hash = first_level_hash(key);
        int second_hash = second_level_hash(key);

        if (first_level[first_hash].empty()) {
            first_level[first_hash].resize(n / 10);
        }

        first_level[first_hash][second_hash].push_back(std::make_pair(key, value));
    }

    std::string search(int key) {
        int first_hash = first_level_hash(key);
        int second_hash = second_level_hash(key);

        if (!first_level[first_hash].empty()) {
            for (const auto& entry : first_level[first_hash][second_hash]) {
                if (entry.first == key) {
                    return entry.second;
                }
            }
        }

        return "Chave não encontrada";
    }
};

int main() {
    HashTableDouble hash_table(100);

    hash_table.insert(15, "Objeto A");
    hash_table.insert(27, "Objeto B");

    std::string result = hash_table.search(15);
    if (result != "Chave não encontrada") {
        std::cout << "Valor encontrado: " << result << std::endl;
    } else {
        std::cout << "Chave não encontrada" << std::endl;
    }

    return 0;
}
# Implementação dos algoritmos de Força Bruta e Busca Exaustiva

Table of Contents:

- [Binary Search](#binary-search)
  - [Binary Search - Implementação](#binary-search---implementação)
  - [Binary Search - Análise](#binary-search---análise)
    - [Binary Search - Expressão Matemática](#binary-search---expressão-matemática)
    - [Binary Search - Cálculo da função de custo](#binary-search---cálculo-da-função-de-custo)
    - [Binary Search - Indicação da classe de eficiência](#binary-search---indicação-da-classe-de-eficiência)
- [Interpolation Search](#interpolation-search)
  - [Interpolation Search - Implementação](#interpolation-search---implementação)
  - [Interpolation Search - Análise](#interpolation-search---análise)
    - [Interpolation Search - Expressão Matemática](#interpolation-search---expressão-matemática)
    - [Interpolation Search - Cálculo da função de custo](#interpolation-search---cálculo-da-função-de-custo)
    - [Interpolation Search - Indicação da classe de eficiência](#interpolation-search---indicação-da-classe-de-eficiência)
- [Binary Search Tree](#binary-search-tree)
  - [Binary Search Tree - Implementação](#binary-search-tree---implementação)
  - [Binary Search Tree - Análise](#binary-search-tree---análise)
    - [Binary Search Tree - Expressão Matemática](#binary-search-tree---expressão-matemática)
    - [Binary Search Tree - Cálculo da função de custo](#binary-search-tree---cálculo-da-função-de-custo)
    - [Binary Search Tree - Indicação da classe de eficiência](#binary-search-tree---indicação-da-classe-de-eficiência)

## Binary Search

### Binary Search - Implementação

```c++
int binary_search(std::vector<int> vector, int key) {
    int left = 0, right = vector.size() - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2; //floor since it truncates and rounds down on positive integers
        if (key == vector[middle])
            return middle;
        else if (key < vector[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
```

### Binary Search - Análise

#### Binary Search - Expressão Matemática

#### Binary Search - Cálculo da função de custo

#### Binary Search - Indicação da classe de eficiência

## Interpolation Search

### Interpolation Search - Implementação

```c++
int interpolation_search(std::vector<int> vector, int key) {
    int left = 0, right = vector.size() - 1;
    while (left <= right && key >= vector[left] && key <= vector[right]) {
        if (left == right) {
            if (vector[left] == key) {
                return left;
            }
            return -1;
        }
        int position = left + ((key - vector[left]) * (right - left) / (vector[right] - vector[left]));
        if (vector[position] == key) {
            return position;
        } else if (vector[position] < key) {
            left = position + 1;
        } else {
            right = position - 1;
        }
    }
    return -1;
}
```

### Interpolation Search - Análise

#### Interpolation Search - Expressão Matemática

#### Interpolation Search - Cálculo da função de custo

#### Interpolation Search - Indicação da classe de eficiência

## Binary Search Tree

### Binary Search Tree - Implementação

```c++
void BinarySearchTree::insert(const int &element) {
    if (!root) {
        root = std::make_shared<Node>(element);
        return;
    }

    std::shared_ptr<Node> current_node = root;
    std::shared_ptr<Node> next_node = current_node;
    while (next_node != nullptr) {
        current_node = next_node;
        if (element < current_node->value) {
            next_node = current_node->left;
        } else if (element > current_node->value) {
            next_node = current_node->right;
        } else {
            return; // don't duplicate elements
        }
    } // while loop breaks when it has found a leaf node that should receive a new child node
    if (element < current_node->value) {
        current_node->left = std::make_shared<Node>(element);
    } else if (element > current_node->value) {
        current_node->right = std::make_shared<Node>(element);
    }
    return;
}

std::shared_ptr<BinarySearchTree::Node> BinarySearchTree::search(int key) {
    std::shared_ptr<BinarySearchTree::Node> current_node = root;
    while (current_node != nullptr) {
        if (key == current_node->value) {
            return current_node;
        } else if (key < current_node->value) {
            current_node = current_node->left;
        } else if (key > current_node->value) {
            current_node = current_node->right;
        }
    }
    return nullptr;
}
```

### Binary Search Tree - Análise

#### Binary Search Tree - Expressão Matemática

#### Binary Search Tree - Cálculo da função de custo

#### Binary Search Tree - Indicação da classe de eficiência

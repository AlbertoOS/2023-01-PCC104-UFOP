# Implementação dos algoritmos de Dividir e Conquistar

Table of Contents:

- [Maior elemento em um arranjo](#maior-elemento-em-um-arranjo)
  - [Maior elemento em um arranjo - Implementação](#maior-elemento-em-um-arranjo---implementação)
  - [Maior elemento em um arranjo - Análise](#maior-elemento-em-um-arranjo---análise)
    - [Maior elemento em um arranjo - Cálculo da função de custo](#maior-elemento-em-um-arranjo---cálculo-da-função-de-custo)
- [Merge Sort](#merge-sort)
  - [Merge Sort - Implementação](#merge-sort---implementação)
  - [Merge Sort - Análise](#merge-sort---análise)
    - [Merge Sort - Expressão Matemática](#merge-sort---expressão-matemática)
    - [Merge Sort - Cálculo da função de custo](#merge-sort---cálculo-da-função-de-custo)
    - [Merge Sort - Indicação da classe de eficiência](#merge-sort---indicação-da-classe-de-eficiência)
- [Quick Sort](#quick-sort)
  - [Quick Sort - Implementação](#quick-sort---implementação)
  - [Quick Sort - Análise](#quick-sort---análise)
    - [Quick Sort - Melhor Caso](#quick-sort---melhor-caso)
    - [Quick Sort - Pior Caso](#quick-sort---pior-caso)
    - [Quick Sort - Expressão Matemática](#quick-sort---expressão-matemática)
    - [Quick Sort - Cálculo da função de custo](#quick-sort---cálculo-da-função-de-custo)
    - [Quick Sort - Indicação da classe de eficiência](#quick-sort---indicação-da-classe-de-eficiência)
- [Binary Search Tree Traversal](#binary-search-tree-traversal)
  - [Binary Search Tree Traversal - Implementação Recursiva](#binary-search-tree-traversal---implementação-recursiva)
  - [Binary Search Tree Traversal - Análise](#binary-search-tree-traversal---análise)
  - [Binary Search Tree Traversal - Cálculo da função de custo](#binary-search-tree-traversal---cálculo-da-função-de-custo)

## Maior elemento em um arranjo

### Maior elemento em um arranjo - Implementação

- Implemente um algoritmo de divisão e conquista para encontrar a posição do maior elemento de um arranjo de n elementos.

```c++
int max_element(std::vector<int> vector, int left, int right) {
    if (left == right)
        return left;
    int left_max = max_element(vector, left, (left + right) / 2);
    int right_max = max_element(vector, (left + right) / 2 + 1, right);
    if (vector[left_max] >= vector[right_max])
        return left_max;
    else
        return right_max;
}
```

- Qual será a saída do método quando vários elementos do arranjo tiverem o maior valor?

  - Pela implementação feita, a saída será o elemento mais a esquerda no arranjo ("primeiro" elemento com aquele valor), isso se prova pelas seguintes linhas:

    ```c++
    if (vector[left_max] >= vector[right_max])
         return left_max;
    ```

    Desse modo, quando o maior elemento encontrado da divisão para a esquerda é igual ao maior elemento da direita, retorna o índice do elemento da esquerda.

### Maior elemento em um arranjo - Análise

- Como este algoritmo se compara com uma solução força bruta?

    Ambos algoritmos tem custo de tempo $O(n)$ sendo que o algoritmo de força bruta realizaria as comparações sem nenhuma estrutura auxiliar com custo de espaço $O(1)$, enquanto o algoritmo de divisão e conquista utiliza $O(\log n)$ como custo de espaço para armazenar a pilha de execução (com ou sem recursividade).

- Defina e resolva a relação de recorrência para o método proposto

    Considerando a operação básica como a comparação entre elementos definida pela linha de código `if (vector[left_max] >= vector[right_max])`:

$$
\begin{aligned}
C(n) & = C(\lceil {n \over 2} \rceil) + C(\lfloor {n \over 2} \rfloor) + 1 \; \forall n > 1 \\
C(1) & = 0 \\
\end{aligned}
$$

#### Maior elemento em um arranjo - Cálculo da função de custo

Considerando $n = 2^k$ a fim de facilitar o cálculo e dado que essa substituição ainda mantém a expressão verdadeira.

$$
\begin{aligned}
C(2^k) & = 2 \cdot C(2^{k-1}) + 1 \\
& = 2 \cdot [2 \cdot (C(2^{k-2}) + 1)] + 1 = 2^2 \cdot C(2^{k-2}) + 2^1 + 1\\
& = 2^2 \cdot [(2 \cdot C(2^{k-3}) + 1)] + 2^1 + 1= 2^3 \cdot C(2^{k-3}) + 2^2 + 2^1 + 1\\
& = 2^i \cdot C(2^{k-i}) + 2^{i-1} + 2^{i-2} + ... + 1\\
& = 2^k \cdot C(2^{k-k}) + 2^{k-1} + 2^{k-2} + ... + 1\\
& = 2^k \cdot C(2^0) + (2^{k-1} + 2^{k-2} + ... + 1)\\
& = 2^k \cdot C(1) + (2^k - 1) = 0 + 2^k - 1\\
& ... \\
C(2^k) & = 2^k - 1 \\
\end{aligned}
$$

Com a relação de recorrência resolvida, é feita a substituição de $k = \log_2 n$ e tem-se que:

$$
\begin{aligned}
C(n) & = n - 1 \\
\end{aligned}
$$

Portanto, $\Theta(n)$.

## Merge Sort

### Merge Sort - Implementação

```c++
void merge(std::vector<int> &vector, int left, int mid, int right) {
    int left_size = mid - left + 1, right_size = right - mid;
    std::vector<int> left_vector(left_size), right_vector(right_size);

    for (int i = 0; i < left_size; i++)
        left_vector[i] = vector[left + i];
    for (int j = 0; j < right_size; j++)
        right_vector[j] = vector[mid + 1 + j];

    int left_index = 0;
    int right_index = 0;
    int vector_index = left;

    // Copy elements from aux vectors to main vector, sorting them in the process
    while (left_index < left_size && right_index < right_size) {
        if (left_vector[left_index] <= right_vector[right_index]) {
            vector[vector_index] = left_vector[left_index];
            left_index++;
        } else {
            vector[vector_index] = right_vector[right_index];
            right_index++;
        }
        vector_index++;
    }

    // To reach here, it must exhaust all elements of left or right vector
    // then it copy the remaining elements in the vector not yet exhausted
    while (left_index < left_size) {
        vector[vector_index] = left_vector[left_index];
        left_index++;
        vector_index++;
    }
    while (right_index < right_size) {
        vector[vector_index] = right_vector[right_index];
        right_index++;
        vector_index++;
    }
}

// Iterative with bottom-up
void merge_sort(std::vector<int> &vector) {
    // vector.size() has constant complexity - https://en.cppreference.com/w/cpp/container/vector/size
    // divide the array into blocks of size `sub_size` and merge them, double 'sub_size' on each interaction
    // sub_size = [1, 2, 4, 8, ...]
    for (int sub_size = 1; sub_size <= vector.size() - 1; sub_size *= 2) { // from 1 to n/2
        // for sub_size = 1, left = 0, 2, 4, 6, 8..., right = 1, 3, 5, 7, 9...
        // for sub_size = 2, left = 0, 4, 8..., right = 3, 7, 11...
        // for sub_size = 4, left = 0, 8..., right = 7, 15...
        // ...
        for (int left = 0; left < vector.size() - 1; left += 2 * sub_size) {
            int mid = std::min(left + sub_size - 1, (int) vector.size() - 1);
            int right = std::min(left + 2 * sub_size - 1, (int) vector.size() - 1);
            // Merge "sub-arrays" vector[left...mid] & vector[mid+1...right]
            merge(vector, left, mid, right);
        }
    }
}
```

### Merge Sort - Análise

_Merge Sort_ é um algoritmo de ordenação estável pois mantém a ordem dentre elementos de mesmo valor; ou seja um elemento que tenha o mesmo valor que outro mas tenha um menor índice (posição mais à esquerda no arranjo), manterá um índice menor com relação ao(s) outro(s) elemento(s) de mesmo valor ao final da ordenação.

Essa característica advém da implementação pela linha de código `if (left_vector[left_index] <= right_vector[right_index])` que faz com que caso haja elementos de mesmo valor, o que se encontra mais à esquerda se mantém mais à esquerda, como essa condição é a mesma aplicada em todos os merges que ocorrem, é uma condição que se mantém válida para a ordenação como um todo.

#### Merge Sort - Expressão Matemática

A análise de complexidade de tempo deste algoritmo é dada pela seguinte expressão matemática:

$$
\begin{aligned}
C(n) & = 2 \cdot C \left(\frac{n}{2}\right) + n - 1 \; \forall n > 1 \\
C(1) & = 0 \\
\end{aligned}
$$

Tal que $C(1)$ representa o caso base e $C(n)$ representa o custo para se realizar a busca em uma entrada de tamanho
$n$, de modo que a cada iteração, a entrada é divida por $2$ e é feita uma operação básica de comparação.

#### Merge Sort - Cálculo da função de custo

Considerando $n = 2^k$ a fim de facilitar o cálculo e dado que essa substituição ainda mantém a expressão verdadeira.

$$
\begin{aligned}
C(2^k) & = C(2^{k-1}) + 1 \\
& = (C(2^{k-2}) + 1) + 1 = C(2^{k-2}) + 2\\
& = (C(2^{k-3}) + 1) + 2 = C(2^{k-3}) + 3\\
& = C(2^{k-i}) + i\\
& = C(2^{k-k}) + k = C(2^0) + k = C(1) + k = 1 + k\\
& ... \\
C(2^k) & = k + 1 \\
\end{aligned}
$$

Com a relação de recorrência resolvida, é feita a substituição de $k = \log_2 n$ e tem-se que:

$$
\begin{aligned}
C(n) & = \log_2 n + 1 \\
\end{aligned}
$$

#### Merge Sort - Indicação da classe de eficiência

Todos os casos do Merge Sort são $\theta (n \log n)$ porém algumas condições podem diminuir ou aumentar o número de comparações.

No melhor caso, o arranjo de entrada já está ordenado de forma crescente, de modo que o número de comparações será a metade do tamanho do sub-problema atual, dado pela função de custo:

$$C_b(n) = 2 \cdot C_b\left(\frac{n}{2}\right) + \frac{n}{2}\; \forall n > 1$$
$$C_b(1) = 0$$

Exemplo melhor caso: [1,2,3,4,5,6,7,8]

\
[No pior caso](https://www.baeldung.com/cs/merge-sort-time-complexity#the-worst-case-of-time-complexity-for-merge-sort), o número de comparações é o maior possível quando os sub-arrays que devem realizar merge possuem elementos alternados, por exemplo o merge do array [1,3,5,7] com [2,4,6,8], com o que é possível calcular a entrada que resultaria nesse último merge. Dado pela função de custo:

$$C_b(n) = 2 \cdot C_b\left(\frac{n}{2}\right) + n\; \forall n > 1$$
$$C_b(1) = 0$$

Exemplo pior caso: [5,1,7,3,6,2,8,4]

---

## Quick Sort

### Quick Sort - Implementação

```c++
void quick_sort(std::vector<int> &vector) {
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(0, vector.size() - 1));

    while (!stack.empty()) {
        // Quick sort state in stack need left and right indexes to work
        // so it could stack/unstack pairs or stack/unstack single elements twice in a row
        int left = stack.top().first;
        int right = stack.top().second;
        stack.pop();

        // Hoare partition
        int pivot = vector[(left + right) / 2];
        int i = left;
        int j = right;

        while (i <= j) {
            while (vector[i] < pivot) { i++; } // increases index i until an element not lesser than pivot is found
            while (vector[j] > pivot) { j--; } // decreases index j until an element not greater than pivot is found
            if (i <= j) {
                std::swap(vector[i], vector[j]); // this swap can and will move pivot if necessary
                i++;
                j--;
            }
        }
        // If there are elements on the left side of pivot, then push left side to stack
        if (left < j) {
            stack.push(std::make_pair(left, j));
        }
        // If there are elements on the right side of pivot, then push right side to stack
        if (i < right) {
            stack.push(std::make_pair(i, right));
        }
    }
}
```

### Quick Sort - Análise

_Quick Sort_ é um algoritmo de ordenação não-estável pois não mantém a ordem dentre elementos de mesmo valor; ou seja um elemento que tenha o mesmo valor que outro mas tenha um menor índice (posição mais à esquerda no arranjo), não tem garantia de que manterá um índice menor com relação ao(s) outro(s) elemento(s) de mesmo valor ao final da ordenação.

Essa característica advém da forma como as trocas são feitos entre elementos não adjacentes.

> **Note**
>
> É possível adaptar o algoritmo _Quick Sort_ para que seja estável
> porém ele naturalmente não é estável e essa adaptação levaria a custos adicionais de espaço e/ou tempo.

#### Quick Sort - Melhor Caso

Para o melhor caso do algoritmo, a escolha do pivô deve resultar na divisão de duas partições de tamanhos iguais ou com 1 elemento de diferença. Fazendo com que a cada iteração o problema seja dividido pela metade.

```
[1 2 3 4 5 6 7], pivot=4
[1 2 3] [5 6 7], pivot=2 & pivot=6
[1] [3] [5] [7]
```

#### Quick Sort - Pior Caso

O pior caso do algoritmo ocorre com a sucessiva escolha de pivôs ruins que gere uma árvore de chamadas degenerada pois a cada interação reduz o problema em 1 elemento ao invés de dividir o problema pela metade.

No algoritmo com esquema de partição de Lomuto e escolhendo o pivô como o último elemento, o pior caso seria uma entrada já ordenada de forma crescente ou decrescente.

Para diminuir a frequência desse tipo de pior caso é possível implementar melhorias no algoritmo, [por exemplo seja pela escolha de um pivô aleatório ou selecionando o pivô como a média de três outros elementos (início, meio e fim do arranjo)](https://www.baeldung.com/cs/quicksort-time-complexity-worst-case#advantages-and-disadvantages).

Dessa forma, tem-se um custo quadrático com relação ao tamanho do array, uma vez que é percorrido todos os elementos a cada iteração e o tamanho do problema somente se reduz em uma unidade.

> **Note**
>
> Obs: a mesma entrada já ordenada de forma crescente seria o melhor caso para o algoritmo escolhendo o pivô como o elemento do meio do arranjo de entrada.

Para a implementação em que a escolha do pivô é sempre o elemento do meio do array, o seguinte array ocasionaria no pior caso:

```
[6 4 2 1 3 5 7], pivot=1
[] [6 4 2 3 5 7], pivot=2
[] [6 4 3 5 7], pivot=3
[] [6 4 5 7], pivot=4
[] [6 5 7], pivot=5
[] [6 7], pivot=6
[] [7], pivot=7
```

#### Quick Sort - Expressão Matemática

O custo de tempo do melhor caso do quick sort é dada a seguinte expressão matemática:

$$
\begin{aligned}
C_b(n) & = 2 \cdot C_b\left(\frac{n}{2}\right) + n \; \forall n > 1 \\
C_b(1) & = 0 \\
\end{aligned}
$$

A análise de complexidade de tempo deste algoritmo para o pior caso é dada pela seguinte expressão matemática:

$$
\begin{aligned}
C_w(n) & = C_w(n - 1) + n \; \forall n > 1 \\
C_w(1) & = 0 \\
\end{aligned}
$$

#### Quick Sort - Cálculo da função de custo

Calculando a função de custo para o melhor caso, tem-se:

Pelo teorema mestre, uma função $T(n) = aT(n/b) + f(n)$, determina a análise assintótica de $T(n)$ com base em $f(n)$, tal que:

$$
  f(n) = \left\[
  \begin{matrix}
    & O(n^{\log_b a - c}) & -> T(n) \in \Theta(n^{\log_b a}) \\
    & \Theta(n^{\log_b a}) & -> T(n) \in \Theta(n^{\log_b a} \cdot \log n) \\
    & \Omega(n^{\log_b a + c}) & -> T(n) \in \Omega(f(n)) \\
  \end{matrix}
  \right.
$$

Assim, temos $a=2$, $b=2$, $f(n) = n$:

$$
\begin{aligned}
f(n) & = O(n^c), \text{ onde } c=1\\
\log_b a & = \log_2 2 = 1\\
\end{aligned}
$$

Com isso, o segundo critério do Teorema Mestre é atendido com $f(n) = \Theta(n^{\log_b a}) = \Theta(n)$, assim tem-se que:

$$T(n) \in \Theta(n^{\log_b a} \cdot \log n)$$
$$T(n) \in \Theta(n \cdot \log n)$$

Calculando a função de custo para o pior caso, tem-se:

$$
\begin{aligned}
C_w(n) & = C_w(n - 1) + n \\
& = (C_w(n - 2) + n-1 ) + n = C_w(n - 2) + n + (n-1\\
& = (C_w(n - 3) + n-2 ) + n + (n-1) = C_w(n - 3) + n + (n-1) + (n-2)\\
& = C_w(n - i) + n + (n-1) + (n-2) + ... + (n-i)\\
& ... \\
& = C_w(n - (n-1)) + n + (n-1) + (n-2) + ... + (n-(n-1))\\
& ... \\
C_w(n) & = C_w(1) + \frac{n\cdot (n+1)}{2} = \frac{n^2 + n}{2} = O(n^2) \\
\end{aligned}
$$

#### Quick Sort - Indicação da classe de eficiência

- Melhor Caso: $\theta(n \log n)$
- Caso Médio: $\theta(n\log n)$
- Pior Caso: $\theta(n^2)$

## Binary Search Tree Traversal

### Binary Search Tree Traversal - Implementação Recursiva

```c++
int binary_search_tree_size(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node == NULL)
        return 0;
    else
        return 1 + binary_search_tree_size(node->left) + binary_search_tree_size(node->right);
}

void bst_preorder_recursive(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node != nullptr) {
        std::cout << node->value << " ";
        bst_preorder_recursive(node->left);
        bst_preorder_recursive(node->right);
    }
}

void bst_postorder_recursive(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node != nullptr) {
        bst_postorder_recursive(node->left);
        bst_postorder_recursive(node->right);
        std::cout << node->value << " ";
    }
}

void bst_inorder_recursive(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node != nullptr) {
        bst_inorder_recursive(node->left);
        std::cout << node->value << " ";
        bst_inorder_recursive(node->right);
    }
}
```

### Binary Search Tree Traversal - Análise

Tanto para o algoritmo de calcular o tamanho da árvore binária `binary_search_tree_size`, quanto para o caminhamento (independente da ordem em que os nós são impressos) é necessário percorrer todos os nodes, portanto seu custo de tempo é relativo ao tamanho da árvore, sendo $\theta (n)$.

$$
\begin{aligned}
C(n) & = 2 \cdot C \left(\frac{n}{2}\right) + 1 \; \forall n > 1 \\
C(1) & = 0 \\
\end{aligned}
$$

### Binary Search Tree Traversal - Cálculo da função de custo

$$
\begin{aligned}
C(2^k) & = 2 \cdot C(2^{k-1}) + 1 \\
\end{aligned}
$$

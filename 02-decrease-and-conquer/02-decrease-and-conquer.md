# Implementação dos algoritmos de Diminuir e Conquistar

Table of Contents:

- [Observação inicial](#observação-inicial)
- [Binary Search](#binary-search)
  - [Binary Search - Implementação](#binary-search---implementação)
  - [Binary Search - Análise](#binary-search---análise)
    - [Binary Search - Expressão Matemática](#binary-search---expressão-matemática)
    - [Binary Search - Cálculo da função de custo](#binary-search---cálculo-da-função-de-custo)
    - [Binary Search - Indicação da classe de eficiência](#binary-search---indicação-da-classe-de-eficiência)
- [Interpolation Search](#interpolation-search)
  - [Interpolation Search - Implementação](#interpolation-search---implementação)
  - [Interpolation Search - Análise](#interpolation-search---análise)
    - [Interpolation Search - Melhor Caso](#interpolation-search---melhor-caso)
    - [Interpolation Search - Pior Caso](#interpolation-search---pior-caso)
    - [Interpolation Search - Caso Médio](#interpolation-search---caso-médio)
    - [Interpolation Search - Expressão Matemática](#interpolation-search---expressão-matemática)
    - [Interpolation Search - Cálculo da função de custo](#interpolation-search---cálculo-da-função-de-custo)
    - [Interpolation Search - Indicação da classe de eficiência](#interpolation-search---indicação-da-classe-de-eficiência)
- [Binary Search Tree](#binary-search-tree)
  - [Binary Search Tree - Implementação](#binary-search-tree---implementação)
  - [Binary Search Tree - Análise](#binary-search-tree---análise)
    - [Binary Search Tree - Expressão Matemática](#binary-search-tree---expressão-matemática)
    - [Binary Search Tree - Cálculo da função de custo](#binary-search-tree---cálculo-da-função-de-custo)
    - [Binary Search Tree - Indicação da classe de eficiência](#binary-search-tree---indicação-da-classe-de-eficiência)

## Observação inicial

Como os algoritmos de busca apresentados aqui (_Binary Search_ e _Interpolation Search_) possuem a necessidade de que o array de entrada esteja ordenado, foi utilizado a função [_std::sort_ da biblioteca algorithm](https://cplusplus.com/reference/algorithm/sort/) para ordenar o array.

Esse função em média possui complexidade linearítimico (linear \* logarítimico) com relação ao tamanho da entrada, performando aproximadamente $n*log_2 n$ (onde $n$ é o tamanho da entrada) comparações de elementos e no máximo esse mesmo número de troca de elementos.

Interessante ressaltar que essa função é uma implementação do algoritmo [_Introsort_](https://en.wikipedia.org/wiki/Introsort), esse algoritmo se caracteriza pela combição de três outros algoritmos: _Quicksort_, _Heapsort_ e _Insertion Sort_. Seu modo de operação permite que até mesmo o pior caso mantenha complexidade linearítimica. Em resumo, a ordenação começa aplicando _Quicksort_ no array de entrada, se a profundidade de recursão exceder o tamanho de $2*\log_2 n$ a ordenação continua a ser feita por _Heapsort_ e altera para _Insertion Sort_ quando o número de elementos é menor que $16$, de modo que sua complexidade média quadrática não terá grande impacto negativo devido ao baixo número de elementos - ao contrário porém, provê um bom desempenho em um número pequeno de elementos onde chamadas recursivas ou estruturas de armazenamento auxiliares seriam mais custosas.

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

> **Note**
>
> _Binary Search_ é um algoritmo de busca que tem como restrição o requisito de ter um array ordenado crescentemente como entrada

Para o algoritmo _Binary Search_, a operação básica é definida pela comparação entre elementos a fim de encontrar um elemento buscado dentro de um array de input. Essa comparação é feita pela linha de código `if (key == vector[middle])` contida em um loop `while (left <= right)` em que ou `left` aumenta ou `right` diminui a cada interação de modo que o problema é reduzido na metade, caracterizando esse algoritmo como Diminuição e Conquista e dentro dessa categoria ele é caracterizado como algoritmo de diminuição por um fator constante.

#### Binary Search - Expressão Matemática

A análise de complexidade de tempo deste algoritmo é dada pela seguinte expressão matemática:

$$
\begin{aligned}
C(n) & = C(\lfloor {n \over 2} \rfloor) + 1 \; \forall n > 1 \\
C(1) & = 1 \\
\end{aligned}
$$

Tal que $C(1)$ representa o caso base e $C(n)$ representa o custo para se realizar a busca em uma entrada de tamanho $n$, de modo que a cada iteração, a entrada é divida por $2$ e é feita uma operação básica de comparação.

#### Binary Search - Cálculo da função de custo

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

> P.s.: Essa relação de recorrência tem uma prova similar em _Example 3, Section 2.4 - Introduction to the Design and Analysis of Algorithms (3rd Edition) - Anany Levitin_

#### Binary Search - Indicação da classe de eficiência

É possível provar que $\log_2 n + 1$ é $\theta(\log_2 n)$ pela aplicação do limite na divisão da função $f(n) = \log_2 n + 1$ por $g(n) = \log_2 n$ de modo que o resultado determina a seguinte relação entre $f$ e $g$:

$$
  \lim_{n \to \infty}{\frac{f(n)}{g(n)}} = \left\[
  \begin{matrix}
    & 0 & -> f(g) \in O(g(n)) \\
    & K & -> f(g) \in \Theta(g(n)) \\
    & \infty & -> f(g) \in \Omega(g(n)) \\
  \end{matrix}
  \right.
$$

Assim, tem-se:

$$
\lim_{n \to \infty}{\frac{log_2(n) + 1}{log_2(n)}} = \lim_{n \to \infty}\left({\frac{\cancel{log_2(n)}}{\cancel{log_2(n)}}} + {\frac{1}{\cancelto{\infty}{log_2(n)}}}\right) = \lim_{n \to \infty}\left(1 + 0\right) = 1
$$

Com isso, conclui-se que a classe de eficiência do algoritmo _Binary Search_ é, em complexidade de tempo, $\theta(\log_2 n)$.

Essa complexidade abrange o caso médio e pior caso, tendo a mesma complexidade assintótica de custo. Para o melhor caso porém, em que o elemento procurado se encontra no meio do array inicial onde ocorre a busca, a complexidade é $O(1)$.

---

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

> **Note**
>
> _Interpolation Search_ é um algoritmo de busca que tem como restrição o requisito de ter um array ordenado crescentemente como entrada

Para o algoritmo _Interpolation Search_, a operação básica é definida pela comparação entre elementos a fim de encontrar um elemento buscado dentro de um array de input. Essa comparação é feita pela linha de código `if (vector[position] == key)` bem como `else if (vector[position] < key)` contida em um loop `while (left <= right && key >= vector[left] && key <= vector[right])` em que ou `left` aumenta ou `right` diminui a cada interação de modo que o problema é reduzido por um fator variável a depender da posição calculada em que se espera que o elemento buscado esteja. Essa posição tem o cálculo a partir dos valores do primeiro (menor) e do último (maior) elementos e levando em consideração também o valor do elemento buscado, supondo um crescimento uniforme e linear entre os elementos do array; de modo que a eficiência do algoritmo é afetada pela precisão dessa suposição, porém não sua corretude. _Interpolation Search_ é caracterizado como um algoritmo de Diminuição e Conquista e dentro dessa categoria ele é caracterizado como algoritmo de diminuição por um fator variável.

> "Unlike binary search, which always compares a search key with the middle value of a given sorted array (and hence
> reduces the problem's instance size by half), interpolation search takes into account the value of the search key in
> order to find the array's element to be compared with the search key. In a sense, the algorithm mimics the way we search
> for a name in a telephone book: if we are searching for someone named Brown, we open the book not in the middle but very
> close to the beginning, unlike our action when searching for someone named, say, Smith"

_Introduction to the Design and Analysis of Algorithms (3rd Edition) - Anany Levitin, p.161._

> "More precisely, on the iteration dealing with the array's portion between the leftmost element A[l] and the rightmost
> element A[r], the algorithm assumes that the array values increase linearly, i.e., along the straight line through the
> points (l, A[l]) and (r, A[r])."
>
> "(The accuracy of this assumption can influence the algorithm's efficiency but not its correctness.)"

_Introduction to the Design and Analysis of Algorithms (3rd Edition) - Anany Levitin, p.162._

Por ter um comportamento que mimetiza a forma como buscamos um nome em uma lista telefônica por exemplo, em que abrimos a lista tentando supor onde os nomes com a letra inicial do nome buscado estão localizado, o _Interpolation Search_ possui uma análise interessante de seus casos.

Dado o cálculo da posição esperada $x$ como:

$$x = l + \left\lfloor \frac{(v - A[l])(r-l)}{A[r] - A[l]} \right\rfloor$$

#### Interpolation Search - Melhor Caso

Para o melhor caso, temos um custo constante ( $O(1)$ ) para acessar qualquer elemento buscado desde que os elementos estejam dispostos em um crescimento uniforme.

Exemplo:

array = [1,2,3,4,5,6,7,8,9,10]

para buscar qualquer elemento nesse array de entrada, temos o cálculo da posição como: $0 + ((key - 1) * (9 - 0) / (10 - 1))$

O que resulta em $(key-1)$ e define o índice baseado no valor da chave para esse exemplo: $index = key-1$; o que é verdadeiro pra todos os elementos do vetor

Se multiplicamos esse array de entrada por alguma constante, o que mantém o crescimento uniforme entre os elementos, a mesma lógica permanece válida.

array = [2,4,6,8,10,12,14,16,18,20]

para buscar qualquer elemento nesse array de entrada, temos o cálculo da posição como: $0 + ((key - 2) * (9 - 0) / (20 - 2))$

O que resulta em $\frac{(key-2)}{2}$ e define o índice baseado no valor da chave para esse exemplo: $index = \frac{(key-2)}{2}$; o que é verdadeiro pra todos os elementos do vetor.

#### Interpolation Search - Pior Caso

Para o pior caso, temos um custo linear com relação ao tamanho do array, esse caso acontece quando os elementos apresentam crescimento uniforme porém o último número é ordens de grandeza maior que os outros elementos do array e é feita a busca pelo penúltimo elemento do array.

Exemplo:

array = [1,2,3,4,5,6,7,8,9,10000]

para buscar o penúltimo elemento nesse array de entrada (ou um elemento não presente que o valor seja maior porém mais próximo do penúltimo elemento do que do último), temos o cálculo do primeiro valor da posição como: $0 + ((key - 1) * (9 - 0) / (10000 - 1))$

O que resulta em $(key-1)/1111$ o que acarreta num divisão que se aproxima de $0$, fazendo com que a comparação ocorra com o primeiro elemento do array e o valor $left$ do algoritmo ande apenas 1 posição para a direita a cada iteração.

Esse comportamento vai se repetindo até encontrar o penúltimo elemento de forma linear, ou até chegar no último elemento (`left == right`) e não encontrar o elemento procurado.

#### Interpolation Search - Caso Médio

$O(\log(\log n))$
> TODO: adicionar cálculo

#### Interpolation Search - Expressão Matemática

A análise de complexidade de tempo deste algoritmo para o pior caso é dada pela seguinte expressão matemática:

$$
\begin{aligned}
C_w(n) & = C_w(n - 1) + 1 \; \forall n > 1 \\
C_w(1) & = 1 \\
\end{aligned}
$$

#### Interpolation Search - Cálculo da função de custo

Calculando a função de custo para o pior caso, tem-se:

$$
\begin{aligned}
C_w(n) & = C_w(n - 1) + 1 \\
& = (C_w(n - 2) + 1 ) + 1 = C_w(n - 2) + 2\\
& = (C_w(n - 3) + 1 ) + 2 = C_w(n - 3) + 3\\
& = C_w(n - i) + i\\
& ... \\
& = C_w(n - n) + n\\
& ... \\
C_w(n) & = C_w(0) + n = n + 1 \\
\end{aligned}
$$

#### Interpolation Search - Indicação da classe de eficiência

- Melhor Caso: $\theta(1)$
- Caso Médio: $\theta(\log_2 \log_2 n)$
- Pior Caso: $\theta(n)$

Para o pior caso, é possível provar que $n+1$ é $\theta(n)$ pela aplicação da definição em que existe uma constante $c_1$ que multiplicada por $n$ limita inferiormente a função $f(n)=n+1$, ao mesmo tempo que existe uma constante $c_2$ que multiplicada por $n$ limita superiormente a mesma função.

Para esse caso, pode-se escrever da seguinte forma e substituindo valores arbitrários para $c_1$ e $c_2$ a fim de manter verdadeira a equação:

$$c_1 n \leq n + 1 \leq c_2 n$$

$${1 \over 2}n \leq n + 1 \leq 2n,\; \forall n > 1$$

Com isso, conclui-se que a classe de eficiência do pior caso do algoritmo _Interpolation Search_ é, em complexidade de tempo, $\theta(n)$.

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

Para os métodos de _insert_ e _search_ dentro da estrutura de dados _Binary Search Tree_, a operação básica é definida pela comparação entre o elemento a ser inserido ou a ser buscado com o valor de cada node na medida que a árvore é percorrida a fim de encontrar a posição em que o elemento deve ser inserido ou a posição em que é esperado que o elemento esteja, respectivamente.

Essa comparação é feita pelas linhas de código `if (element < current_node->value)` e `else if (element > current_node->value)` uma vez que é necessário saber se o elemento é menor ou maior que o valor dos nodes já presentes na árvore para percorrê-la corretamente. Essas comparação estão contidas em um loop `while (next_node != nullptr)` que serve para identificar quando se alcançou um nó folha. No caso do método de inserção, quando o loop é terminado identifica-se a posição em que deve inserir o elemento. Para a busca, se o loop for terminado pela condição do while, o elemento não foi encontrado.

Esse caminhamento na árvore faz com que a cada interação, desde que a árvore esteja balanceada, se despreze aproximadamente metade dos nodes ainda não comparados, fazendo com o problema também diminua pela metade.

#### Binary Search Tree - Expressão Matemática

A Árvore de Busca Binária apresenta diferentes expressões e complexidades para o caso médio, pior caso e melhor caso.

No melhor caso, a inserção é em uma árvore vazia ou inexistente, acarretando em uma operação de custo constante para inserir o elemento na raiz; e a busca é pelo valor que está na raiz, retornando em tempo constante conferindo apenas o primeiro elemento, o que pode ocorrer independente do tamanho ou altura da árvore.

No pior caso, a árvore é degenerada, formando um caminho linear e pode se manifestar de 3 formas: cada node na árvore possui valor menor que o node anterior, sendo degenerada para à esquerda; cada node na árvore possui valor maior que o node anterior, sendo degenerada para à direita; ou cada node alterna aleatoriamente em ter um valor menor e/ou maior que o node anterior formando "zig-zags".

A análise de complexidade de tempo deste algoritmo para o pior caso é dada pela seguinte expressão matemática:

$$
\begin{aligned}
C_w(n) & = C_w(n - 1) + 1 \; \forall n > 1 \\
C_w(1) & = 1 \\
\end{aligned}
$$

Para o caso médio, a Árvore de Busca Binária tem seus métodos de inserção e busca com complexidade similar ao algoritmo de Busca Binária.

A análise de complexidade de tempo deste algoritmo para o caso médio é dada pela seguinte expressão matemática:

$$
\begin{aligned}
C(n) & = C(\lfloor {n \over 2} \rfloor) + 1,\; \forall n > 1 \\
C(1) & = 1 \\
\end{aligned}
$$

Tal que $C(1)$ representa o caso base e $C(n)$ representa o custo para se realizar a busca em uma entrada de tamanho $n$, de modo que a cada iteração, a entrada é divida por $2$ e é feita uma operação básica de comparação.



#### Binary Search Tree - Cálculo da função de custo

Calculando a função de custo para o pior caso, tem-se:

$$
\begin{aligned}
C_w(n) & = C_w(n - 1) + 1 \\
& = (C_w(n - 2) + 1 ) + 1 = C_w(n - 2) + 2\\
& = (C_w(n - 3) + 1 ) + 2 = C_w(n - 3) + 3\\
& = C_w(n - i) + i\\
& ... \\
& = C_w(n - n) + n\\
& ... \\
C_w(n) & = C_w(0) + n = n + 1 \\
\end{aligned}
$$

Para o caso médio, tem-se que considerando $n = 2^k$ a fim de facilitar o cálculo e dado que essa substituição ainda mantém a expressão verdadeira, e considerando também que uma comparação dentro de um `if` seguida de uma comparação em um `else if` atrelado ao if anterior ocorre 1.5 vezes em média por interação:

$$
\begin{aligned}
C(2^k) & = C(2^{k-1}) + 1.5 \\
& = (C(2^{k-2}) + 1.5) + 1.5 = C(2^{k-2}) + 3\\
& = (C(2^{k-3}) + 1.5) + 3 = C(2^{k-3}) + 4.5\\
& = C(2^{k-i}) + i*1.5\\
& = C(2^{k-k}) + k = C(2^0) + k = C(1) + k = 1.5 + k\\
& ... \\
C(2^k) & = k + 1.5 \\
\end{aligned}
$$

Com a relação de recorrência resolvida, é feita a substituição de $k = \log_2 n$ e tem-se que:

$$
\begin{aligned}
C(n) & = \log_2 n + 1.5 \\
\end{aligned}
$$

#### Binary Search Tree - Indicação da classe de eficiência

- Melhor Caso: $\theta(1)$
- Caso Médio: $\theta(\log_2 n)$
- Pior Caso: $\theta(n)$

Para o pior caso, é possível provar que $n+1$ é $\theta(n)$ pela aplicação da definição em que existe uma constante $c_1$ que multiplicada por $n$ limita inferiormente a função $f(n)=n+1$, ao mesmo tempo que existe uma constante $c_2$ que multiplicada por $n$ limita superiormente a mesma função.

Para esse caso, pode-se escrever da seguinte forma e substituindo valores arbitrários para $c_1$ e $c_2$ a fim de manter verdadeira a equação:

$$c_1 n \leq n + 1 \leq c_2 n$$

$${1 \over 2}n \leq n + 1 \leq 2n,\; \forall n > 1$$

Com isso, conclui-se que a classe de eficiência do métodos de _insert_ e _search_ em uma Árvore Binária de Busca degenerada (pior caso) é, em complexidade de tempo, $\theta(n)$.

Para o caso médio, é possível provar que $\log_2 n + 1.5$ é $\theta(\log_2 n)$ pela aplicação do limite na divisão da função $f(n) = \log_2 n + 1.5$ por $g(n) = \log_2 n$ de modo que o resultado determina a seguinte relação entre $f$ e $g$:

$$
  \lim_{n \to \infty}{\frac{f(n)}{g(n)}} = \left\[
  \begin{matrix}
    & 0 & -> f(g) \in O(g(n)) \\
    & K & -> f(g) \in \Theta(g(n)) \\
    & \infty & -> f(g) \in \Omega(g(n)) \\
  \end{matrix}
  \right.
$$

Assim, tem-se:

$$
\lim_{n \to \infty}{\frac{log_2(n) + 1.5}{log_2(n)}} = \lim_{n \to \infty}\left({\frac{\cancel{log_2(n)}}{\cancel{log_2(n)}}} + {\frac{1.5}{\cancelto{\infty}{log_2(n)}}}\right) = \lim_{n \to \infty}\left(1 + 0\right) = 1
$$

Com isso, conclui-se que a classe de eficiência do métodos de _insert_ e _search_ em uma Árvore Binária de Busca balanceada (caso médio) é, em complexidade de tempo, $\theta(\log_2 n)$.

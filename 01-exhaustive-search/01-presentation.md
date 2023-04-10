# Implementação dos algoritmos de Força Bruta e Busca Exaustiva

Table of Contents:

- [Selection Sort](#selection-sort)
  - [Selection Sort - Implementação](#selection-sort---implementação)
  - [Selection Sort - Análise](#selection-sort---análise)
    - [Selection Sort - Expressão Matemática](#selection-sort---expressão-matemática)
    - [Selection Sort - Cálculo da função de custo](#selection-sort---cálculo-da-função-de-custo)
    - [Selection Sort - Indicação da classe de eficiência](#selection-sort---indicação-da-classe-de-eficiência)
- [Sequential Search](#sequential-search)
  - [Sequential Search - Implementação](#sequential-search---implementação)
  - [Sequential Search - Análise](#sequential-search---análise)
    - [Sequential Search - Expressão Matemática](#sequential-search---expressão-matemática)
    - [Sequential Search - Cálculo da função de custo](#sequential-search---cálculo-da-função-de-custo)
    - [Sequential Search - Indicação da classe de eficiência](#sequential-search---indicação-da-classe-de-eficiência)

---

## Selection Sort

### Selection Sort - Implementação

```c++
void selection_sort(std::vector<int> &vector) {
    const int vector_size = (int) vector.size();
    int min_index, tmp;
    for (int i = 0; i < vector_size - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < vector_size; ++j) {
            if (vector[j] < vector[min_index])
                min_index = j;
        }
        if (min_index != i) {
            tmp = vector[min_index];
            vector[min_index] = vector[i];
            vector[i] = tmp;
        }
    }
}
```

### Selection Sort - Análise

Para o Selection Sort implementado a operação básica é a comparação entre elementos a fim de saber qual o menor elemento ao percorrer o array de input (e posteriormente movê-lo para a posição correta caso necessário), essa comparação é feita pela linha de código `if (vector[j] < vector[min_index])`, contida em um loop definido por `for (int j = i + 1; j < vector_size; ++j)` que por sua vez está dentro do loop `for (int i = 0; i < vector_size - 1; ++i)`.

#### Selection Sort - Expressão Matemática

Assim, a análise de complexidade de tempo deste algoritmo é dada pela seguinte expressão matemática:

$$T(n) = \sum\limits_{i=0}^{n-2}\sum\limits_{j=i+1}^{n-1}1$$

em que os somatórios representam os loops e o número representa a quantidade de operações básicas feitas dentro desses loops, sendo no caso `1` operação dentro do loop mais interno.

#### Selection Sort - Cálculo da função de custo

Partindo desta expressão, é possível realizar o cálculo da função de custo de tempo da seguinte forma:

$$
\begin{aligned}
T(n) & = \sum\limits_{i=0}^{n-2}\sum\limits_{j=i+1}^{n-1}1 = \sum\limits_{i=0}^{n-2}[(n-1)-(i+1)+1] = \sum\limits_{i=0}^{n-2}(n-1-i) \\
& = \sum\limits_{i=0}^{n-2}(n-1) - \sum\limits_{i=0}^{n-2}i = (n-1) \sum\limits_{i=0}^{n-2}1 - {(n-2) (n-1) \over 2} \\
& = (n-1)^2 - {(n-2) (n-1)\over 2} = {(n-1) n \over 2} = {n^2-n \over 2} \approx {1 \over 2}n^2 \in \theta(n^2)
\end{aligned}
$$

#### Selection Sort - Indicação da classe de eficiência

É possível provar que ${1 \over 2}n^2$ é $\theta(n^2)$ pela aplicação da definição em que existe uma constante $c_1$ que multiplicada por $n^2$ limita inferiormente a função $f(n)={1 \over 2}n^2$, ao mesmo tempo que existe uma constante $c_2$ que multiplicada por $n^2$ limita superiormente a mesma função.

Para esse caso, pode-se escrever da seguinte forma e substituindo valores arbitrários para $c_1$ e $c_2$ a fim de manter verdadeira a equação:

$$c_1 n^2 \leq {1 \over 2}n^2 \leq c_2 n^2$$

$${1 \over 3}n^2 \leq {1 \over 2}n^2 \leq 1n^2$$

Com isso, conclui-se que a classe de eficiência do algoritmo *Selection Sort* é, em complexidade de tempo, $\theta(n^2)$.

---

## Sequential Search

### Sequential Search - Implementação

```c++
int sequential_search(std::vector<int> vector, int key) {
    int n = (int) vector.size();
    vector.push_back(key);
    int i = 0;
    while (vector[i] != key) {
        ++i;
    }
    if (i < n)
        return i;
    else
        return -1;
}
```

### Sequential Search - Análise

Para o Sequential Search implementado a operação básica é a comparação entre o elemento que se deseja encontrar e o atual elemento ao percorrer o array de input, a fim de localizá-lo no array e retornar o índice em que ele ocorre. Como essa implementação é feita a partir do algoritmo SequentialSearch2 (Demonstrado na  Seção 3.2 de Introduction to the Design and Analysis of Algorithms (3rd Edition) - Anany Levitin), há a adição de uma "sentinela" no array. Essa "sentinela" nada mais é que o próprio elemento procurado adicionado ao final do array, dessa forma a implementação pode usar um laço `while` em que somente se verifica a igualdade entre elementos, sem a necessidade de verificar se foi atingido o fim do array.

Assim, a operação básica e o loop em que ela ocorre são ambos expressados pela linha de código `while (vector[i] != key)`.

#### Sequential Search - Expressão Matemática

A análise de complexidade de tempo deste algoritmo é dada pela seguinte expressão matemática:

$$T(n) = \sum\limits_{i=0}^{n}1$$

em que o somatório representa o loop e o número representa a quantidade de operações básicas feitas dentro desse loop, sendo no caso `1` operação como condição de parada do próprio loop.

#### Sequential Search - Cálculo da função de custo

Partindo desta expressão, é possível realizar o cálculo da função de custo de tempo da seguinte forma:

$$T(n) = \sum\limits_{i=0}^{n}1 = n+1 \approx n \in \theta(n)$$

#### Sequential Search - Indicação da classe de eficiência

É possível provar que $n$ é $\theta(n)$ pela aplicação da definição em que existe uma constante $c_1$ que multiplicada por $n$ limita inferiormente a função $f(n)=n$, ao mesmo tempo que existe uma constante $c_2$ que multiplicada por $n$ limita superiormente a mesma função.

Para esse caso, pode-se escrever da seguinte forma e substituindo valores arbitrários para $c_1$ e $c_2$ a fim de manter verdadeira a equação:

$$c_1 n \leq n \leq c_2 n$$

$${1 \over 2}n \leq n \leq 2n$$

Com isso, conclui-se que a classe de eficiência do algoritmo *Sequential Search* é, em complexidade de tempo, $\theta(n)$.

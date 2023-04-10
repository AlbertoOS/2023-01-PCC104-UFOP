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
- [Busca em Largura (BFS) e Busca em Profundidade (DFS) em Grafos](#busca-em-largura-bfs-e-busca-em-profundidade-dfs-em-grafos)
  - [BFS \& DFS - Implementação](#bfs--dfs---implementação)
  - [BFS \& DFS - Análise](#bfs--dfs---análise)
    - [BFS \& DFS - Expressão Matemática](#bfs--dfs---expressão-matemática)
    - [BFS \& DFS - Cálculo da função de custo](#bfs--dfs---cálculo-da-função-de-custo)
    - [BFS \& DFS - Indicação da classe de eficiência](#bfs--dfs---indicação-da-classe-de-eficiência)

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

Com isso, conclui-se que a classe de eficiência do algoritmo _Selection Sort_ é, em complexidade de tempo, $\theta(n^2)$.

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

Para o Sequential Search implementado a operação básica é a comparação entre o elemento que se deseja encontrar e o atual elemento ao percorrer o array de input, a fim de localizá-lo no array e retornar o índice em que ele ocorre. Como essa implementação é feita a partir do algoritmo SequentialSearch2 (Demonstrado na Seção 3.2 de Introduction to the Design and Analysis of Algorithms (3rd Edition) - Anany Levitin), há a adição de uma "sentinela" no array. Essa "sentinela" nada mais é que o próprio elemento procurado adicionado ao final do array, dessa forma a implementação pode usar um laço `while` em que somente se verifica a igualdade entre elementos, sem a necessidade de verificar se foi atingido o fim do array.

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

Com isso, conclui-se que a classe de eficiência do algoritmo _Sequential Search_ é, em complexidade de tempo, $\theta(n)$.

## Busca em Largura (BFS) e Busca em Profundidade (DFS) em Grafos

### BFS & DFS - Implementação

A implementação de métodos de Busca em Largura e Busca em Profundidade em grafos pode ser feita com uma base de código iterativo em comum em que somente se altera a política de inserção e remoção de nós na fronteira de busca.

Para uma busca em largura (breadth-first search - BFS) é utilizado uma fila como estrutura de dados da fronteira, em que a política de acesso aos dados é _FIFO_, que determina que o primeiro elemento que foi inserido será o primeiro elemento a ser removido. De modo que os nós serão explorados numa precedência horizontal no grafo, portanto em largura.

Para uma busca em profundidade (depth-first search - DFS) é utilizado uma pilha como estrutura de dados da fronteira, em que a política de acesso aos dados é _LIFO_, que determina que o último elemento que foi inserido será o primeiro elemento a ser removido. De modo que os nós serão explorados numa precedência vertical no grafo, portanto em profundidade.

A generalização do acesso ao primeiro elemento da Fila e da Pilha foi feita através de sobrecarga de funções em C++ pois suas implementações na STL possuem diferentes formas de acessar o mesmo elemento:

```c++
int get_first_element(const std::stack<int> &stack) {
    return stack.top();
}

int get_first_element(const std::queue<int> &queue) {
    return queue.front();
}
```

Fora isso, foi criada uma classe que utiliza uma lista de adjacências para especificar quais nodes são vizinhos, funções para adicionar nós e adicionar arestas (tornando nós vizinhos), além da função principal para os algoritmos `valid_path` que determina se existe um caminho válido entre dois nós informados e retorna esse caminho.

```c++
class Graph {
private:
    std::map<int, std::set<int>> adjacency_list;
public:
    std::map<int, std::set<int>> get_adjacency_list();

    void add_node(int node);

    void add_edge(int node1, int node2);

    std::list<int> valid_path(int src_node, int dst_node, auto frontier);

    std::list<int> valid_path(int src_node, int dst_node, char const *method);
};
```

Uma das funções `valid_path` é utilizada pra determinar qual estrutura será usada para a fronteira com base no input de qual método será usado:

```c++
std::list<int> Graph::valid_path(int src_node, int dst_node, char const *method) {
    if (strcmp(method, "DFS")) {
        std::stack<int> frontier;
        return valid_path(src_node, dst_node, frontier);
    } else if (strcmp(method, "BFS")) {
        std::queue<int> frontier;
        return valid_path(src_node, dst_node, frontier);
    } else {
        return (std::list<int>) {};
    }
}
```

Uma vez determinado o método de busca, a implementação a seguir representa o funcionamento para os dois algoritmos:

```c++
std::list<int> Graph::valid_path(int src_node, int dst_node, auto frontier) {
    std::list<int> path;
    std::set<int> nodes_visited;
    std::map<int, int> path_parent;
    path_parent[src_node] = -1;
    frontier.push(src_node);
    int current_node;
    while (!frontier.empty()) {
        current_node = get_first_element(frontier);
        frontier.pop();
        if (current_node == dst_node) {
            // Reference for path reconstruction - access date 09/04/2023 : https://www.baeldung.com/cs/dfs-vs-bfs-vs-dijkstra
            path.push_front(current_node); // O(1)
            int parent_node = path_parent[current_node];
            while (parent_node != -1) {
                path.push_front(parent_node); // O(1)
                parent_node = path_parent[parent_node];
            }
            return path;
        }
        if (nodes_visited.find(current_node) == nodes_visited.end()) {
            nodes_visited.insert(current_node);
            for (auto &neighbor: adjacency_list[current_node]) {
                if (neighbor != current_node) {
                    if (path_parent.find(neighbor) == path_parent.end())
                        path_parent[neighbor] = current_node;
                    frontier.push(neighbor);
                }
            }
        }
    }
    return path;
}
```

### BFS & DFS - Análise

Como para cada um dos algoritmos a estrutura de dados utilizada apresenta complexidade constante para inserção, remoção e acesso ao primeiro elemento.

A operação básica para esse algoritmo é definida como a inserção ou remoção de nós a serem explorados na fronteira, determinado respectivamente pelas linhas de código `frontier.push(neighbor)` e `frontier.pop();`, a inserção é executada um número de vezes equivalente ao número de vizinhos de um node, sendo especificada pelo loop `for (auto &neighbor: adjacency_list[current_node])` e esse próprio loop se encontra dentro de um loop externo que executa um número de vezes baseado no número de nós, sendo especificado pelo loop `while (!frontier.empty())`.

Porém, enquanto o somatório interno é baseado no número de vizinhos, o somatório externo para este algoritmo não tem um limite fácil de se determinar. Dessa forma pode-se pensar a expressão matemática como o número total de nós baseado nos valores de vizinhos de cada nó dado por `n` e profundidade calculada do grafo por `h`; de modo que num primeiro nível temos $n^0$ nós, resultando em $1$ nó de partida, e num nível $n^i$ teríamos o valor de nós como em função exponencial do número de vizinhos elevado à profundidade.

#### BFS & DFS - Expressão Matemática

Portanto, a análise de complexidade de tempo deste algoritmo pode ser dada pela seguinte expressão matemática:

$$T(n,h) = \sum\limits_{i=0}^{h}n^i$$

#### BFS & DFS - Cálculo da função de custo

Partindo desta expressão, é possível realizar o cálculo da função de custo de tempo da seguinte forma:

$$T(n,h) = \sum\limits_{i=0}^{h-1}n^i = {1(n^{h} -1) \over n-1} \leq n^h \in O(n^h)$$

#### BFS & DFS - Indicação da classe de eficiência

Assim, tem-se que para um grafo com número comum de vizinhos `n` e profundidade `h`, a complexidade tempo possui classe de eficiência $O(n^h)$.

Alternativamente, assumindo $|E|$ o número total de arestas (edges) e $|V|$ o número total de vértices/nós (vertex/nodes). Neste algoritmo tem-se $T(E) = \sum\limits_{j=1}^{|E|}1$ de adições de vizinhos a serem explorados na fronteira, enquanto $T(V) = \sum\limits_{i=1}^{|V|}1$ de remoções de nodes explorados da fronteira.

Com isso, pode-se concluir também que a classe de eficiência de ambos algoritmos, _BFS_ e _DFS_, é, em complexidade de tempo, $O(|V| + |E|)$.

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UbOI8poW)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11263907&assignment_repo_type=AssignmentRepo)

<h1 align="center">💻 Proyecto Final de AED 2023-1 🖱</h1>
<h1 align="center">BlockChain</h1>

<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/blockchain.gif" alt="GIF de bienvenida">
</p>

<hr>


<h1 align="center">Integrantes 👨‍💻</h1>

| <a href="https://github.com/anaaccilio2004" target="_blank">**Ana Maria Accilio Villanueva**</a> | <a href="https://github.com/Diegospf12" target="_blank">**Diego Pacheco Ferrel**</a> | <a href="https://github.com/juanpedrovv" target="_blank">**Juan Pedro Vasquez Vilchez**</a> | <a href="https://github.com/TheJoigoMan" target="_blank">**Diego Salvador Peñaflor Peña**</a> |
| :---: | :---: | :---: | :---: |
| <img src="https://avatars.githubusercontent.com/u/91237434?v=4" alt="drawing" width="200"/> | <img src="https://avatars.githubusercontent.com/u/94090499?v=4" alt="drawing" width="200"/> | <img src="https://avatars.githubusercontent.com/u/83739305?v=4" alt="drawing" width="200"/> | <img src="https://avatars.githubusercontent.com/u/75008901?v=4" alt="drawing" width="200"/> |

<hr>

<a name="readme-top"></a>
<details open>
  <summary><h2>Tabla de contenidos:<h2></summary>
  <ul>
    <li><a href="#introducción-🖊">
      Introducción
      <ul>
        <li><a href="#descripción-del-caso-de-estudio">Descripción del Caso de Estudio</a></li>
        <li><a href="#¿qué-es-sha-256-secure-hash-algorithm-256-bit">SHA-256</a></li>
        <li><a href="#importancia-del-blockchain-❗">Importancia del Blockchain</a></li>
      </ul>
    </a></li>
    <li><a href="#funcionalidad-de-la-aplicación">Funcionalidad de la aplicación
      <ul>
        <li><a href="#funcionalidad-de-la-aplicación">Diagrama UML(Blockchain)
        <li><a href="#interfaz">Interfaz</a></li>
        <li><a href="#estructuras-de-datos-💽">Estructuras de datos</a></li>
        <li><a href="#proof-of-work">Proof of work</a></li>
        <li><a href="#análisis-algorítmico">Análisis algorítmico</a></li>
      </ul>
    </a></li>
    <li><a href="#conclusiones">Conclusiones</a></li>
    <li><a href="#referencias-bibliográficas">Referencias bibliográficas</a></li>
    <li><a href="#anexos">Anexos
    <ul>
        <li><a href="#participación-grupal">Participación grupal</a></li>
  </ul>
</details>

<hr>

# Introducción 🖊

Un BlockChain o cadena de bloques es un tipo de Tecnología de Contabilidad Distribuida (DLT).

Los DLTs son sistemas electrónicos, diseñados en hardware o software, para registrar información que no es ejecutada por una sola entidad. Permiten almacenar y usar datos descentralizados y distribuidos tanto de forma privada o pública.

De manera que se puedan reemplazar a intermediarios, o terceros, en operaciones de tipo transacción como transferencia de dinero, propiedades, datos, etc; se creó el concepto de Blockchain, un método más seguro para las transacciones.

Blockchain es una cadena de bloques con la capacidad de no poder ser alterado y es seguro gracias al uso de encriptaciones de los datos de los usuarios.

En este caso, los blockchains consisten de una lista creciente de registros de datos, llamados bloques, que están conectados entre ellos a través de criptografía. Cada bloque contiene un hash criptográfico del bloque anterior, una marca de tiempo y la información de la transacción.

Con la marca de tiempo se prueba que la información de la transacción existió cuando el bloque fue creado. 
Ya que cada bloque contiene información del bloque anterior, crean una cadena entre ellos (linked list). Cada bloque adicional se encadena a los anteriores a él.

Por consecuencia, las transacciones en un blockchain son prácticamente irreversibles, pues una vez han sido registradas, la información de ese bloque no puede ser alterada sin alterar los bloques siguientes.

Se requiere una red de igual a igual, así como algoritmos de consenso, para garantizar la replicación entre los nodos.​ Una forma de diseño de libro mayor distribuido es el sistema blockchain, que puede ser público o privado.

<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/blob/main/Images/blockchain-explain.gif">

</p>
<hr>

## Descripción del Caso de Estudio

El proyecto se centra en construir una cadena de bloques. Este fue desarrollado con una estructura Doublelist, implementada por nosotros. La cadena de bloques destaca porque una vez que se introduce cualquier información, se crea un registro del tiempo y un enlace al bloque anterior y vez creada no se puede manipular sin alterar los siguientes bloques.

<hr>

## ¿Qué es SHA-256? (Secure Hash Algorithm 256-bit)

SHA-256 es una función criptográfica que toma una entrada de datos de cualquier longitud y produce una salida de 256 bits (32 bytes). Se utiliza para generar un resumen único de los datos, conocido como "hash". Es ampliamente utilizado en criptografía y seguridad de la información para garantizar la integridad y autenticidad de los datos. SHA-256 es resistente a colisiones y computacionalmente difícil de revertir, lo que lo hace seguro para aplicaciones como autenticación de contraseñas y generación de claves.



<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/assets/91237434/367e4627-d775-4fa5-af6c-47fc22640eb9">

</p>

<hr>

## Importancia del Blockchain ❗

Blockchain tiene una gran cantidad de aplicaciones en todo tipo de industrias. Las más importantes a mencionar serían las siguientes:
- Criptomonedas.
- Non-Fungible Token.
- Almacenamiento de datos del gobierno.
- Votaciones.
- Etc.

Aunque la importancia económica es discutible, pues el valor de las criptomonedas no está sustentado en ningún activo, la función de incorruptibilidad de sus datos es extremadamente útil para asegurar y validar compras y transacciones, evitar estafas y registrar información sin permitir ningún tipo de manipulación.

De esa misma manera, si se desea registrar votaciones electrónicas basadas en Blockchain, no habría forma de alterar la cantidad de votos o la información del voto, sin alterar toda la cadena. De manera que se hace irreversible.

<hr>



# Funcionalidad de la Aplicación

## Diagrama UML(Blockchain)

<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/assets/91237434/2b266d9f-320f-4a11-8365-85b4cc87b9e8">

</p>


## Interfaz

![GIF de explicación](https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/blob/main/Images/interfaz.png)

<hr>

# Estructuras de datos 💽

A continuación, se presentarán las estructuras realizadas para el proyecto. Cada una de estas se encuentra dentro de un archivo .h en la carpeta libs:

## **Trie**
La estructura de datos Trie se usó para la implementación de las funciones start_with() y contains() para la busqueda de los nombres de los usuarios que realizaron o recibieron transacciones.
<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/trie.gif" width="300">
</p>
  
```
class Trie{
public:
    virtual void insert(string key) = 0;
    virtual bool search(string key) = 0;
    virtual void remove(string key) = 0;
    virtual string toString(string sep=",") = 0;
};

class TriePatricia : public Trie {
private:
    struct TrieNode {
        TrieNode **children;
        string prefix;
        bool endWord; // indica si es el final de una palabra

        TrieNode() : children(new TrieNode*[ALPHA_SIZEs]()), prefix(""), endWord(false) {}

        ~TrieNode() {
            for (int i = 0; i < ALPHA_SIZEs; i++) {
                delete children[i];
            }
            delete[] children;
        }
    };
    TrieNode* root;

public:
    TriePatricia() : root(nullptr);
    void insert(string key);
    bool search(string key);
    void remove(string key);
    string toString(string sep);
    vector<string> getWordsWithPrefix(string prefix)

private:
    void toStringHelper(TrieNode* node, string& result, string& sep);
    void getWordsHelper(TrieNode* node, vector<string>& words);
};
```
## **Heap**
La estructura de datos Heap se usó para implementar las funcion de max_value() y min_value() para la busqueda de el valor máximo o mínimo de las transacciones realizadas.
<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/heap.png" width="350">
</p>

```
template <typename T>
class Heap{
public:
    enum Type {
        MAX_HEAP, MIN_HEAP
    };

private:
    T *elements;
    int capacity;
    int n;
    Type type;

public:
    Heap(T *elements, int n, Type type=MAX_HEAP) : elements(elements), n(n), type(type);
    Heap(int capacity, Type type=MAX_HEAP) : capacity(capacity), type(type);
    ~Heap();
    void buildFromArray(T *elements, int n);
    int size();
    bool is_empty();
    void push(T value);
    T pop();
    T top();
    vector<T> extractTheTopK(int k);
    static void sortAsc(T* arr, int n);
    static void sortDesc(T* arr, int n);

private:
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void heapify_down(int i);
    void heapify_up(int i);
    void resize(int new_capacity);
};
```
## **Hash Table (con Chaining)**
La estructura de datos Hash Table con Chaining se usó para implementar la funcion search() para la busqueda del monto recaudado por cada usuario.
<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/chaining.png" width="450">
</p>

```
const float maxFillFactor = 0.4;
const int maxColision = 10;

template <typename TK, typename TV>
struct Entry{
    TK key;
    TV value;
    size_t hashcode;
    Entry(TK _key, TV _value);
    ~Entry();
};

template<typename TK, typename TV>
class ChainHash{
private:
    list<Entry<TK, TV>> *array;
    int capacity;
    int size;
    hash<TK> hashFunction;

public:
    ChainHash(int cap = 13);
    void set(TK key, TV value);
    int get_size();
    bool find(TK key);
    TV search(TK key);
    void display();
    void remove(TK key, TV value);
    int bucket_count();
    int bucket_size(int i);
    ~ChainHash();

private:
    void rehashing();
};
```
## **DoublyLinkedList**
La estructura de datos DoublyLinkedList se usó para la indexación de las transacciones en los bloques y la indexación de los bloques en la Blockchain.
<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/doubly.png" width="450">
</p>

```
template <typename T>
class IteratorDouble;

template <typename T>
class DoubleList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;
public:
    DoubleList() : List<T>();
    DoubleList(const DoubleList<T>& other);
    DoubleList<T>& operator=(const DoubleList<T>& other);
    ~DoubleList();
    IteratorDouble<T> begin() const;
    IteratorDouble<T> end() const;
    T front() override;
    T back() override;
    void push_front(T data) override;
    void push_back(T data) override;
    T pop_front() override;
    T pop_back() override;
    T insert(T data, int pos) override;
    bool remove(int pos) override;
    T& operator[](int pos) override;
    bool is_empty() override;
    int size() override;
    void clear() override;
    string list_to_string() const;

private:
    std::string name() override{
        return "DoubleList";
    }
};

template <typename T>
class IteratorDouble{
private:
    Node<T> *current;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;

    IteratorDouble() : current(nullptr){};
    explicit IteratorDouble(Node<T> * node) : current(node){};

    IteratorDouble<T>& operator=(IteratorDouble<T> other);

    friend bool operator==(const IteratorDouble<T>& a, const IteratorDouble<T>& b);
    friend bool operator!= (const IteratorDouble<T>& a, const IteratorDouble<T>& b);

    IteratorDouble<T> operator++();
    IteratorDouble<T> operator++(int);
    IteratorDouble<T> operator--();
    reference operator*();
    pointer operator->();
};
```
## **B+ Tree**
La estructura de datos B+tree se usó para la implementación de la funcion range_search() para la busqueda de montos por un rango dado.
<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/bptree.jpg" width="400">
</p>

```
template <typename T>
struct NodeBPlus{
    bool is_leaf;
    std::size_t degree;
    std::size_t size;
    T* item;
    NodeBPlus<T>** children;
    NodeBPlus<T>* parent;

public:
    NodeBPlus(std::size_t _degree);
};

template <typename T>
class BPlusTree {
    NodeBPlus<T>* root;
    std::size_t degree;

public:
    BPlusTree(std::size_t _degree);
    ~BPlusTree();
    NodeBPlus<T>* getroot();
    NodeBPlus<T>* btree_search(NodeBPlus<T>* node, T key);
    NodeBPlus<T>* btreerange_search(NodeBPlus<T>* node, T key);
    vector<T> range_search(T start, T end);
    bool search(T data);
    int find_index(T* arr, T data, int len);
    T* item_insert(T* arr, T data, int len);
    NodeBPlus<T>** child_insert(NodeBPlus<T>** child_arr, NodeBPlus<T>*child,int len,int index);
    NodeBPlus<T>* child_item_insert(NodeBPlus<T>* node, T data, NodeBPlus<T>* child);
    void InsertPar(NodeBPlus<T>* par,NodeBPlus<T>* child, T data);
    void insert(T data);
    void remove(T data);
    void Removepar(NodeBPlus<T>* node, int index, NodeBPlus<T>* par);
    void clear(NodeBPlus<T>* cursor);
    void printer();
    void print(NodeBPlus<T>* cursor);
};
```
<hr>

## Proof of Work

El Proof of Work utilizada fue la de Hashcash, tambien utilizada por Bitcoin.

El algoritmo de Proof of Work Hashcash se utiliza para prevenir spam y ataques de denegación de servicio. Se basa en encontrar un hash que cumpla con ciertos criterios, como tener un número específico de ceros iniciales (en nuestro caso 4 ceros al inicio). Esto requiere realizar cálculos computacionalmente costosos. Una vez que se encuentra un hash válido, se considera que se ha completado la Prueba de Trabajo. Este algoritmo se utiliza en sistemas descentralizados, como blockchain, para garantizar la seguridad y evitar manipulaciones.

El nonce, o número utilizado solo una vez, es un componente clave en el Proof of Work. Al ajustar su valor, se puede buscar un hash que cumpla con los requisitos establecidos, como tener un cierto número de ceros iniciales. El nonce introduce aleatoriedad y dificultad en el proceso de generación de hash, lo que garantiza la seguridad y evita manipulaciones. Es un elemento esencial para el funcionamiento efectivo del algoritmo en la Blockchain.

En este caso si el hash de cualquier bloque en la Blockchain tiene 4 ceros al inicio se considera un bloque válido, en caso no cumpla esa condicion se considera inválido, al igual que todos los bloques que le siguen.

<p align="center">
  <img src="https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/raw/main/Images/hashcash.png" alt="Hashcash">
</p>

<hr>

# Análisis algorítmico


<p align="center">
  <img src="https://pablocianes.com/static/7fe65d23a75a27bf5fc95ce529c28791/3f97c/big-o-notation.png">
</p>

### insert_transaction(): O(log n)
La complejidad de tiempo de este método es O(log n), donde n es el número de transacciones en la cadena de bloques. Esto se debe a que el método necesita insertar una nueva transacción en el último bloque de la cadena o crear un nuevo bloque si el último bloque está lleno, y luego actualizar varios índices como heaps, árboles B+, tries y tablas hash. La complejidad de tiempo de insertar un elemento en un heap, árbol B+, trie o tabla hash es O(log n) en promedio. Por lo tanto, la complejidad de tiempo general del método es O(log n).
### chain_size(): O(1)
La complejidad de tiempo de este método es O(1). Esto se debe a que el método devuelve el valor de una variable que representa el tamaño de la cadena de bloques. El método no realiza cálculos u operaciones que dependan del tamaño de la cadena de bloques, por lo que su complejidad de tiempo es constante.
### max_amount(): O(1)
La complejidad de tiempo de este método es O(1), ya que simplemente devuelve el elemento superior de un max heap.
### min_amount(): O(1)
La complejidad de tiempo de este método también es O(1), ya que simplemente devuelve el elemento superior de un min heap.
### range_search(): O(log n + k)
La complejidad de tiempo de este método es O(log n + k), donde n es el número de transacciones en la cadena de bloques y k es el número de transacciones con montos en el rango. Esto se debe a que necesita realizar una búsqueda por rango en un árbol B+.
### contains(): O(k + m)
La complejidad de tiempo de este método es O(k + m), donde k es la longitud del patrón y m es el número total de caracteres en todas las llaves que contienen el patrón. Esto se debe a que necesita buscar llaves que contengan el patrón en un trie.
### start_with(): O(k + m)
La complejidad de tiempo de este método también es O(k + m), donde k es la longitud del prefijo y m es el número total de caracteres en todas las llaves que tienen el prefijo dado. Aquí se busca el prefijo en vez del patrón en cada llave.
### search(): O(1)
La complejidad de tiempo de este método es O(1) en promedio, ya que necesita buscar una clave en una tabla hash. Sin embargo, en el peor caso, si todas las entradas están en la misma lista debido a colisiones, este método toma un tiempo O(n), donde n es el número de entradas en la tabla hash.
### print_block(): O(k)
La complejidad de tiempo de este método es O(k), donde k es el número de transacciones en el bloque especificado. Esto se debe a que necesita imprimir los detalles del bloque y sus transacciones.
### modify_block(): O(n)
La complejidad de tiempo de este método es O(n), donde n es el número de bloques en la cadena de bloques. Esto se debe a que necesita modificar una transacción en un bloque y luego actualizar los hashes de ese bloque y todos los bloques posteriores.
### get_block(): O(1)
La complejidad de tiempo de este método es O(1), ya que simplemente devuelve un puntero a un bloque en una lista doblemente enlazada.
### load_transactions_from_csv(): O(n log n)
La complejidad de tiempo de este método es O(n log n), donde n es el número de transacciones en el archivo CSV. Esto se debe a que necesita leer cada transacción del archivo y luego insertarla en la cadena de bloques utilizando el método insert_transaction.

<hr>

# Conclusiones

- Gracias a este tipo de algoritmos, se puede realizar un sinnúmero de proyectos basados en seguridad y transacciones. 
- Las dos funciones básicas (Insert y Search) no presentan gran complejidad computacional, con lo cual podemos concluir que la metodología Blockchain es óptima. Sin embargo, esta puede mejorar al momento de realizar búsquedas implementando estructuras como hash table.

<hr>

# Referencias bibliográficas
- [B+ Tree visualization](https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html)
- [Convert to SHA256 in C++](https://www.delftstack.com/howto/cpp/sha256-cpp/)
- [J. Pastor (2018). Qué es blockchain: la explicación definitiva para la tecnología más de moda. Xataka.](https://www.xataka.com/especiales/que-es-blockchain-la-explicacion-definitiva-para-la-tecnologia-mas-de-moda#:~:text=Es%2C%20en%20otras%20palabras%2C%20una,por%20qu%C3%A9%20ser%20necesariamente%20econ%C3%B3micas.) 
- [? (2022). Blockchain Applications: What Is Blockchain Used For?. Software Testing Help.](https://www.softwaretestinghelp.com/blockchain-application-examples/)
- [Blockchain Architecture Basics: Components, Structure, Benefits & Creation](https://mlsdev.com/blog/156-how-to-build-your-own-blockchain-architecture)
- [Blockchain](https://andersbrownworth.com/blockchain/)
- [QMainWindow Class](https://doc.qt.io/qt-6/qmainwindow.html)
<hr>

# Anexos
## Participación Grupal

[Project Boards with GitHub](https://github.com/orgs/utec-cs-aed-2023-1/projects/3)

![image](https://github.com/utec-cs-aed-2023-1/proyecto-blockchain-grupo8/assets/91237434/f1cd2cdb-a588-4570-a02d-c567f89847e5)


<hr>

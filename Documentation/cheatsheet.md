# Cheat Sheet
## *Progrmación Competitiva EIA*



## Índice
* [Estructuras de datos](#estructuras-de-datos)
  * [Range Queries](#range-queries)
    * [Sparse Table](#sparse-table)
* [Algoritmos](#algoritmos)
* [Funciones](#funciones)
  * [Matemáticas](#matemáticas)
    * [Logaritmo Discreto](#logaritmo-discreto)
* [Otros](#otros)
---

## Estructuras de datos

### Range Queries

#### Sparse Table
**Definición**
````c++
int st[K][N];
````
K >= ⌊Log2(N)⌋


**Llenado**
````c++
copy(array.begin(), array.end(), st[0]);

for(int i = 1; i < K; i++) {
        for(int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = f(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
    }
````

**RMQ**
````c++
i = log2_floor(L - R + 1);

rmq = min(st[i][L], st[i][R - (1 << i)] + 1);
````

**RSQ**
````c++
for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
````

## Algoritmos

## Funciones

### Matemáticas

#### Logaritmo Discreto
````c++
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
````

## Otros
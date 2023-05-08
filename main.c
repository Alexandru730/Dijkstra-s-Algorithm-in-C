
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 10
#define INF 99999

typedef struct {

    int E;
    int **a;
} Graph;

// functie pentru a genera o valoare aleatoare intre 0 si max
int rand_int(int max) {
    return rand() % (max + 1);
}

void dijkstra(Graph *g, int source, int dist[V], int parent[V], int visited[V]) {
    int i, j, u, v, min_dist;
    // initializam distantele minime si vectorul de marcaj
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    // distanta minima de la sursa la sursa este 0
    dist[source] = 0;

    // aplicam algoritmul lui Dijkstra
    for (i = 0; i < V - 1; i++) {
        // gasim nodul nevizitat cu distanta minima de la sursa
        min_dist = INF;
        for (j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        // marcăm nodul ca fiind vizitat
        visited[u] = 1;

        // actualizam distantele minime catre vecinii nevizitati
        for (v = 0; v < V; v++) {
            if (!visited[v] && g->a[u][v] && dist[u] + g->a[u][v] < dist[v]) {
                dist[v] = dist[u] + g->a[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    int dist[V]; // distantele minime de la sursa
    int visited[V]; // vector de marcaj pentru nodurile vizitate
    int parent[V];
    int i, j, u, v, min_dist;
    Graph *g = (Graph *) malloc(sizeof(Graph));
    if (g == NULL) {
        printf("Eroare la alocarea memoriei pentru Graph");
        return 1;
    }

    g->E = 0;
    g->a = (int **) malloc(V * sizeof(int *));
    if (g->a == NULL) {
        printf("Eroare la alocarea memoriei pentru matricea de adiacență");
        return 1;
    }

    for (int i = 0; i < V; i++) {
        g->a[i] = (int *) calloc(V, sizeof(int));
        if (g->a[i] == NULL) {
            printf("Eroare la alocarea memoriei pentru linia %d din matricea de adiacență", i);
            return 1;
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->a[i][j] = -1;
        }
    }
    // initializam generatorul de numere aleatoare
    srand(time(NULL));

    // generam graful aleator
    for(i = 0; i < V; i++) {
        for(j = i; j < V; j++) {
            if(i == j) {
                g->a[i][j] = 0; // nu exista muchii de la un nod la el insusi
            } else {
                // generam o valoare aleatoare intre 0 si 20 pentru ponderile muchiilor
                int weight = rand_int(20);
                g->a[i][j] = weight;
                g->a[j][i] = weight; // graful este neorientat, deci adaugam muchiile in ambele directii
            }
        }
    }
    // afișăm matricea de adiacență
    printf("Matricea de adiacenta:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%2d ", g->a[i][j]);
        }
        printf("\n");
    }
    int source = rand() % V;

    printf("%d\n", source);

    dijkstra(g, source, dist, parent, visited);

    // afisam distantele minime
    printf("Distante minime de la nodul %d la celelalte noduri:\n", source);
    for(i = 0; i < V; i++) {
        if (dist[i] == INF) {
                printf("nu are cale\n");
            } else {
        printf("Nod %d: distanta =%d, drum =", i, dist[i]);
        j = i;
        while(parent[j] != -1){
            printf("%d->", j);
            j = parent[j];
        }
        printf("%d\n", j);
    }}
    for(i = 0; i < V; i++){
        free(g->a[i]);
    }
    free(g->a);
    free(g);
    return 0;
}

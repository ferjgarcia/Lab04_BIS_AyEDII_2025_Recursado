#include <stdio.h>
#include <stdlib.h>

#define LINKED_LIST_LENGTH 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    List my_list = NULL;
    Node *a_node = NULL;
    unsigned int i = LINKED_LIST_LENGTH; 

    my_list = malloc(sizeof(struct Node));
    a_node = my_list;
    i = i-1; 

    while (i > 0) {
        a_node->data = i*10;
        a_node->next = malloc(sizeof(struct Node));
        a_node = a_node->next;
        i--;
    }
    
    a_node->data = 0;
    a_node->next = NULL;

    return my_list;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    Node *a_node = NULL;
    a_node = xs;

    while (a_node->next != NULL) {
        a_node = a_node->next;
    }

    a_node->next = malloc(sizeof(struct Node));
    a_node->next->data = 88;
    a_node->next->next = NULL;   
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}

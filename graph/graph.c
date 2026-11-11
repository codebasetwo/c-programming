#include<stdlib.h>
#include<stdio.h>

// Graph: Vertex 
struct Graph {
    struct Vertex* vertices;
};

struct Edge {
    int edge;
    struct Edge* left;
    struct Edge* right;
};

struct Vertex {
    int vertex;
    struct Edge* edges;
    struct Vertex* next;
};

struct Graph adjacency_list[100];


struct Edge* get_edge(int vertex)
{
    struct Edge* edge =  (struct Edge*)malloc(sizeof(struct Edge));
    edge->edge = vertex;
    edge->left = edge->right = NULL;
    return edge;
}

struct Edge* insert_edge(struct Edge* edge, int vertex){
    if (edge == NULL){
        return get_edge(vertex);
    }
    if (vertex <= edge->edge) {
        edge->left = insert_edge(edge->left, vertex);
    }
    else {
        edge->right= insert_edge(edge->right, vertex);
    }
    return edge;
}

//  Helper function to find a vertex or create a vertex if it doesn't exist.
struct Vertex* find_or_create_vertex(struct Graph* graph, int vertex_id) {
    struct Vertex* curr = graph->vertices;
    
    while (curr != NULL) {
        if (curr->vertex == vertex_id) {
            return curr;
        }
        curr = curr->next;
    }

    struct Vertex* new_vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    new_vertex->vertex = vertex_id;
    new_vertex->edges = NULL;
    new_vertex->next = graph->vertices;
    graph->vertices = new_vertex;
    
    return new_vertex;
}

// `add_edge` function to add edge to a vertex
void add_edge(struct Graph* graph, int from, int to) {
    // Find or create the 'from' vertex
    struct Vertex* v = find_or_create_vertex(graph, from);
    // Insert the 'to' node into the vertex's edge BST
    v->edges = insert_edge(v->edges, to);
}

// Helper function to print the edge BST using in-order traversal
void print_bst(struct Edge* root) {
    if (root == NULL) {
        return;
    }
    print_bst(root->left);
    printf("%d ", root->edge);
    print_bst(root->right);
}

// Function to print the entire graph
void print_graph(struct Graph* graph) {
    if (graph == NULL || graph->vertices == NULL) {
        printf("Graph is empty.\n");
        return;
    }

    struct Vertex* curr_vertex = graph->vertices;
    while (curr_vertex != NULL) {
        printf("Vertex %d -> Edges: ", curr_vertex->vertex);
        print_bst(curr_vertex->edges);
        printf("\n");
        curr_vertex = curr_vertex->next;
    }
}

void delete_edge(struct Graph* graph, int edge, int vertex){}
void delete_vertex(struct Graph* graph, int vertex){}

int main() {
    // Initialize our graph container
    struct Graph my_graph;
    my_graph.vertices = NULL;
    
    // Add edges to test the implementation
    add_edge(&my_graph, 1, 3);
    add_edge(&my_graph, 1, 1);
    add_edge(&my_graph, 1, 2);
    add_edge(&my_graph, 1, 5);
    
    add_edge(&my_graph, 2, 4);
    add_edge(&my_graph, 2, 1);

    add_edge(&my_graph, 3, 5);

    printf("--- Graph Adjacency List (BST Edges) ---\n");
    print_graph(&my_graph);

    return 0;
}
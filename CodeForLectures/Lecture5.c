#include <stdio.h>
#include <stdlib.h>
#include "HeaderLecture5.h"
#include <stdbool.h>

void lecture5(){
	printf("\n\n");
	intro();
	//freestuff();
	treestuff();
	arenastuff();
	printf("\n\n");
}

void intro(){
	printf("LECTURE 5: Aliasing, Graphs, Deallocation\n");
}

void freestuff(){
	int * pi = malloc(sizeof(int));
	printf("Enter a number below:\n");
	scanf(" %d", pi);
	if(*pi % 2-1){
		printf("Even!\n");
	}
	free(pi);
}

struct node {
	int value;
	struct node * left;
	struct node * right;
};

typedef struct node tree;
tree * node(int value, tree * left, tree * right);
void tree_free(tree * tree);
tree * tree_free2(tree * tree);

tree * node(int value, tree * left, tree * right){
	tree * t = malloc(sizeof(tree));
	t->value = value;
	t->left = left;
	t->right = right;
	return t;
}

void tree_free(tree * tree){
	if(tree != NULL){
		free(tree->left);
		free(tree->right);
		free(tree);
	}
}

tree * tree_free2(tree * tree){
	if(tree != NULL){
		if(tree->left != NULL) free(tree->left), tree->left = NULL;
		if(tree->right != NULL) free(tree->right), tree->right = NULL;
	}
	return NULL;
}

void treestuff(){
	tree * node2 = node(2, NULL, NULL);
	
	tree * node1 = node(1, node2, node2);
	
	printf("Trying to free the tree that has two pointers to the same sub tree, at first causes error.\n");
	//tree_free(node1);
	//node1 = tree_free2(node1);
	//even tree_free2 doesnt work because the right side isnt NULL as far as its concerned after the left is set to null
	//it due to copying etc how pointers work etc... eugh what a faff, so we do a tree that tracks the way that it works instead
}

struct node_track_visits {
	bool visited;
	int value;
	struct node_track_visits * left;
	struct node_track_visits * right;
};
typedef struct node_track_visits tree2;

tree2 * make_node(int value, tree2 * left, tree2 * right){
	tree2 * t = malloc(sizeof(tree2));
	t->visited = false;
	t->value = value;
	t->right = right;
	t->left = left;
	return t;
}

typedef struct TreeListCell treelist;
struct TreeListCell {
	tree2 * head;
	treelist * tail;
};

treelist * cons(tree2 * head, treelist * tail);
treelist * getNodes(tree2 * tree, treelist * nodes);

treelist * cons(tree2 * head, treelist * tail){
	treelist * result = malloc(sizeof(treelist));
	result->head = head;
	result->tail = tail;
	return result;
	//cons dynamically allocates a new element of a list.
}

treelist * getNodes(tree2 * treex, treelist * nodes) {
	if(treex == NULL || treex->visited) {
		return nodes;
	} else {
		treex->visited = true;
		nodes = cons(treex, nodes);
		nodes = getNodes(treex->right, nodes);
		nodes = getNodes(treex->left, nodes);
		return nodes;
	}
	// adds the unvisited nodes of the tree to nodes list
	//fninished is the node is a leaf or already visited (so solves the dag problem)
	//otherwise add the current node and recurse.
}

// now nodes can finally be freed
void tree_free3(tree2 * treex){
	treelist * nodes = getNodes(treex, NULL);
	while(nodes != NULL){
		tree2 * head = nodes->head;
		treelist * tail = nodes->tail;
		free(head);
		free(nodes);
		nodes = tail;
	}
}

//ARENAS NOW OKAY
//lets go back to the origional trees now okay. nice.
//but add

typedef struct area * arena_t;
struct area {
	int size;
	int current;
	tree* elts;
};

arena_t make_arena(int size){
	arena_t arena = malloc(sizeof(arena_t));
	arena->size = size;
	arena->current = 0;
	arena->elts = malloc(size * sizeof(tree));
	return arena;
}

tree* addnode(int value, tree* left, tree* right, arena_t arena){
	if(arena->current < arena->size){
		tree* t = arena->elts + arena->current; // points to the current tree element, it allocates a node in the arena you see
		arena->current += 1;
		t->value = value, t->left = left, t->right = right;
		return t;
	} else {
		return NULL;
	}
}

void free_arena(arena_t arena){
	free(arena->elts);
	free(arena);
	// now trees are not free individuallty
	//instead free a whole arena at a time
	//all tree nodes allocated from the arena are freed at once
	// no extra dynamically alocating memory to do it and no troublesome visited node needed.
}

void arenastuff(){
	arena_t a = make_arena(100);
	
	tree* node2 = addnode(2, NULL, NULL, a);
	tree* node1 = addnode(1, node2, node2, a);
	
	// do something with your nodes
	printf("now i can make a graph and delete the nodes without having to worry about the graph structure, using arenas\n");
	free_arena(a);
}
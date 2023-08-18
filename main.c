// Compile command: gcc -o main main.c
// Run command: ./main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)



// Node of the tree.
struct node {
	char letter;
	struct node* left;
	struct node* right;
};



// Allocates a new node with given letter.
// Right and left pointers are NULL.
struct node* createNode(char character) {

	// Node memory allocation.
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));

	// Data assignment.
	NewNode -> letter = character;
	NewNode -> left = NULL;
	NewNode -> right = NULL;

	// Return newly created node.
	return NewNode;

}



// Builds the tree needed to perform morse to english conversion.
void buildMorseTree(struct node* root) {

	// Root node's children.
	root -> left = createNode('e');
	root -> right = createNode('t');

	// Root node's grandchildren.
	(root -> left) -> left = createNode('i');
	(root -> left) -> right = createNode('a');
	(root -> right) -> left = createNode('n');
	(root -> right) -> right = createNode('m');

	// Root node's children's grandchildren.
	((root -> left) -> left) -> left = createNode('s');
	((root -> left) -> left) -> right = createNode('u');
	((root -> left) -> right) -> left = createNode('r');
	((root -> left) -> right) -> right = createNode('w');
	((root -> right) -> left) -> left = createNode('d');
	((root -> right) -> left) -> right = createNode('k');
	((root -> right) -> right) -> left = createNode('g');
	((root -> right) -> right) -> right = createNode('o');

	// Root node's grandchildren's grandchildren.
	(((root -> left) -> left) -> left) -> left = createNode('h');
	(((root -> left) -> left) -> left) -> right = createNode('v');
	(((root -> left) -> left) -> right) -> left = createNode('f');
	(((root -> left) -> left) -> right) -> right = createNode(' ');
	(((root -> left) -> right) -> left) -> left = createNode('l');
	(((root -> left) -> right) -> left) -> right = createNode(' ');
	(((root -> left) -> right) -> right) -> left = createNode('p');
	(((root -> left) -> right) -> right) -> right = createNode('j');
	(((root -> right) -> left) -> left) -> left = createNode('b');
	(((root -> right) -> left) -> left) -> right = createNode('x');
	(((root -> right) -> left) -> right) -> left = createNode('c');
	(((root -> right) -> left) -> right) -> right = createNode('y');
	(((root -> right) -> right) -> left) -> left = createNode('z');
	(((root -> right) -> right) -> left) -> right = createNode('q');
	(((root -> right) -> right) -> right) -> left = createNode(' ');
	(((root -> right) -> right) -> right) -> right = createNode(' ');

	// Root node's children's grandchildren's grandchildren (for numbers).
	((((root -> left) -> left) -> left) -> left) -> left = createNode('5');
	((((root -> left) -> left) -> left) -> left) -> right = createNode('4');
	((((root -> left) -> left) -> left) -> right) -> left = createNode(' ');
	((((root -> left) -> left) -> left) -> right) -> right = createNode('3');
	((((root -> left) -> left) -> right) -> left) -> left = createNode(' ');
	((((root -> left) -> left) -> right) -> left) -> right = createNode(' ');
	((((root -> left) -> left) -> right) -> right) -> left = createNode(' ');
	((((root -> left) -> left) -> right) -> right) -> right = createNode('2');
	((((root -> left) -> right) -> left) -> left) -> left = createNode(' ');
	((((root -> left) -> right) -> left) -> left) -> right = createNode(' ');
	((((root -> left) -> right) -> left) -> right) -> left = createNode(' ');
	((((root -> left) -> right) -> left) -> right) -> right = createNode(' ');
	((((root -> left) -> right) -> right) -> left) -> left = createNode(' ');
	((((root -> left) -> right) -> right) -> left) -> right = createNode(' ');
	((((root -> left) -> right) -> right) -> right) -> left = createNode(' ');
	((((root -> left) -> right) -> right) -> right) -> right = createNode('1');
	((((root -> right) -> left) -> left) -> left) -> left = createNode('6');
	((((root -> right) -> left) -> left) -> left) -> right = createNode(' ');
	((((root -> right) -> left) -> left) -> right) -> left = createNode(' ');
	((((root -> right) -> left) -> left) -> right) -> right = createNode(' ');
	((((root -> right) -> left) -> right) -> left) -> left = createNode(' ');
	((((root -> right) -> left) -> right) -> left) -> right = createNode(' ');
	((((root -> right) -> left) -> right) -> right) -> left = createNode(' ');
	((((root -> right) -> left) -> right) -> right) -> right = createNode(' ');
	((((root -> right) -> right) -> left) -> left) -> left = createNode('7');
	((((root -> right) -> right) -> left) -> left) -> right = createNode(' ');
	((((root -> right) -> right) -> left) -> right) -> left = createNode(' ');
	((((root -> right) -> right) -> left) -> right) -> right = createNode(' ');
	((((root -> right) -> right) -> right) -> left) -> left = createNode('8');
	((((root -> right) -> right) -> right) -> left) -> right = createNode(' ');
	((((root -> right) -> right) -> right) -> right) -> left = createNode('9');
	((((root -> right) -> right) -> right) -> right) -> right = createNode('0');

	// Additional leaf nodes (for common punctuation).
	(((((root -> left) -> left) -> right) -> right) -> left) -> left = createNode('?');
	(((((root -> left) -> right) -> left) -> right) -> left) -> right = createNode('.');
	(((((root -> left) -> right) -> left) -> left) -> right) -> left = createNode('"');
	(((((root -> left) -> right) -> right) -> right) -> right) -> left = createNode('\'');
	(((((root -> right) -> left) -> right) -> left) -> right) -> left = createNode(';');
	(((((root -> right) -> left) -> right) -> left) -> right) -> right = createNode('!');
	(((((root -> right) -> right) -> left) -> left) -> right) -> right = createNode(',');
	(((((root -> right) -> right) -> right) -> left) -> left) -> left = createNode(':');

}



// Prints the Morse Tree in preorder.
void printMorseTree(struct node* node) {

	if(node == NULL) {
		return;
	} else {
		if((node -> letter) != ' ') {
			printf("%c ", (node -> letter));
			printMorseTree(node -> left);
			printMorseTree(node -> right);
		}
	}

}



// Appends a given character 'c', to a character array 'src'.
void charAppend(char* src, char c) {

	int len = strlen(src);
	src[len] = c;
	src[len + 1] = '\0';

}



// Converts all the morse characters(dot, dash, space, slash) pointed by the characters parameter and converts them to english characters.
// The english character conversions are stored using the output parameter.
// This function will also create the root by calling createNode.
// The data of the root node can be a character 0 and will build the tree by calling buildTree(root).
// After building the tree, printMorseTree is called to show it was built correctly.
void convertMorseToEnglish(char* characters, char* output) {

	struct node* root = createNode('~');
	buildMorseTree(root);
	printf("Binary tree (pre-order): ");
	printMorseTree(root);
	struct node* curr = root;

	printf("\n");

	for(int i = 0; i < strlen(characters); i++) {
		if(characters[i] == '.')
			curr = curr -> left;

		else if(characters[i] == '-')
			curr = curr -> right;

		else if((characters[i] == ' ') && (curr -> letter != root -> letter)) {
			charAppend(output, (curr -> letter));
			curr = root;
		}

		else if(characters[i] == '/')
			charAppend(output, ' ');
	}

}



int main(int argc, char** argv) {

	// Create and initialize arrays message and output.
	char message[500] = { '0' };
	char output[500] = { '\0' };

	// The input file is the second argument when executing the program
	FILE* datafile = fopen((argv[1]), "r");/* open file for reading*/
	if (datafile == NULL) { printf("can't open\n"); }
	else {
		fgets(message, 500, datafile);
		int length = strlen(message);
		message[length] = ' ';
		message[length + 1] = '\0';
		convertMorseToEnglish(message, output);

		// Print out the initial morse characters.
		printf("Morse code: ");
	    for(int i = 0; i < strlen(message); i++) {
			printf("%c", message[i]);
    	}
		printf("\n");

		// Print out the resulting english conversion.
		printf("English conversion: ");
	    for(int i = 0; i < strlen(output); i++) {
			printf("%c", output[i]);
    	}
		printf("\n");
	}

	fclose(datafile);
}
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);
// A linked list node
struct Node
{
char* data;
struct Node *next;
};


void insert(struct Node** head, char* new_data)//function to add nodes
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head;// Temporarily store the last node
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head == NULL) // check if its the first node being placed
	{
	*head = new_node;
	return;
	}
	while (last->next != NULL)
	last = last->next;
	last->next = new_node;
	return;
}

// checks the word from note with every node in magazine
int crosschecker(struct Node *node,char** note)
{

while (node != NULL)
{
	if (0 == (strcmp(node->data,*(note)))){
		node->data = "@";// we dont want to use this word again so we rewrite it to something note cant be
		//printf("%s",*note);
		return 1; //true the word is in the magazine
	}
	node = node->next;
}
return 0;
}

// Complete the checkMagazine function below.
void checkMagazine(int magazine_count, char** magazine, int note_count, char** note) {
	struct Node* head = NULL;
	for(int i=0;i<magazine_count;i++){
	insert(&head, magazine[i]);// put the magazine array into linked list form
	}

int i =0;
for (i; i<note_count;i++){
	if (!(crosschecker(head,note+i))){
	printf("No"); // do the no answer because got to the end of the magazine and found no matches
	break;
	}
}
if (i == note_count){ // must be true if gotten to this point
	printf("Yes"); // do the yes answer
	}


}
int main()
{
    char** mn = split_string(readline()); // What does this do?

    char* m_endptr;
    char* m_str = mn[0];
    int m = strtol(m_str, &m_endptr, 10); //counts the number of words in the magazine

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); } // end is the beggining or end doesnt end with enter key

    char* n_endptr; // what is n and why is it from the second element of the split string
    char* n_str = mn[1];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** magazine_temp = split_string(readline());// temporary and same as mn

    char** magazine = malloc(m * sizeof(char*)); //define memory to store char size m times

    for (int i = 0; i < m; i++) {
        char* magazine_item = *(magazine_temp + i); // store pointers of each item (in the magazine) into the magazine array
        *(magazine + i) = magazine_item;
    }

    int magazine_count = m;

    char** note_temp = split_string(readline()); //

    char** note = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) { // do the same as the magazine just for the note string now
        char* note_item = *(note_temp + i);

        *(note + i) = note_item;
    }

    int note_count = n;

    checkMagazine(magazine_count, magazine, note_count, note);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin); //puts a word in of max size 1024

        if (!line) { 
            break;
        }

        data_length += strlen(cursor); // checks how large the word was

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1; // shift the alocation length over 1 since already inputted a word

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data; // one whole sentence
}

char** split_string(char* str) {// not so sure but assume splits up spaces into array slots
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

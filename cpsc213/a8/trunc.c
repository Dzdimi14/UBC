#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "trunc.h"

void printString (element_t sv) {
  char* s = sv;
  printf ("%s\n", s);
}
void printInts (element_t sv) {
  int* s = sv;
  printf ("%d\n", *s);
}
void filter_strings (element_t* tv, element_t sv){
  int** t = (int**) tv;
  char *s = (char*) sv;
  if (*t == NULL)
	  *t = malloc(sizeof(int));
  
  char* temp = 0;
  **t = strtol(s, &temp, 0);
  if (!**t)
	  **t = -1;
}

void filter_numbers(element_t* tv, element_t iv, element_t sv){
	char** t = (char**) tv;
	int *i = (int*) iv;
	char* s = (char*) sv;
	if (*t == NULL)
		*t = malloc(sizeof(int));
	
	if (*i != -1)
		*s = '\0'; //*s = NULL
	*t = s;
}

int remove_negatives(element_t iv){
	int* i = (int*) iv;
	return (*i >= 0);
}

int remove_nulls(element_t sv){
	char* s = (char*) sv;
	return (*s != '\0'); //*s != NULL
}

void truncate_strings(element_t* tv, element_t iv, element_t sv){
	char** t = (char**) tv;
	int *i = (int*) iv;
	char* s = (char*) sv;
	if (*t == NULL)
		*t = malloc(sizeof(int));
	
	s[*i] = '\0';
	*t = strdup(s);
}


void concat_string(element_t sv){
	char* s = sv;
	printf("%s ", s);
}

void max_value(element_t* tv, element_t av, element_t bv){
	char** t = (char**) tv;
	char *a = av;
	char* b =  bv;
	if (*t == NULL)
		*t = malloc(sizeof(int));

	if (*a < *b)
		**t = *b;
}

void main(int argc, char** argv){

	//step 1
	struct list* l0 = list_create(); //original 
	for(int i = 0; i<argc-1; i++){
		element_t e = argv[i+1];
		list_append(l0, e);
	}
	//list_foreach(printString, l0);
	
	// step 2
	struct list* l1 = list_create(); //ints & -1s
	list_map1(filter_strings, l1, l0);
	//list_foreach(printInts, l1);
	
	// step 3
	struct list* l2 = list_create(); //strings & NULL
	list_map2(filter_numbers, l2, l1, l0);
	//list_foreach(printString, l2);
	
	// step 4
	struct list* l3 = list_create(); //removed -1s
	list_filter(remove_negatives, l3, l1);
	//list_foreach(printInts, l3);
	
	// step 5
	struct list* l4 = list_create(); //removed nulls
	list_filter(remove_nulls, l4, l2);
	//list_foreach(printString, l4);
	
	// step 6
	struct list* l5 = list_create();
	list_map2(truncate_strings, l5, l3, l4);
	
	// step 7
	list_foreach(printString, l5);
	
	// step 8
	list_foreach(concat_string, l5);

	// step 9
	int x = 0, *xp = &x;
	list_foldl(max_value, (element_t*) &xp, l3);
	printf("\n%d\n", x);
	
	//list_foreach (free, l0);
	list_foreach (free, l1);
	//list_foreach (free, l2); // ):
	//list_foreach (free, l3);
	//list_foreach (free, l4);
	list_foreach (free, l5); // ):

	
	list_destroy (l0);
	list_destroy (l1);
	list_destroy (l2);
	list_destroy (l3);
	list_destroy (l4);
	list_destroy (l5);


}

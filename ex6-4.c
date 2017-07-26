#include <stdio.h> 
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
#include "getch.c"
#define MAXWORD 100 
struct tnode {     /* the tree node: */ 
	char *word;           /* points to the text */ 
	int count;            /* number of occurrences */ 
	struct tnode *left;   /* left child */ 
	struct tnode *right;  /* right child */ 
};

struct tnode *addtree(struct tnode *, char *);

void word_count_addtree(struct tnode **, char *, int); 
void treeprint(struct tnode *);
void insert_priority_queue(struct tnode *, struct tnode **); 
int getword(char *, int); 

/* word frequency count */ 
int main() { 
	struct tnode *root; 
	struct tnode *root2;
	char word[MAXWORD]; 

	root = NULL;
	root2 = NULL; 
	while (getword(word, MAXWORD) != EOF) 
		if (isalpha(word[0])) 
			root = addtree(root, word); 

	insert_priority_queue(root, &root2); 
	treeprint(root2);
	return 0; 
} 
 

char *istrdup(char *);
struct tnode *talloc(void); 

/* addtree:  add a node with w, at or below p */ 
struct tnode *addtree(struct tnode *p, char *w) 
{ 
	int cond; 
	if (p == NULL) {     /* a new word has arrived */ 
		p = talloc();    /* make a new node */ 
		p->word = istrdup(w); 
		p->count = 1; 
		p->left = p->right = NULL; 
	} else if ((cond = strcmp(w, p->word)) == 0) 
		p->count++;      /* repeated word */ 
	else if (cond < 0)   /* less than into left subtree */ 
		p->left = addtree(p->left, w); 
	else             /* greater than into right subtree */ 
		p->right = addtree(p->right, w); 
	return p; 
} 
/* addtree:  add a node with w, at or below p */ 
void word_count_addtree(struct tnode **p1, char *w, int count) 
{ 
    
	int cond; 
	if ((*p1) == NULL) {     /* a new word has arrived */ 
		(*p1) = talloc();    /* make a new node */ 
		(*p1)->word = istrdup(w); 
		(*p1)->count = count; 
		(*p1)->left = (*p1)->right = NULL; 
	}
	else if (count < (*p1)->count)   /* less than into left subtree */ 
		word_count_addtree(&((*p1)->left), w, count); 
	else             /* greater than into right subtree */ 
		word_count_addtree(&((*p1)->right), w, count); 
}
 
/* treeprint:  in-order print of tree p */ 
void treeprint(struct tnode *p) 
{ 
	if (p != NULL) { 
		treeprint(p->left); 
		printf("%4d %s\n", p->count, p->word); 
		treeprint(p->right); 
	} 
} 

void insert_priority_queue(struct tnode *p, struct tnode **root2){
	if (p!= NULL){
		insert_priority_queue(p->left, root2);
		word_count_addtree(root2, p->word, p->count);
		insert_priority_queue(p->right, root2);
	}
}
/* talloc:  make a tnode */ 
struct tnode *talloc(void) 
{ 
	return (struct tnode *) malloc(sizeof(struct tnode)); 
}

char *istrdup(char *s)   /* make a duplicate of s */ 
{ 
	char *p; 
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */ 
	if (p != NULL) 
		strcpy(p, s); 
	return p; 
}
   /* getword:  get next word or character from input */ 

 
int getword(char *word, int lim) 
{ 
	int c;
	int getch(void); 
	void ungetch(int);
	char *w = word; 
	while (isspace(c = getch())) 
		; 
	if (c != EOF) 
		*w++ = c; 
	if (!isalpha(c)) { 
		*w = '\0'; 
		return c; 
	} 
	for ( ; --lim > 0; w++) 
		if (!isalnum(*w = getch())) { 
			ungetch(*w); 
			break; 
		} 
	*w = '\0'; 
	return word[0]; 
}


   

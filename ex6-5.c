#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101 
struct nlist {       /* table entry: */ 
	struct nlist *next;   /* next entry in chain */ 
	char *name;           /* defined name */ 
	char *defn;           /* replacement text */ 
}; 
static struct nlist *hashtab[HASHSIZE];  /* pointer table */ 




/* hash:  form hash value for string s */ 
unsigned hash(char *s) 
{ 
	unsigned hashval; 
	for (hashval = 0; *s != '\0'; s++) 
		hashval = *s + 31 * hashval; 
	return hashval % HASHSIZE; 
}


/* lookup:  look for s in hashtab */ 
void print_list() 
{ 
	struct nlist *np;
    int i;
    printf("\n\nPrinting actual list\n");
    for (i = 0 ; i < HASHSIZE ; i++){
        
	    for (np = hashtab[i];  np != NULL; np = np->next) 
		    printf("HASH: %d Name:%s Definition:%s\n", i, np->name, np->defn);
    }
}   

/* lookup:  look for s in hashtab */ 
struct nlist *lookup(char *s) 
{ 
	struct nlist *np; 
	for (np = hashtab[hash(s)];  np != NULL; np = np->next) 
		if (strcmp(s, np->name) == 0) 
			return np;     /* found */ 
	return NULL;           /* not found */ 
}


char *istrdup(char *); 
/* install:  put (name, defn) in hashtab */ 
struct nlist *install(char *name, char *defn) 
{ 
	struct nlist *np; 
	unsigned hashval; 
	if ((np = lookup(name)) == NULL) { /* not found */ 
		np = (struct nlist *) malloc(sizeof(*np)); 
		if (np == NULL || (np->name = strdup(name)) == NULL) 
		return NULL; 
		hashval = hash(name); 
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np; 
	} else       /* already there */ 
		free((void *) np->defn);   /*free previous defn */ 
	if ((np->defn = istrdup(defn)) == NULL) 
		return NULL; 
	return np; 
}
char *istrdup(char *s)   /* make a duplicate of s */ 
{ 
	char *p; 
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */ 
	if (p != NULL) 
		strcpy(p, s); 
	return p; 
}


/* install:  put (name, defn) in hashtab */ 
struct nlist *undef(char *name, char *defn) 
{ 
	struct nlist *np; 
	unsigned hashval; 
	if ((np = lookup(name)) != NULL) {
        if (np == hashtab[hash(name)]){
            hashtab[hash(name)] = np->next;
            free((void *) np->defn);
            free(np);   
        }else{
            
            struct nlist *p, *prev = hashtab[hash(name)];
            p = prev->next;
            while (p!= NULL) {
                if (p != np) {
                    p = p->next;
                    prev = prev->next;
                } else
                    break;
            }
            prev->next = p->next;            
            free((void *) np->defn);
            free(np); 
        }
	} 
}
int main(){
    

    install("alex", "superman");
    install("bogdan", "batman");
    install("andrei", "spiderman");
    print_list();
    printf("Undef bogan, batman\n");
    undef("bogdan", "batman");
    print_list();
    printf("Undef alex, superman\n");
    undef("alex", "superman");
    print_list();
}


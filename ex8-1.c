#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <sys/time.h> 
#define PERMS 0666
/* cat:  concatenate files, version 1 */ 
int main(int argc, char *argv[]) 
{ 
    FILE *fp; 
    int f1;
    void filecopy(FILE *, FILE *);
    void standard_filecopy(int, int);
    long elapsed1,elapsed2;

    int new_argc = argc;

    struct timeval t0, t1;    
    gettimeofday(&t0, 0);
    if (argc == 1) /* no args; copy standard input */ 
        filecopy(stdin, stdout); 
    else 
        while(--new_argc > 0) 
            if ((fp = fopen(argv[new_argc], "r")) == NULL) { 
                printf("cat: can't open %s\n", *argv); 
                return 1;   
            } else { 
                filecopy(fp, stdout); 
                fclose(fp); 
            }
    gettimeofday(&t1, 0);
    elapsed1 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    

    gettimeofday(&t0, 0);    
    if (argc == 1) /* no args; copy standard input */ 
        standard_filecopy(0, 1); 
    else
        while(--argc > 0) 
            if ((f1 = open(argv[argc], O_RDONLY, 0)) == -1) { 
                printf("cat: can't open %s\n", *argv); 
                return 1;   
            } else { 
                standard_filecopy(f1, 1); 
                close(f1); 
            }

    gettimeofday(&t1, 0);
    elapsed2 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    printf("\n---Time consumed for system_cals: %ld/non-system_cals: %ld\n", elapsed2, elapsed1);
         
    return 0; 
}
 
/* filecopy:  copy file ifp to file ofp */ 
void filecopy(FILE *ifp, FILE *ofp) 
{ 
    int c; 
    while ((c = getc(ifp)) != EOF) 
        putc(c, ofp); 
} 
 
void standard_filecopy(int ifp, int ofp)
{ 
    char c[1]; 
    while (read(ifp, c, 1) > 0) 
        write(ofp, c, 1); 
}

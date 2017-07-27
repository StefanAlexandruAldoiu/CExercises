#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>      /* flags for read and write */ 
#include <sys/types.h>  /* typedefs */ 
#include <sys/stat.h>   /* structure returned by stat */ 
#include "dirent.h" 
#include <sys/dir.h>   /* local directory structure */ 
#include <stdlib.h>
#include <unistd.h>
#ifndef DIRSIZ 
#define DIRSIZ  14
#define MAX_PATH 1024  
#endif 

/* system-dependent */ 
typedef struct {       /* portable directory entry */ 
    long ino;                  /* inode number */ 
    char name[NAME_MAX+1];     /* name + '\0' terminator */ 
} Direnti; 

typedef struct {       /* minimal DIR: no buffering, etc. */ 
    int fd;               /* file descriptor for the directory */ 
    Direnti d;             /* the directory entry */ 
} DIRi; 


void fsize(char *); 
void dirwalk(char *, void (*fcn)(char *)); 

/* opendir:  open a directory for readdir calls */ 
DIRi *opendiri(char *dirname) 
{ 
    int fd; 
    struct stat stbuf; 
    DIRi *dp; 
    if ((fd = open(dirname, O_RDONLY, 0)) == -1 
    || fstat(fd, &stbuf) == -1 
    || (stbuf.st_mode & S_IFMT) != S_IFDIR 
    || (dp = (DIRi *) malloc(sizeof(DIRi))) == NULL) 
        return NULL; 
    dp->fd = fd; 
    return dp; 
} 

/* closedir:  close directory opened by opendir */ 
void closediri(DIRi *dp) { 
    if (dp) { 
    close(dp->fd); 
    free(dp); 
    } 
} 
   
/* readdir:  read directory entries in sequence */ 
Direnti *readdiri(DIRi *dp) 
{ 
    struct direct dirbuf;  /* local directory structure */ 
    static Direnti  d;      /* return: portable structure */ 
    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) { 
        if (dirbuf.d_ino == 0) /* slot not in use */ 
            continue; 
        d.ino = dirbuf.d_ino; 
        strncpy(d.name, dirbuf.d_name, DIRSIZ); 
        d.name[DIRSIZ] = '\0';  /* ensure termination */ 
        return &d; 
    } 
    return NULL; 
} 

/* print file name */ 
int main(int argc, char **argv) 
{
    if (argc == 1)  /* default: current directory */ 
        fsize("."); 
    else 
        while (--argc > 0) 
            fsize(*++argv);  
    return 0; 
} 

/* fsize:  print the name of file "name" */ 
void fsize(char *name) 
{ 
    struct stat stbuf; 
    if (stat(name, &stbuf) == -1) { 
        fprintf(stderr, "fsize: can't access %s\n", name); 
        return; 
    } 
    
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) 
        dirwalk(name, fsize); 
    printf("size: %8ld and inode:%d for name: %s\n", stbuf.st_size, (int)stbuf.st_ino, name); 
} 

/* dirwalk:  apply fcn to all files in dir */ 
void dirwalk(char *dir, void (*fcn)(char *)) { 
    char name[MAX_PATH]; 
    Direnti *dp; 
    DIRi *dfd; 
    if ((dfd = opendiri(dir)) == NULL) { 
        fprintf(stderr, "dirwalk: can't open %s\n", dir); 
        return; 
    } 
    while ((dp = readdiri(dfd)) != NULL) { 
        if (strcmp(dp->name, ".") == 0 
        || strcmp(dp->name, "..")) 
            continue;    /* skip self and parent */ 
        if (strlen(dir)+strlen(dp->name)+2 > sizeof(name)) 
            fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name); 
        else { 
            sprintf(name, "%s/%s", dir, dp->name); 
            (*fcn)(name); 
        } 
    } 
    closediri(dfd); 
} 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int readFile(FILE* fpsrc, FILE* fpdest);


int main() {
    FILE *fp = NULL;
    FILE *crashfp = NULL;
    DIR *dir;
    struct  dirent* ent;
    int count = 0;

    dir = opendir("../sql/");
    if (!dir)
    {
        crashfp =fopen("../crash.log","a");
        fprintf(crashfp, "fichier x introuvable\n");
        closedir(dir);
        return EXIT_FAILURE;
    }

    while ((ent = readdir (dir))!= NULL)
    {
        if (strstr(ent->d_name,".sql")) {
            count++;
        }

    }
    printf("%d",count);
    closedir(dir);
    for (int i = 0; i <count ; ++i) {

    }

    return EXIT_SUCCESS;
}

int readFile(FILE *fpsrc, FILE *fpdest) {
    int count = 0;
    char st[200];

    while (fgets(st, 200, fpsrc),feof(fpsrc) ==0 ) {
        if (strstr(st,"insert into")  || strstr(st,"INSERT INTO") ) {
            fputs(st,fpdest);
            count++;
        }
    }
    return count;
}
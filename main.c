#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int readFile(FILE* fpsrc, FILE* fpdest);


int main() {
    FILE *fp = NULL;
    FILE *newfp = NULL;
    FILE *crashfp = NULL;
    DIR *dir;
    struct  dirent* ent;
    int count = 0;
    char  path[256];

    dir = opendir("../sql/");
    if (!dir)
    {
        crashfp = fopen("../crash.log","a");
        fprintf(crashfp, "dossier sql introuvable\n");
        fclose(crashfp);
        return EXIT_FAILURE;
    }
    newfp = fopen("../new.sql","a");
    if (!newfp)
    {
        crashfp = fopen("../crash.log","a");
        fprintf(crashfp, "fichier de fusion impossible à creer\n");
        fclose(crashfp);
        return EXIT_FAILURE;
    }
    while ((ent = readdir (dir))!= NULL)
    {
        if (strstr(ent->d_name,".sql")) {
            strcpy(path,"../sql/");
            count++;
            strcat(path,ent->d_name);
            puts(path);
            fp = fopen(path,"r");
            if (!fp)
            {
                crashfp = fopen("../crash.log","a");
                fprintf(crashfp, "fichier introuvable %s \n",ent->d_name);
                fclose(crashfp);
                return EXIT_FAILURE;
            }
            printf("lignes copiees %d\n",readFile(fp,newfp));
        }

    }
    printf("nombre de fichiers sql trouves:%d",count);
    closedir(dir);

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
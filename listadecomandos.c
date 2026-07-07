#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    DIR *directorio;
    struct dirent *archivo;
    char archivos[100][256];
    int contador = 0;
    int opcion;
    char comando[300];


    directorio = opendir("/mnt/raid0/terminal");

    if (directorio == NULL)
    {
        printf("No se pudo abrir el directorio.\n");
        return 1;
    }

    while ((archivo = readdir(directorio)) != NULL)
    {
        if (archivo->d_name[0] != '.')
        {
            strcpy(archivos[contador], archivo->d_name);

            printf("%d - %s\n", contador + 1, archivos[contador]);

            contador++;
        }
    }

    closedir(directorio);

    printf("\nSeleccione un archivo: ");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= contador)
    {
        printf("Seleccionó: %s\n", archivos[opcion - 1]);

        
		snprintf(comando, sizeof(comando),"cat /mnt/raid0/terminal/%s", archivos[opcion - 1]);

		system(comando);
    }
    else
    {
        printf("Opción inválida.\n");
    }

    return 0;
}
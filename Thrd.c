#include "Thrd.h"

void* ThrdFunc (void* arg) //so sieht API aus
{
    int* Numb = (int*) arg; // Casting. It was : int* Numb = arg;
    printf("\nThread has the number %2d",*Numb); // Before Casting in was printf("\nThread has the number %2d",Numb);
    //sleep(2);
    return 0;
}

/*
 * & - adresse
 * * - inhalt
 */

int main(void)
{
    //pthread_t ID; // actually pthread_t is an integer
    pthread_t ID[TCOUNT]; // array of number of threads
    int j;

    for(j=0; j<TCOUNT; j++)
    {
        //VORSICHT - Array fängt mit 0 an, aber threads fangen mit 1 an!!!
        pthread_create(&ID[j], NULL, &ThrdFunc, &ID[j]);
        printf("\nFrom main(): %d", ID[j]);
    }
    for(j=0; j<TCOUNT; j++)
    {
        pthread_join(ID[j],NULL);
    }
    //pthread_create(&ID, NULL, &ThrdFunc, &ID); //(&ID - For Operation System, NULL, &ThrdFunc - Funktion übergabe, &ID - Argument from ThrdFunc(void* arg))
    //printf("\nFrom main(): %d", ID);
    //pthread_join(ID,NULL); // Thread abwarten
    //sleep(3);
    return 0;
}
/*
 * main - parent process
 * ThrdFunc - child process, because we use pthread_create(&ID, NULL, &ThrdFunc, &ID);
 * pthread_join(ID,NULL); - we wait for thread
 */


/*
 * Sollte ThrdFunc mehrere parameter haben, dann übergeben wir in den pthread_create(&ID, NULL, &ThrdFunc, &ID); letzte &ID als ein Typ(struct) übergeben
void* ThrdFunc (void* arg) //so sieht API aus
{
    // Typ* S = (Typ*) arg;
    ...
    return 0;
}
 */

/*
int main(void)
{

    int j;
    for(j=1; j<=TCOUNT; j++)
    {
        printf("\nFrom main(): %d", j);
    }

    return 0;
}*/

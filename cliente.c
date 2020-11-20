#include <stdio.h>
#include <unistd.h>
#include "get_free_token.h"

// função que chama RPC get_1
bool_t get (CLIENT *clnt)
{
    bool_t *res;

    res = get_1(NULL, clnt);

    return (*res);
}

// função que chama RPC free_1
void free_token (CLIENT *clnt)
{
    free_1(NULL, clnt);
}


int main( int argc, char *argv[])
{
    CLIENT *clnt;


    /* verifica se o cliente foi chamado corretamente */
    if (argc!=2)
    {
        fprintf (stderr,"Usage: %s hostname\n",argv[0]);
        exit (1);
    }

    /* cria uma struct CLIENT que referencia uma interface RPC */
    clnt = clnt_create (argv[1], GET_FREE_PROG, GET_FREE_VERSION, "udp");

    /* verifica se a referência foi criada */
    if (clnt == (CLIENT *) NULL)
    {
        clnt_pcreateerror (argv[1]);
        exit(1);
    }

    /* executa os procedimentos remotos */
    for (int i = 0; i < 10; ++i)
    {
        if(get(clnt)){
            printf("Pegou o token\n");
            sleep(1);
            free_token(clnt);
        }else
        {
            printf("Não pegou o token\n");
        }    
        sleep(1);
    }      

    return (0);
}
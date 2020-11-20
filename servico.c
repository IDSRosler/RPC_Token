#include <stdio.h>
#include "get_free_token.h"

static bool_t token = TRUE;

// implementação da função get
bool_t * get_1_svc (void *argp, struct svc_req *rqstp)
{
    static bool_t res;
    printf ("Recebi chamado: get token\n");
    if (token)
    {
        res = TRUE;
        token = FALSE;
        return (&res);
    }else
    {
        res = FALSE;
        return (&res);
    }
}

// implementação da função free
void * free_1_svc (void *argp, struct svc_req *rqstp)
{
    printf ("Recebi chamado: free token\n");
    token = TRUE;
}
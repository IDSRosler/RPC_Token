#define PROGRAM_NUMBER 12345
#define VERSION_NUMBER 1

program GET_FREE_PROG
{
    version GET_FREE_VERSION
    {
        bool GET  (void) = 1;
        void FREE (void) = 2;
    }
    = VERSION_NUMBER;
}
= PROGRAM_NUMBER;
#include "dependency.h"

int main ()
{
    struct sockaddr_un serv_adr;
    char               filename [FILENAME_SZ];

    filename[FILENAME_SZ-1] = EOS;
    
    r_strcpy (serv_adr.sun_path, filename);

    return 0;
}

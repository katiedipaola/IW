#include "dependency.h"

int main ()
{
    struct sockaddr_un serv_adr;
    char               filename [FILENAME_SZ];

    filename[FILENAME_SZ-1] = EOS;
    
    r_strncpy (serv_adr.sun_path, filename, SUN_PATH_SZ-1);

    return 0;
}

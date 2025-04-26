#include "../stubs.h"

#define BUFSZ BASE_SZ

#define INSZ BUFSZ + 3

typedef char u_char;
typedef short int16_t;
typedef int time_t;
typedef int u_int;
typedef int uint32_t;
typedef long u_long;

struct databuf {
  struct databuf	*d_next;
  int16_t		d_type;
  u_char		d_data[sizeof(char*)];
  int16_t		d_class;
  int           	d_flags;
  int16_t		d_zone;
};

struct namebuf {
  u_int	        	n_hashval;
  struct namebuf	*n_next;
  struct databuf	*n_data;
  struct namebuf	*n_parent;
  struct hashbuf	*n_hash;
  char		        _n_name[sizeof(void*)];
};

struct timeval
{
  time_t tv_sec;
};

typedef uint32_t in_addr_t;
struct in_addr {
  in_addr_t s_addr;
};

struct sockaddr_in {
  short            sin_family;
  unsigned short   sin_port;
  struct in_addr   sin_addr;
};

#define NSMAX 16 
struct qinfo {
  struct databuf	*q_usedns[NSMAX];
  u_char		q_naddr;
  u_char		q_nusedns;
};

#define T_A            1 
#define T_NS           2

#define	INIT_REFRESH	600

#define NAME(nb)    ((nb)._n_name + 1)

#define C_ANY          255 
#define T_ANY          255 

#define DB_F_HINT       0x01	
#define DB_F_ACTIVE     0x02	

#define DB_Z_CACHE      (0)

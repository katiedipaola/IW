#include "dependency.h"

extern int nondet_int();

int haveComplained (const char *tag1,
                    const char *tag2)
{
  return nondet_int();
}

const char *p_type (int type)
{
  return NULL;
}


static void
nslookupComplain(const char *sysloginfo, 
                 const char *net_queryname, 
                 const char *complaint, 
                 const char *net_dname, 
                 const struct databuf *a_rr, 
                 const struct databuf *nsdp)
{
	char queryname[INSZ+1], dname[INSZ+1];
	const char *a, *ns;
	const char *a_type;
	int print_a;

	strncpy(queryname, net_queryname, sizeof queryname);
	queryname[(sizeof queryname) - 1] = EOS;
	strncpy(dname, net_dname, sizeof dname);
	dname[(sizeof dname) - 1] = EOS;

	if (sysloginfo && queryname && !haveComplained(queryname, complaint))
	{
          char buf[BUFSZ];
          
          a = ns = (char *)NULL;
          print_a = (a_rr->d_type == T_A);
          a_type = p_type(a_rr->d_type);

          if ( a != NULL || ns != NULL) {
            
            r_strcpy (buf, sysloginfo);
          } else {
            
            r_strcpy (buf, sysloginfo);
          }
	}
}

int main ()
{
  char sysloginfo [INSZ];
  char net_queryname [INSZ];
  char net_dname [INSZ];
  struct databuf a_rr;
  struct databuf nsdp;
  static char *complaint =
      "Glue A RR missing";

  sysloginfo [INSZ-1] = EOS;
  net_queryname [INSZ-1] = EOS;
  net_dname [INSZ-1] = EOS;

  nslookupComplain (sysloginfo, net_queryname, complaint, net_dname,
                    &a_rr, &nsdp);

  return 0;
}

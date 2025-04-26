#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <dependency.h>

#define OPTIONS	"B:b:C:cd:e:F:f:Gh:IiL:M:mN:nO:o:p:q:R:r:sTtUV:vX:"

#define LEN 100
unsigned char tTdvect[LEN];


int
main(argc, argv, envp)
	int argc;
	char **argv;
	char **envp;
{
	int j;

	tTsetup(tTdvect, LEN, "0-99.1");
	
	while ((j = getopt(argc, argv, OPTIONS)) != -1)
	  {
	    switch (j)
	      {
	      case 'd':
		if (strcmp(optarg, "ANSI") == 0)
		  {
		    break;   
		  }
		tTflag(optarg);
		setbuf(stdout, (char *) NULL);
		break;
		
	      case 'G':
		break;
	  
	      case 'L':
		break;
		
	      case 'U':
		break;
	      }
	  }
	
	
	return 0;


}


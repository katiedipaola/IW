#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <dependency.h>

static u_char	*tTvect;
static int	tTsize;
static char	*DefFlags;

#define OPTIONS	"B:b:C:cd:e:F:f:Gh:IiL:M:mN:nO:o:p:q:R:r:sTtUV:vX:"

void
tTsetup(vect, size, defflags)
	u_char *vect;
	int size;
	char *defflags;
{
        tTvect = vect;
	tTsize = size;
	DefFlags = defflags;
}

void
tTflag(s)
	register char *s;
{
	int first, last;
	register unsigned int i;

	printf ("s: %s", s);

	if (*s == '\0')
		s = DefFlags;

	for (;;)
	{
		i = 0;
               
		while (isascii(*s) && isdigit(*s))
			i = i * 10 + (*s++ - '0');

 		first = i;

		if (*s == '-')
		{
			i = 0;
			while (isascii(*++s) && isdigit(*s))
				i = i * 10 + (*s - '0');
		}
		last = i;

		i = 1;
		if (*s == '.')
		{
			i = 0;
			while (isascii(*++s) && isdigit(*s))
				i = i * 10 + (*s - '0');
		}

		if (first >= tTsize) 
			first = tTsize - 1;
		if (last >= tTsize)  
		  last = tTsize - 1;

		while (first <= last){ 
		{                     
		  printf("index = %d\n", first); 
		  tTvect[first++] = i; 
		}
		}
		if (*s++ == '\0')
			return;
	}
}


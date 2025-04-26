# include "dependency.h"
# include <string.h>
#include <assert.h>

void mime7to8(HDR *, ENVELOPE *);
char * hvalue(char *, HDR *);

int main(int argc, char **argv){
  
  HDR *header;
  register ENVELOPE *e;
  FILE *temp;
 
  assert (argc==2);

  header = (HDR *) malloc(sizeof(struct header));
  
  header->h_field = "Content-Transfer-Encoding";
  header->h_value = "base64";

  e = (ENVELOPE *) malloc(sizeof(struct envelope));
  e->e_id = "First Entry";

  temp = fopen(argv[1],"r");
 
  e->e_dfp = temp;
  mime7to8(header, e);

  fclose(temp);

  return 0;


  return 0;
}

static char index_64[128] =
{
	-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
	-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
	-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,62, -1,-1,-1,63,
	52,53,54,55, 56,57,58,59, 60,61,-1,-1, -1,-1,-1,-1,
	-1, 0, 1, 2,  3, 4, 5, 6,  7, 8, 9,10, 11,12,13,14,
	15,16,17,18, 19,20,21,22, 23,24,25,-1, -1,-1,-1,-1,
	-1,26,27,28, 29,30,31,32, 33,34,35,36, 37,38,39,40,
	41,42,43,44, 45,46,47,48, 49,50,51,-1, -1,-1,-1,-1
};

#define CHAR64(c)  (((c) < 0 || (c) > 127) ? -1 : index_64[(c)])

void
mime7to8(header, e)
	HDR *header;
	register ENVELOPE *e;
{
 
	register char *p;
	u_char *fbufp;
	char canary[10];
	u_char fbuf[MAXLINE + 1];
	
	strcpy(canary, "GOOD");

	p = hvalue("Content-Transfer-Encoding", header);
	if (p == NULL)
	  {
	    printf("Content-Transfer-Encoding not found in header\n");
	    return;
	  }

	if (strcasecmp(p, "base64") == 0)
	{
		int c1, c2, c3, c4;

		fbufp = fbuf;
		while ((c1 = fgetc(e->e_dfp)) != EOF)
		{
			if (isascii(c1) && isspace(c1))
				continue;

			do
			{
				c2 = fgetc(e->e_dfp);
			} while (isascii(c2) && isspace(c2));
			if (c2 == EOF)
				break;

			do
			{
				c3 = fgetc(e->e_dfp);
			} while (isascii(c3) && isspace(c3));
			if (c3 == EOF)
				break;

			do
			{
				c4 = fgetc(e->e_dfp);
			} while (isascii(c4) && isspace(c4));
			if (c4 == EOF)
				break;

			if (c1 == '=' || c2 == '=')
				continue;
			c1 = CHAR64(c1);
			c2 = CHAR64(c2);
			
			*fbufp = (c1 << 2) | ((c2 & 0x30) >> 4); 

			if (*fbufp++ == '\n' || fbuf >= &fbuf[MAXLINE]) 
			{
			  if (*--fbufp != '\n' || *--fbufp != '\r')
			    fbufp++;                                        
			  *fbufp = '\0';
			  printf("resetting fbufp\n");
			  fbufp = fbuf;                             
			}
			if (c3 == '=')
				continue;
			c3 = CHAR64(c3);

			*fbufp = ((c2 & 0x0f) << 4) | ((c3 & 0x3c) >> 2);
			if (*fbufp++ == '\n' || fbuf >= &fbuf[MAXLINE])
			{
			  if (*--fbufp != '\n' || *--fbufp != '\r')
					fbufp++;
				*fbufp = '\0';
				printf("resetting fbufp\n");
				fbufp = fbuf;
			}
			if (c4 == '=')
				continue;
			c4 = CHAR64(c4);

			*fbufp = ((c3 & 0x03) << 6) | c4;
			if (*fbufp++ == '\n' || fbuf >= &fbuf[MAXLINE])
			{
			  if (*--fbufp != '\n' || *--fbufp != '\r')
			    fbufp++;
			  *fbufp = '\0';
			  printf("resetting fbufp\n");
			  fbufp = fbuf;
			}
		}

		if (fbufp > fbuf)
		{
		  *fbufp = '\0';
		}
	}
	else
	{
	  printf("We only support base64 encoding...\n");
	}

	printf("canary should be GOOD\n");
	printf("canary = %s\n", canary);
}

char * hvalue(field, header)
	char *field;
	HDR *header;
{
	register HDR *h;

	for (h = header; h != NULL; h = h->h_link)
	{
		if (!bitset(H_DEFAULT, h->h_flags) &&
		    strcasecmp(h->h_field, field) == 0)
			return (h->h_value);
	}
	return (NULL);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma ccuredvararg("scanf", printf(1))

#define MACROEXPAND	((unsigned char)0201)
#define MAXNAME		30	
#define MAXCANARY 10

enum bool {false, true}; 


int	ColonOkInAddr;
char	*MustQuoteChars;

char *
crackaddr(addr)
	register char *addr;
{
	register char *p;
	register char c;
	int cmtlev;
	int realcmtlev;
	int anglelev, realanglelev;
	int copylev;
	int bracklev;
	enum bool qmode;
	enum bool realqmode;
	enum bool skipping;
        enum bool putgmac = false;
	enum bool quoteit = false;
	enum bool gotangle = false;
	enum bool gotcolon = false;
	register char *bp;
	char *obp;
	char *buflim;
	char *bufhead;
	char *addrhead;
  static char canary[MAXCANARY+1];
	static char buf[MAXNAME + 1];
	static char test_buf[10];
	
  memset (canary, 'A', MAXCANARY+1);
	strcpy(test_buf, "GOOD");
	
        printf("Inside crackaddr!\n");

	while (*addr != '\0' && isascii((int)*addr) && isspace((int)*addr))
		addr++;


	bp = bufhead = buf;
	obp = bp;
	buflim = &buf[sizeof buf - 7];
	p = addrhead = addr;
	copylev = anglelev = realanglelev = cmtlev = realcmtlev = 0;
	bracklev = 0;
	qmode = realqmode = false;

        printf("qmode = %d\n", qmode);

	while ((c = *p++) != '\0')
	{

	  printf("c = %c\n", c);

		skipping = bp >= buflim;
              
		if (copylev > 0 && !skipping)
		      { 
		      *bp++ = c;
		      }
		if (c == '\\')
		{
			if (cmtlev <= 0 && !qmode)
				quoteit = true;

			if ((c = *p++) == '\0')
			{
				p--;
				goto putg;
			}
			if (copylev > 0 && !skipping)
			  {  
			    *bp++ = c;
			  }
			goto putg;
		}

		if (c == '"' && cmtlev <= 0)
		{
		  printf("quoted string...\n");
			qmode = !qmode;
			if (copylev > 0 && !skipping)
				realqmode = !realqmode;
			continue;
		}
		if (qmode)
			goto putg;

		if (c == '(')
		{
		  printf("left ( seen....\n");
			cmtlev++;

			if (!skipping)
			{
				buflim--;
				realcmtlev++;
				if (copylev++ <= 0)
				{
					if (bp != bufhead)
					  {
					    *bp++ = ' ';
					  }
					*bp++ = c;
				}
			}
		}
		if (cmtlev > 0)
		{
			if (c == ')')
			{
				cmtlev--;
				copylev--;
				if (!skipping)
				{
					realcmtlev--;
					buflim++;
				}
			}
			continue;
		}
		else if (c == ')')
		{
			if (copylev > 0 && !skipping)
				bp--;
		}

		if (c == '[')
			bracklev++;
		  else if (c == ']')
			bracklev--;

		if (c == ':' && anglelev <= 0 && bracklev <= 0 &&
		    !gotcolon && !ColonOkInAddr)
		{		        
			register char *q;
			
			if (*p == ':' || *p == '.')
			{
				if (cmtlev <= 0 && !qmode)
					quoteit = true;
				if (copylev > 0 && !skipping)
				{
				  *bp++ = c;
				  *bp++ = *p;
				}
				p++;
				goto putg;
			}

			gotcolon = true;

			bp = bufhead;
			if (quoteit)
			{
			  *bp++ = '"';

			  --p;
			  
			  while (isascii((int) *--p) && isspace((int) *p))
				  continue;
			  p++;
			}
			for (q = addrhead; q < p; )
			{
				c = *q++;
				if (bp < buflim)
				{
					if (quoteit && c == '"')
					  *bp++ = '\\';
					*bp++ = c;
				
				}
			}
			if (quoteit)
			{
				if (bp == &bufhead[1])
					bp--;
				else{
				  *bp++ = '"';
				}
				while ((c = *p++) != ':')
				  {
				    if (bp < buflim){
				      *bp++ = c;
				    }
				  }
				*bp++ = c;
			}
			while (isascii((int) *p) && isspace((int)*p) && bp < buflim)
			  {
			    *bp++ = *p++;
			  }
			copylev = 0;
			putgmac = quoteit = false;
			bufhead = bp;
			addrhead = p;
			continue;
		}

		if (c == ';' && copylev <= 0 && !ColonOkInAddr)
		{
			if (bp < buflim)
			  *bp++ = c;
		}
		if (strchr(MustQuoteChars, c) != NULL)
		{
			if (cmtlev <= 0 && !qmode)
				quoteit = true;
		}

		if (c == '<')
		{
			register char *q;

			if (gotangle)
				quoteit = true;
			gotangle = true;

			anglelev = 1;
			if (!skipping)
				realanglelev = 1;

			bp = bufhead;
			if (quoteit)
			  {
			    *bp++ = '"';
			    
			    --p;
			    while (isascii((int)*--p) && isspace((int)*p))
			      continue;
			    p++;
			  }
			for (q = addrhead; q < p; )
			  {
				c = *q++;
				if (bp < buflim)
				  {
				    if (quoteit && c == '"')
				      *bp++ = '\\';
				    *bp++ = c;
				}
			}
			if (quoteit)
			{
			  if (bp == &buf[1])
				  bp--;
				else
				  *bp++ = '"';
			  while ((c = *p++) != '<')
			    {
			      if (bp < buflim)
				*bp++ = c;
			    }
			  *bp++ = c;
			}
			copylev = 0;
			putgmac = quoteit = false;
			continue;
		}

		if (c == '>')
		{
			if (anglelev > 0)
			{
				anglelev--;
				if (!skipping)
				{
					realanglelev--;
					buflim++;
				}
			}
			else if (!skipping)
			{
				if (copylev > 0)
					bp--;
				quoteit = true;
				continue;
			}
			if (copylev++ <= 0)
			  *bp++ = c;
			continue;
		}
	putg:
		if (copylev <= 0 && !putgmac)
		  {
		    if (bp > bufhead && bp[-1] == ')')
		      *bp++ = ' ';
		    *bp++ = MACROEXPAND;
		    *bp++ = 'g';
		    putgmac = true;
		  }
		printf("Buf = %s\n", buf);
	}
	
	if (realqmode)
	  *bp++ = '"';
	while (realcmtlev-- > 0)
	  *bp++ = ')';
	while (realanglelev-- > 0)
	  *bp++ = '>';
	*bp++ = '\0';
	
  printf("canary:\n");
  printbuf (canary, MAXCANARY+1);
  printf("buf:\n");
  printbuf (buf, MAXNAME+1);

	return buf;
}


int main(){

  char address[100];
  char *res_addr;

  MustQuoteChars = "@,;:\\()[].'";

  printf("Enter email address:\n");
  scanf("%99s", address);
  
  res_addr = crackaddr(address);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

struct header
{
	char		*h_field;
	char		*h_value;
	struct header	*h_link;
	u_short		h_flags;	

};

typedef struct header	HDR;

struct address
{
	char		*q_paddr;	
	char		*q_user;
	char		*q_ruser;
	char		*q_host;
	u_long		q_flags;
	uid_t		q_uid;
	gid_t		q_gid;
	char		*q_home;
	char		*q_fullname;
	struct address	*q_next;
	struct address	*q_alias;
	char		*q_owner;
	struct address	*q_tchain;
	char		*q_orcpt;
	char		*q_status;
	char		*q_rstatus;
	char		*q_statmta;	
	short		q_specificity;
};

typedef struct address ADDRESS;

struct envelope
{
	HDR		*e_header;
	long		e_msgpriority;
	time_t		e_ctime;
	char		*e_to;	
	ADDRESS		e_from;	
	char		*e_sender;	
	char		**e_fromdomain;
	ADDRESS		*e_sendqueue;	
	ADDRESS		*e_errorqueue;	
	long		e_msgsize;
	long		e_flags;
	int		e_nrcpts;
	short		e_class;
	short		e_hopcount;
	short		e_nsent;	
	short		e_sendmode;	
	short		e_errormode;
	short		e_timeoutclass;
	struct envelope	*e_parent;
	struct envelope *e_sibling;
	char		*e_bodytype;
	FILE		*e_dfp;
	char		*e_id;	
	FILE		*e_xfp;	
	FILE		*e_lockfp;
	char		*e_message;
	char		*e_statmsg;	
	char		*e_msgboundary;
	char		*e_origrcpt;
	char		*e_envid;	
	char		*e_status;
	time_t		e_dtime;
	int		e_ntries;
	dev_t		e_dfdev;
	ino_t		e_dfino;
	char		*e_macro[256];
};


typedef struct envelope	ENVELOPE;

# define bitset(bit, word)     (((word) & (bit)) != 0)
# define MAXLINE 50       
# define H_DEFAULT      0x0004  

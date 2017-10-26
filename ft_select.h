
#ifndef FT_SELECT_H
#define FT_SELECT_H

#include "libft/libft.h"
#include <termcap.h>
#include <termios.h>
#include <signal.h>

typedef struct		s_term
{
	struct termios	kankn;
	struct termios	nonkanon;
	char			*env;
	int				fd;
	int				colum;
	int				height;

}					t_term;

typedef struct		s_arg
{
	char			*line;
	size_t			len;
	int				flag;
}					t_arg;


void	ft_termcap_do(char *flag);

#endif
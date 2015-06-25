#include "minishell.h"

void	setenv_format_error(void)
{
	ft_putendl("usage: setenv [variable] [data] | [variable]=[data]");
}

void	setenv_already_exist_error(void)
{
	ft_putendl("setenv: environment line already exist");
}

void	unsetenv_format_error(void)
{
	ft_putendl("usage: unsetenv [environment line]");
}

void	unsetenv_no_exist_error(void)
{
	ft_putendl("unsetenv: environment line does not exist");
}

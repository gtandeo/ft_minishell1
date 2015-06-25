#include "minishell.h"

void	setenv_format_error(void)
{
	printf("usage: setenv [variable] [data] | [variable]=[data]");
}

void	setenv_already_exist_error(void)
{
	printf("setenv: environment line already exist");
}

void	unsetenv_format_error(void)
{
	printf("usage: unsetenv [environment line]");
}

void	unsetenv_no_exist_error(void)
{
	printf("unsetenv: environment line does not exist");
}

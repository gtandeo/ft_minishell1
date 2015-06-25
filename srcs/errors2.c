#include "minishell.h"

void	args_error(int ac)
{
	if (ac != 1)
	{
		printf("usage: ./ft_minishell1\n");
		exit(-1);
	}
}

void	env_error(const char **env)
{
	if (!env)
	{
		printf("error: can't start ft_minishell1 with an empty environment");
		exit(ENV_ERROR);
	}
}

void	cd_not_dir_error(void)
{
	;
}

void	cd_path_error(void)
{
	;
}

void	cd_rights_error(void)
{
	;
}

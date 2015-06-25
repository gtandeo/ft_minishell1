#include "minishell.h"

void	args_error(int ac)
{
	if (ac != 1)
	{
		ft_putendl("usage: ./ft_minishell1\n");
		exit(-1);
	}
}

void	env_error(char **env)
{
	if (!env)
	{
		ft_putendl("error: can't start ft_minishell1 with an empty or incomplete environment");
		exit(ENV_ERROR);
	}
}

void	malloc_error(void)
{
	ft_putendl("Malloc error");
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

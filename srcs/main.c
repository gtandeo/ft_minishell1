#include "minishell.h"

static void	start_errors(int ac, char **env)
{
	args_error(ac);
	env_error((const char**)env);
}

t_sh		*struct_init(char **env)
{
	t_sh	*ret;

	ret = (t_sh*)malloc(sizeof(t_sh));
	ret->error[0] = setenv_format_error;
	ret->error[1] = setenv_already_exist_error;
	ret->error[2] = unsetenv_format_error;
	ret->error[3] = unsetenv_no_exist_error;
	ret->error[4] = cd_not_dir_error;
	ret->error[5] = cd_path_error;
	ret->error[6] = cd_rights_error;
	(void)env;
	//ret->env = ft_tabdup(env);
	return ret;
}

void		ft_sh(t_sh *data)
{
	pid_t	father;
	char *str = "/bin/ls ..";

	(void)data;
	father = fork();
	if (father > 0)
		wait(NULL);
	else if (father == 0)
		execve("/bin/ls", ft_strsplit(str, ' '), NULL);
}

int			main(int ac, char **av, char **env)
{
	t_sh	*data;

	(void)av;
	start_errors(ac, env);
	data = struct_init(env);
	ft_sh(data);
	return (0);
}

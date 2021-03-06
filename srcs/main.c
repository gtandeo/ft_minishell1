#include "minishell.h"

static void	start_errors(int ac, char **env)
{
	args_error(ac);
	env_error(env);
}

void		ft_free_struct(t_sh *data)
{
	free(data->oldpwd);
	free(data->pwd);
	free(data->home);
	free(data->path);
	free(data->env);
}

char		*ft_epur_str(char *line)
{
	char	*ret;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	if ((ret = (char*)malloc(sizeof(char) * ft_strlen(line))) != NULL)
	{
		while (line[i])
		{
			if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v')
				ret[j] = ' ';
			else
				ret[j] = line[i];
			i++;
			j++;
		}
	}
	ret[j] = '\0';
	return (ret);
}

char		*ft_get_env_elm(char **env, const char *target)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], target, ft_strlen(target)))
			return ft_strdup(env[i] + ft_strlen(target));
		i++;
	}
	return NULL;
}

t_sh		*struct_init(char **env)
{
	t_sh	*ret;

	if ((ret = (t_sh*)malloc(sizeof(t_sh))) == NULL)
		malloc_error();
	ret->error[0] = setenv_format_error;
	ret->error[1] = setenv_already_exist_error;
	ret->error[2] = unsetenv_format_error;
	ret->error[3] = unsetenv_no_exist_error;
	ret->error[4] = cd_not_dir_error;
	ret->error[5] = cd_path_error;
	ret->error[6] = cd_rights_error;
	ret->env = ft_tabdup(env);
	if (!(ret->path = ft_get_env_elm(env, "PATH=")) ||!(ret->home = ft_get_env_elm(env, "HOME")) || !(ret->pwd = ft_get_env_elm(env, "PWD=")) || !(ret->oldpwd = ft_get_env_elm(env, "OLDPWD=")))
		return NULL;
	ret->line = NULL;
	return ret;
}

int			ft_line_parsor(t_sh *data)
{
	pid_t	father;
	char	**line = ft_strsplit(data->line, ' ');
	char	**path;
	char	*cmd = ft_strdup(line[0]);
	int		i;
	
	i = 0;
	path = ft_strsplit(data->path, ':');
	ft_print_tab(line);
	while (path[i])
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		else if (father == 0)
			execve(ft_strjoin(ft_strjoin(path[i], "/"), cmd), line, data->env);
		i++;
	}
	return (1);
}

void		ft_sh(t_sh *data)
{
	char	*line;
	char	*prompt;
	
	prompt = ft_get_env_elm(data->env, "USER=");
	while (1)
	{
		ft_putstr(prompt);
		ft_putstr("> ");
		get_next_line(0, &line);
		if (line[0])
		{
			if (!ft_strcmp(line, "exit"))
				return ;
			data->line = ft_epur_str(line);
			ft_line_parsor(data);
			free(data->line);
			free(line);
		}
	}
}

int			main(int ac, char **av, char **env)
{
	t_sh	*data;

	(void)av;
	start_errors(ac, env);
	if ((data = struct_init(env)) == NULL)
		env_error(NULL);
	ft_sh(data);
	ft_free_struct(data);
	return (0);
}

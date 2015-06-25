#include "minishell.h"

static void	start_errors(int ac, char **env)
{
	args_error(ac);
	env_error(env);
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
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if ((ret = (char*)malloc(sizeof(char) * ft_strlen(line))) != NULL)
		while (line[i])
		{
			if (line[i] == ' ' || line[i] == '\t')
			{
				while (line[i] == ' ' || line[i] == '\t')
					i++;
				if (!line[i])
					break;
				ret[j++] = ' ';
				ret[j] = line[i];
				j++;
			}
			else if (line[i])
				ret[j++] = line[i++];
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
	if (!(ret->path = (const char **)ft_get_env_elm(env, "PATH=")) || !(ret->pwd = ft_get_env_elm(env, "PWD=")) || !(ret->oldpwd = ft_get_env_elm(env, "OLDPWD=")))
		return NULL;
	ret->line = NULL;
	return ret;
}

int			ft_line_parsor(t_sh *data)
{
	char	**line = ft_strsplit(data->line, ' ');
	(void)line;
	return (0);
}

void		ft_sh(t_sh *data)
{
	//pid_t	father;
	char	*line;
	
	while (ft_strcmp(data->line, "exit"))
	{
		get_next_line(0, &(line));
		data->line = ft_epur_str(line);
		printf("|%s|\n", data->line);
		if (ft_line_parsor(data))
			ft_putendl("line_OK");
		/*if (line)
		{
			father = fork();
			if (father > 0)
				wait(NULL);
			else if (father == 0)
				execve("/bin/ls", ft_strsplit(line, ' '), data->env);
		}*/
		free(line);
		if (data->line)
			free(data->line);
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
	return (0);
}

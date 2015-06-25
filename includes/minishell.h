#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define ENV_ERROR 0
# define SETENV_FORMAT_ERROR 1
# define SETENV_ALREADY_EXIST_ERROR 2
# define UNSETENV_FORMAT_ERROR 3
# define UNSETENV_NO_EXIST_ERROR 4
# define CD_NO_DIR_ERROR 5
# define CD_PATH_ERROR 6
# define CD_RIGHTS_ERROR 7

typedef struct	s_sh
{
	void		(*error[7])();
	char		**env;
	const char	**path;
	char		*pwd;
	char		*oldpwd;
	char		*line;
}				t_sh;

/*
** ERROR FUNCTIONS
*/
void	args_error(int ac);
void	env_error(char **env);
void	malloc_error(void);
void	setenv_format_error(void);
void	setenv_already_exist_error(void);
void	unsetenv_format_error(void);
void	unsetenv_no_exist_error(void);
void	cd_not_dir_error(void);
void	cd_path_error(void);
void	cd_rights_error(void);

#endif

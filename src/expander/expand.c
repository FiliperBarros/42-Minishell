#include "minishell.h"


int		to_expand(t_token *t)
{
	return ((ft_strrchr(t->value, '$') && t->quote_type != '\''));
}

void	ft_strlen_till_end_of_$(char *var)
{
	int	i = 0;
	while (var[i] && !ft_is_space(var[i]))
		i++;
	return(i);
}

void	expand(t_env **env, t_token **token)
{
	t_token	*t;
	char *$_pos;
	int		len;

	t = *tokens;
	$_pos = ft_strrchr(t->value, '$');
	if (ft_isdigit(++$_pos))
		return (not_expand());
	len = ft_strlen_till_end_of_$(&t->value[++pos])
	else (ft_strncmp( ))
}
void	expander(t_env *env, t_token **tokens)
{
	t_token	*t;

	t = *tokens;
	while (t)
	{
		if (to_expand(t))
			expand(&env, t);
		else if(t->quote_type)
			remove_quotes(t);
		t = t->next;
	}
}




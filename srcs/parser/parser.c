/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:37:51 by helvi             #+#    #+#             */
/*   Updated: 2021/04/10 15:14:26 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static void	debug_print_right(t_node *node, char *prefix)
{
	char	*temp;

	temp = NULL;
	if (prefix == NULL && node->left)
		temp = ft_strdup("|");
	else if (prefix == NULL)
		temp = ft_strdup("");
	else if (node->right->left || node->right->right)
		temp = ft_strjoin(prefix, "  |");
	else
		temp = ft_strjoin(prefix, "  ");
	debug_print_tree(node->right, temp);
	ft_free(temp);
}

static void	debug_print_left(t_node *node, char *prefix)
{
	char	*temp;

	temp = NULL;
	if (prefix == NULL)
		temp = ft_strdup("");
	else
		temp = ft_strjoin(prefix, "  ");
	debug_print_tree(node->left, temp);
	ft_free(temp);
}

void	debug_print_tree(t_node *node, char *prefix)
{
	if (!node)
		return ;
	if (prefix != NULL)
	{
		ft_printf(prefix);
		if (ft_strlen(prefix) > 0 && prefix[ft_strlen(prefix) - 1] == '|')
			ft_printf("--");
		else
			ft_printf("|--");
	}
	ft_printf("[%s]\n", node->command);
	if (node->right)
		debug_print_right(node, prefix);
	if (node->left)
		debug_print_left(node, prefix);
}

t_job	*parser(char *input, t_term *term)
{
	t_token	*tokens;
	t_node	*root;
	t_job	*returnable;

	tokens = lexer(input, term);
	root = ast_creator(tokens, term);
	if (term->flag_debug == 1)
		debug_print_tree(root, NULL);
	returnable = job_creation(root, term);
	free_ast(root);
	return (returnable);
}

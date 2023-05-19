#include "main.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new_var, *tmp;

	new_var = malloc(sizeof(r_var));
	if (new_var == NULL)
		return (NULL);

	new_var->len_var = lvar;
	new_var->val = val;
	new_var->len_val = lval;

	new_var->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new_var;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_var;
	}

	return (*head);
}
/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *tmp;
	r_var *curr_var;

	if (head != NULL)
	{
		curr_var = *head;
		while ((tmp = curr_var) != NULL)
		{
			curr_var = curr_var->next;
			free(tmp);
		}
		*head = NULL;
	}
}

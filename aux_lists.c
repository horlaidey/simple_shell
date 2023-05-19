#include "main.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new_ptr, *tmp;

	new_ptr = malloc(sizeof(sep_list));
	if (new_ptr == NULL)
		return (NULL);

	new_ptr->separator = sep;
	new_ptr->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new_ptr;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_ptr;
	}

	return (*head);
}

/**
 * free_sep_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *tmp;
	sep_list *curr_ptr;

	if (head != NULL)
	{
		curr_ptr = *head;
		while ((tmp = curr_ptr) != NULL)
		{
			curr_ptr = curr_ptr->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new_list, *tmp;

	new_list = malloc(sizeof(line_list));
	if (new_list == NULL)
		return (NULL);

	new_list->line = line;
	new_list->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new_list;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_list;
	}

	return (*head);
}

/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **head)
{
	line_list *tmp;
	line_list *curr_list;

	if (head != NULL)
	{
		curr_list = *head;
		while ((tmp = curr_list) != NULL)
		{
			curr_list = curr_list->next;
			free(tmp);
		}
		*head = NULL;
	}
}

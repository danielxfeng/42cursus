/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:23:57 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/17 20:01:49 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Create a new node for the value.
// The caller handles the free on error.
static t_node *new_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->prev = NULL;
    node->next = NULL;
    node->value = value;
}

// Add a node for given `value`, then push to the end of `list`.
// The caller handles the free on error.
t_node *push_back(t_stack *stack, int value)
{
    t_node *node;
    t_node *tail;

    node = new_node(value);
    if (!node)
        return (NULL);
    if (!stack->root)
    {
        stack->root = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        tail = stack->root->prev;
        node->next = stack->root;
        node->prev = tail;
        tail->next = node;
        stack->root->prev = node;
    }
    ++(stack->len);
    return (node);
}

// Add a `node` to the front of `list`.
t_node *insert_front(t_stack *stack, t_node *node)
{
    t_node *head;

    if (!node)
        return (NULL);
    head = stack->root;
    stack->root = node;
    if (!head)
    {
        node->next = node;
        node->prev = node;
    }
    else
    {
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }
    ++(stack->len);
    return (node);
}

// Pop a `node` from the front of list.
// The caller should free the popped node.
t_node *pop_front(t_stack *stack)
{
    t_node *res;

    res = stack->root;
    if (res->next == res)
        stack->root = NULL;
    else
    {
       stack->root = res->next;
       stack->root->prev = res->prev;
       res->prev->next = res->next;
    }
    --(stack->len);
    return (res);
}

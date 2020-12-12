/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/11 11:23:13 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// typedef struct s_sh
// {
//     char    **g_env;
//     int     status;
    
// } t_sh;

typedef struct s_cmd
{
    char *cmd;
    char **arg;
    char *op;
    struct s_cmd *next;
    struct s_cmd *prev;
    
} t_cmd;

t_cmd   *g_cmd;
#endif
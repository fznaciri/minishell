/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 10:47:10 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_red
{
    char *red_type;
    char *file;
    struct s_red *next;
} t_red;

typedef struct s_cmd
{
    char *cmd;
    char **arg;
    char *op;
    t_red *red;
    struct s_cmd *next;
    struct s_cmd *prev;
    
} t_cmd;


t_cmd   *g_cmd;
#endif
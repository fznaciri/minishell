/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:21 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/26 13:10:00 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>
# define BUFFER_SIZE 32

int			gnl(int fd, char **line);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(const char *s1, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int		count_first_word(char *str, char c);
int		words_count(char *str, char c);
char	*ft_nstrdup(char *str, int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
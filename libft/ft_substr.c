/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:13 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 17:24:29 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
    char	*dest;
    size_t	i;

    if (!s)
        return (NULL);
    if (ft_strlen(s) <= start)
    {
        dest = ft_strdup("");
        if (!dest)
            return (NULL);
        return (dest);
    }
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    dest = (char *)malloc(len + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dest[i] = s[start + i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

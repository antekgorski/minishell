/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:11:26 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/05 15:14:19 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

typedef struct s_split_data
{
	int				i;
	int				word_start;
	int				word_index;
}					t_split_data;

// Part 1
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, char *s2);

// Part 2
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*get_next_line(int fd);
void				ft_free_split(char **split);
int					ft_atoi_base(const char *str, int base);
int					ft_wordcount(const char *str, char delimiter);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				**ft_strsplit(const char *str, char delimiter);
char				*ft_strsubchr(const char *s, char c);
void				*ft_memalloc(size_t size);
char				*ft_strchrs(const char *s, int c);
size_t				ft_strlen_gnl(const char *s);
char				*ft_substr_gnl(char const *s, unsigned int start,
						size_t len);
char				*ft_strdup_gnl(const char *s1);
char				*ft_strjoin_gnl(char const *s1, char const *s2);
char				*ft_strchr_gnl(const char *s, int c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));
int					ft_isspace(char c);
void				ft_free_char2(char **tofree);
void				ft_free_char3(char ***tofree);
char				*ft_strjoin_with(char const *s1, char const *s2, char c);
int					ft_strcmp(const char *s1, const char *s2);

#endif

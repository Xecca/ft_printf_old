/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:23:30 by aponomar          #+#    #+#             */
/*   Updated: 2019/11/18 19:37:13 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 5

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_rest
{
	int				fd;
	char			*rest;
	struct s_rest	*next;
}					t_rest;

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
int					ft_chcount(char const *s, char c);
char				*ft_ftoa(double nbr, unsigned int precision);
char				*ft_ftoa_long(long double nbr, unsigned int precision);
int					ft_intlen(int n);
char				*ft_intrevstr(int n, int count, int sign);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned int n, int base);
char				*ft_itoa_base_unsigned(size_t n, int base);
char				*ft_itoa_long(long n);
char				*ft_itoa_unsigned(size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, \
					void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_malloclen(const char *s);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, \
					const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, \
					const void *s2, size_t n);
void				*ft_memcpy(void *restrict dst, \
					const void *restrict src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(unsigned char c);
void				ft_putchar_fd(char c, int fd);
char				*ft_putdouble(int dval);
void				ft_putendl(char const *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char *str);
void				ft_putstr_fd(char const *s, int fd);
char				**ft_sfill(char const *s, char **str, \
					int wdcount, char c);
char				*ft_straddchar(char *str, char ch);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, int det);
size_t				ft_strlcat(char *restrict dst, \
					const char *restrict src, size_t dstsize);
void				*ft_strldup(void const *s, size_t l);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, \
					char (*f)(unsigned int, char));
char				*ft_strncat(char *restrict s1, \
					const char *restrict s2, size_t n);
int					ft_strncmp(const char *s1, \
					const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_strnequ(char const *s1, \
					char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, \
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, \
					unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_strupper(char *str);
void				ft_swap(char *ch1, char *ch2);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_trimlen(const char *s);
int					ft_wdcount(char const *s, char c);
int					get_next_line(const int fd, char **line);

#endif

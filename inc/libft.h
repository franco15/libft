/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:14:30 by lfranco-          #+#    #+#             */
/*   Updated: 2017/05/29 21:55:41 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <term.h>
# include <stddef.h>
# include <inttypes.h>

# define BUFF_SIZE	1024

typedef struct		s_gnl
{
	struct s_gnl	*next;
	char			data;
}					t_gnl;

typedef struct		s_lst
{
	void			*content;
	size_t			size;
	struct s_lst	*next;
}					t_lst;

/*
** array.c
*/
void				ft_arrdel(void **arr, int len);
size_t				ft_arrlen(void **s);
char				**ft_arrdup(char **s, int len);

/*
** conv.c
*/
char				*ft_itoa_base(long long int n, int b);
int					ft_atoi(char const *str);
int					ft_abs(int a);

/*
** conv2.c
*/
char				*ft_itoa_basel(unsigned long long int value, int base);

/*
** ft_printf.c
*/
void				ft_printfcolor(const char *format, ...);
void				ft_printf(const char *format, ...);

/*
** ft_printf_fd.c
*/
void				ft_printfcolor_fd(int fd, const char *format, ...);
void				ft_printf_fd(int fd, const char *format, ...);

/*
** ft_quicksort.c
*/
void				ft_swap(void **s, int i, int j);
void				ft_quicksort(void **s, int start, int end,
											int (comp)(void *, void *));

/*
** get_next_line.c
*/
int					get_next_line(int fd, char **line);

/*
** gnl_lst.c
*/
int					ft_lst_inc(t_gnl *lst, char c);
size_t				ft_lst_len(t_gnl *lst);
t_gnl				*ft_lst_new(char data);
void				ft_lst_push_back(t_gnl **begin_lst, char data);
char				*ft_lst_to_s(t_gnl *lst);

/*
** is.c
*/
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_isallupper(char *s);
int					ft_isletter(char uk, char k);
int					ft_isalnum(int c);

/*
** is2.c
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isprint(int c);

/*
** lst.c
*/
t_lst				*ft_lstpush(t_lst *list, void *content);
void				ft_lstforeach(t_lst *list, void (*f)());
void				ft_lst_rec_free(t_lst *list);
void				ft_lstadd(t_lst **alst, t_lst *n);
void				ft_lstaddback(t_lst **alst, t_lst *n);

/*
** lst2.c
*/
void				ft_lstdel(t_lst **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_lst *lst, void (*f)(t_lst *elem));
t_lst				*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem));
t_lst				*ft_lstnew(void const *content, size_t size);

/*
** mem.c
*/
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
** mem2.c
*/
void				*ft_realloc(void *ptr, size_t size, size_t newsize);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** put.c
*/
size_t				ft_putstr(char const *s);
void				ft_putnbr(int nb);
size_t				ft_putchar(char c);

/*
** put2.c
*/
void				ft_putendl(char const *s);
void				ft_putcstr(char const *s, size_t col);

/*
** put_fd.c
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putcharn_fd(int c, int n, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**
*/
void				ft_putcstr_fd(char const *s, size_t col, int fd);
void				ft_putendl_fd(char const *s, int fd);

/*
** str.c
*/
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strchr(const char *s, int c);

/*
** str2.c
*/
size_t				ft_strlenc(const char *s, char c);
char				*ft_strcpy(char *dst, const	char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);

/*
** str3.c
*/
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *s1, size_t l);
int					ft_str_inc(char *str, char c);

/*
** str4.c
*/
char				**ft_strsplit(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));

/*
** str5.c
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncatalrevez(char *s, char c, size_t n);

/*
** str6.c
*/
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strtrim(char const *s);

/*
** term.c
*/
void				ft_termcmd(char *s);
void				ft_clearscreen(int rows);
void				ft_cursor_goto(int x, int y);
size_t				ft_max_len(char **s);

/*
** unicode.c
*/
void				ft_uctoa(wchar_t c, char *str);
int					ft_uclen(wchar_t c);

/*
** wstr.c
*/
wchar_t				*ft_wstrnew(size_t len);
size_t				ft_wstrlen(const wchar_t *s);
wchar_t				*ft_wstrdup(const wchar_t *src);
char				*ft_wstr2str(wchar_t *ws);

/*
** xtra.c
*/
void				ft_error(char *s);
int					ft_countwords(char const *s, char c);
int					ft_wordlen(char const *s, char c);
int					ft_onlyspaces(char *s);
int					ft_onlyzeros(char *s);

/*
** xtra2.c
*/
int					ft_baselen(long long value, int base);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif

/**
**	\file	ft_select.h
**	\author	Alexis Guérin
**	\date	8 novembre 2017
*/

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <term.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/ioctl.h>

/**
**	\brief	Structure pour les informations d'un argument
**
**	La structure `t_select` contient le nom de l'argument et permet de connaître
**	son état d'affichage :
**	affichable ou non, (dé)sélectionné, sous le curseur ou non.
*/

typedef struct	s_select
{
	char	*arg;		/*!< Argument donné à ft_select */
	int		cursor;		/*!< flag indiquant si le curseur est sur l'élément */
	int		selec;		/*!< flag indiquant si l'élément est sélectionné */
	int		print;		/*!< flag indiquant si l'élément doit être affiché */
}				t_select;

/**
**	error.c
*/

int				error_alloc(void);
int				error_winsize(void);

/*
**	error_init.c
*/

int				error_usage(void);
int				error_noenv(void);
int				error_termvar(void);

/**
**	error_term.c
*/

int				error_termbase(void);
int				error_termdef(char *term);
int				error_termbehav(void);
int				error_termrestore(void);

/*
**	get_term.c
*/

int				get_term(char *term);
struct winsize	window_size(int init);
struct termios	set_term(struct termios term);
int				reset_term(struct termios term);

/*
**	launch.c
*/

int				launch(int argc, char **argv, char *term, struct termios save);

/*
**	list.c
*/

t_list			*get_list(int argc, char **argv);
void			print(t_list *elem);
void			delete(void *elem, size_t size);
void			ft_lstiter_if(t_list *lst, void (*f)(void*), int (t)(void*));
int				max_size_arg(t_list *list);

/**
**	list_move.c
*/

t_list			*find_printable_right(t_list *list);
void			move_last(t_list *list);
void			move_first(t_list *list);
int				move_up(t_list *list, struct winsize win);
int				move_down(t_list *list, struct winsize win);
int				move_right(t_list *list);
int				move_left(t_list *list);

/*
**	struct.c
*/

void			del_tselect(t_select **struc);
int				put_tselect(t_select *select);
void			put_select_arg(void *elem);

/*
**	struct_is.c
*/

int				is_oncursor(void *elem);
int				is_printable(void *elem);
int				is_select(void *elem);

/*
**	struct_member.c
*/

void			set_print(t_select *elem);
void			unset_print(void *elem);
void			set_cursor(t_select *elem);
void			select_change(void *elem);
void			set_all_member(t_select *elem);
void			select_arg(void *elem);
void			unselect_arg(void *elem);

/*
**	window.c
*/

int				nb_line_tot(t_list *list, int size);
int				nb_column(struct winsize window, int max_size);
void			padding(t_list *list, struct winsize window);
void			print_message(char *msg, int fd);

#endif

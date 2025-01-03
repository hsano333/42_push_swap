NAME 	:= push_swap
ifdef WITH_BONUS
NAME 	:= checker
endif
LIB	:= ./lib/

LIBFTDIR	:= $(LIB)/libft
LIBFTNAME	:= libft.a
LIBFT		:= $(LIBFTDIR)/$(LIBFTNAME)

OBJDIR		:= ./obj

SRCDIR	:= ./srcs/
SRC	:= push_swap.c quick_sort_asce.c quick_sort_desc.c push_swap_init.c deque.c clear_deque.c deque_util.c pop_deque.c shift_deque.c ab_table.c swap_ab_table.c rotete_ab_table.c reverse_ab_table.c divide_ab_table.c ab_table_util.c ab_table_inst.c push_swap_util.c can_shift.c can_rotate.c divide_ab_table_util.c divide_ab_table_rotate.c two_or_three_node.c two_or_three_node_util.c main_common.c checker.c only_two_or_three_node.c
ENTRY	:= main.c
ENTRYBONUS	:= main_bonus.c
DELENTRY	:= $(OBJDIR)/main_bonus.o
ifdef WITH_BONUS
ENTRY	:= $(ENTRYBONUS)
DELENTRY	:= $(OBJDIR)/main.o
endif
SRC	+= $(ENTRY)

SRCS	:= $(addprefix $(SRCDIR), $(SRC))
OBJS	:= $(SRCS:.c=.o)
OBJECTS	:= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS	:= $(OBJECTS:.o=.d)
INCS	:= ./include $(LIBFTDIR)/include

LIBDIRS	:= $(LIBFTDIR)
IFLAGS	:= $(addprefix -I,$(INCS))
LFLAGS	:= $(addprefix -L,$(LIBDIRS))
LIBS	:= $(LIBFT)

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
LDFLAGS := $(IFLAGS) $(LFLAGS) -lft 

all:
	@make -C $(LIBFTDIR)
	@make $(NAME)	

$(NAME)	:	$(OBJECTS) $(LIBS) 
		$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
		$(RM) $(DELENTRY)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) / $(*D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -MMD -MP -MF $(OBJDIR)/$*.d  -o $@
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean	:
			$(RM) $(OBJECTS)
			$(RM) $(DEPS)
			$(RM) $(OBJDIR)/$(ENTRYBONUS:.c=.o)
			$(RM) $(OBJDIR)/$(ENTRYBONUS:.c=.d)
			make clean -C $(LIBFTDIR)

fclean	:	clean
			$(RM) push_swap
			$(RM) checker
			$(RM) $(LIBS)

re	:		fclean all

bonus	:	
			@make WITH_BONUS=1

ifeq ($(findstring clean,$(MAKECMDGOALS)),)
-include $(DEPS)
endif

.PHONY: clean fclean bonus re

CC = cc
CFLAGS = -Wall -Wextra -Werror

TARGET = expander
DEPS = expander.o expander_utils.o create_lists_env.o ft_split_double.o new_ft_split.o


%.o: %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(DEPS)


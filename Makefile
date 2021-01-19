

all: 
# 	gcc -g -fsanitize=address *.c libft.a libmlx.dylib -framework OpenGL -framework Appkit
	gcc -g *.c libft.a libmlx.dylib -framework OpenGL -framework Appkit

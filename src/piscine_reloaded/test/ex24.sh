cd ../ex24
mkdir srcs
mkdir includes
cp ../ex10/ft_swap.c srcs/
cp ../ex15/ft_putstr.c srcs/
cp ../ex16/ft_strlen.c srcs/
cp ../ex17/ft_strcmp.c srcs/
cp ../text/libft.h includes/
make
rm -rf srcs
rm -rf includes
rm -rf objs
rm -rf libft.a
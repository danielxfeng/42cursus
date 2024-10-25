cd ../ex27
echo "ss\ndd" >> test
make re
./ft_display_file
./ft_display_file 123 333
./ft_display_file test
rm -rf objs
rm test
rm ft_display_file

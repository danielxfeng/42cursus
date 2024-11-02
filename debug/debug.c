#include <bsd/string.h>
#include "../src/libft/libft.h"
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

void test_strlcpy() {
    char src1[] = "hi";
    char dest1[10];
    char dest2[10];
    int res1;
    int res2;

    strcpy(dest1, "look");
    strcpy(dest2, "look");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest2, src1, 2);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "look");
    strcpy(dest2, "look");
    res1 = strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest2, src1, 0);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "look");
    strcpy(dest2, "look");
    res1 = strlcpy(dest1, src1, 10);
    res2 = ft_strlcpy(dest2, src1, 10);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(src1, "look");
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest2, src1, 2);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = ft_strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest2, src1, 0);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(src1, "");
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest2, src1, 2);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "look");
    strcpy(dest2, "look");
    res1 = strlcpy(dest1, src1, 1);
    res2 = ft_strlcpy(dest2, src1, 1);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(src1, "123456789");
    strcpy(dest1, "abcdefghi");
    strcpy(dest2, "abcdefghi");
    res1 = strlcpy(dest1, src1, strlen(src1) + 1);
    res2 = ft_strlcpy(dest2, src1, strlen(src1) + 1);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "longbuffer");
    strcpy(dest2, "longbuffer");
    res1 = strlcpy(dest1, src1, 5);
    res2 = ft_strlcpy(dest2, src1, 5);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(src1, "");
    strcpy(dest1, "nonempty");
    strcpy(dest2, "nonempty");
    res1 = strlcpy(dest1, src1, 10);
    res2 = ft_strlcpy(dest2, src1, 10);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(src1, "This is a long string");
    strcpy(dest1, "short");
    strcpy(dest2, "short");
    res1 = strlcpy(dest1, src1, 5);
    res2 = ft_strlcpy(dest2, src1, 5);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s, end\n", res1, res2, dest1, dest2);
}

void test_strlcat() {
    char src1[20] = "world";
    char dest1[15];
    char dest2[15];
    int res1, res2;

    strcpy(dest1, "hello ");
    strcpy(dest2, "hello ");
    res1 = strlcat(dest1, src1, 15);
    res2 = ft_strlcat(dest2, src1, 15);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "hello ");
    strcpy(dest2, "hello ");
    res1 = strlcat(dest1, src1, 0);
    res2 = ft_strlcat(dest2, src1, 0);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "hello ");
    strcpy(dest2, "hello ");
    res1 = strlcat(dest1, src1, 3);
    res2 = ft_strlcat(dest2, src1, 3);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "hello ");
    strcpy(dest2, "hello ");
    res1 = strlcat(dest1, src1, strlen("hello ") + 1);
    res2 = ft_strlcat(dest2, src1, strlen("hello ") + 1);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "hello ");
    strcpy(dest2, "hello ");
    strcpy(src1, "");
    res1 = strlcat(dest1, src1, 15);
    res2 = ft_strlcat(dest2, src1, 15);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "");
    strcpy(dest2, "");
    strcpy(src1, "hello world");
    res1 = strlcat(dest1, src1, 15);
    res2 = ft_strlcat(dest2, src1, 15);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "full buffer");
    strcpy(dest2, "full buffer");
    res1 = strlcat(dest1, src1, strlen(dest1));
    res2 = ft_strlcat(dest2, src1, strlen(dest2));
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);

    strcpy(dest1, "short");
    strcpy(dest2, "short");
    strcpy(src1, "added");
    res1 = strlcat(dest1, src1, 1);
    res2 = ft_strlcat(dest2, src1, 1);
    printf("res1: %d, res2: %d, dest1: %s, dest2: %s\n", res1, res2, dest1, dest2);
}

int main(void)
{
    //test_strlcpy();
    test_strlcat();
}
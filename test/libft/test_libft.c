#include "../../src/libft/libft.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <bsd/string.h>

// Setup function called before each test
void	setUp(void)
{
	// Initialize or allocate resources if needed (optional)
}

// Teardown function called after each test
void	tearDown(void)
{
	// Clean up resources if needed (optional)
}

void	test_isalpha(void)
{
	int	n;

	n = 65;
	TEST_ASSERT_EQUAL_INT(1, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
	n = 64;
	TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
	n = 122;
	TEST_ASSERT_EQUAL_INT(1, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
	n = 123;
	TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
	n = -1;
	TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
	n = 70;
	TEST_ASSERT_EQUAL_INT(1, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
	n = 92;
	TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
	TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
}

void	test_isdigit(void)
{
	int	n;

	n = '0';
	TEST_ASSERT_EQUAL_INT(1, ft_isdigit(n));
	TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
	n = 'a';
	TEST_ASSERT_EQUAL_INT(0, ft_isdigit(n));
	TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
	n = '9';
	TEST_ASSERT_EQUAL_INT(1, ft_isdigit(n));
	TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
	n = 'Z';
	TEST_ASSERT_EQUAL_INT(0, ft_isdigit(n));
	TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
	n = -1;
	TEST_ASSERT_EQUAL_INT(0, ft_isdigit(n));
	TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
}

void	test_isalnum(void)
{
	int	n;

	n = '0';
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
	TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
	n = 'a';
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
	TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
	n = '9';
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
	TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
	n = 'Z';
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
	TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
	n = -1;
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum(n));
	TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
	n = '-';
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum(n));
	TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
}

void	test_isascii(void)
{
	int	n;

	n = '0';
	TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
	n = 'a';
	TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
	n = '9';
	TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
	n = 'Z';
	TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
	n = -1;
	TEST_ASSERT_EQUAL_INT(0, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
	n = '-';
	TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
	n = 130;
	TEST_ASSERT_EQUAL_INT(0, ft_isascii(n));
	TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
}

void	test_isprint(void)
{
	int	n;

	for (int i = 0; i < 128; ++i)
	{
		TEST_ASSERT_EQUAL_INT(isprint(i) != 0, ft_isprint(i));
	}
	n = -1;
	TEST_ASSERT_EQUAL_INT(0, ft_isprint(n));
	TEST_ASSERT_EQUAL_INT(isprint(n) != 0, ft_isprint(n));
	n = 130;
	TEST_ASSERT_EQUAL_INT(0, ft_isprint(n));
	TEST_ASSERT_EQUAL_INT(isprint(n) != 0, ft_isprint(n));
}

void	test_ft_strlen(void)
{
	char	*test_arrs[] = {"", "test"};

	for (int i = 0; i < 2; ++i)
	{
		TEST_ASSERT_EQUAL_INT(strlen(test_arrs[i]), ft_strlen(test_arrs[i]));
	}
}

void	test_ft_memset(void)
{
	char	test[8] = "aaaaaaaa";
	char	test2[8] = "aaaaaaaa";

	memset((void *)test, '0', 2);
	ft_memset((void *)test2, '0', 2);
	TEST_ASSERT_EQUAL_STRING("00aaaaaa", test2);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, sizeof(test));
	memset((void *)test, 1000, 4);
	ft_memset((void *)test2, 1000, 4);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, sizeof(test));
}

void	test_bzero(void)
{
	char	test[8] = "aaaaaaaa";
	char	test2[8] = "aaaaaaaa";

	bzero(test, 2);
	ft_bzero(test2, 2);
	TEST_ASSERT_EQUAL_MEMORY(test, test2, sizeof(test));
}

void	test_memcpy(void)
{
	char	test[8] = "aaaaaaaa";
	char	test2[10] = "bbbbbbbbbb";
	char	test3[8] = "aaaaaaaa";
	char	test4[10] = "bbbbbbbbbb";

	memcpy(test, test2, 1);
	ft_memcpy(test3, test4, 1);
	TEST_ASSERT_EQUAL_MEMORY(test, test3, sizeof(test));
	memcpy(test, test2, 10);
	ft_memcpy(test3, test4, 10);
	TEST_ASSERT_EQUAL_MEMORY(test, test3, sizeof(test));
	memcpy(0, 0, 10);
	ft_memcpy(0, 0, 10);
}

void	test_memmove(void)
{
	char	test1[20] = "aaaaaaaa";
	char	test2[20] = "aaaaaaaa";
	char	test3[20] = "bbbbbbbbbb";
	char	test4[20] = "bbbbbbbbbb";
	char	test5[20] = "cccccccccc";
	char	test6[20] = "cccccccccc";

	ft_memmove(test1 + 8, test1, 6);
	memmove(test2 + 8, test2, 6);
	TEST_ASSERT_EQUAL_MEMORY(test1, test2, sizeof(test2));
	ft_memmove(test3 + 2, test3, 9);
	memmove(test4 + 2, test4, 9);
	TEST_ASSERT_EQUAL_MEMORY(test3, test4, sizeof(test4));
	ft_memmove(test5, test5 + 2, 9);
	memmove(test6, test6 + 2, 9);
	TEST_ASSERT_EQUAL_MEMORY(test5, test6, sizeof(test6));
	TEST_ASSERT_EQUAL_INT(0, ft_memmove(0, 0, 9));
}

void	test_tolower(void)
{
	TEST_ASSERT_EQUAL_CHAR('a', ft_tolower('A'));
	TEST_ASSERT_EQUAL_CHAR('a', ft_tolower('a'));
	TEST_ASSERT_EQUAL_CHAR('-', ft_tolower('-'));
}

void	test_toupper(void)
{
	TEST_ASSERT_EQUAL_CHAR('A', ft_toupper('A'));
	TEST_ASSERT_EQUAL_CHAR('A', ft_toupper('a'));
	TEST_ASSERT_EQUAL_CHAR('-', ft_toupper('-'));
}

void	test_strchr(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "abcbd";
	TEST_ASSERT_EQUAL_PTR(s1 + 1, ft_strchr(s1, 'b'));
	TEST_ASSERT_EQUAL_PTR(strchr(s1, 'b'), ft_strchr(s1, 'b'));
	s2 = "abc";
	TEST_ASSERT_EQUAL_PTR(s2 + 3, ft_strchr(s2, '\0'));
	TEST_ASSERT_EQUAL_PTR(strchr(s2, '\0'), ft_strchr(s2, '\0'));
	s3 = "abc";
	TEST_ASSERT_EQUAL_PTR(NULL, ft_strchr(s3, 'd'));
	TEST_ASSERT_EQUAL_PTR(strchr(s3, 'd'), ft_strchr(s3, 'd'));
}

void	test_strrchr(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "abcbd";
	TEST_ASSERT_EQUAL_PTR(s1 + 3, ft_strrchr(s1, 'b'));
	TEST_ASSERT_EQUAL_PTR(strrchr(s1, 'b'), ft_strrchr(s1, 'b'));
	s2 = "abc";
	TEST_ASSERT_EQUAL_PTR(s2 + 3, ft_strchr(s2, '\0'));
	TEST_ASSERT_EQUAL_PTR(strrchr(s2, '\0'), ft_strrchr(s2, '\0'));
	s3 = "abc";
	TEST_ASSERT_EQUAL_PTR(NULL, ft_strchr(s3, 'd'));
	TEST_ASSERT_EQUAL_PTR(strrchr(s3, 'd'), ft_strrchr(s3, 'd'));
}

void	test_strncmp(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	*s6;
	char	*s7;
	char	*s8;
	char	*s9;
	char	*s10;

	s1 = "hi";
	s2 = "hi";
	TEST_ASSERT_EQUAL_INT(strncmp(s1, s2, 2), ft_strncmp(s1, s2, 2));
	s3 = "hir";
	TEST_ASSERT_EQUAL_INT(strncmp(s3, s1, 2), ft_strncmp(s3, s1, 2));
	TEST_ASSERT_EQUAL_INT(strncmp(s3, s1, 3), ft_strncmp(s3, s1, 3));
	s4 = "";
	TEST_ASSERT_EQUAL_INT(strncmp(s4, s4, 3), ft_strncmp(s4, s4, 3));
	TEST_ASSERT_EQUAL_INT(strncmp(s2, s4, 3), ft_strncmp(s2, s4, 3));
	TEST_ASSERT_EQUAL_INT(strncmp(s1, s3, 0), ft_strncmp(s1, s3, 0));
	s5 = "Hi";
	TEST_ASSERT_EQUAL_INT(strncmp(s5, s2, 2), ft_strncmp(s5, s2, 2));
	s6 = "hello";
	TEST_ASSERT_EQUAL_INT(strncmp(s1, s6, 5), ft_strncmp(s1, s6, 5));
	s7 = "hi!";
	TEST_ASSERT_EQUAL_INT(strncmp(s7, s1, 3), ft_strncmp(s7, s1, 3));
	s8 = "hi\0hello";
	TEST_ASSERT_EQUAL_INT(strncmp(s8, s1, 5), ft_strncmp(s8, s1, 5));
	s9 = "test\200";
	s10 = "test\0";
	TEST_ASSERT_EQUAL_INT(strncmp(s9, s10, 6), ft_strncmp(s9, s10, 6));
}

void	test_memchr(void)
{
	char	*s;

	s = "abc";
	TEST_ASSERT_EQUAL_PTR(memchr((void *)s, 'b', 3), ft_memchr((void *)s, 'b',
			3));
	TEST_ASSERT_EQUAL_PTR(memchr((void *)s, 'd', 3), ft_memchr((void *)s, 'd',
			3));
	memchr(0, 'd', 3);
	ft_memchr(0, 'd', 3);
}

void	test_memcmp(void)
{
	char	*s;
	char	*s2;
	char	*s3;

	s = "abc";
	s2 = "abcd";
	s3 = "abc";
	TEST_ASSERT_EQUAL_INT(memcmp((void *)s, (void *)s2, 3), ft_memcmp((void *)s,
			(void *)s2, 3));
	TEST_ASSERT_EQUAL_INT(memcmp((void *)s, (void *)s2, 4), ft_memcmp((void *)s,
			(void *)s2, 4));
	TEST_ASSERT_EQUAL_INT(memcmp((void *)s, (void *)s3, 4), ft_memcmp((void *)s,
			(void *)s3, 4));
	memchr(0, (void *)s, 3);
	memchr((void *)s, 0, 3);
	memchr(0, 0, 3);
	ft_memchr(0, (void *)s, 3);
	ft_memchr((void *)s, 0, 3);
	ft_memchr(0, 0, 3);
}

void	test_strnstr(void)
{
	char	*big;
	char	*l1;
	char	*l2;
	char	*l3;

	big = "abcde";
	l1 = "bc";
	l2 = "ab";
	l3 = "de";
	TEST_ASSERT_EQUAL_PTR(big + 1, ft_strnstr(big, l1, 5));
	TEST_ASSERT_EQUAL_PTR(0, ft_strnstr(big, l1, 2));
	TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, l2, 2));
	TEST_ASSERT_NULL(ft_strnstr(big, l2, 0));
	TEST_ASSERT_EQUAL_PTR(big + 3, ft_strnstr(big, l3, 5));
}

void	test_atoi(void)
{
	TEST_ASSERT_EQUAL_INT(999, ft_atoi("999"));
	TEST_ASSERT_EQUAL_INT(999, ft_atoi("+999"));
	TEST_ASSERT_EQUAL_INT(999, ft_atoi("   +999"));
	TEST_ASSERT_EQUAL_INT(-999, ft_atoi("   -999"));
	TEST_ASSERT_EQUAL_INT(-999, ft_atoi("   -999sss"));
	TEST_ASSERT_EQUAL_INT(-999, ft_atoi("   -999  "));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("   --999  "));
	TEST_ASSERT_EQUAL_INT(atoi("9999999999999999999999999"),
		ft_atoi("9999999999999999999999999"));
	TEST_ASSERT_EQUAL_INT(atoi("-9999999999999999999999999"),
		ft_atoi("-9999999999999999999999999"));
}

void	test_calloc(void)
{
	TEST_ASSERT_EQUAL_MEMORY(calloc(2, 3), ft_calloc(2, 3), 6);
	TEST_ASSERT_EQUAL_MEMORY(calloc(0, 3), ft_calloc(0, 3), 1);
	TEST_ASSERT_EQUAL_MEMORY(calloc(0, 0), ft_calloc(0, 0), 1);
	TEST_ASSERT_EQUAL_INT(calloc(SIZE_MAX - 1, SIZE_MAX - 1), ft_calloc(SIZE_MAX
			- 1, SIZE_MAX - 1));
}

void	test_strdup(void)
{
	TEST_ASSERT_EACH_EQUAL_STRING(strdup("str"), ft_strdup("str"), 4);
	TEST_ASSERT_EACH_EQUAL_STRING(strdup("string"), ft_strdup("string"), 6);
	TEST_ASSERT_EACH_EQUAL_STRING(strdup(""), ft_strdup(""), 1);
}

void	test_substr(void)
{
	TEST_ASSERT_EQUAL_STRING("tri", ft_substr("string", 1, 3));
	TEST_ASSERT_EQUAL_STRING("st", ft_substr("string", 0, 2));
	TEST_ASSERT_EQUAL_STRING("g", ft_substr("string", 5, 3));
	TEST_ASSERT_EQUAL_STRING("", ft_substr("string", 10, 3));
	TEST_ASSERT_EQUAL_STRING("", ft_substr("string", 2, 0));
	TEST_ASSERT_EQUAL_INT(0, ft_substr(0, 2, 0));
}

void	test_strjoin(void)
{
	TEST_ASSERT_EQUAL_STRING("s1s2", ft_strjoin("s1", "s2"));
	TEST_ASSERT_EQUAL_STRING("s1", ft_strjoin("s1", ""));
	TEST_ASSERT_EQUAL_STRING("s2", ft_strjoin("", "s2"));
}

void	test_strtrim(void)
{
	TEST_ASSERT_EQUAL_STRING("strs", ft_strtrim("trstrstr", "rt"));
	TEST_ASSERT_EQUAL_INT(0, ft_strtrim(0, "rt"));
	TEST_ASSERT_EQUAL_STRING("trstrstr", ft_strtrim("trstrstr", 0));
}

void	test_split(void)
{
	char	*res1[] = {"a", "bb", "cc", NULL};
	char	**ret1;
	int		i;
	char	*res2[] = {"a", "bb", "cc", NULL};
	char	**ret2;
	char	*res3[] = {NULL};
	char	**ret3;
	char	*res4[] = {NULL};
	char	**ret4;

	ret1 = ft_split("aebbecc", 'e');
	i = 0;
	TEST_ASSERT_EQUAL_STRING_ARRAY(res1, ret1, 4);
	ret2 = ft_split("eeaebbeecce", 'e');
	TEST_ASSERT_EQUAL_STRING_ARRAY(res2, ret2, 4);
	ret3 = ft_split("", 'e');
	TEST_ASSERT_EQUAL_STRING_ARRAY(res3, ret3, 1);
	ret4 = ft_split("eeeeeeeee", 'e');
	TEST_ASSERT_EQUAL_STRING_ARRAY(res4, ret4, 1);
}

void	test_itoa(void)
{
	TEST_ASSERT_EQUAL_STRING("0", ft_itoa(0));
	TEST_ASSERT_EQUAL_STRING("100", ft_itoa(100));
	TEST_ASSERT_EQUAL_STRING("-234", ft_itoa(-234));
	TEST_ASSERT_EQUAL_STRING("1234", ft_itoa(1234));
	TEST_ASSERT_EQUAL_STRING("2147483647", ft_itoa(2147483647));
	TEST_ASSERT_EQUAL_STRING("-2147483648", ft_itoa(-2147483648));
}

char	test_map(unsigned int i, char c)
{
	return (i + '0');
}

void	test_iter(unsigned int i, char *c)
{
	*c = i + '0';
}

void	test_strmapi(void)
{
	TEST_ASSERT_EQUAL_STRING("0", ft_strmapi("a", test_map));
	TEST_ASSERT_EQUAL_STRING("01234", ft_strmapi("aaaaa", test_map));
	TEST_ASSERT_EQUAL_STRING("", ft_strmapi("", test_map));
}

void	test_striteri(void)
{
	char	t1[] = "a";
	char	t2[] = "01234";
	char	t3[] = "";

	ft_striteri(t1, test_iter);
	TEST_ASSERT_EQUAL_STRING("0", t1);
	ft_striteri(t2, test_iter);
	TEST_ASSERT_EQUAL_STRING("01234", t2);
	ft_striteri(t3, test_iter);
	TEST_ASSERT_EQUAL_STRING("", t3);
}

void	test_lstnew(void)
{
	int		*content;
	t_list	*node;

	content = malloc(sizeof(int));
	*content = 1;
	node = ft_lstnew(content);
	TEST_ASSERT_NOT_NULL(node);
	TEST_ASSERT_EQUAL_PTR(content, node->content);
	TEST_ASSERT_NULL(node->next);
}

void	test_lstadd_front(void)
{
	t_list	*node1;
	t_list	*new_node;

	node1 = ft_lstnew("second");
	new_node = ft_lstnew("first");
	ft_lstadd_front(&node1, new_node);
	TEST_ASSERT_EQUAL_PTR(new_node, node1);
	TEST_ASSERT_EQUAL_STRING("first", (char *)node1->content);
	TEST_ASSERT_EQUAL_STRING("second", (char *)node1->next->content);
}

void	test_lstsize(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("first");
	node2 = ft_lstnew("second");
	node1->next = node2;
	TEST_ASSERT_EQUAL_INT(2, ft_lstsize(node1));
}

void	test_lstlast(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("first");
	node2 = ft_lstnew("second");
	node3 = ft_lstnew("third");
	node1->next = node2;
	node2->next = node3;
	TEST_ASSERT_EQUAL_PTR(node3, ft_lstlast(node1));
}

void	test_lstadd_back(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("first");
	node2 = ft_lstnew("second");
	ft_lstadd_back(&node1, node2);
	TEST_ASSERT_EQUAL_PTR(node2, node1->next);
}

void	del_function(void *content)
{
	free(content);
}

void	test_lstdelone(void)
{
	char	*content;
	t_list	*node;

	content = malloc(6);
	strcpy(content, "Hello");
	node = ft_lstnew(content);
	ft_lstdelone(node, del_function);
	TEST_PASS();
}

void	test_lstclear(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew(malloc(6));
	strcpy(node1->content, "first");
	node2 = ft_lstnew(malloc(7));
	strcpy(node2->content, "second");
	node1->next = node2;
	ft_lstclear(&node1, del_function);
	TEST_ASSERT_NULL(node1);
}

void	increment_by_one(void *content)
{
	int	*value;

	value = (int *)content;
	(*value)++;
}

void	test_lstiter(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew(malloc(sizeof(int)));
	node2 = ft_lstnew(malloc(sizeof(int)));
	*(int *)(node1->content) = 1;
	*(int *)(node2->content) = 2;
	node1->next = node2;
	ft_lstiter(node1, increment_by_one);
	TEST_ASSERT_EQUAL_INT(2, *(int *)(node1->content));
	TEST_ASSERT_EQUAL_INT(3, *(int *)(node2->content));
	ft_lstclear(&node1, del_function);
}

void	*duplicate_content(void *content)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	if (new_value)
		*new_value = *(int *)content * 2;
	return (new_value);
}

void	test_lstmap(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*new_list;

	node1 = ft_lstnew(malloc(sizeof(int)));
	node2 = ft_lstnew(malloc(sizeof(int)));
	*(int *)(node1->content) = 1;
	*(int *)(node2->content) = 2;
	node1->next = node2;
	new_list = ft_lstmap(node1, duplicate_content, del_function);
	TEST_ASSERT_NOT_NULL(new_list);
	TEST_ASSERT_EQUAL_INT(2, *(int *)(new_list->content));
	TEST_ASSERT_EQUAL_INT(4, *(int *)(new_list->next->content));
	TEST_ASSERT_NULL(new_list->next->next);
	ft_lstclear(&node1, del_function);
	ft_lstclear(&new_list, del_function);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_isalpha);
	RUN_TEST(test_isdigit);
	RUN_TEST(test_isalnum);
	RUN_TEST(test_isascii);
	RUN_TEST(test_isprint);
	RUN_TEST(test_ft_strlen);
	RUN_TEST(test_ft_memset);
	RUN_TEST(test_bzero);
    RUN_TEST(test_memcpy);
	RUN_TEST(test_memmove);
	RUN_TEST(test_tolower);
	RUN_TEST(test_toupper);
	RUN_TEST(test_strchr);
	RUN_TEST(test_strrchr);
	RUN_TEST(test_strncmp);
	RUN_TEST(test_memchr);
	RUN_TEST(test_memcmp);
	RUN_TEST(test_strnstr);
	RUN_TEST(test_atoi);
	RUN_TEST(test_calloc);
	RUN_TEST(test_substr);
	RUN_TEST(test_strjoin);
	RUN_TEST(test_strtrim);
	RUN_TEST(test_split);
	RUN_TEST(test_itoa);
	RUN_TEST(test_strmapi);
	RUN_TEST(test_striteri);
    RUN_TEST(test_lstnew);
    RUN_TEST(test_lstadd_front);
    RUN_TEST(test_lstsize);
    RUN_TEST(test_lstlast);
    RUN_TEST(test_lstadd_back);
    RUN_TEST(test_lstdelone);
    RUN_TEST(test_lstclear);
    RUN_TEST(test_lstiter);
    RUN_TEST(test_lstmap);

	return (UNITY_END());
}
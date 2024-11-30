#include "../../src/so_long/so_long.h"
#include "../../src/so_long/libft/libft.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_board(t_tile ***board, int height);
void free_parameter(char ***parameter);
void free_game(t_game **game);
// valgrind --leak-check=full --show-leak-kinds=all ./build/test_so_long

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

char **mock_parameter(void)
{
    char **param = malloc(5 * sizeof(char *));
    if (!param)
        return NULL;
    param[0] = strdup("11111");
    param[1] = strdup("10PC1");
    param[2] = strdup("1CE01");
    param[3] = strdup("11111");
    param[4] = '\0';
    if (!param[0] || !param[1] || !param[2])
    {
        free(param[0]);
        free(param[1]);
        free(param[2]);
        free(param[3]);
        free(param);
        return NULL;
    }
    return param;
}

void test_create_game_success(void)
{
    char **param = mock_parameter();
    TEST_ASSERT_NOT_NULL(param);
    t_game *game = create_game(5, 4, param);
    TEST_ASSERT_NOT_NULL(game);
    TEST_ASSERT_EQUAL_INT(5, game->length);
    TEST_ASSERT_EQUAL_INT(4, game->height);
    TEST_ASSERT_EQUAL_INT(2, game->total_collectible);
    TEST_ASSERT_NOT_NULL(game->player);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    TEST_ASSERT_EQUAL_INT(0, game->player->has_collectible);
    TEST_ASSERT_EQUAL_INT(0, game->player->movements);
    TEST_ASSERT_NOT_NULL(game->board);
    for (int i = 0; i < game->height; ++i)
    {
        for (int j = 0; j < game->length; ++j)
        {
            TEST_ASSERT_NOT_NULL(&(game->board[i][j]));
            if (i == 0 || i == game->height - 1 || j == 0 || j == game->length - 1)
            {
                TEST_ASSERT_EQUAL_INT(TILE_WALL, game->board[i][j].type);
                TEST_ASSERT_EQUAL_INT(false, game->board[i][j].is_collectible);
                TEST_ASSERT_EQUAL_INT(false, game->board[i][j].is_exit);
                TEST_ASSERT_EQUAL_INT(j, game->board[i][j].x);
                TEST_ASSERT_EQUAL_INT(i, game->board[i][j].y);
            }
            else
            {
                TEST_ASSERT_EQUAL_INT(TILE_EMPTY, game->board[i][j].type);
                TEST_ASSERT_EQUAL_INT(j, game->board[i][j].x);
                TEST_ASSERT_EQUAL_INT(i, game->board[i][j].y);
            }
        }
    }
    TEST_ASSERT_EQUAL_INT(true, game->board[1][3].is_collectible);
    TEST_ASSERT_EQUAL_INT(true, game->board[2][1].is_collectible);
    TEST_ASSERT_EQUAL_INT(true, game->board[2][2].is_exit);
    TEST_ASSERT_EQUAL(STATUS_NOT_START, game->status);
    free_game(&game);
    free_parameter(&param);
}

void set_not_vist(t_game *game)
{
    for (int i = 0; i < game->height; ++i)
    {
        for (int j = 0; j < game->length; ++j)
            game->board[i][j].is_visited = false;
    }
}

void test_valid_path()
{
    char **param = mock_parameter();
    TEST_ASSERT_NOT_NULL(param);
    t_game *game = create_game(5, 4, param);
    TEST_ASSERT_EQUAL_INT(true, path_check(game));
    game->board[2][2].is_exit = false;
    game->board[2][2].type = TILE_WALL;
    game->board[2][3].type = TILE_WALL;
    game->board[3][1].is_exit = true;
    game->board[3][1].type = TILE_EMPTY;
    set_not_vist(game);
    TEST_ASSERT_EQUAL_INT(true, path_check(game));
    game->board[2][1].type = TILE_WALL;
    set_not_vist(game);
    TEST_ASSERT_EQUAL_INT(false, path_check(game));
    free_game(&game);
    free_parameter(&param);
}

void test_valid_move()
{
    char **param = mock_parameter();
    TEST_ASSERT_NOT_NULL(param);
    t_game *game = create_game(5, 4, param);
    move(game, DIR_D);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    game->status = STATUS_MOVING;
    move(game, DIR_D);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    game->status = STATUS_WAIT_MOVE;
    move(game, DIR_U);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    move(game, DIR_U);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    move(game, DIR_L);
    TEST_ASSERT_EQUAL_INT(1, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    move(game, DIR_L);
    TEST_ASSERT_EQUAL_INT(1, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    move(game, DIR_R);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    TEST_ASSERT_EQUAL_INT(true, game->board[1][3].is_collectible);
    move(game, DIR_R);
    TEST_ASSERT_EQUAL_INT(3, game->player->x);
    TEST_ASSERT_EQUAL_INT(1, game->player->y);
    TEST_ASSERT_EQUAL_INT(1, game->player->has_collectible);
    TEST_ASSERT_EQUAL_INT(false, game->board[1][3].is_collectible);
    move(game, DIR_D);
    TEST_ASSERT_EQUAL_INT(3, game->player->x);
    TEST_ASSERT_EQUAL_INT(2, game->player->y);
    move(game, DIR_D);
    TEST_ASSERT_EQUAL_INT(3, game->player->x);
    TEST_ASSERT_EQUAL_INT(2, game->player->y);
    TEST_ASSERT_EQUAL_INT(true, game->board[2][2].is_exit);
    move(game, DIR_L);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(2, game->player->y);
    move(game, DIR_L);
    TEST_ASSERT_EQUAL_INT(1, game->player->x);
    TEST_ASSERT_EQUAL_INT(2, game->player->y);
    TEST_ASSERT_EQUAL_INT(false, game->board[2][1].is_collectible);
    TEST_ASSERT_EQUAL_INT(2, game->player->has_collectible);
    move(game, DIR_R);
    TEST_ASSERT_EQUAL_INT(2, game->player->x);
    TEST_ASSERT_EQUAL_INT(2, game->player->y);
    TEST_ASSERT_EQUAL_INT(STATUS_WON, game->status);
    TEST_ASSERT_EQUAL_INT(7, game->player->movements);
    free_game(&game);
    free_parameter(&param);
}

void test_play_game()
{
    char *map = "11111\n1C0E1\n10101\n1P0C1\n11111";
    char **param = ft_split(map, '\n');
    t_game *game = create_game(5, 5, param);
    game->status = STATUS_WAIT_MOVE;
    move(game, DIR_R);
    move(game, DIR_R);
    move(game, DIR_L);
    move(game, DIR_L);
    move(game, DIR_U);
    move(game, DIR_U);
    move(game, DIR_R);
    move(game, DIR_R);
    TEST_ASSERT_EQUAL_INT(STATUS_WON, game->status);
    TEST_ASSERT_EQUAL_INT(8, game->player->movements);
    free_game(&game);
    free_parameter(&param);
}

void test_auto_play_game()
{
    char *map = "1111111111111111\n1P0000E1100C1111\n1001100000000011\n1C00000001100111\n1100C11100000C11\n11001110C0000001\n1C000000001100C1\n1111111111111111";
    char **param = ft_split(map, '\n');
    t_game *game = create_game(16, 8, param);
    game->status = STATUS_WAIT_MOVE;
    while (game->status != STATUS_WON)
    {
        t_direction d = (t_direction)(rand() % 4);
        move(game, d);
    }
    TEST_ASSERT_EQUAL_INT(STATUS_WON, game->status);
    TEST_ASSERT_EQUAL_INT(7, game->player->has_collectible);
    printf("auto movements: %d\n", game->player->movements);
    free_game(&game);
    free_parameter(&param);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_create_game_success);
    RUN_TEST(test_valid_path);
    RUN_TEST(test_valid_move);
    RUN_TEST(test_play_game);
    RUN_TEST(test_auto_play_game);
	return (UNITY_END());
}
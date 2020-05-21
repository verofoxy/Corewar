/*
** EPITECH PROJECT, 2020
** linked_list.h
** File description:
** linked_list.h
*/

#ifndef __linked_list__
#define __linked_list__

#define print my_printf
#define g_n_index(x, y) get_node_from_index(x, y)
#define g_n_tag(x, y) get_node_from_tag(x, y)
#define g_e_index(x, y) get_node_from_index(x, y)
#define g_e_tag(x, y) get_node_from_tag(x, y)
#define d_tag(x, y) destroy_node_from_tag(x, y)
#define d_index(x, y) destroy_node_from_index(x, y)
#define EXEC_SUCCESS    0
#define EXEC_FAILURE    0
#define ERROR 84
#define CHECK_NULL(x) if (!x) return EXEC_FAILURE;
#define CHECK_MALLOC(x) if (!x) return NULL;
#define CHECK_ERR(x) if (x == RETURN_ERR) return RETURN_ERR;
#define CHECK_END(x) if (my_strlen(x) == 0) break;

typedef struct node_s{
    void *element;
    char *tag;
    struct node_s *next;
    struct node_s *previous;
}node_t;

typedef struct linked_list_s{
    struct node_s *head;
    struct node_s *tail;
} linked_list_t;

void my_printf(char *str, ...);
int m_strcmp(char *s1, char *s2);


int list_destroy(linked_list_t *list);
void *get_element_from_tag(linked_list_t *list, char *tag);
void *get_element_from_index(linked_list_t *list, int index);
node_t *get_node_from_tag(linked_list_t *list, char *tag);
node_t *get_node_from_index(linked_list_t *list, int index);
int destroy_node_from_tag(linked_list_t *list, char *tag);
int destroy_node_from_index(linked_list_t *list, int index);
int add_node(linked_list_t *list, void *element, char *tag);
int display_tag(linked_list_t *list);
int list_count(linked_list_t *l);
#endif

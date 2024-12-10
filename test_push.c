#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

// Prototypes
void push_to_b_sorted(t_stack **a, t_stack **b);
void push_to_a(t_stack **a, t_stack **b);
void rotate_stack(t_stack **stack, char stack_name);
void reverse_rotate_stack(t_stack **stack, char stack_name);
void push_stack(t_stack **src, t_stack **dest, char direction);
int find_insert_position(t_stack *b, int value);
void rotate_to_top(t_stack **stack, int position, char stack_name);
int stack_size(t_stack *stack);

// Tri par Insertion Simulé
void insertion_sort(t_stack **a, t_stack **b) {
    push_to_b_sorted(a, b);
    push_to_a(a, b);
}

// Déplacer `a` vers `b` en ordre croissant
void push_to_b_sorted(t_stack **a, t_stack **b) {
    int position;

    while (*a) {
        position = find_insert_position(*b, (*a)->value);
        rotate_to_top(b, position, 'b');
        push_stack(a, b, 'b');
    }
}

// Réinsérer `b` dans `a` (trié)
void push_to_a(t_stack **a, t_stack **b) {
    while (*b)
        push_stack(b, a, 'a');
}

// Trouver la position d'insertion dans `b`
int find_insert_position(t_stack *b, int value) {
    int position = 0;
    t_stack *tmp = b;

    if (!b)
        return 0;
    while (tmp) {
        if (tmp->value > value)
            break;
        position++;
        tmp = tmp->next;
    }
    return position;
}

// Faire monter une position spécifique en haut de la pile
void rotate_to_top(t_stack **stack, int position, char stack_name) {
    int size = stack_size(*stack);

    if (position <= size / 2) {
        while (position--)
            rotate_stack(stack, stack_name);
    } else {
        position = size - position;
        while (position--)
            reverse_rotate_stack(stack, stack_name);
    }
}

// Opérations de base
void push_stack(t_stack **src, t_stack **dest, char direction) {
    t_stack *tmp;

    if (!*src)
        return;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
    if (direction == 'b')
        write(1, "pb\n", 3);
    else
        write(1, "pa\n", 3);
}

void rotate_stack(t_stack **stack, char stack_name) {
    t_stack *tmp, *tail;

    if (!*stack || !(*stack)->next)
        return;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    tail = *stack;
    while (tail->next)
        tail = tail->next;
    tail->next = tmp;
    if (stack_name == 'a')
        write(1, "ra\n", 3);
    else
        write(1, "rb\n", 3);
}

void reverse_rotate_stack(t_stack **stack, char stack_name) {
    t_stack *prev, *tail;

    if (!*stack || !(*stack)->next)
        return;
    prev = NULL;
    tail = *stack;
    while (tail->next) {
        prev = tail;
        tail = tail->next;
    }
    prev->next = NULL;
    tail->next = *stack;
    *stack = tail;
    if (stack_name == 'a')
        write(1, "rra\n", 4);
    else
        write(1, "rrb\n", 4);
}

// Taille de la pile
int stack_size(t_stack *stack) {
    int size = 0;

    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

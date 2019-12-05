/**
 * simple linked-list implements
 */

struct node_t
{
    int index;
    int count;
    struct node_t *next;
    struct node_t *last;
};

int node_remove_first(struct node_t *head, struct node_t **node)
{
    *node = head->next;
    if (head->next == NULL) return -1;

    head->next = (*node)->next;
    if ((*node)->next == NULL) head->last = NULL;
    (*node)->next = NULL;
    head->count -= 1;
    return 0;
}

int node_add_last(struct node_t *head, int val)
{
    struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
    node->index = val;
    node->next = NULL;

    // 记录尾节点的下一个节点
    if (head->last != NULL) head->last->next = node;
    else head->next = node;
    head->last = node;
    head->count += 1;
}

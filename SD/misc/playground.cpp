void swap ( int* a, int* b )
{ 
    int t = *a; *a = *b; *b = t; 
}
 
Node* partition(Node *l, Node *h)
{
    int x = h->data;
    Node *i = l->prev;
 
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL)? l : i->next;
 
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next;
    swap(&(i->data), &(h->data));
    return i;
}
 
void _quickSort(Node* head, Node *tail)
{
    if (tail != NULL && head != tail && head != tail->next)
    {
        Node *p = partition(head, tail);
        _quickSort(head, p->prev);
        _quickSort(p->next, tail);
    }
}
 
void quickSort(Node *head, Node *tail)
{
    _quickSort(head, tail);
}
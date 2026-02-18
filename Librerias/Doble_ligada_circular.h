#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int value;
    struct nodo *next;
    struct nodo *prev;
} nodo;

void firstIn(nodo **head, nodo **elem)
{
    if ((*head) == NULL)
    {
        (*head) = (*elem);
        (*head)->next = (*head);
        (*head)->prev = (*head);
    }
    else
    {
        nodo *last = (*head)->prev; 
        nodo *aux = (*head);
        (*head) = (*elem);

        (*head)->next = aux;
        (*head)->prev = last;
        aux->prev = (*head);
        last->next = (*head);
    }

    printf(">> Element [%d] successfully implemented\n", (*elem)->value);
}

void lastIn(nodo **head, nodo **elem)
{
    if ((*head) == NULL)
    {
        (*head) = (*elem);
        (*head)->next = (*head);
        (*head)->prev = (*head);
    }
    else
    {
        nodo *last = (*head)->prev;

        last->next = (*elem);
        (*elem)->prev = last;
        (*elem)->next = (*head);
        (*head)->prev = (*elem);
    }

    printf(">> Element [%d] successfully implemented\n", (*elem)->value);
}

void orderIn(nodo **head, nodo **elem)
{
    if ((*head) == NULL)
    {
        (*head) = (*elem);
        (*head)->next = (*head);
        (*head)->prev = (*head);
    }
    else
    {
        if ((*head)->value > (*elem)->value)
        {
            nodo *last = (*head)->prev;
            nodo *aux = (*head);

            (*head) = (*elem);
            (*head)->next = aux;
            (*head)->prev = last;
            aux->prev = (*head);
            last->next = (*head);
        }
        else
        {
            nodo *aux = (*head);

            while (aux->next != (*head) && aux->next->value < (*elem)->value)
            {
                aux = aux->next;
            }

            (*elem)->next = aux->next;
            (*elem)->prev = aux;
            aux->next->prev = (*elem);
            aux->next = (*elem);
        }
    }
    order(&(*head));

    printf(">> Element [%d] successfully implemented\n", (*elem)->value);
}

int order(nodo **head)
{
    if ((*head) == NULL || (*head)->next == *head)
    {
        return 0;
    }

    int flag;
    nodo *aux;
    nodo *last = (*head)->prev;

    do
    {
        flag = 0; // Reset flag
        aux = (*head);

        while (aux->next != (*head))
        {
            if (aux->value > aux->next->value)
            {
                int temp = aux->value;
                aux->value = aux->next->value;
                aux->next->value = temp;
                flag = 1; //Change maded
            }
            aux = aux->next;
        }
    } while (flag); //Verify if a change was maded

    return 1;
}

int firstOut(nodo **head)
{
    if ((*head) == NULL)
        return -1;

    nodo *aux = (*head);
    int val = (*head)->value;

    if ((*head)->next == (*head))
    {
        (*head) = NULL;
    }
    else
    {
        nodo *last = (*head)->prev;
        (*head) = (*head)->next;
        (*head)->prev = last;
        last->next = (*head);
    }
    free(aux);
    return val;
}

int lastOut(nodo **head)
{
    if (*head == NULL)
        return -1;

    nodo *last = (*head)->prev;
    int val = last->value;

    if ((*head)->next == (*head))
    {
        return firstOut(head);
    }
    else
    {
        last->prev->next = *head;
        (*head)->prev = last->prev;
        free(last);
    }

    return val;
}

int orderOut(nodo **head)
{
    if (*head == NULL)
        return 0;

    int val;
    printf("Valor: ");
    scanf("%d", &val);

    nodo *aux = (*head);

    if ((*head)->value == val)
    {
        return firstOut(head);
    }

    do
    {
        if (aux->value == val)
        {
            if (aux->next == *head)
            {
                return lastOut(head);
            }
            else
            {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                int res = aux->value;
                free(aux);
                return res;
            }
        }
        aux = aux->next;
    } while (aux != (*head));

    return 0;
}

void print(nodo **head)
{
    if (*head == NULL)
    {
        printf(">>> Empty list...\n");
        return;
    }

    nodo *aux = (*head);

    do
    {
        printf("[%d] ", aux->value);
        aux = aux->next;
    } while (aux != (*head));

    printf("\n");
}

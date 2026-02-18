#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int value;
    struct elem *next;
    struct elem *prev;
} elem;

void firstIn(elem **head, elem **elem)
{
    if ((*head) == NULL)
        (*head) = (*elem);
    else
    {
        elem *aux = (*head);
        (*head) = (*elem);

        (*head)->next = aux;
        aux->prev = (*head);
    }

    printf(">> Element [%d] successfully implemented\n", (*elem)->value);
}

void lastIn(elem **head, elem **elem)
{
    if ((*head) == NULL)
        (*head) = (*elem);
    else
    {
        elem *aux = (*head);

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = (*elem);
        (*elem)->prev = aux;
    }

    printf(">> Element [%d] successfully implemented\n", (*elem)->value);
}

void orderIn(elem **head, elem **elem)
{
    if ((*head) == NULL)
        (*head) = (*elem);
    else
    {
        if ((*head)->value > (*elem)->value)
        {
            elem *aux = (*head);
            (*head) = (*elem);
            (*head)->next = aux;
            aux->prev = (*elem);
        }
        else
        {
            elem *aux = (*head);

            while (aux != NULL)
            {
                if ((*elem)->value == aux->value && aux->next != NULL)
                {
                    printf(">>> Value alredy exist\n");
                    return;
                }
                else if (aux != (*head) && aux->prev->value < (*elem)->value && aux->value > (*elem)->value)
                {
                    (*elem)->next = aux;
                    (*elem)->prev = aux->prev;
                    aux->prev = (*elem);
                    (*elem)->prev->next = (*elem);
                }
                if ((*elem)->prev == NULL && aux->next == NULL)
                {
                    aux->next = (*elem);
                    (*elem)->prev = aux;
                }
                aux = aux->next;
            }
        }
    }

    order(&(*head));

    printf(">> Element [%d] successfully implemented\n", (*elem)->value);
}

int order(elem **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return 0;
    }

    int flag;
    elem *aux;
    elem *last = NULL;

    do
    {
        flag = 0; // Reset flag
        aux = (*head);

        while (aux->next != last)
        {
            if (aux->value > aux->next->value)
            {
                int temp = aux->value;
                aux->value = aux->next->value;
                aux->next->value = temp;
                flag = 1; // Change maded
            }
            aux = aux->next;
        }
        last = aux; // Last iteam alredy in place
    } while (flag); // Verify if a change was maded

    return 1;
}

int firstOut(elem **head)
{
    elem *aux = (*head);

    int val = (*head)->value;
    if ((*head)->next == NULL)
        (*head) = NULL;
    else
    {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
    }
    free(aux);
    return val;
}

int lastOut(elem **head)
{
    elem *aux = (*head);
    int val;

    if ((*head)->next == NULL)
        return firstOut(&(*head));
    else
    {
        while (aux->next != NULL)
            aux = aux->next;

        val = aux->value;
        aux = aux->prev;
        aux->next = NULL;
        aux = aux->next;
        free(aux);

        return val;
    }
}

int orderOut(elem **head)
{
    int val;
    printf("Valor: ");
    scanf("%d", &val);
    elem *aux = (*head), *aux2;

    if ((*head)->value == val)
        return firstOut(&(*head));
    else
    {
        while (aux->value != val && aux->next != NULL)
            aux = aux->next;

        if (aux->value == val)
        {
            if (aux->next == NULL)
                return lastOut(&(*head));
            else
            {
                val = aux->value;
                aux2 = aux->prev;
                aux2->next = aux->next;
                aux->prev = aux2;
                free(aux);
                return val;
            }
        }
        else
            return 0;
    }
}

void print(elem **head)
{
    if ((*head) == NULL)
        printf(">>> Empty list...\n");
    else
    {
        elem *aux = (*head);

        while (aux != NULL)
        {
            printf("[%d] ", aux->value);
            aux = aux->next;
        }

        printf("\n");

        free(aux);
    }
}
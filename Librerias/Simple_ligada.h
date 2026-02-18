#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int value;
    struct elem *next;
} elem;

void firstIn(elem **head, elem **elem)
{
    elem *aux = (*head);

    (*head) = (*elem);
    (*head)->next = aux;
}

void lastIn(elem **head, elem **elem)
{
    elem *aux = (*head);
    while (aux->next != NULL)
        aux = aux->next;

    aux->next = (*elem);
}

void orderIn(elem **head, elem **elem)
{
    if ((*head) == NULL)
    {
        (*head) = (*elem);
    }
    else
    {
        if ((*head)->next > (*elem)->next)
        {
            elem *aux = (*head);
            (*head) = (*elem);
            (*head)->next = aux;
        }
        else
        {
            elem *aux = (*head), *aux2;

            while (aux->next != NULL)
            {
                if ((*elem)->value < aux->next->value)
                {
                    aux2 = aux->next;
                    aux->next = (*elem);
                    (*elem)->next = aux2;
                    break;
                }
                aux = aux->next;
            }

            if ((*elem)->next == NULL)
                aux->next = (*elem);
        }
    }
    
    order(&(*head));
}

int order(elem **head)
{
    if ((*head) == NULL || (*head)->next == NULL) 
        return 0;
        
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
        last = aux; // Last item alredy in place
    } while (flag); // Verify if a change was maded

    return 1;
}

int firstOut(elem **head)
{
    elem *aux = *head;
    int value = (*head)->value;
    (*head) = (*head)->next;
    free(aux);
    return value;
}

int lastOut(elem **head)
{
    if ((*head)->next == NULL)
        return firstOut(&*head);
    else
    {
        elem *aux = *head;
        while (aux->next->next != NULL)
            aux = aux->next;
        int value = aux->next->value;
        aux->next = NULL;
        return value;
    }
}

int orderOut(elem **head)
{
    int num;
    printf("Value: ");
    scanf("%d", &num);
    elem *aux2, *aux = (*head);

    if ((*head)->value == num)
    {
        if ((*head)->next == NULL)
            return firstOut(&*head);
        else
        {
            aux = (*head)->next;
            free((*head));
            (*head) = aux;
            return num;
        }
    }
    else
    {
        while (aux->value != num && aux->next != NULL)
            aux = aux->next;
        if (aux->value == num)
        {
            if (aux->next == NULL)
                return lastOut(&*head);
            else
            {
                aux2 = (*head);
                while (aux2->next->next != aux->next)
                    aux2 = aux2->next;
                aux2->next = aux->next;
                free(aux);
                return num;
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
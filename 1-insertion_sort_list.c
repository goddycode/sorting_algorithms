#include "sort.h"
/**
 * insertion_sort_list - sort elements of doubling linklist
 * based on Insertion sort algorithm in ascending order
 *@list: pointer to the list head
 *Return: Always nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head_tmp1, *head_tmp2, *myaux1, *myaux2;
	int myflag;

	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				myflag = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->n > head_tmp2->next->n)
				{
					myaux1 = head_tmp2;
					myaux2 = head_tmp2->next;
					myaux1->next = myaux2->next;
					if (myaux2->next)
						myaux2->next->prev =my aux1;
					if (myaux2)
					{
						myaux2->prev = myaux1->prev;
						myaux2->next = myaux1;
					}
					if (myaux1)
						myaux1->prev = myaux2;
					if (myaux2->prev)
						myaux2->prev->next = myaux2;
					head_tmp2 = myaux2->prev;
					if (!myaux2->prev)
						*list = myaux2;
					print_list(*list);
					myflag = 1;
				}
			}
			if (myflag == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}


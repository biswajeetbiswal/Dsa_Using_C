void sort1(int size1)
{
    struct node *ptr1;
    for (int i = 0; i < size1 - 1; i++)
    {

        ptr1 = poly1;
        for (int j = 0; j < size1 - i - 1; j++)
        {
            if (ptr1->expo > ptr1->next->expo)
            {
                int temp = ptr1->expo;
                ptr1->expo = ptr1->next->expo;
                ptr1->next->expo = temp;
            }
            ptr1 = ptr1->next;
        }
    }
}
void sort2(int size2)
{
    struct node *ptr2;
    for (int i = 0; i < size2 - 1; i++)
    {

        ptr2 = poly2;
        for (int j = 0; j < size2 - i - 1; j++)
        {
            if (ptr2->expo > ptr2->next->expo)
            {
                int temp = ptr2->expo;
                ptr2->expo = ptr2->next->expo;
                ptr2->next->expo = temp;
            }
            ptr2 = ptr2->next;
        }
    }
}
struct node *Newnode = NULL;
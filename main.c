#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sravn=0, perest = 0;

void quicksort(int *arr,int first,int last)
{
    int t;
    if (first>=last)
        return;
    int p_ind = first + abs(last-first) / 2;
    int piv = arr[p_ind];

    int i = first, j = last;

    do
    {
        while (i != p_ind && arr[i] < piv)
        {
            if (i < j)
                sravn++;
            i++;

        }
        if (i != p_ind && i < j)
            sravn++;


        while (j != p_ind && arr[j] > piv)
        {
            if (i < j)
                sravn++;

            j--;

        }
        if (j != p_ind && i < j)
            sravn++;

        if (i <= j)
        {

            if (i != j)
            {
                t=arr[j];
                arr[j]=arr[i];
                arr[i]=t;
                perest++;
            }

            i++;
            j--;

        }
    }
    while (i <= j);

    if (i < last)

        quicksort(arr,i,last);

    if (j > first)

        quicksort(arr,first,j);
}
int main()
{
    setlocale(LC_ALL, "Russian");


        int  *arr, n, i;
        printf("Êîë-âî ýëåìåíòîâ â ìàññèâå:\n");
        scanf("%d", &n);
        int first = 0, last = n-1;
        arr = (int*) malloc(n*sizeof(int));
        printf("Ýëåìåíòû ìàññèâà\n");
        for (i=0; i<n; i++)
            scanf("%d", &arr[i]);
        quicksort(arr, first, last) ;
        printf("\nÎòñîðòèðîâàííûé ìàññèâ:\n");
        for(i=0; i<n; i++)
            printf("%d  ", arr[i]);
        printf("\nÊîëè÷åñòâî ïåðåñòàíîâîê: ");
        printf("%d\n",perest);
        printf("Êîëè÷åñòâî ñðàâíåíèé: ");
        printf("%d\n", sravn);
        sravn = 0;
        perest = 0;



}

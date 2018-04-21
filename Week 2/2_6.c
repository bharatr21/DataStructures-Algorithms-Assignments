#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

struct Item
{
    char itemName[20];
    int itemCode;
    float price;
    int QtyInStock;
    int IsHighDemand;
    int SoldToday;
};

typedef struct Item Item;

void add(char* itemName, int itemCode, float price, int QtyInStock, int IsHighDemand, int SoldToday) {
    Item* newItem = (Item*) malloc(sizeof(Item));
    strcpy((*newItem).itemName, itemName);
    (*newItem).itemCode = itemCode;
    (*newItem).price = price;
    (*newItem).QtyInStock = QtyInStock;
    (*newItem).IsHighDemand = IsHighDemand;
    (*newItem).SoldToday = SoldToday;
}

void updatePrice(int itemCode, int price)
{
    if(it.itemCode == itemCode)
    {
        it.price = price;
    }
}

void updateStock(int itemCode, int qty)
{
    if(it.itemCode == itemCode)
    {
        it.QtyInStock += qty;
    }
}

void pricelist(Item a[])
{
    int i;
    int num = sizeof(a)/sizeof(a[0]);
    f(i,1,num+1)
    {
        printf("%d ",a[i].itemCode);
        printf("%s ",a[i].itemName);
        printf("%f\n",a[i].price);
    }
}

void sell(int itemCode, int qtysold)
{
    if(it.itemCode == itemCode)
    {
        it.QtyInStock -= qtysold;
    }
}

int main()
{
    int n;
    int qty, itemCode, price, QtyInStock, IsHighDemand, SoldToday;
    char itemName[20];
    Item a[100];
    printf("Enter a number\n1. Add a new item\n2. Update Price of item\n3. Update the stock of item\n4. Show price list\n5. Sell an item\n6. Exit\n");
    scanf("%d",&n);
    p:
    switch(n)
    {
        case 1:  {
            printf("Enter all details of item to be added\n");
            scanf("%s %d %d %d %d %d",&itemName,&itemCode,&price,&QtyInStock,&IsHighDemand, &SoldToday);
            add(itemName, itemCode, price, QtyInStock, IsHighDemand, SoldToday);
            break;
        }
        case 2: {
            printf("Enter itemcode and new price to be updated\n");
            scanf("%d",&itemCode);
            scanf("%d",&price);
            updatePrice(itemCode, price);
            break;
        
        }        
        case 3: {
            printf("Enter itemcode and quantity to be refilled\n");
            scanf("%d",&itemCode);
            scanf("%d",&qty);
            updateStock(itemCode,qty);
            break;
        }
         case 4: {
            printf("Displaying price list\n");
            pricelist(a);
            break;
        }
        case 5:
        {
            printf("Enter itemcode and quantity to sell\n");
            scanf("%d %d",&itemCode,&qty);
            sell(itemCode,qty);
            break;
        }
        case 6:
        {
        	printf("Exiting....\n");
        	return 0;
        }
        default:
        {
        	printf("Enter a number again");
        	scanf("%d",&n);
        	goto p;
        }

    }
    return 0;
}
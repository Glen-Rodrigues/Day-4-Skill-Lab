#include <stdio.h>
struct order
{
    int order_id;
    char customer_name[50], product[100];
    int amount;
};
typedef struct order Order;

void readOrders(Order o[], int n)
{
    printf("Enter details (Order ID, Customer Name, Product, Amount):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Order %d: ", i + 1);
        scanf("%d %s %s %d", &o[i].order_id, o[i].customer_name, o[i].product, &o[i].amount);
    }
}

void saveOrders(Order o[], int n)
{
    FILE *file = fopen("Orders.txt", "w");
    if (file == NULL)
    {
        printf("Error in creating file.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        fprintf(file, "%d %s %s %d\n", o[i].order_id, o[i].customer_name, o[i].product, o[i].amount);
    fclose(file);
    printf("Record saved in \"Orders.txt\"\n");
}

void searchOrder(Order o[], int n)
{
    int orderId, flag = 1;
    printf("Enter Order ID to search: ");
    scanf("%d", &orderId);
    for (int i = 0; i < n; i++)
    {
        if (orderId == o[i].order_id)
        {
            printf("Order Found: %s - %s - ₹%d\n", o[i].customer_name, o[i].product, o[i].amount);
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Order not found\n");
}

int main()
{
    int num_orders;
    Order orders[100];
    printf("Enter number of orders: ");
    scanf("%d", &num_orders);
    readOrders(orders, num_orders);
    searchOrder(orders, num_orders);
    saveOrders(orders, num_orders);
    return 0;
}

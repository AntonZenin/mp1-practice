#include <stdio.h>
#include <string.h>

#define N_SYMBOLS 5
#define NAME_LEN 20
#define N_PRODUCTS 12

typedef struct {
    char barcode[N_SYMBOLS];
    char name[NAME_LEN];
    float price;
    float discount;
}Product; 

Product scanProduct(Product products[], int size) {
    char barcode[5];
    printf("Input barcode: ");
    scanf("%s", barcode);

    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].barcode, barcode) == 0) {
            return products[i];
        }
    }

    Product emptyProduct;
    strcpy(emptyProduct.barcode, "0000"); 
    return emptyProduct; 
}
int main() {
    Product products[N_PRODUCTS] = {
        {"0001", "Bread", 60.f, 30.f},
        {"0002", "Milk", 95.f, 0.f},
        {"0003", "Cheese", 650.f, 0.f},
        {"0004", "Butter", 140.f, 20.f},
        {"0005", "Water", 35.f, 0.f},
        {"0006", "Buiscuits", 115.f, 0.f},
        {"0007", "Juice", 120.f, 50.f},
        {"0008", "Lemonade", 106.f, 0.f},
        {"0009", "Milk chocolate bar", 150.f, 5.f},
        {"0010", "Sour cream", 90.f, 0.f},
        {"0011", "Mars", 65.f, 0.f},
        {"0012", "Nutella", 460.f, 10.f}
    };
    int size = sizeof(products) / sizeof(products[0]);

    Product receipt[100]; 
    int receiptSize = 0; 
    float totalPrice = 0; 
    float totalDiscount = 0; 
    float finalAmount = 0; 

    int choice;
    do {
        printf("\n1. Scan product\n");
        printf("2. Show the description of product\n");
        printf("3. Add product in receipt\n");
        printf("4. Make a receipt\n");
        printf("5. Calculate the amount to be paid\n");
        printf("0. Exit\n");
        printf("Input choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            Product scannedProduct = scanProduct(products, size);
            if (strcmp(scannedProduct.barcode, "0000") == 0) {
                printf("Product not found\n");
                break;
            }
            printf("Name: %s\n", scannedProduct.name);
            printf("Price per unit: %.2f\n", scannedProduct.price);
            printf("Discount: %.2f%%\n", scannedProduct.discount);
            break;
        }
        case 2: {
            printf("Input the barcode: ");
            char barcode[5];
            scanf("%s", barcode);
            for (int i = 0; i < size; i++) {
                if (strcmp(products[i].barcode, barcode) == 0) {
                    printf("Name: %s\n", products[i].name);
                    printf("Price per unit: %.2f\n", products[i].price);
                    printf("Discount: %.2f%%\n", products[i].discount);
                    break;
                }
            }
            break;
        }
        case 3: {
            Product scannedProduct = scanProduct(products, size);
            if (strcmp(scannedProduct.barcode, "0000") == 0) {
                printf("Product not found\n");
                break;
            }
            receipt[receiptSize++] = scannedProduct;
            printf("The product was added to the receipt\n");
            break;
        }
        case 4: {
            printf("Your receipt:\n");
            for (int i = 0; i < receiptSize; i++) {
                Product product = receipt[i];
                float productTotal = product.price * (100 - product.discount) / 100;
                printf("%s - %.2f - 1 - %.2f\n", product.name, product.price, productTotal);
                totalPrice += productTotal;
                totalDiscount += product.price - productTotal;
            }
            break;
        }
        case 5: {
            finalAmount = totalPrice - totalDiscount;
            printf("Your amount to pay: %.2f\n", finalAmount);
            break;
        }
        case 0: {
            printf("Exit\n");
            break;
        }
        default: {
            printf("Incorrect choice\n");
            break;
        }
    }
  } while (choice != 0);

    return 0;
}

        
        
 
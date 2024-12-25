#include <stdio.h>
#include <math.h>
int main()
{
    int n, choice, checkElement=0;
    int arr[100];
    do {
        printf("\n=====================MENU======================\n");
        printf("1.Nhap so phan tu gia tri cua phan tu cho mang.\n");
        printf("2.In ra mang.\n");
        printf("3.So luong so nguyen to co trong mang.\n");
        printf("4.In ra gia tri nho thu hai trong mang.\n");
        printf("5.Them 1 phan tu vao vi tri cu the trong mang.\n");
        printf("6.Xoa 1 phan tu tai vi tri cu the.\n");
        printf("7.Sap xep mang theo thu tu giam dan(insertion sort).\n");
        printf("8.Tim kiem phan tu trong mang bang.\n");
        printf("9.Xoa toan bo phan tu trung lap torng mang.\n");
        printf("10.Dao nguoc thu tu cua cac phan tu co trong mang.\n");
        printf("11.Thoat MENU.\n");
        printf("\nLua chon cua ban: ");
        scanf("%d",&choice);
        switch (choice){
            
            
            case 1:
            printf("Nhap so phan tu cua mang: ");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                printf("Nhap phan tu thu %d: ",i);
                scanf("%d",&arr[i]);
            }
            checkElement=1;
                break;
            
            
            case 2:
            if(checkElement==0){
                printf("Ban chua nhap mang.Vui long nhap mang.\n");
                break;
            }
            printf("Cac phan tu trong mang la: ");
            for(int i=0;i<n;i++){
                printf("arr[%d]= %d, ",i,arr[i]);
            }
            printf("\n");
                break;
            
            
           case 3:
            if (checkElement==0) {
                printf("Ban chua nhap mang. Vui long nhap mang.\n");
                    break;
            }
            int numCount=0;
                for (int i=0;i<n;i++){
            int check=1;
                if(arr[i]<2){
                    check = 0;
                }else{
                    for(int j = 2; j <= sqrt(arr[i]); j++) {
                        if (arr[i] % j == 0) {
                            check = 0;
                    break;
                    }
                    }
                }
                if(check == 1) {
                    numCount++;
                }
                    }

                    printf("So luong so nguyen to co trong mang la: %d\n", numCount);
                        break;
                        
            case 4:
            int min1 = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] < min1) {
                    min1 = arr[i];
                }
            }
            int min2 = arr[0];
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] > min1) {
                    if (!found || arr[i] < min2) {
                        min2 = arr[i];
                        found = 1;
                    }
                }
            }
            if (!found) {
                printf("Khong co gia tri nho thu hai trong mang.\n");
            } else {
                printf("Gia tri nho thu hai la: %d\n", min2);
            }
                break;
                
            case 5:
                if (checkElement==0){
                    printf("Ban chua nhap mang. Vui long nhap mang.\n");
                    break;
                }
                int addValue, position;
                printf("Nhap gia tri can them vao mang: ");
                scanf("%d", &addValue);
                printf("Nhap vi tri can them (0 -> %d): ", n);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le. Vui long thu lai.\n");
                    break;
                }
                for(int i = n; i > position; i--) {
                    arr[i] = arr[i - 1];
                }
            
                    arr[position] = addValue;
                        n++;
            
                    printf("Them thanh cong. Mang sau khi them la:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                    printf("\n");
                        break;
                
            case 6:
                if (checkElement==0){
                printf("Ban chua nhap mang.Vui long nhap mang.\n");
                    break;
                }
                int delete;
                printf("Nhap vi tri can xoa(0 -> %d): ", n-1);
                scanf("%d", &delete);
                    for (int i=delete;i<n-1;i++){
                        arr[i]=arr[i+1];
                    }n--;
                    printf("Xoa thanh cong. Mang sau khi xoa la:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                    printf("\n");
                        break;
            case 7:
                for (int i = 1; i < n; i++) {
                    int temp = arr[i];
                for (int j = i - 1; j >= 0; j--) {
                    if (arr[j] < temp) {
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Mang sau khi sap xep giam dan(insertion sort): ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
                    break;
            
            case 8:
                int start = 0, end = n - 1, mid, flag=0, value;
                printf("Nhap phan tu can tim trong mang: ");
                scanf("%d", &value);
            while (start <= end) {
                mid = start + (end - start) / 2;
                if (arr[mid] == value) {
                    printf("Phan tu %d tim thay tai vi tri %d.\n", value, mid);
                    flag = 1;
                    break;
                }else if (arr[mid] < value) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        
            if (flag==0) {
                printf("Phan tu %d khong ton tai trong mang.\n", value);
            }
                break;
            
            case 9:    
            int k = 0;
                for (int i = 0; i < n; i++) {
                    int duplicate = 0;
                    for (int j = 0; j < k; j++) {
                        if (arr[i] == arr[j]) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate == 0) {
                        arr[k++] = arr[i];
                    }
                }
                printf("Mang sau khi xoa cac phan tu trung lap: ");
                for (int i = 0; i < k; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            
            case 11:
            printf("Thoat MENU!!!");
                break;
            default:
                printf("Lua chon khong hop le vui long nhap lai.\n");
            }
    } while(choice!=11);
    return 0;
}

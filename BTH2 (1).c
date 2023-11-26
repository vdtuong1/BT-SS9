#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,m;
	printf("Nhap vao so dong cua mang 2 chieu:");
	scanf("%d",&n);
	printf("Nhap vao so cot cua mang 2 chieu:");
	scanf("%d",&m);
	int numbers[n][m];
	int sumNumbers;
	int mulNumbers;
	int min, max;
	int avgValue;
	int cntNumber;
	int maxRow;
	int sumRow;
	int indexMaxRow;
	//2. In menu
	do{
		printf("***************MENU**************\n");
		printf("1. Nhap gia tri cac phan tu mang\n");
		printf("2. In gia tri cac phan tu mang theo ma tran\n");
		printf("3. In gia tri cac phan tu le va tinh tong\n");
		printf("4. In gia tri cac phan tu tren duong bien va tinh tich\n");
		printf("5. In gia tri cac phan tu cheo chinh, cheo phu va tinh tong\n");
		printf("6. In gia tri lon nhat va nho nhat trong mang\n");
		printf("7. Tinh gia tri trung binh va thong ke phan tu\n");
		printf("8. In ra dong co tong gia tri phan tu lon nhat\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban:");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap gia tri cac phan tu mang:\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						printf("numbers[%d][%d]=",i,j);
						scanf("%d",&numbers[i][j]);
					}
				}
				break;
			case 2:
				printf("Gia tri cac phan tu trong mang:\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						printf("%d\t",numbers[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				break;
			case 3:
				sumNumbers=0;
				printf("Cac phan tu le trong mang la:\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(numbers[i][j]%2!=0){
							printf("%d\t",numbers[i][j]);
							sumNumbers+=numbers[i][j];
						}
					}
				}
				printf("\nTong cac phan tu le trong mang: %d\n",sumNumbers);
				break;
			case 4:
				mulNumbers = 1;
				printf("Cac phan tu nam tren duong bien:\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(i==0 || i==n-1 || j ==0 || j == m-1){
							printf("%d\t",numbers[i][j]);
							mulNumbers*=numbers[i][j];
						}
					}
				}
				printf("\nTich cac phan tu tren bien la: %d\n",mulNumbers);
				break;
			case 5:
				if(n==m){
					sumNumbers = 0;
					printf("Cac phan tu nam tren duong cheo chinh:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i==j){
								printf("%d\t",numbers[i][j]);
								sumNumbers+=numbers[i][j];
							}
						}
					}
					printf("\nTong cac phan tu tren cheo chinh: %d\n",sumNumbers);
					sumNumbers=0;
					printf("Cac phan tu nam tren duong cheo phu:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i+j==n-1){
								printf("%d\t",numbers[i][j]);
								sumNumbers+=numbers[i][j];
							}
						}
					}
					printf("\nTong cac phan tu tren cheo phu: %d\n",sumNumbers);
				}else{
					printf("Day khong phai ma tran vuong, khong co cheo chinh va cheo phu\n");	
				}			
				break;
			case 6:
				min = numbers[0][0];
				max = numbers[0][0];
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(min>numbers[i][j]){
							min = numbers[i][j];
						}
						if(max<numbers[i][j]){
							max = numbers[i][j];
						}
					}
				}
				printf("Gia tri lon nhat: %d - Nho nhat: %d\n",max,min);
				break;
			case 7:
				sumNumbers = 0;
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						sumNumbers+=numbers[i][j];
					}
				}
				avgValue = sumNumbers/(n*m);
				cntNumber = 0;
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(avgValue==numbers[i][j]){
							cntNumber++;
						}
					}
				}
				printf("Co %d phan tu co gia tri bang gia tri trung binh: %d\n",cntNumber,avgValue);
				break;
			case 8:
				indexMaxRow = 0;
				maxRow = 0;
				for(int j=0;j<m;j++){
					maxRow+=numbers[0][j];
				}
				for(int i=1;i<n;i++){
					sumRow = 0;
					for(int j=0;j<m;j++){
						sumRow+= numbers[i][j];
					}
					if(maxRow<sumRow){
						maxRow=sumRow;
						indexMaxRow=i;
					}
				}
				printf("Dong %d co tong cac phan tu lon nhat:\n",indexMaxRow);
				for(int j=0;j<m;j++){
					printf("%d\t",numbers[indexMaxRow][j]);
				}
				printf("\n");
				break;
			case 9:
				exit(0);
			default:
				printf("Vui long nhap tu 1-9");
		}
	}while(1==1);
}

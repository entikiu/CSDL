#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;
void Swap(recordtype *x,recordtype *y){
	recordtype temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
//buble 
void bubblesort(recordtype a[] ,int n){
	int i ,j;
	for(i=0;i<=n-2;i++)
		for(j=n-1;j>=i+1;j--)
			if(a[j].key<a[j-1].key)
				Swap(&a[j],&a[j-1]);
}
//select 
void selectionsort(recordtype a[] ,int n){
	int i ,j,lowindex;
	keytype lowkey;
	for(i=0;i<=n-2;i++){
		lowkey=a[i].key;
		lowindex=i;
		for(j=i+1;j<=n-1;j++)
			if(a[j].key<lowkey){
				lowkey=a[j].key;
				lowindex=j;
	}
	Swap(&a[i],&a[lowindex]);
}
}
//insert
 void insertionsort(recordtype a[] ,int n){
	int i ,j;
	for(i=1;i<=n-1;i++){
		j=i;
		while(j>0 && a[j].key<a[j-1].key){
		
			Swap(&a[j],&a[j-1]);	
			j--;
		}
	}

}
//heap
void Pushdown(recordtype a[], int first ,int last){
	int r =first;
	while(r<=(last-1)/2)
	if (last == 2*r+1){
		if (a[r].key<a[last].key) Swap(&a[r],&a[last]);
		r=last;
	}else
		if(a[r].key<a[2*r+1].key && a[2*r+1].key>=a[2*r+2].key){
		Swap(&a[r],&a[2*r+1]);
		r=2*r+1;
	}else
		if(a[r].key<a[2*r+2].key) {
		Swap(&a[r],&a[2*r+2]);
		r=2*r+2;
	}else 
		r=last;
}	
void heapsort(recordtype a[],int n){
	int i;
	for(i=(n-2)/2;i>=0;i--)
	Pushdown(a,i,n-1);
	for(i=n-1;i>=2;i--){
		Swap(&a[0],&a[i]);
		Pushdown(a,0,i-1);
	}
	Swap(&a[0],&a[1]);
}
//quick
int Findpivot(recordtype a[],int i,int j){
	keytype firstkey;
	int k;
	k=i+1;
	firstkey =a[i].key;
	while(k<=j && a[k].key ==firstkey)k++;
	if(k>j) return -1;
	if (a[k].key>firstkey) return k;
	return i;
}
int Partition(recordtype a[] , int i, int j, keytype pivot){
	int L,R;
	L=i;
	R=j;
	while (L<=R){
		while(a[L].key<pivot) L++;
		while(a[R].key>=pivot) R--;
		if(L<R) Swap(&a[L],&a[R]);
	}
	return L;
}
void quicksort(recordtype a[] ,int i,int j){
	keytype pivot;
	int pivotindex,k;
	pivotindex= Findpivot(a,i,j);
	if(pivotindex !=-1){
		pivot =a[pivotindex].key;
		k= Partition(a,i,j,pivot);
		quicksort(a,i,k-1);
		quicksort(a,k,j);
	}
}
//quick bthe 
int Partition(recordtype a[] , int i, int j){
	int pivot = a[i].key;
	int L=i+1;
	int R =j;

	while (L<=R){
		while(L<=R && a[L].key<=pivot) L++;
		while(L<=R && a[R].key>=pivot) R--;
		if(L<R) Swap(&a[L],&a[R]);
	}
	Swap(&a[R],&a[i]);
	return R;
}
void quicksort(recordtype a[] ,int i,int j){

	if(i<j){
	
		int p= Partition(a,i,j);
		quicksort(a,i,p-1);
		quicksort(a,p+1,j);
	}
} 
void read_data(recordtype a[],int*n){
	FILE*f;
	f= fopen("data.txt","r");
	int i=0;
	if(f!=NULL)
	while (!feof(f)){
		fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
		i++;
	}else printf("Loi mo file\n");
	fclose(f);
	*n=i;
}
void print_data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++)
	printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
}
main(){
	recordtype a[100];
	int n;
	printf("Thuat toan Bubble_Sort\n\n");
	read_data(a,&n);
	printf("Du kieu truoc khi sap xep:\n");
	print_data(a,n);
	bubblesort(a,n);
	printf("Du lieu sau khi sao xep:\n");
	print_data(a,n);
	return 0;
}
//THAM AN
 //ATM
 #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int MG;            
    char TenTien[50];   
    int PA;           
} Tien;

Tien * ReadFromFile(int *n){
    FILE *f;
    f=fopen("ATM.txt","r");
    if(f == NULL) {
        printf("Khong tim thay file ATM.TXT!\n");
        exit(1);
    }
    
    Tien *dslt;
    dslt=(Tien*)malloc(sizeof(Tien));
    int i=0;
    while (!feof(f)){
       
        fscanf(f, "%d %[^\n]", &dslt[i].MG, dslt[i].TenTien);
        dslt[i].PA=0;
        i++;
        dslt=(Tien*)realloc(dslt, sizeof(Tien)*(i+1));
    }
    *n=i;
    fclose(f);
    return dslt;
}


void Swap(Tien *x, Tien *y){
    Tien Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}


void BubbleSort(Tien *dslt, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (dslt[j].MG > dslt[j-1].MG) {
                Swap(&dslt[j], &dslt[j-1]);
            }
        }
    }
}


void InDS(Tien *dslt , int n, int TienCanRut){
    int i;
    int TongTienTra=0;
    printf("|---|-------------------------|---------|---------|----------|\n");
    printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n", "STT", "Loai tien", "Menh Gia", "So to", "Thanh tien");
    printf("|---|-------------------------|---------|---------|----------|\n");
    for(i=0;i<n;i++){
        if (dslt[i].PA !=0){
            printf("|%-3d",i+1);
            printf("|%-25s",dslt[i].TenTien);
            printf("|%-9d",dslt[i].MG);
            printf("|%-9d",dslt[i].PA);
            printf("|%-10d|\n",dslt[i].MG*dslt[i].PA);
            TongTienTra=TongTienTra+dslt[i].PA * dslt[i].MG;
        }
        else {
            continue;
        }
    }
    printf("|---|-------------------------|---------|---------|----------|\n");
    printf("So tien can rut= %9d\n",TienCanRut);
    printf("So tien da tra= %9d\n", TongTienTra);
}


void Greedy(Tien *dslt,int n, int TienCanRut){
    int i=0;
    while(i<n && TienCanRut>0) {
        dslt[i].PA = TienCanRut/dslt[i].MG;
        TienCanRut = TienCanRut - dslt[i].PA * dslt[i].MG;
        i++;
    }
}

int main(){
    int n;
    int TienCanRut;
    printf("Nhap so tien can rut: ");
    scanf("%d",&TienCanRut);
    
    Tien *dslt;
    dslt=ReadFromFile(&n);
    
    BubbleSort(dslt,n);
    
    Greedy(dslt,n,TienCanRut);
    
    InDS(dslt, n, TienCanRut);
    
    free(dslt);
    
    return 0;
}
//BAOL1
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    float TL, GT, DG; 
    int PA;        
} DoVat;

DoVat *ReadFromFile(float *W, int *n) {
    FILE *f;
    f = fopen("CaiBalo1.TXT", "r");
    if (f == NULL) {
        printf("Khong tim thay file CaiBalo1.TXT!\n");
        exit(1);
    }
    
    fscanf(f, "%f", W); 
    
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    
  while (!feof(f)) {

    if (fscanf(f, "%f %f %[^\n]", &dsdv[i].TL, &dsdv[i].GT, dsdv[i].TenDV) < 2) {
        break; 
    }
    
    dsdv[i].DG = dsdv[i].GT / dsdv[i].TL; 
    dsdv[i].PA = 0;
    i++;
    dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
}
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y) {
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat *dsdv, int n) {
    int i, j;
    for (i = 0; i <= n - 2; i++) {
        for (j = n - 1; j >= i + 1; j--) {
            if (dsdv[j].DG > dsdv[j - 1].DG) {
                swap(&dsdv[j], &dsdv[j - 1]);
            }
        }
    }
}

void InDSDV(DoVat *dsdv, int n, float W) {
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    
    printf("\nPhuong an Cai Ba lo 1 dung thuat toan Tham an:\n");
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat     | T Luong | Gia tri | Don gia | Phuong an |\n");
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    
    for(i = 0; i < n; i++) {
        printf("|%2d |%-20s|%9.2f|%9.2f|%9.2f|%6d     |\n", 
            i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(i = 0; i < n - 1; i++) {
        printf("%d, ", dsdv[i].PA);
    }
    printf("%d)", dsdv[n - 1].PA);
    printf("\nTong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}

void Greedy(DoVat *dsdv, int n, float W) {
    int i;
    for (i = 0; i < n; i++) {
        dsdv[i].PA = (W / dsdv[i].TL); 
        W = W - dsdv[i].PA * dsdv[i].TL;
    }
}

int main() {
    int n;
    float W;
    DoVat *dsdv;
    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);
    free(dsdv);
    return 0;
}
//BALO2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    float TL, GT, DG; 
    int SL, PA;      
} DoVat;

DoVat * ReadFromFile(float *W, int *n){
    FILE *f;
    f = fopen("CaiBalo2.TXT", "r");
    if (f == NULL) {
        printf("Khong tim thay file CaiBalo2.TXT!\n");
        exit(1);
    }
    
    fscanf(f, "%f", W); 
    
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;

    while (fscanf(f, "%f %f %d %[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, dsdv[i].TenDV) == 4){
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }
    
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y){
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
    int i, j;
    for(i = 0; i <= n - 2; i++){
        for(j = n - 1; j >= i + 1; j--){
            if (dsdv[j].DG > dsdv[j - 1].DG){
                swap(&dsdv[j], &dsdv[j - 1]);
            }
        }
    }
}

void InDSDV(DoVat *dsdv, int n, float W){
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    
    printf("\nPhuong an Cai Ba lo 2 dung thuat toan Tham an:\n");
    printf("|---|--------------------|---------|---------|-----|---------|-----------|\n");
    printf("|STT|     Ten Do Vat     | T Luong | Gia tri | S.L | Don gia | Phuong an |\n");
    printf("|---|--------------------|---------|---------|-----|---------|-----------|\n");
    
    for(i = 0; i < n; i++){
        printf("|%2d |%-20s|%9.2f|%9.2f|%5d|%9.2f|%6d     |\n", 
            i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|-----|---------|-----------|\n");
    
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(i = 0; i < n - 1; i++){
        printf("%d, ", dsdv[i].PA);
    }
    printf("%d)\n", dsdv[n - 1].PA);
    printf("Tong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}

void Greedy(DoVat *dsdv, int n, float W){
    int i;
    for(i = 0; i < n; i++){
        dsdv[i].PA = (W / dsdv[i].TL); 
        if (dsdv[i].PA > dsdv[i].SL) {
            dsdv[i].PA = dsdv[i].SL;
        }
        
        W = W - dsdv[i].PA * dsdv[i].TL;
    }
}

int main(){
    int n;
    float W;
    DoVat *dsdv;

    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);

    free(dsdv); 

    return 0;
}
//BALO3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    float TL, GT, DG;
    int PA;
} DoVat;

DoVat * ReadFromFile(float *W, int *n){
    FILE *f;
    f = fopen("CaiBalo3.TXT", "r");
    if (f == NULL) {
        printf("Khong tim thay file CaiBalo3.TXT!\n");
        exit(1);
    }
    
    fscanf(f, "%f", W); 
    
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
 
    while (fscanf(f, "%f %f %[^\n]", &dsdv[i].TL, &dsdv[i].GT,dsdv[i].TenDV) == 3){
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL; 
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }
    
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y){
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
    int i, j;
    for(i = 0; i <= n - 2; i++){
        for(j = n - 1; j >= i + 1; j--){
            if (dsdv[j].DG > dsdv[j - 1].DG){
                swap(&dsdv[j], &dsdv[j - 1]);
            }
        }
    }
}

void InDSDV(DoVat *dsdv, int n, float W){
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    
    printf("\nPhuong an Cai Ba lo 3 dung thuat toan Tham an:\n");
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat     | T Luong | Gia tri | Don gia | Phuong an |\n");
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    
    for(i = 0; i < n; i++){
        printf("|%2d |%-20s|%9.2f|%9.2f|%9.2f|%6d     |\n", 
            i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(i = 0; i < n - 1; i++){
        printf("%d, ", dsdv[i].PA);
    }
    printf("%d)\n", dsdv[n - 1].PA);
    printf("Tong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}

void Greedy(DoVat *dsdv, int n, float W){
    int i;
    for(i = 0; i < n; i++){
        dsdv[i].PA = (W / dsdv[i].TL); 

        if (dsdv[i].PA > 1) {
            dsdv[i].PA = 1;
        }
        
        W = W - dsdv[i].PA * dsdv[i].TL;
    }
}

int main(){
    int n;
    float W;
    DoVat *dsdv;

    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);

    free(dsdv);

    return 0;
} 
//TSP
#include <stdio.h>
#define size 30

typedef struct {
    float do_dai;
    int dau, cuoi;
} canh;

void read_file(char file_name[], canh a[], int *n){
    int i, j, t;
    float temp;
    FILE *f;
    f = fopen("TSP.TXT", "r");
    if (f == NULL){
        printf("Loi mo file!!!\n");
        return;
    }

    fscanf(f, "%d", n); 

    int k = 0;
    for(i = 0; i < *n; i++)
        for(j = i; j < *n; j++)
            if(i == j) 
                for(t = 0; t <= j; t++) fscanf(f, "%f", &temp);
            else {
                fscanf(f, "%f", &a[k].do_dai); 
                a[k].dau = i;
                a[k].cuoi = j;
                k++;
            }
    fclose(f);
}

void in_ds_canh(canh a[], int m, int la_PA){
    int i;
    float tong = 0.0;
    for(i = 0; i < m; i++){
        printf("%3d %c%c=%8.2f\n", i+1, a[i].dau+97, a[i].cuoi+97, a[i].do_dai);
        if (la_PA)
            tong += a[i].do_dai;
    }
    if (la_PA)
        printf("Tong do dai cac canh = %5.2f\n", tong);
}

void swap(canh *x, canh *y){
    canh temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(canh a[], int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = n - 1; j > i; j--){
            if(a[j].do_dai < a[j-1].do_dai){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}

void init_forest(int parent[], int n){
    int i;
    for(i = 0; i < n; i++)
        parent[i] = i;
}

int find_root(int parent[], int u){
    while (u != parent[u])
        u = parent[u];
    return u;
}

int chu_trinh(int r_dau, int r_cuoi){
    return (r_dau == r_cuoi);
}

void update_forest(int parent[], int r1, int r2){
    parent[r2] = r1; 
}

int dinh_cap3(canh PA[], int k, canh e){
    int i, dem_dau = 1, dem_cuoi = 1;
    for(i = 0; i < k; i++){
        if(e.dau == PA[i].dau || e.dau == PA[i].cuoi) dem_dau++;
        if(e.cuoi == PA[i].dau || e.cuoi == PA[i].cuoi) dem_cuoi++;
    }
    if(dem_dau >= 3 || dem_cuoi >= 3) return 1;
    return 0;
}

void greedy(canh ds_canh[], int n, canh PA[]){
    int i, j;
    int parent[n];
    init_forest(parent, n);
    int r_dau, r_cuoi;

    j = 0;
    for(i = 0; i < n*(n-1)/2 && j < n-1; i++){
        r_dau = find_root(parent, ds_canh[i].dau);
        r_cuoi = find_root(parent, ds_canh[i].cuoi);
        if (!dinh_cap3(PA, j, ds_canh[i]) && !chu_trinh(r_dau, r_cuoi)){
            PA[j] = ds_canh[i]; 
            j++;
            update_forest(parent, r_dau, r_cuoi); 
        }
    }

    for(; i < n*(n-1)/2; i++){
        r_dau = find_root(parent, ds_canh[i].dau);
        r_cuoi = find_root(parent, ds_canh[i].cuoi);
        if ((!dinh_cap3(PA, n-1, ds_canh[i])) && (chu_trinh(r_dau, r_cuoi))){
            PA[n-1] = ds_canh[i];
            break; 
        }
    }
}

int main(){
    canh ds_canh[size];
    int n;

    printf("Phuong an TSP dung thuat toan THAM AN:\n");
    read_file("TSP1.txt", ds_canh, &n);
    printf("Danh sach cac canh cua do thi:\n");
    in_ds_canh(ds_canh, n*(n-1)/2, 0);

    bubble_sort(ds_canh, n*(n-1)/2);
    printf("\nDanh sach cac canh cua do thi da SAP XEP:\n");
    in_ds_canh(ds_canh, n*(n-1)/2, 0);

    canh PA[n];
    greedy(ds_canh, n, PA);

    printf("\nPHUONG AN\n");
    in_ds_canh(PA, n, 1);

    return 0;
} 
//NHÁNH CAN
//BALO1
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAX_N 100

typedef struct {
    int w, v, qty;
    float ppu; 
    char name[25];  
} item;

void swap (item *a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void sort (item *a, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].ppu < a[j].ppu)
                swap(&a[i], &a[j]);
}

void readFile (item **a, int *n, int *m){
    FILE *f = fopen("CaiBalo1.TXT", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file CaiBalo1.TXT\n");
        exit(1);
    }
    
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (1){
        (*a) =(item*) realloc(*a, sizeof(item)*(i+1));
        int scan_count = fscanf(f, "%d %d %[^\n]", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        if (scan_count == 3) {
            (*a)[i].ppu = (float)(*a)[i].v / (*a)[i].w;
            (*a)[i].qty = 0;
            i++;
        } else {
            break; 
        }
    }
    *n = i;
    fclose(f);
}

void printChart (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
    printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
    for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].ppu, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
    }   
    printf("|---|---------------------|-----------|-------|-------|---------|\n");  
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(int i=0; i<n-1; i++){
        printf("%d,", a[i].qty);
    }   
    printf("%d)\n", a[n-1].qty);
    printf("Trong luong cua ba lo = %5d\n",m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void solve(item *a, int n, int p_val, int m, int x[], int i, float *final_res){
    for(int j = m/a[i].w; j >= 0; j--){
        float cur_val, remain, ubound;
        cur_val = p_val + j*a[i].v;
        remain = m - j*a[i].w;

        ubound = cur_val;
        if (i < n - 1) {
            ubound += remain * a[i+1].ppu;
        }

        if(ubound > *final_res){
            x[i] = j;           
            if((i == n-1 || remain == 0) && cur_val > *final_res){
                *final_res = cur_val;
                for(int k = 0; k < n; k++){
                    a[k].qty = x[k];
                }       
            }
            else {
                
                if (i < n - 1) {
                    solve(a, n, cur_val, remain, x, i+1, final_res);
                }
            }
        }       
        x[i] = 0;   
    }
}

int main (){
    item *a;
    int n, m, x[MAX_N];
    float final_res = 0;

    for(int i=0; i<MAX_N; i++) x[i] = 0;

    readFile(&a, &n, &m);
    sort(a, n); 
    solve(a, n, 0, m, x, 0, &final_res);
    printChart(a, n, m);
    
    free(a);
    return 0;
}
//BALO2
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX_N 100

typedef struct {
    int w, v, qty, max_qty;
    float ppu; 
    char name[25];  
} item;

void swap (item *a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void sort (item *a, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].ppu < a[j].ppu)
                swap(&a[i], &a[j]);
}

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("CaiBalo2.txt", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file CaiBalo2.txt\n");
        exit(1);
    }
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    

    while (1){
        (*a) = (item*)realloc(*a, sizeof(item)*(i+1));
        int scan_count = fscanf(f, "%d %d %d %[^\n]", &(*a)[i].w, &(*a)[i].v, &(*a)[i].max_qty, (*a)[i].name);
        if (scan_count == 4) {
            (*a)[i].ppu = (float)(*a)[i].v / (*a)[i].w;
            (*a)[i].qty = 0;
            i++;
        } else {
            break;
        }
    }
    *n = i;
    fclose(f);
}

void printChart (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("|---|---------------------|-----------|-------|--------|-------|---------|\n");
    printf("|%-3s|%-21s|%-11s|%-7s|%-8s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "So luong", "Don gia","Phuong an");
    printf("|---|---------------------|-----------|-------|--------|-------|---------|\n");
    for(int i = 0, k = 1; i < n; i++){
        printf("| %-2d| %-20s|%11d|%7d|%8d|%7.2f|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].max_qty, a[i].ppu, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
    }   
    printf("|---|---------------------|-----------|-------|--------|-------|---------|\n");
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(int i=0; i<n-1; i++){
        printf("%d,", a[i].qty);
    }   
    printf("%d)\n", a[n-1].qty);
    printf("Trong luong cua ba lo = %5d\n", m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

int min(int a, int b){
    return a < b ? a : b;
}

void solve(item *a, int n, int p_val, int m, int x[], int i, float *final_res){
    for(int j = min(a[i].max_qty, m/a[i].w); j >= 0; j--){
        float cur_val, remain, ubound;
        cur_val= p_val + j*a[i].v;
        remain = m - j*a[i].w;
        ubound = cur_val;
        if (i < n - 1) {
            ubound += remain * a[i+1].ppu;
        }

        if(ubound > *final_res){
            x[i] = j;           
            if((i == n-1 || remain == 0) && cur_val > *final_res){
                *final_res = cur_val;
                for(int k = 0; k < n; k++){
                    a[k].qty = x[k];
                }       
            }
            else if (i < n - 1) {
                solve(a, n, cur_val, remain, x, i+1, final_res);
            }
        }       
        x[i] = 0;   
    }
}

int main (){
    item *a;
    int n, m;
    int x[MAX_N] = {0}; 
    float final_res = 0;
    
    readFile(&a, &n, &m);   
    sort(a, n); 
    solve(a, n, 0, m, x, 0, &final_res);
    printChart(a, n, m);
    
    free(a); 
    return 0;
}
//BALO3
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAX_N 100

typedef struct {
    int w, v, qty;
    float ppu; 
    char name[25];  
} item;

void swap (item *a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void sort (item *a, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].ppu < a[j].ppu)
                swap(&a[i], &a[j]);
}

void readFile (item **a, int *n, int *m){
    FILE *f = fopen("CaiBalo3.txt", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file CaiBalo3.txt\n");
        exit(1);
    }
    
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    

    while (1){
        (*a) = (item*)realloc(*a, sizeof(item)*(i+1));
        int scan_count = fscanf(f, "%d %d %[^\n]", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        if (scan_count == 3) {
            (*a)[i].ppu = (float)(*a)[i].v / (*a)[i].w;
            (*a)[i].qty = 0;
            i++;
        } else {
            break;
        }
    }
    *n = i;
    fclose(f); 
}

void printChart (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
    printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
    for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].ppu, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
    }   
    printf("|---|---------------------|-----------|-------|-------|---------|\n");  
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(int i=0; i<n-1; i++){
        printf("%d,", a[i].qty);
    }   
    printf("%d)\n", a[n-1].qty);
    printf("Trong luong cua ba lo = %5d\n",m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void solve(item *a, int n, int p_val, int m, int x[], int i, float *final_res){
    for(int j = (m/a[i].w > 0 ? 1 : 0); j >= 0; j--){
        float cur_val, remain, ubound;
        cur_val = p_val + j*a[i].v;
        remain = m - j*a[i].w;
        ubound = cur_val;
        if (i < n - 1) {
            ubound += remain * a[i+1].ppu;
        }

        if(ubound > *final_res){
            x[i] = j;           
            if((i == n-1 || remain == 0) && cur_val > *final_res){
                *final_res = cur_val;
                for(int k = 0; k < n; k++){
                    a[k].qty = x[k];
                }       
            }
            else if (i < n - 1) {
                solve(a, n, cur_val, remain, x, i+1, final_res);
            }
        }       
        x[i] = 0;   
    }
}

int main (){
    item *a;
    int n, m;
    int x[MAX_N] = {0}; 
    float final_res = 0;
    
    readFile(&a, &n, &m);
    sort(a, n);
    solve(a, n, 0, m, x, 0, &final_res);
    printChart(a, n, m);
    
    free(a); 
    return 0;
}
//TSP
#include <stdio.h>
#include <stdlib.h> 
#define MAX_N 100
#define INF 3.4e38 

typedef struct {
    float length;
    int first, last, mark;
} Edge;

typedef struct {
    int n;
    Edge E[MAX_N][MAX_N];
} Graph;

void readFile(Graph *G){
    FILE *f = fopen("TSP.TXT", "r");
    if (f == NULL) {
        printf("Loi khong the mo file TSP1.txt\n");
        exit(1);
    }
    fscanf(f,"%d", &G->n);
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            fscanf(f, "%f", &G->E[i][j].length);
            G->E[i][j].first = i;
            G->E[i][j].last  = j;
            G->E[i][j].mark  = 0;
        }
    }
    fclose(f);
}

void printGraph(Graph *G){
    printf("Ma tran trong so cua do thi:\n");
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            printf(" %c%c =%5.2f  ", G->E[i][j].first+97, G->E[i][j].last+97, G->E[i][j].length);
        }
        printf("\n");
    }
}

void printResult(Edge x[], int n){
    printf("\nPhuong an tim duoc:\n");
    for(int i = 0; i < n; i++){
        printf("  Canh %c%c = %5.2f\n", x[i].first+97, x[i].last+97, x[i].length);        
    }
    float sum = 0;
    printf("Chu trinh:\n  ");
    for(int i = 0; i < n; i++){
        printf("%c -> ", x[i].first+97);
        sum += x[i].length;
    }
    printf("%c\n", x[0].first+97);
    printf("Tong do dai cac canh cua chu trinh = %5.2f\n\n", sum);
}

int isCycle(Edge x[], int n, int next){
    for(int i = 0; i < n; i++){
        if(next == x[i].first)
            return 1;
    }
    return 0;
}

float lowerBound(Graph *G, float cost, int level){
    float min_Edge = INF;
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            if(i != j && !G->E[i][j].mark && G->E[i][j].length < min_Edge)
                min_Edge = G->E[i][j].length;
        }
    }
    return cost + (G->n - level) * min_Edge;
}

Edge result[MAX_N];

void updateResult(Graph *G, float cost, float *final_cost, Edge x[]){
    int n = G->n;
    x[n-1] = G->E[x[n-2].last][x[0].first];
    cost += x[n-1].length;
    
    if(cost < *final_cost){
        *final_cost = cost;
        for(int i = 0; i < n; i++){
            result[i] = x[i];
        }
    }
}

void solve(Graph *G, int i, int current, float p_cost, float *final_cost, Edge x[]){    
    int n = G->n;
    for(int next = 0; next < n; next++){
        if(current != next && !G->E[current][next].mark && !isCycle(x, i, next)){
            float cost, lbound;
            cost = p_cost + G->E[current][next].length;
            lbound = lowerBound(G, cost, i+1);
            
            if(lbound < *final_cost){
                x[i] = G->E[current][next];
                G->E[current][next].mark = 1;
                G->E[next][current].mark = 1; 
                
                if(i == n - 2)
                    updateResult(G, cost, final_cost, x);
                else
                    solve(G, i+1, next, cost, final_cost, x);
            }
            G->E[current][next].mark = 0;
            G->E[next][current].mark = 0;
        }
    }
}

void reset(Graph *G){
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            G->E[i][j].mark = 0;
        }
    }
}

int main(){
    Graph G;
    readFile(&G);    
    printf("TSP su dung thuat toan NHANH CAN:\n\n");
    Edge x[MAX_N];    
    
    while(1){
        printGraph(&G);
        reset(&G);
        float final_cost = INF;
        char s;
        do {
            printf("Chon thanh pho xuat phat (tu a den %c): ", 'a' + G.n - 1);
            scanf(" %c", &s);
        } while (s < 'a' || s >= 'a' + G.n);
        
        solve(&G, 0, s - 97, 0, &final_cost, x);
        
        if (final_cost == INF) {
            printf("\nKhong tim thay chu trinh!\n\n");
        } else {
            printResult(result, G.n);        
        }
        
        do {
            printf("Tiep tuc (Y/N)? ");
            scanf(" %c", &s);
            if(s == 'n' || s == 'N')
                return 0;
        } while(s != 'y' && s != 'Y');
        
        printf("\n-------------------------\n");
    }
    return 0;        
}
// QUY HOACH DONG
// BALO1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w, v, qty;
    char name[25];  
} item;

typedef int table[50][100];

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("CaiBalo1.TXT", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file CaiBalo1.TXT\n");
        exit(1);
    }
    
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    

    while (1){
        (*a) = (item*)realloc(*a, sizeof(item)*(i+1));
        int scan_count = fscanf(f, "%d %d %[^\n]", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        if (scan_count == 3) {
            (*a)[i].qty = 0;
            i++;
        } else {
            break;
        }
    }
    *n = i;
    fclose(f);
}

void printResult (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("Phuong an Cai balo 1 su dung Quy hoach dong:\n");
    printf("|---|---------------------|-----------|-------|---------|\n");
    printf("|%-3s|%-21s|%-11s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Phuong an");
    printf("|---|---------------------|-----------|-------|---------|\n");
    for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
    }   
    printf("|---|---------------------|-----------|-------|---------|\n");  
    printf("Trong luong cua ba lo = %5d\n", m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void createTable(item *a, int n, int m, table F, table X){
    for(int i = 0; i <= m; i++){
        X[0][i] = i/a[0].w;
        F[0][i] = X[0][i] * a[0].v;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            F[i][j] = F[i-1][j];
            X[i][j] = 0;
            
            int max_qty = j/a[i].w; 
            for(int k = 1; k <= max_qty; k++){
                if(k*a[i].v + F[i-1][j-k*a[i].w] > F[i][j]){
                    F[i][j] = k*a[i].v + F[i-1][j-k*a[i].w];
                    X[i][j] = k; 
                }
            }
        }
    }
}

void printHorizontalLine(int m) {
    printf("|---");
    for(int i = 0; i <= m; i++) printf("|-----");
    printf("|\n");
}

void printTable(int n, int m, table F, table X){
    printf("Bang quy hoach dong:\n");   
    printHorizontalLine(m);

    printf("|k\\V");
    for(int i = 0; i <= m; i++){    
        printf("|  %-3d", i);
    }           
    printf("|\n");
    printHorizontalLine(m);

    for(int i = 0; i < n; i++){
        printf("| %-2d", i);
        for(int j = 0; j <= m; j++){
            printf("|%2d %2d", F[i][j], X[i][j]);
        }
        printf("|\n");
    }
    printHorizontalLine(m);
    printf("\n");
}

void searchTable(item *a, int n, int m, table X){
    for(int i = n-1; i >= 0; i--){
        a[i].qty = X[i][m];
        m -= X[i][m]*a[i].w;
    }
}

int main (){
    int n = 0, m = 0;    
    item *a;
    table F, X;
    readFile(&a, &n, &m);
    createTable(a, n, m, F, X);
    printTable(n, m, F, X);
    searchTable(a, n, m, X);
    printResult(a, n, m);
    
    free(a);
    return 0;
}
//BALO2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w, v, qty, max_qty;
    char name[25];  
} item;

typedef int table[50][100];

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("CaiBalo2.TXT", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file CaiBalo2.TXT\n");
        exit(1);
    }
    
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    

    while (1){
        (*a) =(item*) realloc(*a, sizeof(item)*(i+1));

        int scan_count = fscanf(f, "%d %d %d %[^\n]", &(*a)[i].w, &(*a)[i].v, &(*a)[i].max_qty, (*a)[i].name);
        if (scan_count == 4) {
            (*a)[i].qty = 0;
            i++;
        } else {
            break;
        }
    }
    *n = i;
    fclose(f); 
}

void printResult(item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("Phuong an Cai balo 2 su dung Quy hoach dong:\n");
    printf("|---|---------------------|-----------|-------|--------|---------|\n");
    printf("|%-3s|%-21s|%-11s|%-7s|%-8s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "So luong", "Phuong an");
    printf("|---|---------------------|-----------|-------|--------|---------|\n");
    for(int i = 0, k = 1; i < n; i++){
        printf("| %-2d| %-20s|%11d|%7d|%8d|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].max_qty, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
    }   
    printf("|---|---------------------|-----------|-------|--------|---------|\n");
    

    printf("Phuong an (theo thu tu file dau vao): X(");
    for(int i=0; i<n-1; i++){
        printf("%d,", a[i].qty);
    }   
    printf("%d)\n", a[n-1].qty);
    printf("Trong luong cua ba lo = %5d\n", m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

int min(int a, int b){
    return a < b ? a : b;
}

void createTable(item *a, int n, int m, table F, table X){

    for(int i = 0; i <= m; i++){
        X[0][i] = min(i/a[0].w, a[0].max_qty);
        F[0][i] = X[0][i] * a[0].v;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            F[i][j] = F[i-1][j];
            X[i][j] = 0;
            int max_qty = min(j/a[i].w, a[i].max_qty); 
            for(int k = 1; k <= max_qty; k++){
                if(k*a[i].v + F[i-1][j-k*a[i].w] > F[i][j]){
                    F[i][j] = k*a[i].v + F[i-1][j-k*a[i].w];
                    X[i][j] = k;
                }
            }
        }
    }
}

void printHorizontalLine(int m) {
    printf("|---");
    for(int i = 0; i <= m; i++) printf("|-----");
    printf("|\n");
}

void printTable(int n, int m, table F, table X){
    printf("\nBang quy hoach dong:\n");   
    printHorizontalLine(m);
    printf("|k\\V");
    for(int i = 0; i <= m; i++){    
        printf("|  %-3d", i);
    }           
    printf("|\n");
    printHorizontalLine(m);
    for(int i = 0; i < n; i++){
        printf("| %-2d", i);
        for(int j = 0; j <= m; j++){
            printf("|%2d %2d", F[i][j], X[i][j]);
        }
        printf("|\n");
    }
    printHorizontalLine(m);
    printf("\n");
}

void searchTable(item *a, int n, int m, table X){
    for(int i = n-1; i >= 0; i--){
        a[i].qty = X[i][m];
        m -= X[i][m]*a[i].w;
    }
}

int main (){
    int n = 0, m = 0;    
    item *a;
    table F, X;
    readFile(&a, &n, &m);
    createTable(a, n, m, F, X);
    printTable(n, m, F, X);
    searchTable(a, n, m, X);
    printResult(a, n, m);
    free(a);
    
    return 0;
} 
 //BALO3
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w, v, qty;
    char name[25];  
} item;

typedef int table[50][100];

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("CaiBalo3.TXT", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file CaiBalo3.TXT\n");
        exit(1);
    }
    
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (1){
        (*a) =(item*) realloc(*a, sizeof(item)*(i+1));
        int scan_count = fscanf(f, "%d %d %[^\n]", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        if (scan_count == 3) {
            (*a)[i].qty = 0;
            i++;
        } else {
            break;
        }
    }
    *n = i;
    fclose(f);
}

void printResult (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("Phuong an Cai balo 3 su dung Quy hoach dong:\n");
    printf("|---|---------------------|-----------|-------|---------|\n");
    printf("|%-3s|%-21s|%-11s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Phuong an");
    printf("|---|---------------------|-----------|-------|---------|\n");
    for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
    }   
    printf("|---|---------------------|-----------|-------|---------|\n");  
    printf("Trong luong cua ba lo = %5d\n", m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void createTable(item *a, int n, int m, table F, table X){
    for(int i = 0; i <= m; i++){
        X[0][i] = (i >= a[0].w ? 1 : 0); 
        F[0][i] = X[0][i] * a[0].v;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            F[i][j] = F[i-1][j]; 
            X[i][j] = 0;
            if(j >= a[i].w && F[i][j] < a[i].v + F[i-1][j-a[i].w]){
                F[i][j] = a[i].v + F[i-1][j-a[i].w];
                X[i][j] = 1;                
            }
        }
    }
}

void printHorizontalLine(int m) {
    printf("|---");
    for(int i = 0; i <= m; i++) printf("|-----");
    printf("|\n");
}

void printTable(int n, int m, table F, table X){
    printf("Bang quy hoach dong:\n");   
    printHorizontalLine(m);

    printf("|k\\V");
    for(int i = 0; i <= m; i++){    
        printf("|  %-3d", i);
    }           
    printf("|\n");
    printHorizontalLine(m);
    for(int i = 0; i < n; i++){
        printf("| %-2d", i);
        for(int j = 0; j <= m; j++){
            printf("|%2d %2d", F[i][j], X[i][j]);
        }
        printf("|\n");
    }
    printHorizontalLine(m);
    printf("\n");
}

void searchTable(item *a, int n, int m, table X){
    for(int i = n-1; i >= 0; i--){
        a[i].qty = X[i][m];
        m -= X[i][m]*a[i].w;
    }
}

int main (){
    int n = 0, m = 0;    
    item *a;
    table F, X;
    readFile(&a, &n, &m);
    createTable(a, n, m, F, X);
    printTable(n, m, F, X);
    searchTable(a, n, m, X);
    printResult(a, n, m);
    free(a);
    
    return 0;
}
//TAM GIAC SO
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50

void readFile(int a[][MAX_N], int *n){
    FILE *f = fopen("tam_giac_so.txt", "r");
    if (f == NULL) {
        printf("Loi: Khong the mo file tam_giac_so.txt\n");
        exit(1);
    }
    
    int i = 0;
    while (1){
        int success = 1;
        for(int j = 0; j <= i; j++){
            if (fscanf(f, "%d", &a[i][j]) != 1) {
                success = 0;
                break;
            }
        }
        if (!success) break;
        i++;
    }
    *n = i;
    fclose(f);
}

void printTriangle(int a[][MAX_N], int n){
    printf("Tam giac so da cho:\n");
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void printResult(int res[], int n){
    printf("\nPhuong an la duong di qua cac so: \n  ");
    int sum = 0; 
    for(int i = 0; i < n-1; i++){
        printf("%d -> ", res[i]);
        sum += res[i];
    }
    sum += res[n-1];
    printf("%d\n", res[n-1]);
    printf("Tong cac so tren duong di la: %d\n\n", sum);
}

int colIndex(int F[][MAX_N], int i, int j){
    if (j == 0) return 0;         
    if (j == i) return i - 1;
    if (F[i-1][j-1] > F[i-1][j]) {
        return j - 1;
    } else {
        return j;
    }
}

void createTable(int a[][MAX_N], int n, int F[][MAX_N]){
    F[0][0] = a[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            int k = colIndex(F, i, j);
            F[i][j] = F[i-1][k] + a[i][j];
        }
    }
}

void printTable(int F[][MAX_N], int n){
    printf("\nBang quy hoach dong:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%5d", F[i][j]);
        }
        printf("\n");
    }
}

void searchTable(int a[][MAX_N], int n, int F[][MAX_N], int res[]){
    int max = F[n-1][0], k = 0;
    for(int j = 1; j < n; j++){
        if(F[n-1][j] > max){
            max = F[n-1][j];
            k = j;
        }
    }
    for(int i = n-1; i >= 0; i--){
        res[i] = a[i][k];
        if (i > 0) {
            k = colIndex(F, i, k);
        }
    }       
}

int main(){
    int a[MAX_N][MAX_N], n = 0, F[MAX_N][MAX_N], res[MAX_N];
    readFile(a, &n);
    printTriangle(a, n);

    createTable(a, n, F);
    printTable(F, n);

    searchTable(a, n, F, res);
    printResult(res, n);
    
    return 0;
} 
 
 

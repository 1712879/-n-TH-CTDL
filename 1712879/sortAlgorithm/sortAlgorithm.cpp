#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include <time.h>
#define N 24
#define M 13

using namespace std;

//----Thuat Toan selectionSort
void hoanVi(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void selectionSort(int* a, int n){

	int idMin;
	for (int i = 0; i < n - 1; i++)
	{
		idMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[idMin])
			{
				idMin = j;
			}
		}
		hoanVi(a[i], a[idMin]);
	}
}

//---- Thuat Toan insertionSort
void insertionSort(int* a, int n){
	int j, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

//---Thuat Toan binaryinsertionSort
int binarySearch(int* a, int x, int l, int r){
	if (r <= l){
		return (x > a[l]) ? (l + 1) : l;
	}
	// mid: phan tu o giua l & r
	int mid = (l + r) / 2;
	if (x == a[mid]){
		return mid + 1;
	}
	if (x > a[mid]){
		return binarySearch(a, x, mid + 1, r);
	}
	return binarySearch(a, x, l, mid - 1);
}
void binaryinsertionSort(int* a, int n){
	int j, x, y;
	for (int i = 1; i < n; ++i)
	{
		j = i - 1;
		x = a[i];
		y = binarySearch(a, x, 0, j);
		while (j >= y)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

//--- Thuat Toan interchangeSort
void interchangeSort(int a[], int n){
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				hoanVi(a[i], a[j]);
			}
		}
	}
}

//--- Thuat Toan bubbleSort
void bubbleSort(int a[], int n)
{
	int i, j;
	bool temp;
	for (i = 0; i < n - 1; i++)
	{
		temp = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				hoanVi(a[j], a[j + 1]);
				temp = true;
			}
		}
		if (!temp){
			break;
		}
	}
}

//--- Thuat Toan shakerSort
void shakerSort(int a[], int n)
{
	int l = 0;
	int r = n - 1;
	int k = 0;
	while (l < r)
	{
		for (int i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		r = k;
		for (int i = r; i > l; i--)
		{
			if (a[i] < a[i - 1])
			{
				hoanVi(a[i], a[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}

//--- Thuat Toan shellSort
void shellSort(int a[], int n)
{
	int j, x;
	for (int mid = n / 2; mid > 0; mid /= 2)
	{
		for (int i = mid; i < n; i += 1)
		{
			int x = a[i];
			for (j = i; j >= mid && a[j - mid] > x; j -= mid)
			{
				a[j] = a[j - mid];
			}
			a[j] = x;
		}
	}
}

//--- Thuat Toan heapSort
void heap(int arr[], int n, int i)
{
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[max])
	{
		max = l;
	}

	if (r < n && arr[r] > arr[max])
	{
		max = r;
	}

	if (max != i)
	{
		hoanVi(arr[i], arr[max]);
		heap(arr, n, max);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		hoanVi(a[0], a[i]);
		heap(a, i, 0);
	}
}

//---- Thuat Toan mergeSort
void pre_merge(int a[], int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;;
	// Tao 2 mang A & B phu
	int* A = new int[n1];
	int* B = new int[n2];

	for (i = 0; i < n1; i++)
	{
		A[i] = a[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		B[j] = a[m + 1 + j];
	}

	i = j = 0; k = l;
	while (i < n1 && j < n2)
	{
		if (A[i] <= B[j])
		{
			a[k] = A[i];
			i++;
		}
		else
		{
			a[k] = B[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = A[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = B[j];
		j++;
		k++;
	}
	delete[] A, B;
}

void mergeSort(int a[], int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = l + (r - l) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);

		pre_merge(a, l, mid, r);
	}
}

//---- Thuat Toan quickSort
void QuickSort(int a[], int left,int right){
	int i, j, x;

	if (left >= right)
	{
		return;
	}

	x = a[(left + right) / 2];
	i = left;
	j = right;
	
	while (i < j)
	{
		while (a[i] < x){
			i++;
		}

		while (a[j] > x)
		{
			j--;
		}

		if (i <= j)
		{
			hoanVi(a[i], a[j]);
			i++;
			j--;
		}
	}

	QuickSort(a, left, j);
	QuickSort(a, i, right);
}
//---- Thuat Toan countingSort
int findMax(int a[], int n);

void countingSort(int a[], int n)
{
	int max = findMax(a, n) + 1;
	int* c = new int[max];
	for (int i = 0; i < max; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	for (int i = 1; i < max; i++)
	{
		c[i] += c[i - 1];
	}

	int *b = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		b[--c[a[i]]] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
	delete[] b;
	delete[] c;
}

//---- Thuat Toan radixSort
int findMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void cntSort(int a[], int n, int x)
{
	int* temp = new int[n];
	int i, C[10] = { 0 };
	for (i = 0; i < n; i++)
	{
		C[(a[i] / x) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		C[i] += C[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		temp[C[(a[i] / x) % 10] - 1] = a[i];
		C[(a[i] / x) % 10]--;
	}
	//Gan lai vao mang da sap xep
	for (i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}
	delete[] temp;
}

void radixsort(int a[], int n)
{
	int max = findMax(a, n);

	for (int x = 1; max / x > 0; x = x * 10)
	{
		cntSort(a, n, x);
	}
}

//---- Thuat Toan flashSort
void flashSort(int a[], int n){
	int i, j, k, t;
	i = j = k = 0;
	int m = (int)(n * 0.45);
	int* l = new int[m];

	int min = a[0];
	int idmax = 0;
	int idmove = 0;

	for (i = 1; i < n; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > a[idmax])
		{
			idmax = i;
		}
	}

	if (min == a[idmax])
	{
		return;
	}

	int c1 = (m - 1) / (a[idmax] - min);

	for (k = 0; k < m; k++)
	{
		l[k] = 0;
	}
	for (j = 0; j < n; j++)
	{
		k = (int)(c1 * (a[j] - min));
		++l[k];
	}

	for (int p = 1; p < m; ++p)
	{
		l[p] = l[p] + l[p - 1];
	}

	int hold = a[idmax];
	a[idmax] = a[0];
	a[0] = hold;

	idmove = 0; int flash;
	j = 0; k = m - 1;
	while (idmove < (n - 1))
	{
		while (j >(l[k] - 1)){
			++j;
			k = (int)(c1 * (a[j] - min));
		}
		if (k < 0)
		{
			break;
		}

		flash = a[j];
		while (j != l[k])
		{
			k = (int)(c1 * (flash - min));
			hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++idmove;
		}
	}

	for (j = 1; j < n; j++)
	{
		hold = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > hold)
		{
			a[i + 1] = a[i--];
		}
		a[i + 1] = hold;
	}

}

// Ghi du lieu truoc & sau khi sap xep
void ghiDuLieu(string sortAlg, int state, string kieu, int a[], int size){
	string s;
	switch (state)
	{
	case 1:
		s = "sorted";
		break;
	case 2:
		s = "reversed";
		break;
	case 3:
		s = "random";
		break;
	case 4:
		s = "nearly sorted";
		break;
	default:
		break;
	}
	ostringstream strSize;
	strSize << size;
	ofstream fp(sortAlg + s + "_" + strSize.str() + kieu);
	for (int i = 0; i < size; i++)
	{
		fp << a[i] << " ";
	}
	fp.close();
}

// Ghi ket qua vao Result.csv
void ghiKetQua(double a[N][M]){
	ofstream fp("Result.csv"); int hang;
	fp << "Input State,Input Size,Selection,Insertion, Binary Insertion,Interchange,Bubble,Shaker,Shell,Heap,Merge,Quick,Counting,Radix,Flash\n";
	for (int j = 1; j < 5; j++)
	{
		switch (j)
		{
		case 1:
			hang = 0;
			break;
		case 2:
			hang = 6;
			break;
		case 3:
			hang = 12;
			break;
		case 4:
			hang = 18;
			break;
		default:
			break;
		}
		for (int i = 1; i < 7; i++)
		{
			switch (j)
			{
			case 1:
				fp << "sorted,";
				break;
			case 2:
				fp << "reversed,";
				break;
			case 3:
				fp << "random,";
				break;
			case 4:
				fp << "nearly sorted,";
				break;
			default:
				break;
			}

			switch (i)
			{
			case 1:
				fp << "1000";
				break;
			case 2:
				fp << "5000";
				break;
			case 3:
				fp << "10000";
				break;
			case 4:
				fp << "50000";
				break;
			case 5:
				fp << "100000";
				break;
			case 6:
				fp << "250000";
				break;
			default:
				break;
			}
			for (int k = 0; k < 13; k++)
			{
				fp << "," << a[hang][k];
			}
			hang++;
			fp << "\n";
		}
	}
}

// Tao mang co thu tu
void sorted(int a[], int n){
	for (int i = 1; i < n + 1; i++)
	{
		a[i - 1] = i;
	}
}

//Tao mang co thu tu nguoc
void reversed(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = n - i;
	}
}

//Tao mang ngau nhien
void random(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n + 1;
	}
}

//Tao mang gan nhu co thu tu
void nearly_sorted(int a[], int n){
	random(a, n);
	for (int i = 1; i < (int)(n / 3); i++)
	{
		a[i] = i;
	}
}

// Menu chon size cua mang
int chonSize(int &size){
	int n, i;
	do
	{
		cout << " 1. Size n = 1.000\n";
		cout << " 2. Size n = 5.000\n";
		cout << " 3. Size n = 10.000\n";
		cout << " 4. Size n = 50.000\n";
		cout << " 5. Size n = 100.000\n";
		cout << " 6. Size n = 250.000\n";
		cout << "chon kich co du lieu: ";
		cin >> i;
		switch (i)
		{
		case 1:
			n = 1000;
			break;
		case 2:
			n = 5000;
			break;
		case 3:
			n = 10000;
			break;
		case 4:
			n = 50000;
			break;
		case 5:
			n = 100000;
			break;
		case 6:
			n = 250000;
			break;
		default:
			break;
		}
		if (i > 0 && i < 7)
		{
			size = i;
			break;
		}
	} while (true);
	return n;
}
//Menu chon tinh trang du lieu
int chonState(int a[], int n){
	int i;
	do
	{
		cout << " 1. sorted - Co thu tu\n";
		cout << " 2. reversed - Co thu tu nguoc\n";
		cout << " 3. random - Ngau nhien\n";
		cout << " 4. nearly sorted - Gan nhu co thu tu\n";
		cin >> i;
		switch (i)
		{
		case 1:
			sorted(a, n);
			break;
		case 2:
			reversed(a, n);
			break;
		case 3:
			random(a, n);
			break;
		case 4:
			nearly_sorted(a, n);
			break;
		default:
			break;
		}
		if (i > 0 && i < 5)
		{
			break;
		}
	} while (true);
	return i;
}

//luu thoi gian vao mang 2 chieu
void xuatKetQua(double a[N][M], int sortAlg, int state, int size, double x){
	switch (state)
	{
	case 1:
		state = -1;
		break;
	case 2:
		state = 5;
		break;
	case 3:
		state = 11;
		break;
	case 4:
		state = 17;
		break;
	default:
		break;
	}

	a[state + size][sortAlg - 1] = x;
}
//Hien thi thoi gian ra man hinh
void hienThiThoiGian(string sortAlg, int size, double time){
	ostringstream strSize;
	strSize << size;
	cout << "\n------------------------\n";
	cout << "Thoat Toan: " << sortAlg << " - Size: " << strSize.str() << endl;
	cout << "Thoi Gian Chay: " << time << endl;
	cout << "------------------------\n";
}
void chay(int* &a){
	int size, i; double result[N][M] = { 0 };
	double total; int* b;
	string s;  clock_t start, end;
	do
	{
		int n = chonSize(size);
		a = new int[n];
		int state = chonState(a, n);
		b = new int[n];
		for (int i = 0; i < n; i++)
		{
			b[i] = a[i];
		}
		ghiDuLieu("", state, ".inp", a, n);
		for (i = 1; i < 14; i++)
		{
			for (int k = 0; k < n; k++)
			{
				a[k] = b[k];
			}
			switch (i)
			{
			case 1:
				start = clock();
				selectionSort(a, n);
				end = clock();
				s = "selectionSort";
				ghiDuLieu("selectionSort_", state, ".out", a, n);
				break;
			case 2:
				start = clock();
				insertionSort(a, n);
				end = clock();
				s = "insertionSort";
				ghiDuLieu("insertionSort_", state, ".out", a, n);
				break;
			case 3:
				start = clock();
				binaryinsertionSort(a, n);
				end = clock();
				s = "binaryinsertionSort";
				ghiDuLieu("binaryinsertionSort_", state, ".out", a, n);
				break;
			case 4:
				start = clock();
				interchangeSort(a, n);
				end = clock();
				s = "interchangeSort";
				ghiDuLieu("interchangeSort_", state, ".out", a, n);
				break;
			case 5:
				start = clock();
				bubbleSort(a, n);
				end = clock();
				s = "bubbleSort";
				ghiDuLieu("bubbleSort_", state, ".out", a, n);
				break;
			case 6:
				start = clock();
				shakerSort(a, n);
				end = clock();
				s = "shakerSort";
				ghiDuLieu("shakerSort_", state, ".out", a, n);
				break;
			case 7:
				start = clock();
				shellSort(a, n);
				end = clock();
				s = "shellSort";
				ghiDuLieu("shellSort_", state, ".out", a, n);
				break;
			case 8:
				start = clock();
				heapSort(a, n);
				end = clock();
				s = "heapSort";
				ghiDuLieu("heapSort_", state, ".out", a, n);
				break;
			case 9:
				start = clock();
				mergeSort(a, 0, n - 1);
				end = clock();
				s = "mergeSort";
				ghiDuLieu("mergeSort_", state, ".out", a, n);
				break;
			case 10:
				start = clock();
				QuickSort(a, 0, n - 1);
				end = clock();
				s = "quickSort";
				ghiDuLieu("quickSort_", state, ".out", a, n);
				break;
			case 11:
				start = clock();
				countingSort(a, n);
				end = clock();
				s = "countingSort";
				ghiDuLieu("countingSort_", state, ".out", a, n);
				break;
			case 12:
				start = clock();
				radixsort(a, n);
				end = clock();
				s = "radixsort";
				ghiDuLieu("radixsort_", state, ".out", a, n);
				break;
			case 13:
				start = clock();
				flashSort(a, n);
				end = clock();
				s = "flashsort";
				ghiDuLieu("flashsort_", state, ".out", a, n);
				break;
			default:
				break;
			}
			total = ((double)(end - start)) / CLOCKS_PER_SEC;
			xuatKetQua(result, i, state, size, total);
			hienThiThoiGian(s, n, total);
		}
		cout << "chon 0. Thoat  /  1. Tiep Tuc\n";
		cin >> i;		
	} while (i != 0);
	ghiKetQua(result);
	delete[] b;
}

int main(){
	int* a;
	chay(a);
	delete[] a;
	return 0;
}
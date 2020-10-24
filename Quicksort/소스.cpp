/** pivot�� �迭�� ������ ���ҷ� ������ ��, ũ�⿡ ���� �־�� �� ���� �ڸ��� �̵� ��Ų ����,
pivot���� ���� ������ pivot�� ����, pivot���� ū������ pivot�� ���������� ��ġ�ϵ��� �����߽��ϴ� **/

#include <iostream>

using namespace std;

void qsort(int* arr, int start, int last) { // arr = �迭, start = ù��° index, last = ������ index
	if (start >= last) //���Ұ� 1�� ������ ���
	{
		return;
	}
	int pivot = arr[last];  // pivot = �迭�� ������ ����
	int i = start - 1; 
	int j = start; // j = Ž�� ���� ����
	int tmp = 0;
	for (; j < last; j++) { // j�� ù ��° ���Һ��� pivot����
		if (arr[j] <= pivot) { // arr[j] �� pivot���� ������ i������ pivot���� ���� �����̹Ƿ� i+1�� arr[j]�� ���� �߰�
			tmp = arr[j];  // a[i+1]�� a[j]�� �ٲ���
			arr[j] = arr[i + 1];
			arr[i + 1] = tmp;
			i =i+1; // i+1������ pivot���� �������̴� i�� i+1�� 
		}
	}
	tmp = arr[last]; //i+1�̶� pivot�� ���� �ٲ�
	arr[last] = arr[i + 1];
	arr[i + 1] = tmp;
	qsort(arr, start, i); // start~i+1, i+2~last �̷��� �ΰ��� �������� ���������Ƿ� 
	qsort(arr, i + 2, last);
	return;
}
int main() {
	int n; // ������ ����
	cout << "enter number of elements";
	cin >> n;
	int* arr; //�迭
	arr = (int*)malloc(sizeof(int) * n); //�迭 ũ��
	for (int i = 0; i < n; i++) { //�迭 �Է�
		cout << "enter element for array";
		cin >> arr[i];
	}
	qsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) { //�迭 ���
		cout << arr[i] << " ";
	}
	return 0;
}
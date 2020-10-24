/** pivot을 배열의 마지막 원소로 지정한 후, 크기에 따라 있어야 할 원래 자리로 이동 시킨 다음,
pivot보다 작은 수들은 pivot의 왼쪽, pivot보다 큰수들은 pivot의 오른쪽으로 배치하도록 구현했습니다 **/

#include <iostream>

using namespace std;

void qsort(int* arr, int start, int last) { // arr = 배열, start = 첫번째 index, last = 마지막 index
	if (start >= last) //원소개 1개 이하일 경우
	{
		return;
	}
	int pivot = arr[last];  // pivot = 배열의 마지막 원소
	int i = start - 1; 
	int j = start; // j = 탐색 시작 원소
	int tmp = 0;
	for (; j < last; j++) { // j를 첫 번째 원소부터 pivot까지
		if (arr[j] <= pivot) { // arr[j] 가 pivot보다 작으면 i까지는 pivot보다 작은 수들이므로 i+1에 arr[j]를 새로 추가
			tmp = arr[j];  // a[i+1]과 a[j]를 바꿔줌
			arr[j] = arr[i + 1];
			arr[i + 1] = tmp;
			i =i+1; // i+1까지는 pivot보다 작은값이니 i를 i+1로 
		}
	}
	tmp = arr[last]; //i+1이랑 pivot을 서로 바꿈
	arr[last] = arr[i + 1];
	arr[i + 1] = tmp;
	qsort(arr, start, i); // start~i+1, i+2~last 이렇게 두개의 구간으로 나뉘어지므로 
	qsort(arr, i + 2, last);
	return;
}
int main() {
	int n; // 원소의 개수
	cout << "enter number of elements";
	cin >> n;
	int* arr; //배열
	arr = (int*)malloc(sizeof(int) * n); //배열 크기
	for (int i = 0; i < n; i++) { //배열 입력
		cout << "enter element for array";
		cin >> arr[i];
	}
	qsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) { //배열 출력
		cout << arr[i] << " ";
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<malloc.h>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

struct Node {
	int value;
	int absv;
	int index;
};

void handle(Node *a, Node *b);
int  max(int a, int b);
void addtostring(int w);
void addtostring(int flag, int sum);

string str = "";

int main() {
	int w = 0;
	
	//scanf("%d", &w);
	while(scanf("%d", &w) && w) {
		//printf("%d\n", w);
		addtostring(w);
		int size = w + 2;
		Node *arr;
		arr = (Node *) malloc (sizeof(Node) * size);
		while(NULL == arr) {
			arr = (Node *) malloc (sizeof(Node) * size);
		}
		int count   = 0;
		int current = 0;
		int flag    = 0;
		int sum     = 0;
		int index   = 0;

		int v = 0;
		int n = 0;
		//scanf("%d%d", &v, &n);

		while(scanf("%d%d", &v, &n) && !(v == 0 && n == 0)) {
			if(n >= 3 * w + 4) {
				//
				for(int i = 0; i < w + 2; i++) {
					current = count % (w + 2);
					if(count >= (w + 2)) {
						//
						if(0 == arr[current].index) {
							handle(arr + current, arr + (current + 1) % (w + 2));
							handle(arr + current, arr + (current + w) % (w + 2));
							handle(arr + current, arr + (current + w + 1) % (w + 2));
						} else if(w - 1 == arr[current].index) {
							handle(arr + current, arr + (current + w - 1) % (w + 2));
							handle(arr + current, arr + (current + w) % (w + 2));
						} else {
							handle(arr + current, arr + (current + 1) % (w + 2));
							handle(arr + current, arr + (current + w - 1) % (w + 2));
							handle(arr + current, arr + (current + w) % (w + 2));
							handle(arr + current, arr + (current + w + 1) % (w + 2));
						}
					
						//
						if(flag != arr[current].absv) {
						
							if(sum != 0) {
								//printf("%d %d\n", flag, sum);
								addtostring(flag, sum);
							}
							flag = arr[current].absv;
							sum = 1;
						} else {
							sum++;
						}
					}
					arr[current].value = v;
					arr[current].absv  = 0;
					arr[current].index = index;
					count++;
					index = (index + 1) % w;
					//count = (count + 1) % ((w + 2) * w);

				}
				int head = count % (w + 2);
				int total = w + 2;
				//total = count > w + 2 ? w + 2 : count;
				for(int i = 0; i < total; i++) {
					current = (head + i) % (w + 2);
					if(0 == arr[current].index) {
						if(i + 1 < total)
						handle(arr + current, arr + (current + 1) % (w + 2));
						if(i + w < total)
						handle(arr + current, arr + (current + w) % (w + 2));
						if(i + w + 1 < total)
						handle(arr + current, arr + (current + w + 1) % (w + 2));
					} else if(w - 1 == arr[current].index) {
						if(i + w - 1 < total)
						handle(arr + current, arr + (current + w - 1) % (w + 2));
						if(i + w < total)
						handle(arr + current, arr + (current + w) % (w + 2));
					} else {
						if(i + 1 < total)
						handle(arr + current, arr + (current + 1) % (w + 2));
						if(i + w - 1 < total)
						handle(arr + current, arr + (current + w - 1) % (w + 2));
						if(i + w < total)
						handle(arr + current, arr + (current + w) % (w + 2));
						if(i + w + 1 < total)
						handle(arr + current, arr + (current + w + 1) % (w + 2));
					}			
		 			if(flag != arr[current].absv) {
						if(sum != 0) {
							//printf("%d %d\n", flag, sum);
							addtostring(flag, sum);
						}
						flag = arr[current].absv;
						sum = 1;
					} else {
						sum++;
					}
					//count++;
					//count = (count + 1) % ((w + 2) * w);
				}	
				//printf("%d %d\n", flag, sum);

				//
				if(flag != 0) {
					printf("%d %d\n", flag, sum);
					flag = 0;
					sum = 0;
				} 
				sum = sum + n - (w * 2 + 4);
				index = (index + (n - (w * 2 + 4))) % w;
				count = 0;
				for(int i = 0; i < w + 2; i++) {
					current = count % (w + 2);
					arr[current].value = v;
					arr[current].absv  = 0;
					arr[current].index = index;
					count++;
					index = (index + 1) % w;
				}

			} else {
				for(int i = 0; i < n; i++) {
					current = count % (w + 2);
					if(count >= (w + 2)) {
						//
						if(0 == arr[current].index) {
							handle(arr + current, arr + (current + 1) % (w + 2));
							handle(arr + current, arr + (current + w) % (w + 2));
							handle(arr + current, arr + (current + w + 1) % (w + 2));
						} else if(w - 1 == arr[current].index) {
							handle(arr + current, arr + (current + w - 1) % (w + 2));
							handle(arr + current, arr + (current + w) % (w + 2));
						} else {
							handle(arr + current, arr + (current + 1) % (w + 2));
							handle(arr + current, arr + (current + w - 1) % (w + 2));
							handle(arr + current, arr + (current + w) % (w + 2));
							handle(arr + current, arr + (current + w + 1) % (w + 2));
						}
					
						//
						if(flag != arr[current].absv) {
						
							if(sum != 0) {
								addtostring(flag, sum);
								//printf("%d %d\n", flag, sum);
							}
							flag = arr[current].absv;
							sum = 1;
						} else {
							sum++;
						}
					}
					arr[current].value = v;
					arr[current].absv  = 0;
					arr[current].index = index;
					count++;
					index = (index + 1) % w;
					//count = (count + 1) % ((w + 2) * w);
				}
			}
			//scanf("%d%d", &v, &n);
		}
		int head = count % (w + 2);
		
		int total = 0;
		total = count >= (w + 2) ? (w + 2) : count;
		for(int i = 0; i < total; i++) {
			
			current = (head + i) % (w + 2);
			//printf("");
			if(0 == arr[current].index) {
				if(i + 1 < total)
				handle(arr + current, arr + (current + 1) % (w + 2));
				if(i + w < total)
				handle(arr + current, arr + (current + w) % (w + 2));
				if(i + w + 1 < total)
				handle(arr + current, arr + (current + w + 1) % (w + 2));
			} else if(w - 1 == arr[current].index) {
				if(i + w - 1 < total)
				handle(arr + current, arr + (current + w - 1) % (w + 2));
				if(i + w < total)
				handle(arr + current, arr + (current + w) % (w + 2));
			} else {
				if(i + 1 < total)
				handle(arr + current, arr + (current + 1) % (w + 2));
				if(i + w - 1 < total)
				handle(arr + current, arr + (current + w - 1) % (w + 2));
				if(i + w < total)
				handle(arr + current, arr + (current + w) % (w + 2));
				if(i + w + 1 < total)
				handle(arr + current, arr + (current + w + 1) % (w + 2));
			}			
 			if(flag != arr[current].absv) {
				if(sum != 0) {
					//printf("%d %d\n", flag, sum);
					addtostring(flag, sum);
				}
				flag = arr[current].absv;
				sum = 1;
			} else {
				sum++;
			}
			//count++;
			//count = (count + 1) % ((w + 2) * w);
		}	
		//printf("%d %d\n", flag, sum);
		addtostring(flag, sum);
		free(arr);
		arr = NULL;

		//printf("%d %d\n", v, n);
		addtostring(v, n);
		//scanf("%d", &w);	
	}
	//printf("%d\n", w);
	addtostring(w);
	cout<<str<<endl;
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void handle(Node *a, Node *b) {
	int absv = abs(a->value - b->value);
	a->absv = max(absv, a->absv);
	b->absv = max(absv, b->absv);
}

void addtostring(int w) {
	stringstream ss;
	string substr;
	ss<<w;
	ss>>substr;
	str += substr + "\n";
}

void addtostring(int flag, int sum) {
	stringstream s1;
	string       substr;
	s1<<flag;
	s1>>substr;
	str += substr + " ";
	stringstream s2;
	string       substr2;
	s2<<sum;
	s2>>substr2;
	str += substr2 + "\n";
}

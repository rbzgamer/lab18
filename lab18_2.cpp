#include<iostream>
#include<algorithm>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
	double x_max = max(R1->x,R2->x);
	double x_min = min(R1->x+R1->w,R2->x+R2->w);
	double y_min = min(R1->y,R2->y);
	double y_max = max(R1->y-R1->h,R2->y-R2->h);
	double L1 = x_min - x_max;
	double L2 = y_min - y_max;
	if(L1 < 0 || L2 < 0) return 0;
	else return L1*L2;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};	
	cout << overlap(&R1,&R2) << endl;	

	Rect R3 = {1,1,5,5};
	Rect R4 = {7,2,3,3};	
	cout << overlap(&R3,&R4) << endl;	

	Rect R5 = {-1,2,6.9,9.6};
	Rect R6 = {0,0,1.2,2.5};	
	cout << overlap(&R5,&R6) << endl;
}
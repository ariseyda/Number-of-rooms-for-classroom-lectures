#include<stdio.h>

//Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
//For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

struct lessons{
	int start;
	int end;
};
int main(){
	
	int n;
	printf("Enter number of classroom lecture:");
	scanf("%d",&n);
	
	struct lessons l[n];
	
	int i;
	for(i=0;i<n;i++){
		printf("Enter %d.th classroom lecture start and end times:",i+1);
		scanf("%d%d",&l[i].start,&l[i].end);
	}
	printf("\n[");
	for(i=0;i<n;i++){
		printf("(%d,%d)",l[i].start,l[i].end);
		if(i<n-1){
			printf(",");
		}
	}
	printf("]");
	
	int min=l[0].start;
	int end=l[0].end;
	for(i=1;i<n;i++){
		if(l[i].start<min){
			min=l[i].start;
			end=l[i].end;
		}
	}
	
	int count=1;
	for(i=0;i<n;i++){
		if(l[i].start!=min && l[i].start<end){
			count++;
		}
	}
	
	
	printf("\nThe minimum number of rooms required=%d",count);
	
	
	return 0;
}

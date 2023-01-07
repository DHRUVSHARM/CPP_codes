/*
Convex Hull
Send Feedback
Given a set of points in the plane, the Convex Hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format:
First line of input contains integer N, representing number of points.
Second line contains N space separated integers, which are the X coordinates.
Third line contains N space separated integers, which are the Y coordinates.
Constraints:
1 <= N <= 10^5
1 <= X[i] <= 10^4
1 <= Y[i] <= 10^4
Also input is given in such a way that the number of points on the hull doesn't exceed 50
Output Format:
Print the X coordinate and the Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Input:
5
2 1 7 9 7 
2 5 5 2 4 
Sample Output:
1 5
2 2
9 2
7 5
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class point{
public:
	double x;
	double y;

	point(){
		x=0;
		y=0;
	}
};

long double cross_product(point p , point q , point r){

	//pq vector
	double x1=q.x-p.x;
	double y1=q.y-p.y;

	//rq vector 
	double x2=q.x-r.x;
	double y2=q.y-r.y;

	/*long double ans=x1*y2;
    ans-=(y1*x2);
    */
    return x1*y2 - x2*y1;
}

int main(){

	int n;
	cin>>n; //number of points

	point * points=new point[n];

	for(int i=0;i<n;i++){
		cin>>points[i].x;
	}
	for(int i=0;i<n;i++){
		cin>>points[i].y;
	}

	vector<point> hull; //will store the final convex hull

	int left=0; //index of left most

	for(int i=1;i<n;i++){
		if(points[i].x < points[left].x){
			left=i;
		}
	}

	int p=left;

	do{
		hull.push_back(points[p]);
		int q=(p+1)%n;

		for(int i=0;i<n;i++){
			if(cross_product(points[p] , points[q] , points[i]) > 0){
				q=i;
			}
		}

		p=q;

	}while(p!=left);

	
    
	for(int i=0;i<hull.size();i++){
		cout<<hull[i].x<<" "<<hull[i].y<<endl;
	}

	return 0;
}
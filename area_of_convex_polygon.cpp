/*
Area Of Convex Polygon
Send Feedback
A convex polygon is a set of n vertices that are joined by n edges, such that no two edges intersect and all angles are less than 180 degrees. We can represent a polygon by listing all the vertices, starting at one vertex and following the edges until that vertex is reached again. Thus, element 0 in the array represents the first vertex. The first vertex is connected to the second vertex (element 1), the second vertex is connected to the third vertex (element 2) and so on. The last element represents the last vertex, which is connected to the first vertex.
Given the vertices of a polygon, return its exact area.
Note: Get the integer part of the area. (It can be long). So get your answer in double, and typecast it into long.
Input Format:
First line of input will contain T(number of test cases), each test case follows.
Line 1: Integer N denoting the number of points.
Next N lines will denote the N cordinates (x,y) in a anticlockwise order.
Constraints:
1 <= T <= 10^5
1 <= N <= 50
1 <= X <= Y <= 10^5
The given polygon is guranted to be convex.
Output Format:
For each test case, print the area of polygon in new line.
Sample Input 1:
1
4
1 5
2 2
9 2
7 5
Sample Output 1:
19
*/

#include<bits/stdc++.h>
#include<iostream>
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

class polygon{
public:
	point * points;
	polygon(int n){
		points=new point[n];
	}
};

double cross_product(point start , point first , point second){

	double x1=first.x-start.x;
	double y1=first.y-start.y;

	double x2=second.x-start.x;
	double y2=second.y-start.y;


/*	double x1=first.x-start.x;
	double y1=first.y-start.y;

	double x2=second.x-first.x;
	double y2=second.y-first.y;
*/
	return (x1*y2 - x2*y1);
}

//this works for concave polygons as well

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n; //number of points

		polygon p(n);

		/*for(int i=0;i<n;i++){
			cout<<p.points[i].x<<" "<<p.points[i].y<<'\n';
		}*/

		for(int i=0;i<n;i++){
			cin>>p.points[i].x>>p.points[i].y;
		}

		//now you have to take the cross product and add 

		double area=0;

		point start;
		start.x=p.points[0].x;
		start.y=p.points[0].y;

		for(int i=1;i<n-1;i++){
			area+=cross_product(start , p.points[i] , p.points[i+1]);
			//cout<<area/2<<endl;
		}

		cout<<(long)abs(area/2)<<'\n';

	}

	return 0;
}
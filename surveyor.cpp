/*Surveyor
Send Feedback
A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format:
First line of input contains a string s
Second line of input contains an array (space separated), with the length same as string s.
Constraints:
Direction string will have between 4 and 50 characters inclusive.
Length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Output Format:
For each input, print the area calculated.
Sample Test Case
NWWSE
10 3 7 10 10
Sample Ouput:
100
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
		points=new point[n]();
	}
};

double cross_product(point start , point first , point second){

	double x1=first.x-start.x;
	double y1=first.y-start.y;

	double x2=second.x-start.x;
	double y2=second.y-start.y;

	return x1*y2 - x2*y1;
}

int main(){

	string directions;
	cin>>directions;

	polygon p(directions.size());

	p.points[0].x=0;p.points[0].y=0;
	//starting point

	int n=directions.size();

	for(int i=0;i<n;i++){

		double len;cin>>len;

		if(directions[i]=='N'){
			p.points[(i+1)%n].x=p.points[i].x + 0;
			p.points[(i+1)%n].y=p.points[i].y + len;
		}
		else if(directions[i]=='W'){
			p.points[(i+1)%n].x=p.points[i].x - len;
			p.points[(i+1)%n].y=p.points[i].y + 0;
		}
		else if(directions[i]=='S'){
			p.points[(i+1)%n].x=p.points[i].x + 0;
			p.points[(i+1)%n].y=p.points[i].y - len;
		}
		else{
			//'E'
			p.points[(i+1)%n].x=p.points[i].x + len;
			p.points[(i+1)%n].y=p.points[i].y + 0;
		}
	}

	double area=0;
/*
	for(int i=0;i<n;i++){
		cout<<p.points[i].x<<" "<<p.points[i].y<<endl;
	}
*/

	point start;start.x=p.points[0].x;start.y=p.points[0].y;
	for(int i=1;i<n-1;i++){
		area+=cross_product(start , p.points[i] , p.points[i+1]);
	}

	cout<<(long)abs(area/2)<<'\n';

	return 0;

}
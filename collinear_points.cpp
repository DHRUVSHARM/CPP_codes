/*
Collinear Points
Send Feedback
You are given a set of 3 points in a 2-D plane. You have to find out whether they are collinear or not.
Input Format:
First line of input will contain T, representing the number of test cases.
Each test case contains three lines containing two space separated integers x and y, respectively, denoting the points in 2-D plane.
Constraints:
1 <= T <= 10^5
-10^6 <= x, y <= 10^6
Ouput Format:
For each test case output "YES" if they are collinear and "NO" if they are not.
Sample Input:
2
1 3
1 4
1 5
-1 0
 0 1
 1 0
Sample Output:
YES 
NO
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long double ld;

class point{
public:
    ld x;
    ld y;
    point(){
        x=0;
        y=0;
    }
};

ld cross_product(point p , point q , point r){

    //pq
    ld x1=q.x-p.x;
    ld y1=q.y-p.y;

    //rq
    ld x2=q.x-r.x;
    ld y2=q.y-r.y;


    return x1*y2-y1*x2;
}

int main(){

    int t;
    cin>>t;

    while(t--){

        point * points=new point[3]();
        for(int i=0;i<3;i++){
            cin>>points[i].x>>points[i].y;
        }

        if(cross_product(points[0] , points[1] , points[2]) == 0){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }

        delete[] points;
    }

    return 0;
}
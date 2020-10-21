// A C++ program to check if a given point lies inside a given polygon
#include <iostream>
#include <limits.h>
using namespace std;
struct Point
{
int x;
int y;
};
bool onSegment(Point p, Point q, Point r)
{
if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
return true;
else
return false;
}
int orientation(Point p, Point q, Point r)
{
int value = (q.y - p.y) * (r.x - q.x) -
(q.x - p.x) * (r.y - q.y);
if (value == 0) return 0; 
return (value > 0)? 1: 2; 
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
int o1 = orientation(p1, q1, p2);
int o2 = orientation(p1, q1, q2);
int o3 = orientation(p2, q2, p1);
int o4 = orientation(p2, q2, q1);
if (o1 != o2 && o3 != o4)
return true;
if (o1 == 0 && onSegment(p1, p2, q1)) return true;
if (o2 == 0 && onSegment(p1, q2, q1)) return true;
if (o3 == 0 && onSegment(p2, p1, q2)) return true;
if (o4 == 0 && onSegment(p2, q1, q2)) return true;
return false; 
}
bool isInside(Point polygon[], int n, Point p)
{
if (n < 3) return false;
Point extreme = {INT_MAX, p.y};
int count = 0;
for (int i = 0; i < n-1; i++)
{
if (p.x == polygon[i].x && p.y == polygon[i].y)
return true;
if (doIntersect(polygon[i], polygon[i+1], p, extreme))
count++;
}
if (p.x == polygon[n-1].x && p.y == polygon[n-1].y)
return true;
if (doIntersect(polygon[n-1], polygon[0], p, extreme))
count++;
return count&1;
}
int main()
{
Point polygon[] = {{-3, 2}, {-2, -0.8}, {0, 1.2}, {2.2, 0}, {2, 4.5}};
int n = sizeof(polygon)/sizeof(polygon[0]);
Point p = {0, 0};
isInside(polygon, n, p)? cout << "False \n": cout << "True \n";
return 0;
}

#ifndef POINT_H
#define POINT_H
class Point {
public :
	Point();
	Point(float x, float y=2.);
	void affiche (void) const;
	static void affichePointRef (void);
	void modPointRef (float x, float y);
	void translate (float x, float y);
	bool ok ();
	float distance () const;
    bool operator<(const Point&) const;
    	float operator[](int n);
	Point operator-(Point&);
private :
	float xP, yP;
	static Point PointRef;
};
#endif

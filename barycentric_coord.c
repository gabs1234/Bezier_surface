

float* barycentric_coord(float***Coord, float*** trig)
{
/*
Coord = tableau contenant l'abcisce et l'ordonnée du point 
trig = tableau contenant les coordonnées des 3 sommets du triangle 
*/
	float lambda[3];
	
	float det1, det2;
	
	det1 = ( (Coord[0]-trig[1][0])*(Coord[0]-trig[2][1]) ) - ((Coord[1]-trig[1][1])*(Coord[1]-trig[2][0]));
	det2 = ( (trig[0][0]-trig[1][0])* (trig[0][1]-trig[2][0]) ) - ( (trig[0]|1] - trig[1][1]) * (trig[0][0]-trig[2][0]));
	
	lambda[0] = det1/det2; // lambda_1
	
	det1 = ( (Coord[0]-trig[2][0])*(Coord[0]-trig[0][1]) ) - ((Coord[1]-trig[2][1])*(Coord[1]-trig[0][0]));
	det2 = ( (trig[1][0]-trig[2][0])* (trig[1][1]-trig[0][0]) ) - ( (trig[1]|1] - trig[2][1]) * (trig[1][0]-trig[1][0]));
	
	lambda[1] = det1/det2; // lambda_2
	
	det1 = ( (Coord[0]-trig[0][0])*(Coord[0]-trig[1][1]) ) - ((Coord[1]-trig[0][1])*(Coord[1]-trig[1][0]));
	det2 = ( (trig[2][0]-trig[1][0])* (trig[2][1]-trig[1][0]) ) - ( (trig[2]|1] - trig[0][1]) * (trig[2][0]-trig[1][0]));
	lambda[2] = det1/det2; // lambda_3
	
	return lambda; 
}

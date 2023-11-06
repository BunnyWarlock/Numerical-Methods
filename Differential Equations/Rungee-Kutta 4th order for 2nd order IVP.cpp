#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define endl '\n'
typedef long double ld;

// Express f(x, y, y') for the equation here
ld f(ld x, ld y, ld u){
	return (3+x)*exp(-2*x) - 4*u - 4*y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ld x, y, u, k1, k2, k3, k4, m1, m2, m3, m4, h, xDesired;
	int n, loop;

	// Initialize
	x = 0;
	y = 2;
	u = 5;
	h = 0.1;
	xDesired = 0.4;

	// Calculation of RK4
	loop = (xDesired-x)/h + 1e-9;
	cout<<fixed<<setprecision(10);
	for (n = 0; n < loop; ++n){
		m1 = h * u;
		k1 = h * f(x, y, u);
		m2 = h * (u + (k1/2));
		k2 = h * f(x+(h/2), y+(m1/2), u+(k1/2));
		m3 = h * (u + (k2/2));
		k3 = h * f(x+(h/2), y+(m2/2), u+(k2/2));
		m4 = h * (u + k3);
		k4 = h * f(x+h, y+m3, u+k3);
		
		y += (m1 + 2*m2 + 2*m3 + m4)/6;
		u += (k1 + 2*k2 + 2*k3 + k4)/6;
		x += h;
		
		cout<<"\t   (n = "<<n<<")"<<endl;
		cout<<"y ("<<x<<") = "<<y<<endl;
		cout<<"y'("<<x<<") = "<<u<<endl;
		cout<<"       m     \t       k"<<endl;
		cout<<m1<<" \t "<<k1<<endl;
		cout<<m2<<" \t "<<k2<<endl;
		cout<<m3<<" \t "<<k3<<endl;
		cout<<m4<<" \t "<<k4<<endl<<endl;
	}

    	return 0;
}

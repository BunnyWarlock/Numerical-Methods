#include <iostream>
#include <iomanip>
using namespace std;
#define endl '\n'
typedef long double ld;

// Express f(x, y) for the equation here
ld f(ld x, ld y){
	return 32 - (y*y)/20;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    	cout.tie(NULL);

	ld x, y, k1, k2, k3, k4, h, xDesired;
	int n, loop;

	// Initialize
	x = 0;
	y = 0;
	h = 0.2;
	xDesired = 1;

	// Calculation of RK4
	loop = (xDesired-x)/h + 1e-9;
	cout<<"n \t k1 \t\t k2 \t\t k3 \t\t k4 \t\t yn+1"<<endl;
	cout<<fixed<<setprecision(10);
	for (n = 0; n < loop; ++n){
		k1 = h * f(x, y);
		k2 = h * f(x+(h/2), y+(k1/2));
		k3 = h * f(x+(h/2), y+(k2/2));
		k4 = h * f(x+h, y+k3);
		y += (k1 + 2*k2 + 2*k3 + k4)/6;
		x += h;
		cout<<n<<"\t "<<k1<<"\t "<<k2<<"\t "<<k3<<"\t "<<k4<<"\t "<<y<<endl;
	}

	return 0;
}

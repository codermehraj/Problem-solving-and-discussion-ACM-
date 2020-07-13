/*
	Problem Name : Light OJ 1043 – Triangle Partitioning
	Problem Link : http://www.http://lightoj.com/volume_showproblem.php?problem=1043
	
	This one is a binary search problem 
	Here you are given ab, bc, ca and the ratio 
	now you will search for ae in the range [0,ab]
	Be carefull at handeling the precisions
*/

/* CoderMehRaj */
#include <bits/stdc++.h>

using namespace std;

double ab, ac, bc, ae, de, rasio , init_area, sml_tri_area;

double get_area(double a, double b, double c){
	double s = (a+b+c)/2.0 , ans;
	ans = s * (s - a) * (s - b) * (s - c);
	return sqrt(ans);
}

double get_ratio(double ad){
	ae = (ad / ab) * ac;
	de = (ad / ab) * bc;
	sml_tri_area = get_area(ad, de, ae);
	return sml_tri_area / (init_area - sml_tri_area);
}

double getans(){
	double hi = ab , lo = 0.00, ans, loop = 200;
	while(loop--){
		ans = (hi+lo) / 2.00;
		if(get_ratio(ans) < rasio) lo = ans;
		else hi = ans;
	}
	return ans;
}

int main()
{
	int tc;
	cin >> tc;
	for(int i=1 ; i <= tc; i++){
		cin >> ab >> ac >> bc >> rasio;
		init_area  = get_area(ab, ac, bc);
		cout << "Case " << i << ": ";
		cout << fixed << setprecision(10) << getans() << endl;
	}
	return 0;
}

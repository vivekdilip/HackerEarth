#include <iostream>
#include <vector>
using namespace std;

void saveall(vector <int>&, int, int);

int main() {
	int N;
	double sum=0, suma=0, sumb=0, count=0;
	vector <int> sv;
	cin >> N;
	double A[N];
	for(int i=0; i<N; i++)
	{
		cin >> A[i];
		sum=sum+A[i];
	}
	for(int i=0; i<N; i++)
	{
		suma=0;
		sumb=sum;
		double x, y;
		for(int j=i; j<N; j++)
		{
			suma+=A[j];
			sumb-=A[j];
			if((N-(j-i)-1)<=0)
			x=0;
			else
			x=(sumb)/(N-(j-i)-1);
			y=((suma)/(j-i+1));
			//cout << "++suma=" << y << "++sumb=" << x << "|||";
			if(y>x)
			{
				//cout << "calling saveall\n";
				saveall(sv, i, j);
				count++;
			}
		}
		//cout << '\n';
	}
	cout << count << '\n';
	for(int i=0; i<sv.size(); i++)
	{
		if(sv[i]==0)
		cout << '\n';
		else
		cout << sv[i] << " ";
	}
	return 0;
}

void saveall(vector <int>& sv, int st, int ed){
	
	sv.push_back(st+1);
	sv.push_back(ed+1);
	sv.push_back(0);
}
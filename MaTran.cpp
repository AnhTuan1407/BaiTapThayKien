#include<iostream>
#include<fstream>
using namespace std;

void nhapMang(int a[100][100], int n, int m)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout << "a["<<i<<"]["<<j<<"]: ";
			cin >> a[i][j]; 
		}
	}
}

void xuatMang(int a[100][100], int n, int m)
{
		for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout << a[i][j] << " "; 
		}
		cout << "\n";
	}
}

void fileIn(int a[100][100], int n, int m)
{
	ifstream fileIn;
	fileIn.open("C:\\Users\\PC\\Desktop\\INPUT.txt");
	if(fileIn.is_open())
	{
		cout << "Mo file thanh cong!" << endl;
		while(!fileIn.eof())
		{
			for (int i=0; i<n; i++)
			{
				for (int j=0; j<m; j++)
				{
					cout << "a["<<i<<"]["<<j<<"]: ";
					fileIn >> a[i][j]; 
				}	
			}
		}
	fileIn.close();
}else
	cout << "Deo mo duoc file!" << endl;
}

void fileOut(int a[100][100], int n, int m)
{
	ofstream fileOut;
	fileOut.open("C:\\Users\\PC\\Desktop\\OUTPUT");
	if(fileOut.is_open())
	{
		cout << "Mo file thanh cong!" << endl;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				fileOut << a[i][j] << " "; 
			}
		fileOut<< "\n";
		}
		fileOut.close();
	}else 
		cout << "Deo mo duoc file!" << endl;
}

void doiSo(int a[100][100], int n, int m)
{
	int q, p, x;
	cout << "Nhap hang muon thay doi: ";
	cin >> q;
	cout << "Nhap cot muon thay doi: ";
	cin >> p;
	cout << "Nhap so ban muon thay doi: ";
	cin >> x;
	a[q][p] = x;
}

int main()
{
	int a[100][100];
	int n;
	int m;
	cout << "Nhap so hang: " << endl;
	cin >> n;
	cout << "Nhap so cot: " << endl;
	cin >> m;
	nhapMang(a, n, m);
	xuatMang(a, n, m);
	doiSo(a, n, m);
	xuatMang(a, n, m);
	fileOut(a, n, m);
//	fileIn(a, n, m);
	return 0;
}

#include <iostream>
using namespace std;
/*int MaxDuan(int*a, int**b, int n)
{
	int max = 0;
	int s = 0;
	int m = -1;
	for (int i = 0; i<n; i++)
	{
		s = a[i];
		b[i][0] = a[i];
		for (int j = i + 1; j<n; j++)
		{

			if (s + a[j]>max)
			{
				b[i][j] = a[j];
				s = s + a[j];
				max = s;
				m = i;
			}
		}
	}
	if (m == -1)
	{
		return 0;
	}
	cout << "最大子段:";
	for (int j = 0; j<n; j++)
	{
		if (b[m][j]>0)
		{
			cout << b[m][j] << " ";
		}
	}

	if (max <= 0)
	{
		return 0;
	}
	else
	{
		return max;
	}
}*/




int MaxDuan(int*a, int**b, int n)
{
	int max = 0;
	int s = 0;
	int m = -1;
	for (int i = 0; i < n; i++)
	{
		s = a[i];
		b[i][0] = a[i];
		for (int j = i + 1; j < n; j++)
		{
			s += a[j];
			b[i][j] = a[j];
			if (s > max)
			{
				max = s;
				m = i;
			}
		}
		/*if (s > max)
		{
			m = i;
			max = s;
		}*/
	}
	if(max<0)
	{
		return 0;
	}
	else
	{
		
		for (int j = 0; j< n; j++)
		{
			if(b[m][j]!= 0xffff)
			{
				cout << b[m][j] << " ";
			}
			
		}
		return max;
	}
	
}






int main()
{
	int n;
	cout << "输入序列长度" << endl;
	cin >> n;
	int *a = new int[n];
	int **b = new int*[n];
	cout << "输入序列元素" << endl;
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i<n; i++)
	{
		b[i] = new int[n];
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			b[i][j] = 0xffff;
		}
	}
	cout << endl;
	cout << "最大子段和" << MaxDuan(a, b, n) << endl;
	system("pause");
}
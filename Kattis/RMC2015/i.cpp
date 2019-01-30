//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool grid[10][10];

bool checker(int r, int c)
{
	vector<bool> rows;
	vector<bool> columns;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(grid[i][j])
			{
				rows.push_back(true);
				columns.push_back(true);
				break;
			}
		}
		rows.push_back(false);
		columns.push_back(false);
	}
	bool check[10][10] = {false};
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(rows[i] && columns[j])
				check[i][j] = true;
		}
	}
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(!(check[i][j] == grid[i][j]))
			{
				return false;
			}
		}
	}
	return true;
}

int main() {
	int T = 0;
	cin >> T;
	cout << T;
	bool cr[10][10];
	for(int t = 0; t < T; t++)
	{
		int r = 0;
		int c = 0;
		cin >> r >> c;
		for(int i = 0; i < r; i++)	
		{
			string row = "";
			getline(cin, row);
			for(int j = 0; j < c; j++)
			{
				grid[i][j] = row[j];
				if(row[j] == 0)
					cr[i][j] = 'N';
				else
					cr[i][j] = 'I';
			}
		}
		if(!checker(r, c))
		{
			cout << T << " : impossible" << endl;
		}
		else
		{
			for(int i = 0; i < r; i++)
			{
				int counter = 0;
				for(int j = 0; j < c; j++)
				{
					if(cr[i][j] == 'I')
						counter++;
				}
				if(counter == 1)
					for(int j = 0; j < c; j++)
					{
						if(cr[i][j] == 'I')
						{
							cr[i][j] = 'P';
							break;
						}
					}
			}
			for(int i = 0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
					cout << cr[i][j];
				cout << endl;
			}
		}
	}
	return 0;
}

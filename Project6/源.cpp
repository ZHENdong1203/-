#include<iostream>  
#include<fstream>
#include<vector>  
using namespace std;

void GameTable(vector<vector<int> > &vec) {
	if (vec.size() == 0) {
		return;
	}
	size_t s = vec.size();
	int k = 0;
	while (s = s >> 1) {
		//s = s >> 1;  
		k++;
	}

		//��ʼ��  
	vec[0][0] = 1;
	vec[0][1] = 2;
	vec[1][0] = 2;
	vec[1][1] = 1;

	for (int i = 2; i <= k; i++) {
		int length = 0x1 << i;
		int half = length >> 1;
		//���½ǵ��ӱ�����Ϊ���Ͻ��ӱ��Ӧ���half=2^(i-1)  
		for (int row = 0; row < half; row++) {
			for (int col = 0; col < half; col++) {
				vec[row + half][col] = vec[row][col] + half;
			}
		}
		//���Ͻǵ��ӱ�������½��ӱ�  
		for (int row = 0; row < half; row++) {
			for (int col = 0; col < half; col++) {
				vec[row][col + half] = vec[row + half][col];
			}
		}
		//���½ǵ��ӱ�������Ͻ��ӱ�  
		for (int row = 0; row < half; row++) {
			for (int col = 0; col < half; col++) {
				vec[row + half][col + half] = vec[row][col];
			}
		}
	}
}

int main(void) {

	ofstream outfile("f1.dat",ios::app);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	cout << "����2^k��ѡ�ֲμӱ���������k��k>0����" << endl;
	int k;
	do {
		cin >> k;
		outfile << k<<"\n";
	} while (k < 0 || k > 31);
	
	
	int s = 0x1 << k;
	vector<vector<int> > vec(s, vector<int>(s, 0));

	GameTable(vec);

	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < vec[i].size(); j++) {
			outfile << vec[i][j] << " ";
		}
		outfile << "\n";
	}
	
	outfile.close();
	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#define NIUW 8 //NIU's width for setw function
#define NAMAW 45 //Nama's width for setw function
#define PRODIW 40 //Prodi's width for setw function

struct Mahasiswa
{
public:
	Mahasiswa() = default;
	Mahasiswa(int& NIU, std::string& nama, std::string& prodi)
		:
		NIU(NIU),
		nama(nama),
		prodi(prodi)
	{}
	void Print() const
	{
		std::cout << std::setw(NIUW) << NIU << std::setw(NAMAW) << nama << std::setw(PRODIW) << prodi << '\n';
	}
	const int GetNIU() const
	{
		return NIU;
	}
private:
	int NIU;
	std::string nama;
	std::string prodi;
};

void merge(std::vector<Mahasiswa>& mhs, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<Mahasiswa> L(n1);
	std::vector<Mahasiswa> R(n2);

	for (i = 0; i < n1; i++)
		L[i] = mhs[l + i];
	for (j = 0; j < n2; j++)
		R[j] = mhs[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i].GetNIU() <= R[j].GetNIU())
		{
			mhs[k] = L[i];
			i++;
		}
		else
		{
			mhs[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		mhs[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		mhs[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<Mahasiswa>& mhs, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(mhs, l, m);
		mergeSort(mhs, m + 1, r);

		merge(mhs, l, m, r);
	}
}

int main()
{
	std::vector<Mahasiswa> mhs;
	std::string nama;
	std::string prodi;
	std::string strNIU;
	int intNIU;
	std::string tmp;
	std::ifstream in("prg9.csv");
	
	if (!in.is_open())
	{
		std::cout << "Failed load the file" << std::endl;
	}

	in.seekg(0, std::ios::end);
	int end = in.tellg();
	in.seekg(0, std::ios::beg);
	while (end != in.tellg()) //if 'in' is not reach the end of file
	{
		std::getline(in, tmp);
		std::stringstream ss(tmp);

		std::getline(ss, strNIU, ',');
		intNIU = std::stoi(strNIU);
		std::getline(ss, nama, ',');
		std::getline(ss, prodi, ',');
		mhs.push_back({ intNIU, nama, prodi });
	}
	in.close();

	//urut berdasarkan nama
	std::cout << std::setw(70) << "---URUT BERDASARKAN NAMA---" << '\n';
	std::cout << std::setw(NIUW) << "NIU" << std::setw(NAMAW) << "Nama" << std::setw(PRODIW) << "Prodi" << '\n';
	for (int i = 0; i < mhs.size(); i++)
	{
		mhs[i].Print();
	}

	//merge sort
	mergeSort(mhs, 0, mhs.size() - 1);
	std::cout << std::endl << std::endl;

	//urut berdasarkan niu
	std::cout << std::setw(70) << "---URUT BERDASARKAN NIU---" << '\n';
	std::cout << std::setw(NIUW) << "NIU" << std::setw(NAMAW) << "Nama" << std::setw(PRODIW) << "Prodi" << '\n';
	for (int i = 0; i < mhs.size(); i++)
	{
		mhs[i].Print();
	}
	
	mhs.clear();
	return 0;
}
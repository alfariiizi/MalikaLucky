#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#define NIUW 8
#define NAMAW 45
#define PRODIW 40

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

	std::cout << std::setw(NIUW) << "NIU" << std::setw(NAMAW) << "Nama" << std::setw(PRODIW) << "Prodi" << '\n';
	for (int i = 0; i < mhs.size(); i++)
	{
		mhs[i].Print();
	}
	
	mhs.clear();
	return 0;
}
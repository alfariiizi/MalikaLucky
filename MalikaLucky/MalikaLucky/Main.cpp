#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
	std::ifstream in("prg9.csv");
	
	if (!in.is_open())
	{
		std::cout << "Failed load the file" << std::endl;
	}
	while (in.good())
	{
		std::getline(in, strNIU, ',');
		intNIU = std::stoi(strNIU);
		std::getline(in, nama, ',');
		std::getline(in, prodi, ',');
		mhs.push_back({ intNIU, nama, prodi });
	}

	return 0;
}
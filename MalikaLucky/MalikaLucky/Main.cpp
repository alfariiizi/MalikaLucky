#include <iostream>
#include <fstream>
#include <vector>

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

	return 0;
}
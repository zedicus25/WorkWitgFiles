#include "c_WorkFiles.h"

using std::cout;
using std::cin;
int main()
{
	std::auto_ptr<c_WorkFiles> file(new c_WorkFiles());
	file->setPath("Data.txt");
	file->print();
	cout << "--------------------------\n";
	cout << file->findString("Of") << "\n";
	cout << "--------------------------\n";
	file->replaseString("on", "ON");
	file->print();
	cout << "--------------------------\n";
	file->revert();
	file->print();
}
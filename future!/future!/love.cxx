#include"love.hxx"
int main()
{
	m3Library::initLibrary();
	m3Library::setTitle("love-past-and-future v3.0.");
	std::cout << "copyright(c)2019 momo,welcome fork it,but all rights reserved.\nif you want to reset the game ,delete \"log.log\" file." << std::endl;
	check();
	te();
	remember();

	menu();

	return 0;
}
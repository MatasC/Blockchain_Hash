#include "Time.h"
void Time::Start_clock()
{
	pradzia_ = std::chrono::high_resolution_clock::now();
}
void Time::Stop_clock()
{
	pabaiga_ = std::chrono::high_resolution_clock::now();
}
void Time::Sum_time()
{
	skirtumas_ = pabaiga_ - pradzia_;
	time += skirtumas_.count();
}
void Time::Get_time(std::ofstream& lout)
{
	skirtumas_ = pabaiga_ - pradzia_;
	lout << "eiluciu failo apdorojimo laikas = " << skirtumas_.count() << " s." << std::endl;
}
void Time::get_all(std::ofstream& out)
{
	out << "Visas laikas yra " << time << std::endl;
}
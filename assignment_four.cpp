// PHYS 30762 Programming in C++
// Assignment 4
// Simple demonstration of a C++ class
//
// Hubble types: E[0-7], S0, S[a-c], SB[a-c], Irr
// Redshift z in range [0,10]
// Total mass M_tot in range [1e7,1e12] M_sun
// Stellar mass fraction f_* in range [0,0.05]
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

class galaxy
{
private:
	std::string hubble_type;
	double redshift;
	double total_mass;
	double stellar_mass_fraction;

public:
	// default constructor
	galaxy() : hubble_type{ "E[7]" }, stellar_mass_fraction{0.01}, total_mass{1e7}, redshift{5}  {};
	// Parameterised constructor
	galaxy(std::string Galaxy_hubble_type, double Galaxy_redshift, double Galaxy_total_mass, double Galaxy_stellar_mass_fraction):
		hubble_type{ Galaxy_hubble_type }, redshift{ Galaxy_redshift }, total_mass{ Galaxy_total_mass }, stellar_mass_fraction{ Galaxy_stellar_mass_fraction }{}
	// Destructor
	~galaxy() { std::cout << "Destroying " << hubble_type << std::endl; }

	// Return stellar mass (M_* = f_* x M_tot)
	double stellar_mass(/*double stellar_mass_fraction, double total_mass*/) {
		double star_mass{};
		star_mass = (stellar_mass_fraction) * (total_mass);
		return star_mass;
	}
	// Change galaxy's Hubble type
	void change_type(std::string new_type) { //not sure about this
	}
	// Prototype for function to print out an object's data
	void print_data();
	// Add satellite galaxy

};

// Print out an object's data
void galaxy::print_data()
{
	std::cout.precision(3); // 2 significant figures
	std::cout << "galaxy: [hubble type, stellar mass, redshift, total mass] = [" << hubble_type << ", "
		<< stellar_mass(/*stellar_mass_fraction, total_mass*/) << ", " << redshift << ", " << total_mass << "]" << std::endl;
	return;
	// End of class and associated member functions
}
// Main program
int main()
{
	std::vector<galaxy> galaxy_data;
	// Example using default constructor
	galaxy g1;
	galaxy_data.push_back(galaxy(g1));
	// Example using parameterised constructor
	galaxy trial("E[1]", 1, 1e12, 0.03);
	galaxy_data.push_back(trial);
	// print out data
	//g1.print_data();
	//trial.print_data();

	for (auto galaxy_it = galaxy_data.begin(); galaxy_it < galaxy_data.end(); ++galaxy_it) {
		std::cout << "galaxy data: "<< std::endl;
		galaxy_it->print_data();
		std::cout << "stellar mass: " << galaxy_it->stellar_mass() << std::endl;
	}
	// Get and print out stellar mass

	// Change Hubble type from Irr to S0

	// Add satellite galaxies

	return 0;
}
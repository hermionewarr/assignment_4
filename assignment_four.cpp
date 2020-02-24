// PHYS 30762 Programming in C++
// Assignment 4
// Simple demonstration of a C++ class
//hermione warr

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
	std::vector<galaxy> satellites;

public:
	// default constructor
	galaxy() : hubble_type{ "E[7]" }, stellar_mass_fraction{ 0.01 }, total_mass{ 1e7 }, redshift{ 5 }, satellites{}  {};
	// Parameterised constructor
	galaxy(std::string Galaxy_hubble_type, double Galaxy_redshift, double Galaxy_total_mass, double Galaxy_stellar_mass_fraction) :
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
	void change_type(std::string new_type) {
		hubble_type = new_type;
	}

	void print_type() {
		std::cout << "Hubble type: " << hubble_type << std::endl;
	}

	// Function to print out an object's data
	void print_data();

	// Add satellite galaxy
	void new_satellites(std::string new_satellite) {
		satellites.push_back(new_satellite);
	}

	//print satellite data
	void print_satellite_info() {
		//print satellite data
		for (std::vector<std::string>::iterator satellite_it = satellites.begin(); satellite_it != satellites.end(); ++satellite_it)
			std::cout << ' ' << *satellite_it << std::endl;
	}
};

// Print out galaxies data
void galaxy::print_data()
{
	std::cout.precision(3); // 2 significant figures
	std::cout << "galaxy[hubble type, stellar mass, redshift, total mass] = [" << hubble_type << ", "
		<< stellar_mass(/*stellar_mass_fraction, total_mass*/) << ", " << redshift << ", " << total_mass << "]" << std::endl;
	return;
}

// Main program
int main()
{
	//define a vector
	std::vector<galaxy> galaxy_data;
	std::vector<galaxy> trial_satellites;
	// Hubble types: E[0-7], S0, S[a-c], SB[a-c], Irr
	// Redshift z in range [0,10]
	// Total mass M_tot in range [1e7,1e12] M_sun
	// Stellar mass fraction f_* in range [0,0.05]

	// Example using default constructor
	galaxy g1;
	galaxy_data.push_back(galaxy(g1));
	

	// Example using parameterised constructors
	/*galaxy trial("E[1]", 1, 1e12, 0.03, trial_satellites);
	galaxy_data.push_back(trial);
	galaxy trial_2("Irr", 2, 1e8, 0.04);
	galaxy_data.push_back(trial_2);*/

	// print out data
	std::cout << "galaxy data: " << std::endl;
	for (auto galaxy_it = galaxy_data.begin(); galaxy_it < galaxy_data.end(); ++galaxy_it) {
		galaxy_it->print_data();
		// Get and print out stellar mass
		std::cout << "stellar mass: " << galaxy_it->stellar_mass() << std::endl;
	}

	// Change Hubble type from Irr to S0
	/*trial_2.change_type("S0");
	std::cout << "Galaxy trial_2's hubble type has changed to " << std::endl;
	trial_2.print_type();
	galaxy_data.pop_back();
	galaxy_data.push_back(trial_2);
	//to show the updated vector
	std::cout << "Updated galaxy data: " << std::endl;
	for (auto galaxy_it = galaxy_data.begin(); galaxy_it < galaxy_data.end(); ++galaxy_it) {
		galaxy_it->print_data();
	}
	// Add satellite galaxies
	trial.new_satellites("cloud");
	trial.print_satellite_info();*/
	return 0;
}

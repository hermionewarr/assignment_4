// PHYS 30762 Programming in C++
// Assignment 4
// Simple demonstration of a C++ class
// hermione warr
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
	int number_of_satellites;
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
	double stellar_mass() {
		double star_mass{};
		star_mass = (stellar_mass_fraction) * (total_mass);
		return star_mass;
	}
	// Change galaxy's Hubble type
	void change_type(std::string new_type) {
		hubble_type = new_type;
	}

	void print_type() {
		std::cout <<  hubble_type << std::endl;
	}

	// Function to print out an object's data
	void print_data();

	// Add satellite galaxy
	void new_satellites(std::string new_satellite_type, double satellite_redsift, double satellite_total_mass, double satellite_stellar_mass_fraction) {
		satellites.push_back(galaxy(new_satellite_type, satellite_redsift, satellite_total_mass, satellite_stellar_mass_fraction));
		number_of_satellites += 1;
	}
	int total_number_of_satellites = number_of_satellites;
	//print satellite data
	void print_satellite_info();
};

//print satellite data
void galaxy::print_satellite_info()
{
	if (number_of_satellites != 0) {
		std::cout << "Galaxy satellites: " << std::endl;
		int i{ 1 };
		for (auto satellite_it = satellites.begin(); satellite_it < satellites.end(); ++satellite_it) {
			std::cout <<"Satellite " << i << " [" << satellite_it -> hubble_type << ", " << satellite_it -> redshift << ", " << satellite_it-> total_mass << ", " << satellite_it-> stellar_mass_fraction << "]" << std::endl;
			i++;
		}
	}
}

// Print out galaxies data
void galaxy::print_data()
{
	std::cout.precision(3); // 2 significant figures
	std::cout << "[hubble type, stellar mass, redshift, total mass] = [" << hubble_type << ", "
		<< stellar_mass() << ", " << redshift << ", " << total_mass << "]" << std::endl;
	//or could print out sat info here
	//print satellite data
	std::cout << "Galaxy has " << number_of_satellites << " satellite(s)." << std::endl;
	return;
}


// Main program
int main()
{
	//define a vector
	std::vector<galaxy> galaxy_data;
	std::vector<galaxy>::iterator new_type_pos;
	int counter{1};

	// Example using default constructor
	galaxy g1;
	galaxy_data.push_back(galaxy(g1));

	// Example using parameterised constructors
	galaxy g2("E[1]", 1, 1e12, 0.03);
	galaxy_data.push_back(g2);
	galaxy g3("Irr", 2, 1e8, 0.04);
	galaxy_data.push_back(g3);

	// Add satellite galaxies, types dI, dSph, dE, dS.
	//satellites of g2
	galaxy_data[1].new_satellites("dSph", 1, 1e8, 0.025);
	galaxy_data[1].new_satellites("dI", 2, 5e9, 0.04);

	// print out data
	std::cout << "Galaxy data: " << std::endl;
	for (auto galaxy_it = galaxy_data.begin(); galaxy_it < galaxy_data.end(); ++galaxy_it) {
		std::cout << "Galaxy " << counter << " ";
		galaxy_it->print_data();
		galaxy_it->print_satellite_info();
		// Get and print out stellar mass
		std::cout << "Stellar mass of galaxy " << counter << " is: " << galaxy_it->stellar_mass() << std::endl;
		counter++;
	}

	// Change Hubble type from Irr to S0
	g3.change_type("S0");
	std::cout << "Galaxy 3's hubble type has changed to " ;
	g3.print_type();
	//galaxy_data.pop_back();
	new_type_pos = galaxy_data.begin();
	galaxy_data.erase(new_type_pos+2);
	galaxy_data.push_back(g3);

	//to show the updated vector
	std::cout << "\nUpdated galaxy data: " << std::endl;
	for (auto galaxy_it = galaxy_data.begin(); galaxy_it < galaxy_data.end(); ++galaxy_it) {
		std::cout << "Galaxy " << counter <<" " ;
		galaxy_it->print_data();
		galaxy_it->print_satellite_info();
		counter++;
	}	
	return 0;
}


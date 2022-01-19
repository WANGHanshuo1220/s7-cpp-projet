// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "forces_aeriennes.hh"
#include "forces_terrestres.hh"
#include "forces_navales.hh"
#include "economie.hh"
#include "technologie.hh"
#include "rank.hh"
#include "paysInfo.hh"
#include <iostream>
#include <fstream>
#include <list>
using namespace std;


TEST_CASE("1: print Info"){
	paysInfo pays_1("pays_1", 960, 13);
	//cout << pays_1.show_population() << endl;
 	aeriennes c(pays_1, 1, 2, 1, 1);
 	REQUIRE(c.show_name() == "pays_1");
 	REQUIRE(c.show_population() == 13);
 	REQUIRE(c.show_surface() == 960);
 	cout << c;
}

TEST_CASE("2: Comparer"){
	cout << endl;
	paysInfo pays_2("pays_2", 100, 1);
	//cout << pays_2.show_population() << endl;
 	economie p1(pays_2, 0.1, 0.2, 0.4);
 	REQUIRE(p1.show_name() == "pays_2");
 	REQUIRE(p1.show_population() == 1);
 	REQUIRE(p1.show_surface() == 100);
 	REQUIRE(p1.prediction() == 0.3);
 	cout << p1;

 	paysInfo pays_3("pays_3", 90, 3);
 	economie p2(pays_3, 0.2, 0.2, 0.1);
 	REQUIRE(p2.show_name() == "pays_3");
 	REQUIRE(p2.show_population() == 3);
 	REQUIRE(p2.show_surface() == 90);
 	REQUIRE(p2.prediction() == 0.34);
 	cout << p2;
 	REQUIRE((p2 > p1) == true);
}

TEST_CASE("3: rank_technologie"){
	cout << endl;
	paysInfo pays_4("pays_4", 50, 1);
	//cout << pays_2.show_population() << endl;
 	technologie p3(pays_4, 0.5, 0.4, 0.1);
 	REQUIRE(p3.show_name() == "pays_4");
 	REQUIRE(p3.show_frais_aug() == 0.5);
 	REQUIRE(p3.show_tech_population_aug() == 0.4);
 	REQUIRE(p3.show_rank_universite() == 0.1);
 	cout << p3;

 	cout << endl;
 	paysInfo pays_5("pays_5", 10, 3);
 	technologie p4(pays_5, 0.2, 0.1, 0.3);
 	REQUIRE(p4.show_name() == "pays_5");
 	REQUIRE(p4.show_frais_aug() == 0.2);
 	REQUIRE(p4.show_tech_population_aug() == 0.1);
 	REQUIRE(p4.show_rank_universite() == 0.3);
 	cout << p4;
 	REQUIRE((p4 < p3) == true);

 	cout << endl;
  	paysInfo pays_6("pays_6", 10, 3);
 	technologie p5(pays_6, 0.5, 0.5, 0.4);
 	REQUIRE(p5.show_name() == "pays_6");
 	REQUIRE(p5.show_frais_aug() == 0.5);
 	REQUIRE(p5.show_tech_population_aug() == 0.5);
 	REQUIRE(p5.show_rank_universite() == 0.4);
 	cout << p5;
 	REQUIRE((p5 > p3) == true);

 	cout << endl;
  	paysInfo pays_7("pays_7", 10, 3);
 	technologie p6(pays_7, 0.2, 0.3, 0.2);
 	REQUIRE(p6.show_name() == "pays_7");
 	REQUIRE(p6.show_frais_aug() == 0.2);
 	REQUIRE(p6.show_tech_population_aug() == 0.3);
 	REQUIRE(p6.show_rank_universite() == 0.2);
 	cout << p6;
 	REQUIRE((p6 < p3) == true);

 	cout << endl;
 	vector<technologie> tech_pays_vec;
 	tech_pays_vec.push_back(p3);
 	tech_pays_vec.push_back(p4);
 	tech_pays_vec.push_back(p5);
 	tech_pays_vec.push_back(p6);
 	ranks tech_rank(tech_pays_vec);
 	REQUIRE(tech_rank.sort_pays()[0].first == tech_rank.Meilleur_pays());

}

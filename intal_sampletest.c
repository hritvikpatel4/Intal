// Sample test cases for the intal library. 
// This file contains the test cases for the functions in the intal library.

// @author: Hritvik Patel [hritvik.patel4@gmail.com]

// MIT License

// Copyright (c) 2020 Hritvik Patel

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

int main(int argc, char const *argv[]) {
	int n = 12;
	char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");
	strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
	char *result1;
	int index1;

	result1 = intal_add(a[0], a[1]);
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543216666666666666666666666666")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
		}
		free(result1);
	}

	result1 = intal_add("0", "0");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_add("0", "1");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_add("1", "0");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	index1 = intal_compare(a[0], a[1]);
	if(-1 == index1) {
		printf("Test intal_compare PASSED\n");
	} else {
		printf("Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

	result1 = intal_diff(a[0], a[1]);
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
		}
		free(result1);
	}

	result1 = intal_diff("1", "0");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_diff("0", "1");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_diff("1", "1");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_diff("0", "0");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_multiply(a[8], a[5]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "65185851858518585185851852")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
		}
		free(result1);
	}

	result1 = intal_multiply("0", a[5]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_multiply(a[8], "0");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_multiply("0", "0");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_mod(a[3], a[4]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_mod("978", "5");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_mod(a[0], a[5]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "9")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "9");
		}
		free(result1);
	}

	result1 = intal_mod("5485743258475748273548732587432875758942375847235847254890723854702385784293753827584732895748325740827584676715489257425674892674875894705273485678436561874817584738758784371584310758439170584319758347584758947158974875476485740175841074328975843105748137458467843975843107510578417185748375483290758436584375846510896584375817408134798574893257684362547632578461759674863157647561095640509415674615750157647831561756413756843156138096784397584310751057841718574837548329075843658437584651089658437581740813479857489325768436254763257846175967486315764756109564050548732052089754892768297350823750843275894078328597438297510574328975448936789321573980127501937875892750832475481390759831257381927589378203", "76843625476325784617596748631576475610956405054873205208975489276829735082375084327589407832859743829751057432897544893678932157398012750193787589275083247548139075983125738192758937452375874329587432856472365743627523945432015367564327854647320564732564736573248");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "6745592845074042758050336179214847982127235696391047009999027698134925987445509261599801651598156933137843371719215878285029944889346142501291925415531320146024800732959059576926722380013672792040484448841650176640673892922708805408958509189858278475560819015643")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "6745592845074042758050336179214847982127235696391047009999027698134925987445509261599801651598156933137843371719215878285029944889346142501291925415531320146024800732959059576926722380013672792040484448841650176640673892922708805408958509189858278475560819015643");
		}
		free(result1);
	}

	result1 = intal_pow(a[5], 3);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1728")) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1728");
		}
		free(result1);
	}

	result1 = intal_pow("10", 999);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[10])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[10]);
		}
		free(result1);
	}

	result1 = intal_pow("2", 3000);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[11])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[11]);
		}
		free(result1);
	}

	result1 = intal_gcd(a[0], a[5]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_gcd("1", "0");
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_gcd("0", "1");
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_gcd("0", "0");
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_gcd(a[0], a[0]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[0])) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[0]);
		}
		free(result1);
	}

	result1 = intal_fibonacci(0);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_fibonacci(3);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1000);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
		}
		free(result1);
	}

	result1 = intal_factorial(0);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(1);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(30);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[6])) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(100);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
		}
		free(result1);
	}

	result1 = intal_factorial(449);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "38519305180280725763215847691212875548395805893534467012649055767896288926298594457881668628676415791435136187818720217463596852902892556018549547069670372378159819334271735471638382734807840186751249583042983720300081355781130751601099935399420025859541702588941624119769786447979635875887987628187121141743814227340405786877075540700136227919818634007425579126136583156012933348747449102149815962647863834705576714179015069575989844000509497340761230129254648880664249707996772824842574358558533486456993617018144080838058452833163022395716238804463454122374136551392458402546135467775972918729773166312427787861887749833467752180081269884348992863634984303810255947153663266095784399888312698855788258154809005327539117440908208905353330891394428678158921052069748074205537868136717094006764031023426591318276097353833638375226039787340475684974328746914841262748828969418676947795312640000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
		}
		free(result1);
	}

	result1 = intal_bincoeff(10, 8);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "45")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "45");
		}
		free(result1);
	}

	result1 = intal_bincoeff(1000, 900);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890");
		}
		free(result1);
	}

	index1 = intal_max(a, n);
	if(10 == index1) {
		printf("Test intal_max PASSED\n");
	} else {
		printf("Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	index1 = intal_min(a, n);
	if(2 == index1) {
		printf("Test intal_min PASSED\n");
	} else {
		printf("Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 2);
	}

	index1 = intal_search(a, n, a[7]);
	if(6 == index1) {
		printf("Test intal_search PASSED\n");
	} else {
		printf("Test intal_search FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}
	
	intal_sort(a, n);
	printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}
	printf("\n");

	index1 = intal_binsearch(a, n, "3");
	if(1 == index1) {
		printf("Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 1);
	}

	// Don't forget to free all the memory that is dynamically allocated.
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	return 0;
}

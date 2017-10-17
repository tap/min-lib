///	@brief 		Unit test for the easing classes
///	@author		Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"

// NW: Defining a macro for the test loop so that the syntax is consistent
// The number of steps in our test loop will be equal to the number of values in the reference sample_vector
#define EASING_TEST_LOOP(easing_function, reference_vector) { \
    for (auto i = 0; i < reference_vector.size(); ++i) { \
        auto x = i / double(reference_vector.size()-1); \
        INFO( "when i == " << i ); \
        REQUIRE( easing_function(x) == Approx(reference_vector[i]) ); \
    } \
} \

SCENARIO ("Using Linear Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        0,
        0.01587301587301587,
        0.03174603174603174,
        0.04761904761904762,
        0.06349206349206349,
        0.07936507936507936,
        0.09523809523809523,
        0.1111111111111111,
        0.126984126984127,
        0.1428571428571428,
        0.1587301587301587,
        0.1746031746031746,
        0.1904761904761905,
        0.2063492063492063,
        0.2222222222222222,
        0.2380952380952381,
        0.253968253968254,
        0.2698412698412698,
        0.2857142857142857,
        0.3015873015873016,
        0.3174603174603174,
        0.3333333333333333,
        0.3492063492063492,
        0.3650793650793651,
        0.3809523809523809,
        0.3968253968253968,
        0.4126984126984127,
        0.4285714285714285,
        0.4444444444444444,
        0.4603174603174603,
        0.4761904761904762,
        0.492063492063492,
        0.5079365079365079,
        0.5238095238095238,
        0.5396825396825397,
        0.5555555555555556,
        0.5714285714285714,
        0.5873015873015873,
        0.6031746031746031,
        0.6190476190476191,
        0.6349206349206349,
        0.6507936507936508,
        0.6666666666666666,
        0.6825396825396826,
        0.6984126984126984,
        0.7142857142857143,
        0.7301587301587301, 
        0.746031746031746, 
        0.7619047619047619, 
        0.7777777777777778, 
        0.7936507936507936, 
        0.8095238095238095, 
        0.8253968253968254, 
        0.8412698412698413, 
        0.8571428571428571, 
        0.873015873015873, 
        0.8888888888888888, 
        0.9047619047619048, 
        0.9206349206349206, 
        0.9365079365079365, 
        0.9523809523809523, 
        0.9682539682539683, 
        0.9841269841269841, 
        1
    };
    
	GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
		EASING_TEST_LOOP(c74::min::lib::easing::linear, reference);
	
	}
}

SCENARIO ("Using In Back Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        0,
        -0.0007872052861554308,
        -0.003128890033784019,
        -0.006989271070477585,
        -0.01232475562367729,
        -0.01908401443394193,
        -0.02720808377393558,
        -0.03663049603481367,
        -0.04727743844682841,
        -0.05906793940746457,
        -0.07191408179854235,
        -0.08572124258377627,
        -0.1003883578905333,
        -0.1158082126942681,
        -0.1318677541415904,
        -0.1484484274684027,
        -0.1654265333932787,
        -0.1826736057934785,
        -0.2000568084019443,
        -0.2174393491985045,
        -0.2346809111075447,
        -0.2516380975577758,
        -0.2681648914076146,
        -0.2841131256922727,
        -0.2993329646060633,
        -0.3136733930958325,
        -0.3269827134089173,
        -0.3391090469117437,
        -0.3499008394731898,
        -0.3592073686902318,
        -0.3668792512222226,
        -0.3727689484944767,
        -0.3767312690316608,
        -0.3786238656868486,
        -0.3783077260429712,
        -0.3756476542797589,
        -0.3705127428211004,
        -0.3627768321049648,
        -0.3523189568505887,
        -0.3390237772354198,
        -0.3227819934372388,
        -0.3034907420448214,
        -0.2810539728933296,
        -0.2553828049381625,
        -0.226395859843127,
        -0.1940195720252691,
        -0.1581884739694183,
        -0.1188454557001511, 
        -0.07594199737734691, 
        -0.02943837406346755, 
        0.02069616820401338, 
        0.07448326581330578, 
        0.1319353211392744, 
        0.1930554168582522, 
        0.2578372615143961, 
        0.3262651667375155, 
        0.3983140564128485, 
        0.4739495080024873, 
        0.553127826116286, 
        0.6357961483275298, 
        0.7218925831255953, 
        0.8113463797947321, 
        0.9040781299051253, 
        0.9999999999999999
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::in_back, reference);
        
    }
}
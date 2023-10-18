#ifndef SOURCE_QUICK_TEST_CONFIG_H_
#define SOURCE_QUICK_TEST_CONFIG_H_

#include <stdbool.h>
#include <stdint.h>
/*------------------------------------------ MACROS --------------------------------------------------------------------*/

#define BP_ODR							200														// Output Data Rate is 100
#define SECONDS_60                  	60														// 60 sec per minute
#define BP_NUM_PKS_EXPEC				3														// at least number of peaks req for HR measurement
#define BP_MIN_HR_MEASURE				30														// beats/min
#define BP_MAX_HR_MEASURE				180														// beats/min
#define BP_NUM_SEC_DATA_CAPTURE 		((BP_NUM_PKS_EXPEC * SECONDS_60)/(BP_MIN_HR_MEASURE))	// find out num sec data capture to meet expected peaks
#define BP_NUM_ECG_PPG_SAMPLES			(BP_ODR * BP_NUM_SEC_DATA_CAPTURE)						// calculates number of samples
#define BP_PPG_PEAK_DETECT_TH			(float)0.2

#define BP_CAL_ODR_FACTOR				((float)(1000/BP_ODR))									// for 200 ODR factor = 5

#define BP_MAX_SBP_THRESHOLD			300
#define BP_MAX_DBP_THRESHOLD			150														// Changed to 120 from 140 9/2/19
#define BP_MIN_SBP_THRESHOLD			30
#define BP_MIN_DBP_THRESHOLD			40

#define BP_MAX_NUM_ECG_PEAKS			(uint8_t)5
#define BP_MAX_CAPTURE_ITERATIONS		(SECONDS_60 / BP_NUM_SEC_DATA_CAPTURE)
#define BP_SBP_CALIB_FACTOR				15
#define BP_DBP_CALIB_FACTOR				10

#define BP_ECG_TH_RANGE_RISE_SIDE		6
#define BP_ECG_TH_RANGE_FALL_SIDE		6

#define BP_PPG_TH_RANGE_RISE_SIDE		100
#define BP_PPG_TH_RANGE_FALL_SIDE		40

#define BP_NUM_MINIMUM_ECG_PEAKS		BP_NUM_PKS_EXPEC
#define NUM_MIN_ECG_PEAKS_0pt5			2
#define NUM_MIN_PPG_PEAKS_0pt5			1
#define BP_ECG_PPG_PK_DETECT_TH_0pt5	(float)0.5
#define BP_ECG_PPG_PK_DETECT_TH_0pt4	(float)0.4

//Falling logic constants
#define NBR_PPG_SAMPLES_TO_DETECT				15
#define PPG_FALLING_EDGE_VALLY_TO_PEAK_DIFF		(float)0.05

//Avergae PPT/HR logic logic
#define PERCENTAGE_OF_PTT_BY_HR 				0.25
#define MIN_HEART_RATE_FOR_MULTIPLIER			25
#define NBR_SBP_DBP_MUL_FACTOR					((180 - MIN_HEART_RATE_FOR_MULTIPLIER) + 1)

// BP one time calibration max and min values

#define BP_MAX_SBP_MULTIPIER			0.012903921568628
#define BP_MIN_SBP_MULTIPIER			-0.002442002442002
#define BP_MAX_DBP_MULTIPIER			3.55866310160428
#define BP_MIN_DBP_MULTIPIER			-0.004162504162504


/*-----------------------------------Spo2---------------------------------------------------*/
#define SPO2_IR_LED_SAMPLES 					500
#define SPO2_RED_LED_SAMPLES 					500
#define SPO2_ODR 								100
#define NUM_SEC_DATA_CAPTURE					5
#define	NUM_SPO2_SAMPLES						(NUM_SEC_DATA_CAPTURE * SPO2_ODR)	// 5 * 100 = 500 Samples

#define SPO2_PEAK_DETECT_TH						(float)0.4							//peak threshold
#define SPO2_TH_RANGE_RISE_SIDE					40									//previous 10 samples from present sample
#define SPO2_TH_RANGE_FALL_SIDE					40									//10 next samples from present sample
#define SPO2_MIN_VALUE							70									//minimum spo2 value
#define SPO2_MAX_VALUE							100									//maximum spo2 value
#define MAX_NUM_PEAKS							3
#define SPO2_MAX_CAPTURE_ITERATIONS				10

/*---------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------*/




static const uint8_t SPO2_table[184] = { 95, 95, 95, 96, 96, 96, 97, 97, 97, 97,
										97, 97, 98, 98, 98, 98, 98, 99, 99, 99,
										99, 99, 99, 97, 97, 97, 97, 97, 96, 96,
										97, 97, 96, 96, 95, 97, 96, 96, 96, 96,
										95, 96, 96, 96, 99, 96, 93, 96, 96, 96,
										95, 96, 98, 98, 98, 98, 98, 97, 97, 97,
										97, 97, 97, 96, 96, 96, 95, 95, 95, 94,
										94, 94, 93, 93, 93, 92, 92, 92, 91, 91,
										91, 90, 90, 89, 89, 88, 88, 87, 87, 86,
										86, 85, 85, 84, 84, 83, 82, 82, 81, 81,
										80, 80, 79, 78, 78, 77, 76, 76, 75, 74,
										74, 73, 72, 72, 71, 70, 69, 69, 68, 67,
										66, 66, 65, 64, 63, 62, 62, 61, 60, 59,
										58, 57, 56, 56, 55, 54, 53, 52, 51, 50,
										49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
										39, 38, 37, 36, 35, 34, 33, 31, 30, 29,
										28, 27, 26, 25, 23, 22, 21, 20, 19, 17,
										16, 15, 14, 12, 11, 10, 9, 7, 6, 5, 3, 2, 1 } ;



static const float SBP_MUL_FACTOR [NBR_SBP_DBP_MUL_FACTOR] = {0.01036,0.01034,0.01032,0.0103,0.01028,0.01026,0.01024,0.01022,0.0102,0.01018,0.01016,0.01014,0.01012,0.0101,0.01008,0.01006,0.01004,0.01002,0.01,0.00998,0.00996,0.00994,0.00992,0.0099,0.00988,0.00986,0.00984,0.00982,0.0098,0.00978,0.00976,0.00974,0.00972,0.0097,0.00968,0.00966,0.00964,0.00962,0.0096,0.00958,0.00956,0.00954,0.00952,0.0095,0.00948,0.00946,0.00944,0.00942,0.0094,0.00938,0.00936,0.00934,0.00932,0.0093,0.00928,0.00926,0.00924,0.00922,0.0092,0.00918,0.00916,0.00914,0.00912,0.0091,0.00908,0.00906,0.00904,0.00902,0.009,0.00898,0.00896,0.00894,0.00892,0.0089,0.00888,0.00886,0.00884,0.00882,0.0088,0.00878,0.00876,0.00874,0.00872,0.0087,0.00868,0.00866,0.00864,0.00862,0.0086,0.00858,0.00856,0.00854,0.00852,0.0085,0.00848,0.00846,0.00844,0.00842,0.0084,0.00838,0.00836,0.00834,0.00832,0.0083,0.00828,0.00826,0.00824,0.00822,0.0082,0.00818,0.00816,0.00814,0.00812,0.0081,0.00808,0.00806,0.00804,0.00802,0.008,0.00798,0.00796,0.00794,0.00792,0.0079,0.00788,0.00786,0.00784,0.00782,0.0078,0.00778,0.00776,0.00774,0.00772,0.0077,0.00768,0.00766,0.00764,0.00762,0.0076,0.00758,0.00756,0.00754,0.00752,0.0075,0.00748,0.00746,0.00744,0.00742,0.0074,0.00738,0.00736,0.00734,0.00732,0.0073,0.00728,0.00726};
static const float DBP_MUL_FACTOR [NBR_SBP_DBP_MUL_FACTOR] = {1.606,1.604,1.602,1.6,1.598,1.596,1.594,1.592,1.59,1.588,1.586,1.584,1.582,1.58,1.578,1.576,1.574,1.572,1.57,1.568,1.566,1.564,1.562,1.56,1.558,1.556,1.554,1.552,1.55,1.548,1.546,1.544,1.542,1.54,1.538,1.536,1.534,1.532,1.53,1.528,1.526,1.524,1.522,1.52,1.518,1.516,1.514,1.512,1.51,1.508,1.506,1.504,1.502,1.5,1.498,1.496,1.494,1.492,1.49,1.488,1.486,1.484,1.482,1.48,1.478,1.476,1.474,1.472,1.47,1.468,1.466,1.464,1.462,1.46,1.458,1.456,1.454,1.452,1.45,1.448,1.446,1.444,1.442,1.44,1.438,1.436,1.434,1.432,1.43,1.428,1.426,1.424,1.422,1.42,1.418,1.416,1.414,1.412,1.41,1.408,1.406,1.404,1.402,1.4,1.398,1.396,1.394,1.392,1.39,1.388,1.386,1.384,1.382,1.38,1.378,1.376,1.374,1.372,1.37,1.368,1.366,1.364,1.362,1.36,1.358,1.356,1.354,1.352,1.35,1.348,1.346,1.344,1.342,1.34,1.338,1.336,1.334,1.332,1.33,1.328,1.326,1.324,1.322,1.32,1.318,1.316,1.314,1.312,1.31,1.308,1.306,1.304,1.302,1.3,1.298,1.296};

//static const float SBP_MUL_FACTOR [NBR_SBP_DBP_MUL_FACTOR] = { 0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.0098,0.01,0.01,0.01,0.01,0.01,0.0098,0.0093,0.0091,0.0091,0.0091,0.0094,0.0091,0.009,0.0089,0.0097,0.0093,0.009,0.0095,0.009,0.009,0.009,0.0092,0.0098,0.0095,0.0094,0.0095,0.0088,0.0092,0.0092,0.009,0.0095,0.0095,0.0095,0.0095,0.0086,0.0085,0.0085,0.0104,0.0115,0.01,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095,0.0095 };
//static const float DBP_MUL_FACTOR [NBR_SBP_DBP_MUL_FACTOR] = { 1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.8,1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.5,1.5,1.5,1.5,1.7,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.55,1.55,1.5,1.5,1.45,1.5,1.5,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.4,1.5,1.5,1.5,1.6,1.5,1.4,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2 };



#endif /* SOURCE_QUICK_TEST_CONFIG_H_ */

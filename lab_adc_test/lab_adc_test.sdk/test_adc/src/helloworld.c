/**
*
* @file main.c
*
* This file contains a design example using the driver functions
* of the XADC driver. The example here shows the driver/device in polled mode
* to check the voltage on ADC 14. This example is highly inspired by Xilinx
* standard example on how to use the XADC module.
*
* @note
*
*
*
* <pre>
*
* MODIFICATION HISTORY:
*
* Ver   Who   Date      Changes
* ----- ----  --------  -----------------------------------------------------
* 1.00a jcla  31/03/16  First release based on the Xilinx XADC example driver
*
* </pre>
*
*****************************************************************************/

/***************************** Include Files ********************************/

#include "xparameters.h"
#include "xadcps.h"
#include "xstatus.h"
#include "stdio.h"

/************************** Constant Definitions ****************************/

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place.
 */
#define XADC_DEVICE_ID 		XPAR_XADCPS_0_DEVICE_ID


/**************************** Marco Definitions ******************************/


/************************** Function Prototypes *****************************/

static int XAdcPolledPrintfExample(u16 XAdcDeviceId);
static int XAdcFractionToInt(float FloatNum);


/***************** Macros (Inline Functions) Definitions ********************/

#define printf xil_printf /* Small foot-print printf function */

// converting RAW data from external sourse to voltage
#define XAdcPs_ExternalRawToVoltage(AdcData)\
								((((float)(AdcData))* (1.0f))/65536.0f)


/************************** Variable Definitions ****************************/

static XAdcPs XAdcInst;      /* XADC driver instance */

/****************************************************************************/


int main(void)
{

	int Status;

	/*
	 * Run the polled example, specify the Device ID that is
	 * generated in xparameters.h.
	 */
	Status = XAdcPolledPrintfExample(XADC_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}


/****************************************************************************/
/**
****************************************************************************/
int XAdcPolledPrintfExample(u16 XAdcDeviceId)
{
	int Status;
	XAdcPs_Config *ConfigPtr;
	u32 VccPdroRawData;
	float VccPintData;
	XAdcPs *XAdcInstPtr = &XAdcInst;

	printf("\r\nEntering the XAdc Polled Example. \r\n");

	/*
	 * Initialize the XAdc driver.
	 */
	ConfigPtr = XAdcPs_LookupConfig(XAdcDeviceId);
	if (ConfigPtr == NULL) {
		return XST_FAILURE;
	}
	XAdcPs_CfgInitialize(XAdcInstPtr, ConfigPtr,
				ConfigPtr->BaseAddress);

	/*
	 * Self Test the XADC/ADC device
	 */
	Status = XAdcPs_SelfTest(XAdcInstPtr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}


	/*
	 * Read the AD14 input Voltage Data from the
	 * ADC data registers.
	 */
	//a0
	VccPdroRawData = XAdcPs_GetAdcData(XAdcInstPtr, XADCPS_CH_AUX_MIN+1);
	VccPintData = XAdcPs_ExternalRawToVoltage(VccPdroRawData);
	printf("\r\nThe Voltage on pin a0 is %0d.%03d Volts. \r\n",
			(int)(VccPintData), XAdcFractionToInt(VccPintData));


	//a1
	VccPdroRawData = XAdcPs_GetAdcData(XAdcInstPtr, XADCPS_CH_AUX_MIN+9);
	VccPintData = XAdcPs_ExternalRawToVoltage(VccPdroRawData);
	printf("\r\nThe Voltage on pin a1 is %0d.%03d Volts. \r\n",
			(int)(VccPintData), XAdcFractionToInt(VccPintData));


	//a2
	VccPdroRawData = XAdcPs_GetAdcData(XAdcInstPtr, XADCPS_CH_AUX_MIN+6);
	VccPintData = XAdcPs_ExternalRawToVoltage(VccPdroRawData);
	printf("\r\nThe Voltage on pin a2 is %0d.%03d Volts. \r\n",
			(int)(VccPintData), XAdcFractionToInt(VccPintData));

	//done
	printf("\r\nExiting the XAdc Polled Example. \r\n");

	return XST_SUCCESS;
}


/****************************************************************************/
/*
*
* This function converts the fraction part of the given floating point number
* (after the decimal point)to an integer.
*
* @param	FloatNum is the floating point number.
*
* @return	Integer number to a precision of 3 digits.
*
* @note
* This function is used in the printing of floating point data to a STDIO device
* using the xil_printf function. The xil_printf is a very small foot-print
* printf function and does not support the printing of floating point numbers.
*
*****************************************************************************/
int XAdcFractionToInt(float FloatNum)
{
	float Temp;

	Temp = FloatNum;
	if (FloatNum < 0) {
		Temp = -(FloatNum);
	}

	return( ((int)((Temp -(float)((int)Temp)) * (1000.0f))));
}

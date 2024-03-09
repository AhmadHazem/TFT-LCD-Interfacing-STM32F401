#ifndef _WIFI_INTERFACE_H_
#define _WIFI_INTERFACE_H_

#if WIFI_CONFIG_METHOD == WIFI_POST_BUILD
/*****************************************************************/
/*                     Post build public API                     */
/*****************************************************************/
/* !Comment: for testing and Setting the station mode */
void WIFI_vidInit (void);

/* !Comment: for connecting to WIFI */
Std_ReturnType WIFI_udtConnectToWIFI (uint8* pu8WifiName, uint8* pu8WifiPassword);

/* !Comment: for connecting to the server */
Std_ReturnType WIFI_udtConnectToServer (uint8* pu8IP);

/* !Comment: for getting the data from the server */
Std_ReturnType WIFI_udtGetData (uint8 u8NumOfChars, uint8* pu8GetRequest, uint8* pu8DataRecieved);
#endif

#if WIFI_CONFIG_METHOD == WIFI_PRE_BUILD
/*****************************************************************/
/*                     Pre build public API                      */
/*****************************************************************/
void WIFI_vidInit (void);
Std_ReturnType WIFI_udtConnectToWIFI (void);
Std_ReturnType WIFI_udtConnectToServer (void);
Std_ReturnType WIFI_udtGetData (uint8* pu8ReceivedData);
#endif

#endif
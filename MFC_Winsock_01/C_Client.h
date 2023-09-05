#pragma once
#include "afxsock.h"
#include "Constants.h"

class C_MFC_Winsock_01_Dlg;

class C_Client :
	public CAsyncSocket
{
public:
	C_Client(void);
	~C_Client(void);

   void Set_Parent_Pointer( C_MFC_Winsock_01_Dlg *new_pointer );

	int  Class_Get_WSA_Error_Code();
	bool Class_Initialize();
	bool Class_Connect();
	bool Class_Close();
   bool Class_Receive();
   SYSTEMTIME Class_Get_Time();


	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnOutOfBandData(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);

private:

	TCHAR m_ip_address[ MAX_IP_ADDRESS_LENGTH ];
	UINT m_port_number;
	int  m_wsa_error;
   BOOL m_winsock_status;
   bool m_method_status;

   C_MFC_Winsock_01_Dlg *mp_main_dialog;
   SYSTEMTIME m_current_time;


   unsigned int m_client_on_accept_count;
   unsigned int m_client_on_close_count;
   unsigned int m_client_on_connect_count;
   unsigned int m_client_on_out_of_band_count;
   unsigned int m_client_on_receive_count;
   unsigned int m_client_on_send_count;

};

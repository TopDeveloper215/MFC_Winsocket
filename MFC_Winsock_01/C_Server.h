#pragma once
#include "afxsock.h"

// take out per forum post here:  
// http://social.msdn.microsoft.com/Forums/en-US/vcmfcatl/thread/6048ebf5-e5d6-4ccc-9ca7-cc9dd98067df/
//#include "C_MFC_Winsock_01_Dlg.h"
#include "Constants.h"
#include "C_Server_Send_Time_Socket.h"

  // forward declare the main dialog here so we can declare a pointer to it without
  // includeing the dot H file.  See comment just above and forum reference.
class C_MFC_Winsock_01_Dlg;

class C_Server :
	public CAsyncSocket
{
public:
	C_Server(void);
	~C_Server(void);
   int  Class_Get_WSA_Error_Code();
	bool Class_Initialize();
	bool Class_Listen();
	bool Class_Accept();
	void Class_Close();
   int  Class_Send();

   void Set_Parent_Pointer( C_MFC_Winsock_01_Dlg *new_pointer );

public:
	void SetParentDlg(CDialog *pDlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C_Server_Send_Time_Socket)
	public:
	virtual void OnAccept(        int nErrorCode );
	virtual void OnClose(         int nErrorCode );
	virtual void OnConnect(       int nErrorCode );
	virtual void OnOutOfBandData( int nErrorCode );
	virtual void OnReceive(       int nErrorCode );
	virtual void OnSend(          int nErrorCode );
	//}}AFX_VIRTUAL

private:
	UINT m_port_number;
	int  m_wsa_error;
   bool m_method_status;
 	BOOL m_winsock_status;

   C_MFC_Winsock_01_Dlg *mp_main_dialog;

   unsigned int m_server_on_accept_count;
   unsigned int m_server_on_close_count;
   unsigned int m_server_on_connect_count;
   unsigned int m_server_on_out_of_band_count;
   unsigned int m_server_on_receive_count;
   unsigned int m_server_on_send_count;
   
	C_Server_Send_Time_Socket *mp_C_Server_Send_Time_Socket;

};

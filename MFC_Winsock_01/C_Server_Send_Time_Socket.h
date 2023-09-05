/*
   This class C_Server_Send_Time_Socket is intended to work as parte of an
   asynchronous project.  This will perform the activities of sending and
   receiving data, after the Create() and Listen() have already completed.
*/


#if !defined(AFX_C_Server_Send_Time_Socket_H__166D4120_2F94_4231_AE60_7C719E3EC05C__INCLUDED_)
#define AFX_C_Server_Send_Time_Socket_H__166D4120_2F94_4231_AE60_7C719E3EC05C__INCLUDED_

   // forward declare the main dialog here so we can declare a pointer to it without
   // including the dot H file.  
class C_MFC_Winsock_01_Dlg;
class C_Server_Send_Time_Socket;

/////////////////////////////////////////////////////////////////////////////
// C_Server_Send_Time_Socket command target

class C_Server_Send_Time_Socket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	         C_Server_Send_Time_Socket();
	virtual ~C_Server_Send_Time_Socket();
   void     Set_Parent_Pointer( C_MFC_Winsock_01_Dlg *new_pointer );
   int      Class_Get_WSA_Error_Code();

   int      Class_Send();

// Overrides
public:
	void SetParentDlg(CDialog *pDlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C_Server_Send_Time_Socket)
	public:
	virtual void OnAccept(        int nErrorCode);
	virtual void OnClose(         int nErrorCode);
	virtual void OnConnect(       int nErrorCode);
	virtual void OnOutOfBandData( int nErrorCode);
	virtual void OnReceive(       int nErrorCode);
	virtual void OnSend(          int nErrorCode);
	//}}AFX_VIRTUAL





	// Generated message map functions
	//{{AFX_MSG(C_Server_Send_Time_Socket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
private:
	CDialog * m_pDlg;

      // pointer to the main dialog so this class can initiate sending
      // information to the dialog.
   C_MFC_Winsock_01_Dlg *mp_main_dialog;

   SYSTEMTIME m_current_time;
 	int        m_wsa_error;


   unsigned int m_server_send_on_accept_count;
   unsigned int m_server_send_on_close_count;
   unsigned int m_server_send_on_connect_count;
   unsigned int m_server_send_on_out_of_band_count;
   unsigned int m_server_send_on_receive_count;
   unsigned int m_server_send_on_send_count;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C_Server_Send_Time_Socket_H__166D4120_2F94_4231_AE60_7C719E3EC05C__INCLUDED_)

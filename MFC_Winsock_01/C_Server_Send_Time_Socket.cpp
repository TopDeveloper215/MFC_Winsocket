/*
   This class C_Server_Send_Time_Socket is intended to work as parte of an
   asynchronous project.  This will perform the activities of sending and
   receiving data, after the Create() and Listen() have already completed.
*/

#include "stdafx.h"
#include "C_Server_Send_Time_Socket.h"
#include "C_MFC_Winsock_01_Dlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C_Server_Send_Time_Socket

C_Server_Send_Time_Socket::C_Server_Send_Time_Socket()
{
   C_Server_Send_Time_Socket *mp_CSSTS_this = this;
   unsigned int cssts_address = (unsigned int) &m_server_send_on_accept_count;
  
   m_wsa_error = 0;

   m_server_send_on_accept_count      = 99;
   m_server_send_on_close_count       = 0;
   m_server_send_on_connect_count     = 0;
   m_server_send_on_out_of_band_count = 0;
   m_server_send_on_receive_count     = 0;
   m_server_send_on_send_count        = 0;
}

C_Server_Send_Time_Socket::~C_Server_Send_Time_Socket()
{
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
          m_server_send_on_accept_count      = 0,
          m_server_send_on_close_count       = 0,
          m_server_send_on_connect_count     = 0,
          m_server_send_on_out_of_band_count = 0,
          m_server_send_on_receive_count     = 0,
          m_server_send_on_send_count        = 0 );
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(C_Server_Send_Time_Socket, CAsyncSocket)
	//{{AFX_MSG_MAP(C_Server_Send_Time_Socket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// C_Server_Send_Time_Socket member functions

void C_Server_Send_Time_Socket::Set_Parent_Pointer( C_MFC_Winsock_01_Dlg *new_pointer )
{
   mp_main_dialog = new_pointer;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count      = 0,
      m_server_send_on_close_count       = 0,
      m_server_send_on_connect_count     = 0,
      m_server_send_on_out_of_band_count = 0,
      m_server_send_on_receive_count     = 0,
      m_server_send_on_send_count        = 0 );
}

int C_Server_Send_Time_Socket::Class_Get_WSA_Error_Code()
{
   return m_wsa_error;
}

int C_Server_Send_Time_Socket::Class_Send( )
{  
   int chars_sent = 0;
   int size       = sizeof( m_current_time );
   GetSystemTime( &m_current_time );

   chars_sent = CAsyncSocket::Send( (const void *) &m_current_time, size,  0 );

   return chars_sent;
 }

void C_Server_Send_Time_Socket::OnAccept(int nErrorCode) 
{
   m_server_send_on_accept_count ++;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count,
      m_server_send_on_close_count,
      m_server_send_on_connect_count,
      m_server_send_on_out_of_band_count,
      m_server_send_on_receive_count,
      m_server_send_on_send_count );

	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
//		((CEchoServerDlg*)m_pDlg)->OnAccept();
	}
	CAsyncSocket::OnAccept(nErrorCode);
}

void C_Server_Send_Time_Socket::OnClose(int nErrorCode) 
{
   m_server_send_on_close_count ++;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count,
      m_server_send_on_close_count,
      m_server_send_on_connect_count,
      m_server_send_on_out_of_band_count,
      m_server_send_on_receive_count,
      m_server_send_on_send_count );

	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
//		((CEchoServerDlg*)m_pDlg)->OnClose(); 
	}

	
	CAsyncSocket::OnClose(nErrorCode);
}

void C_Server_Send_Time_Socket::OnConnect(int nErrorCode) 
{
   m_server_send_on_connect_count ++;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count,
      m_server_send_on_close_count,
      m_server_send_on_connect_count,
      m_server_send_on_out_of_band_count,
      m_server_send_on_receive_count,
      m_server_send_on_send_count );

	// TODO: Add your specialized code here and/or call the base class

	
	CAsyncSocket::OnConnect(nErrorCode);
}

void C_Server_Send_Time_Socket::OnOutOfBandData(int nErrorCode) 
{
   m_server_send_on_out_of_band_count ++;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count,
      m_server_send_on_close_count,
      m_server_send_on_connect_count,
      m_server_send_on_out_of_band_count,
      m_server_send_on_receive_count,
      m_server_send_on_send_count );
 
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnOutOfBandData(nErrorCode);
}

void C_Server_Send_Time_Socket::OnReceive(int nErrorCode) 
{
  m_server_send_on_receive_count ++;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count,
      m_server_send_on_close_count,
      m_server_send_on_connect_count,
      m_server_send_on_out_of_band_count,
      m_server_send_on_receive_count,
      m_server_send_on_send_count );

  // TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
//		((CEchoServerDlg*)m_pDlg)->OnReceive(); 
	}
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void C_Server_Send_Time_Socket::OnSend(int nErrorCode) 
{
   m_server_send_on_send_count ++;
   mp_main_dialog->Set_Server_Send_On_Call_Counts( 
      m_server_send_on_accept_count,
      m_server_send_on_close_count,
      m_server_send_on_connect_count,
      m_server_send_on_out_of_band_count,
      m_server_send_on_receive_count,
      m_server_send_on_send_count );

   // TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnSend(nErrorCode);
}

void C_Server_Send_Time_Socket::SetParentDlg(CDialog *pDlg)
{
m_pDlg=pDlg;
}

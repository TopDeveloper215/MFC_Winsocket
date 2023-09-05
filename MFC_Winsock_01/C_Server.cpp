/*
My attempt to create an async serve class.
check forum question here:  
http://social.msdn.microsoft.com/Forums/en-US/vcmfcatl/thread/f779f0ff-f56e-4a5c-9bca-14e853aade9c
and here
http://www.codeproject.com/Messages/4361141/CAsyncSocket-first-application.aspx

*/


#include "StdAfx.h"
#include "C_Server.h"

#include "C_MFC_Winsock_01_Dlg.h"


C_Server::C_Server(void)
{
	m_port_number    = DEFAULT_SOCKET_PORT;
	m_wsa_error      = 0;
   m_method_status  = false;
   m_winsock_status = FALSE;

   m_server_on_accept_count      = 0;
   m_server_on_close_count       = 0;
   m_server_on_connect_count     = 0;
   m_server_on_out_of_band_count = 0;
   m_server_on_receive_count     = 0;
   m_server_on_send_count        = 0;


   mp_C_Server_Send_Time_Socket = NULL;

   // does not work
//   mp_main_dialog =  (MFC_Winsock_01Dlg*)AfxGetMainWnd();
//   m_this_process_handle = GetCurrentProcess();
//   m_main_dialog_handle  = GetParent( (HWND) m_this_process_handle );

//   m_main_dialog_handle->Set_Server_On_Call_Counts( 5 );


}

C_Server::~C_Server(void)
{
	if( mp_C_Server_Send_Time_Socket != NULL && (unsigned int) mp_C_Server_Send_Time_Socket != 0xCCCCCCCC )
		delete mp_C_Server_Send_Time_Socket;

}

void C_Server::Set_Parent_Pointer( C_MFC_Winsock_01_Dlg *new_pointer )
{
   mp_main_dialog = new_pointer;

      // Ensure that the dialog shows zero called.
   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count = 0,
                                              m_server_on_close_count = 0,
                                              m_server_on_connect_count = 0,
                                              m_server_on_out_of_band_count = 0,
                                              m_server_on_receive_count = 0,
                                              m_server_on_send_count = 0 );
}


int  C_Server::Class_Get_WSA_Error_Code()
{
   return m_wsa_error;
}


bool C_Server::Class_Initialize()
{
//	mp_my_echo_socket = new C_Server;
//	mp_CAsyncSocket  = new CAsyncSocket;



	m_winsock_status = AfxSocketInit();
	m_winsock_status == 0 ? m_method_status = false : m_method_status = true;

	if( m_method_status )
	{
		m_winsock_status = Create( m_port_number,
			                        SOCK_STREAM,
                                 FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
                                 DEFAULT_IP_ADDRESS );

		m_wsa_error = WSAGetLastError();
		m_winsock_status == 0 ? m_method_status = false : m_method_status = true;
	}

return m_method_status;
}

bool C_Server::Class_Listen()
{
	m_winsock_status = Listen();
	m_wsa_error = WSAGetLastError();
	m_winsock_status == 0 ? m_method_status = false : m_method_status = true;

	return m_method_status;
}

bool C_Server::Class_Accept()
{

   mp_C_Server_Send_Time_Socket = new C_Server_Send_Time_Socket;
   m_wsa_error = WSAGetLastError();
   if( mp_C_Server_Send_Time_Socket != NULL  && m_wsa_error == 0 )
   {
      mp_C_Server_Send_Time_Socket->Set_Parent_Pointer( mp_main_dialog );
      mp_main_dialog->Set_Server_Send_Class_Pointer( mp_C_Server_Send_Time_Socket );
      m_method_status = true;
      m_winsock_status = CAsyncSocket::Accept( *mp_C_Server_Send_Time_Socket );
      m_wsa_error = WSAGetLastError();
      if( m_wsa_error == 0 || m_wsa_error == WSA_WOULD_BLOCK )
      {  // leave m_method_status true
      }
      else
      {
         m_method_status = false;
      }
   }
   else
   {
      m_method_status = false;

   }

   return m_method_status;
}

void C_Server::Class_Close()
{
   int status_1 = 0;
   int status_2 = 0;

	if( mp_C_Server_Send_Time_Socket != NULL )
	{
		mp_C_Server_Send_Time_Socket->Close();
      status_1 = WSAGetLastError();

		delete mp_C_Server_Send_Time_Socket;
		mp_C_Server_Send_Time_Socket = NULL;
	}

     // Regardless of what happens above, execute this line and
     // try to close the socket.
	CAsyncSocket::Close();
   status_2 = WSAGetLastError();

   if( status_1 != 0 )
      m_wsa_error = status_1;
   else 
      m_wsa_error = status_2;


   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count = 0,
                                              m_server_on_close_count = 0,
                                              m_server_on_connect_count = 0,
                                              m_server_on_out_of_band_count = 0,
                                              m_server_on_receive_count = 0,
                                              m_server_on_send_count = 0 );
}

int C_Server::Class_Send()
{
return 0;
}



/*
all these overrides were copied from the downloaded code from www.codeproject.com
*/

void C_Server::OnAccept(int nErrorCode) 
{
   m_server_on_accept_count ++;
   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count,
                                              m_server_on_close_count,
                                              m_server_on_connect_count,
                                              m_server_on_out_of_band_count,
                                              m_server_on_receive_count,
                                              m_server_on_send_count );

	if(nErrorCode==0)
	{
	CAsyncSocket::OnAccept(nErrorCode);
   }


}

void C_Server::OnClose(int nErrorCode) 
{
   m_server_on_close_count ++;
   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count,
                                              m_server_on_close_count,
                                              m_server_on_connect_count,
                                              m_server_on_out_of_band_count,
                                              m_server_on_receive_count,
                                              m_server_on_send_count );
   if(nErrorCode==0)
	{
//		((CEchoServerDlg*)m_pDlg)->OnClose(); 
	}

	
	CAsyncSocket::OnClose(nErrorCode);
}

void C_Server::OnConnect(int nErrorCode) 
{
   m_server_on_connect_count ++;
   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count,
                                              m_server_on_close_count,
                                              m_server_on_connect_count,
                                              m_server_on_out_of_band_count,
                                              m_server_on_receive_count,
                                              m_server_on_send_count );
	
	CAsyncSocket::OnConnect(nErrorCode);
}

void C_Server::OnOutOfBandData(int nErrorCode) 
{
   m_server_on_out_of_band_count ++;
	// TODO: Add your specialized code here and/or call the base class
	
	CAsyncSocket::OnOutOfBandData(nErrorCode);
}

void C_Server::OnReceive(int nErrorCode) 
{
   m_server_on_receive_count ++;
   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count,
                                              m_server_on_close_count,
                                              m_server_on_connect_count,
                                              m_server_on_out_of_band_count,
                                              m_server_on_receive_count,
                                              m_server_on_send_count );
   
   if(nErrorCode==0)
	{
//		((CEchoServerDlg*)m_pDlg)->OnReceive(); 
	}
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void C_Server::OnSend(int nErrorCode) 
{
   m_server_on_send_count ++;
   mp_main_dialog->Set_Server_On_Call_Counts( m_server_on_accept_count,
                                              m_server_on_close_count,
                                              m_server_on_connect_count,
                                              m_server_on_out_of_band_count,
                                              m_server_on_receive_count,
                                              m_server_on_send_count );

	CAsyncSocket::OnSend(nErrorCode);
}

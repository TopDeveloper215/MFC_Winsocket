#include "StdAfx.h"
#include "C_Client.h"

#include "C_MFC_Winsock_01_Dlg.h"

/*
 Simple client class that connects to a server and receives time messages
 in text format.

*/

C_Client::C_Client(void)
{
	_tcscpy_s( m_ip_address, MAX_IP_ADDRESS_LENGTH, DEFAULT_IP_ADDRESS );
	m_port_number    = DEFAULT_SOCKET_PORT;
	m_wsa_error      = 0;
   m_winsock_status = FALSE;
   m_method_status  = false;

   m_client_on_accept_count      = 0;
   m_client_on_close_count       = 0;
   m_client_on_connect_count     = 0;
   m_client_on_out_of_band_count = 0;
   m_client_on_receive_count     = 0;
   m_client_on_send_count        = 0;


}

C_Client::~C_Client(void)
{
}

void C_Client::Set_Parent_Pointer( C_MFC_Winsock_01_Dlg *new_pointer )
{
   mp_main_dialog = new_pointer;
}

int  C_Client::Class_Get_WSA_Error_Code()
{
	return m_wsa_error;
}

bool C_Client::Class_Initialize()
{

	m_winsock_status = AfxSocketInit( NULL );
	m_wsa_error = WSAGetLastError();

	( m_winsock_status == 0 && m_wsa_error == 0) ? 
        m_method_status = false : 
        m_method_status = true;

	if( m_method_status == true )
	{
      // Does it make any difference if the port is create this way, or with
      // no arguments.
		//winsock_status = Create( m_port_number,
		//	                      SOCK_STREAM,
		//						       FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE,
		//						       DEFAULT_IP_ADDRESS );

      m_winsock_status = Create();
		m_wsa_error = WSAGetLastError();

		( m_winsock_status == 0 && m_wsa_error == 0) ? 
         m_method_status = false : 
         m_method_status = true;
	}
   

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );




return m_method_status;
} // end of: Class_Initialize()



bool C_Client::Class_Connect()
{


	m_winsock_status = CAsyncSocket::Connect( m_ip_address, m_port_number );
	m_wsa_error = WSAGetLastError();

	m_winsock_status == 0 ? m_method_status = false : m_method_status = true;

      // This could be done more elegantly, but I want to show 
      // that this was an enexpected empirical discovery and then
      // declared to be a sucessful condition.
   if( m_wsa_error == 10035 )
   {
      m_method_status = true;
   }

	return m_method_status;
}

bool C_Client::Class_Receive()
{

   int chars_received = 0;
   int size       = sizeof( m_current_time );
   chars_received = CAsyncSocket::Receive( (void *) &m_current_time, size,  0 );
   m_wsa_error = WSAGetLastError();

   chars_received == size ? m_method_status = true : m_method_status = false;
   return m_method_status;
}

SYSTEMTIME C_Client::Class_Get_Time()
{
   return m_current_time;
}

bool C_Client::Class_Close()
{
	CAsyncSocket::Close();
	m_wsa_error = WSAGetLastError();

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count = 0,
                                              m_client_on_close_count = 0,
                                              m_client_on_connect_count = 0,
                                              m_client_on_out_of_band_count = 0,
                                              m_client_on_receive_count = 0,
                                              m_client_on_send_count = 0 );

	return m_method_status;
}

/*  **************************************************************
    All the over rides for the base class are defined below
    **************************************************************  */

void C_Client::OnAccept(int nErrorCode)
{
   m_client_on_accept_count ++;
	int dummy_error_code = 0;
	CAsyncSocket::OnAccept( dummy_error_code );

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );

}

void C_Client::OnClose(int nErrorCode)
{
   m_client_on_close_count ++;
	int dummy_error_code = 0;
	CAsyncSocket::OnClose( dummy_error_code );

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );

}

void C_Client::OnConnect(int nErrorCode)
{
   m_client_on_connect_count ++;
	int dummy_error_code = 0;
	CAsyncSocket::OnConnect( dummy_error_code );

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );

}

void C_Client::OnOutOfBandData(int nErrorCode)
{
   m_client_on_out_of_band_count ++;

	int dummy_error_code = 0;
	CAsyncSocket::OnOutOfBandData( dummy_error_code );

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );

}

void C_Client::OnReceive(int nErrorCode)
{
   m_client_on_receive_count ++;
	int dummy_error_code = 0;
	CAsyncSocket::OnReceive( dummy_error_code );

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );

}

void C_Client::OnSend(int nErrorCode)
{
   m_client_on_send_count ++;
	int dummy_error_code = 0;
	CAsyncSocket::OnSend( dummy_error_code );

   mp_main_dialog->Set_Client_On_Call_Counts( m_client_on_accept_count,
                                              m_client_on_close_count,
                                              m_client_on_connect_count,
                                              m_client_on_out_of_band_count,
                                              m_client_on_receive_count,
                                              m_client_on_send_count );

}
// C_MFC_Winsock_01_Dlg.h : header file
//

#pragma once
#include "C_Server.h"
#include "C_Client.h"
#include "C_Server_Send_Time_Socket.h"
#include "afxwin.h"
#include "resource.h"
#include "Constants.h"


// C_MFC_Winsock_01_Dlg dialog
class C_MFC_Winsock_01_Dlg : public CDialog
{

// Construction
public:
	C_MFC_Winsock_01_Dlg(CWnd* pParent = NULL);	// standard constructor

	~C_MFC_Winsock_01_Dlg();



// Dialog Data
	enum { IDD = IDD_MFC_WINSOCK_01_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	C_Server m_C_Server;
	C_Client m_C_Client;

	bool  m_method_status;
	int   m_wsa_error_code;
   bool  m_okay_to_send_and_receive;
   TCHAR m_wsa_error_text[ WSA_ERROR_MAX_TEXT_LENGTH ];

   TCHAR m_on_call_count_text[ WSA_ERROR_MAX_TEXT_LENGTH ];
   TCHAR m_current_time[ 32 ];

   C_Server_Send_Time_Socket *mp_C_Server_Send_Time_Socket;



public:

      // Allows the Server class to send up the pointer to the object it
      // creates to handle the communications with the client.  Probably not 
      // needed for real server operations.
   void Set_Server_Send_Class_Pointer( C_Server_Send_Time_Socket *new_pointer );

   void  Set_Client_On_Call_Counts( unsigned int on_accept,
                                    unsigned int on_close,
                                    unsigned int on_connect,
                                    unsigned int on_out_band,
                                    unsigned int on_receive,
                                    unsigned int on_send );

   void  Set_Server_On_Call_Counts( unsigned int on_accept,
                                    unsigned int on_close,
                                    unsigned int on_connect,
                                    unsigned int on_out_band,
                                    unsigned int on_receive,
                                    unsigned int on_send );

   void  Set_Server_Send_On_Call_Counts( unsigned int on_accept,
                                         unsigned int on_close,
                                         unsigned int on_connect,
                                         unsigned int on_out_band,
                                         unsigned int on_receive,
                                         unsigned int on_send );

	afx_msg void OnBnClickedBtnServerInit();
	afx_msg void OnBnClickedBtnClientInit();
	afx_msg void OnBnClickedBtnServerListen();
	CStatic m_server_init_status;
	CStatic m_client_init_status;
	CStatic m_server_listen_status;
	CStatic m_server_accept_status;
	afx_msg void OnBnClickedBtnServerAccept();
	CButton cbtn_server_close;
	afx_msg void OnBnClickedBtnServerClose();
	CButton cbtn_client_close;
	afx_msg void OnBnClickedBtnClientClose();
	CButton btn_client_connect;
	afx_msg void OnBnClickedBtnClientConnect();
	afx_msg void OnStnClickedClientInitStatus();
	CStatic m_client_connect_status;
	CStatic m_client_wsa_error_text;
	CStatic m_server_wsa_error_text;
   CStatic m_client_show_on_accept;
   CStatic m_client_show_on_close;
   CStatic m_client_show_on_connect;
   CStatic m_client_show_on_out_band;
   CStatic m_client_show_on_receive;
   CStatic m_client_show_on_send;
   CStatic m_server_show_on_accept;
   CStatic m_server_show_on_close;
   CStatic m_server_show_on_connect;
   CStatic m_server_show_on_out_band;
   CStatic m_server_show_on_receive;
   CStatic m_server_show_on_send;
   afx_msg void OnBnClickedBtnServerSend();
   CStatic m_serv_send_show_on_accept;
   CStatic m_serv_send_show_on_close;
   CStatic m_serv_send_show_on_connect;
   CStatic m_serv_send_show_on_out_band;
   CStatic m_serv_send_show_on_receive;
   CStatic m_serv_send_show_on_send;
   afx_msg void OnBnClickedBtnServerSendSend();
   CStatic m_css_wsa_error_text;
   CStatic m_client_receive_status;
   afx_msg void OnBnClickedBtnClientReceive();
   CStatic m_client_received_time;
};

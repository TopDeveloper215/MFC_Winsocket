// MFC_Winsock_01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "C_MFC_Winsock_01.h"
#include "C_MFC_Winsock_01_Dlg.h"

#include "C_Server.h"
#include "C_Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};


CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// C_MFC_Winsock_01_Dlg dialog




C_MFC_Winsock_01_Dlg::C_MFC_Winsock_01_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C_MFC_Winsock_01_Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    
   mp_C_Server_Send_Time_Socket = NULL;
	m_method_status = false;
	m_wsa_error_code = 0;
   m_okay_to_send_and_receive = false;

}

C_MFC_Winsock_01_Dlg::~C_MFC_Winsock_01_Dlg()
{
   m_C_Server.Close();
	m_C_Client.Close();
}

void C_MFC_Winsock_01_Dlg::Set_Server_Send_Class_Pointer( C_Server_Send_Time_Socket *new_pointer )
{
   mp_C_Server_Send_Time_Socket = new_pointer;
}

void  C_MFC_Winsock_01_Dlg::Set_Client_On_Call_Counts( unsigned int on_accept,
                                                       unsigned int on_close,
                                                       unsigned int on_connect,
                                                       unsigned int on_out_band,
                                                       unsigned int on_receive,
                                                       unsigned int on_send )
{
   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_accept );
   m_client_show_on_accept.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_close );
   m_client_show_on_close.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_connect );
   m_client_show_on_connect.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_out_band );
   m_client_show_on_out_band.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_receive );
   m_client_show_on_receive.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_send );
   m_client_show_on_send.SetWindowText( m_on_call_count_text );

}

void  C_MFC_Winsock_01_Dlg::Set_Server_On_Call_Counts( unsigned int on_accept,
                                                       unsigned int on_close,
                                                       unsigned int on_connect,
                                                       unsigned int on_out_band,
                                                       unsigned int on_receive,
                                                       unsigned int on_send )
{
   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_accept );
   m_server_show_on_accept.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_close );
   m_server_show_on_close.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_connect );
   m_server_show_on_connect.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_out_band );
   m_server_show_on_out_band.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_receive );
   m_server_show_on_receive.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
      _countof( m_wsa_error_text ),  
      L"%d", 
      on_send );
   m_server_show_on_send.SetWindowText( m_on_call_count_text );

}

void  C_MFC_Winsock_01_Dlg::Set_Server_Send_On_Call_Counts( unsigned int on_accept,
                                                            unsigned int on_close,
                                                            unsigned int on_connect,
                                                            unsigned int on_out_band,
                                                            unsigned int on_receive,
                                                            unsigned int on_send )
{
   _stprintf_s(  m_on_call_count_text, 
                _countof( m_wsa_error_text ),  
                L"%d", 
                on_accept );
   m_serv_send_show_on_accept.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
                _countof( m_wsa_error_text ),  
                 L"%d", 
                 on_close );
   m_serv_send_show_on_close.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
                _countof( m_wsa_error_text ),  
                 L"%d", 
                 on_connect );
   m_serv_send_show_on_connect.SetWindowText( m_on_call_count_text );

   _stprintf_s(  m_on_call_count_text, 
                _countof( m_wsa_error_text ),  
                 L"%d", 
                 on_out_band );
   m_serv_send_show_on_out_band.SetWindowText( m_on_call_count_text );   

   _stprintf_s(  m_on_call_count_text, 
                _countof( m_wsa_error_text ),  
                 L"%d", 
                 on_receive );
   m_serv_send_show_on_receive.SetWindowText( m_on_call_count_text ); 

   _stprintf_s(  m_on_call_count_text, 
                _countof( m_wsa_error_text ),  
                 L"%d", 
                 on_send );
   m_serv_send_show_on_send.SetWindowText( m_on_call_count_text ); 

}


void C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerSend()
{
   // TODO: Add your control notification handler code here
   int count_sent = m_C_Server.Class_Send();
}

void C_MFC_Winsock_01_Dlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   DDX_Control(pDX, IDC_TXT_SERVER_INIT_STATUS, m_server_init_status);
   DDX_Control(pDX, IDC_TXT_CLIENT_INIT_STATUS, m_client_init_status);
   DDX_Control(pDX, IDC_TXT_SERVER_LISTEN_STATUS, m_server_listen_status);
   DDX_Control(pDX, IDC_TXT_SERVER_ACCEPT_STATUS, m_server_accept_status);
   DDX_Control(pDX, IDC_BTN_SERVER_CLOSE, cbtn_server_close);
   DDX_Control(pDX, IDC_BTN_CLIENT_CLOSE, cbtn_client_close);
   DDX_Control(pDX, IDC_BTN_CLIENT_CONNECT, btn_client_connect);
   DDX_Control(pDX, IDC_TXT_CLIENT_CONNECT_STATUS, m_client_connect_status);
   DDX_Control(pDX, IDC_CLIENT_WSA_TEXT, m_client_wsa_error_text);
   DDX_Control(pDX, IDC_TXT_SERVER_WSA, m_server_wsa_error_text);
   DDX_Control(pDX, IDC_TXT_CLIENT_ON_ACCEPT, m_client_show_on_accept);
   DDX_Control(pDX, IDC_TXT_CLIENT_ON_CLOSE, m_client_show_on_close);
   DDX_Control(pDX, IDC_TXT_CLIENT_ON_CONNECT, m_client_show_on_connect);
   DDX_Control(pDX, IDC_TXT_CLIENT_ON_OUT_BAND, m_client_show_on_out_band);
   DDX_Control(pDX, IDC_TXT_CLIENT_ON_RECEIVE, m_client_show_on_receive);
   DDX_Control(pDX, IDC_TXT_CLIENT_ON_SEND, m_client_show_on_send);
   DDX_Control(pDX, IDC_TXT_SERVER_ON_ACCEPT, m_server_show_on_accept);
   DDX_Control(pDX, IDC_TXT_SERVER_ON_CLOSE, m_server_show_on_close);
   DDX_Control(pDX, IDC_TXT_SERVER_ON_CONNECT, m_server_show_on_connect);
   DDX_Control(pDX, IDC_TXT_SERVER_ON_OUT_BAND2, m_server_show_on_out_band);
   DDX_Control(pDX, IDC_TXT_SERVER_ON_RECEIVE2, m_server_show_on_receive);
   DDX_Control(pDX, IDC_TXT_SERVER_ON_SEND2, m_server_show_on_send);
   DDX_Control(pDX, IDC_TXT_SERV_SEND_ON_ACCEPT, m_serv_send_show_on_accept);
   DDX_Control(pDX, IDC_TXT_SERV_SEND_ON_CLOSE, m_serv_send_show_on_close);
   DDX_Control(pDX, IDC_TXT_SERV_SEND_ON_CONNECT, m_serv_send_show_on_connect);
   DDX_Control(pDX, IDC_TXT_SERV_SEND_ON_OUT_BAND, m_serv_send_show_on_out_band);
   DDX_Control(pDX, IDC_TXT_SERV_SEND_ON_RECEIVE, m_serv_send_show_on_receive);
   DDX_Control(pDX, IDC_TXT_SERV_SEND_ON_SEND, m_serv_send_show_on_send);
   DDX_Control(pDX, IDC_TEXT_CSS_WSA, m_css_wsa_error_text);
   DDX_Control(pDX, IDC_TXT_CLIENT_RECEIVE_STATUS, m_client_receive_status);
   DDX_Control(pDX, IDC_TXT_CLIENT_RCVD_TIME, m_client_received_time);
}

BEGIN_MESSAGE_MAP(C_MFC_Winsock_01_Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_SERVER_INIT, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerInit)
	ON_BN_CLICKED(IDC_BTN_CLIENT_INIT, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientInit)
	ON_BN_CLICKED(IDC_BTN_SERVER_LISTEN, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerListen)
	ON_BN_CLICKED(IDC_BTN_SERVER_ACCEPT, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerAccept)
	ON_BN_CLICKED(IDC_BTN_SERVER_CLOSE, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerClose)
	ON_BN_CLICKED(IDC_BTN_CLIENT_CLOSE, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientClose)
	ON_BN_CLICKED(IDC_BTN_CLIENT_CONNECT, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientConnect)
	ON_STN_CLICKED(IDC_TXT_CLIENT_INIT_STATUS, &C_MFC_Winsock_01_Dlg::OnStnClickedClientInitStatus)
   ON_BN_CLICKED(IDC_BTN_SERVER_SEND, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerSend)
   ON_BN_CLICKED(IDC_BTN_SERVER_SEND_SEND, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerSendSend)
   ON_BN_CLICKED(IDC_BTN_CLIENT_RECEIVE, &C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientReceive)
END_MESSAGE_MAP()


// C_MFC_Winsock_01_Dlg message handlers

BOOL C_MFC_Winsock_01_Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_server_init_status.SetWindowText(   L"None" );
	m_client_init_status.SetWindowText(   L"None" );
	m_server_listen_status.SetWindowText( L"None" );

   m_C_Server.Set_Parent_Pointer( this );
   m_C_Client.Set_Parent_Pointer( this );

m_server_show_on_accept.SetWindowText(   L"0" );
m_server_show_on_close.SetWindowText(    L"0" );
m_server_show_on_connect.SetWindowText(  L"0" );
m_server_show_on_out_band.SetWindowText( L"0" );
m_server_show_on_receive.SetWindowText(  L"0" );
m_server_show_on_send.SetWindowText(     L"0" );

m_client_show_on_accept.SetWindowText(   L"0" );
m_client_show_on_close.SetWindowText(    L"0" );
m_client_show_on_connect.SetWindowText(  L"0" );
m_client_show_on_out_band.SetWindowText( L"0" );
m_client_show_on_receive.SetWindowText(  L"0" );
m_client_show_on_send.SetWindowText(     L"0" );

m_serv_send_show_on_accept.SetWindowText(   L"0" );
m_serv_send_show_on_close.SetWindowText(    L"0" );
m_serv_send_show_on_connect.SetWindowText(  L"0" );
m_serv_send_show_on_out_band.SetWindowText( L"0" );
m_serv_send_show_on_receive.SetWindowText(  L"0" );
m_serv_send_show_on_send.SetWindowText(     L"0" );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void C_MFC_Winsock_01_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void C_MFC_Winsock_01_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR C_MFC_Winsock_01_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/* *******************************************************
   SERVER methods begin here
   *******************************************************  */

void C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerInit()
{
//  m_server_wsa_error_text


      m_method_status = m_C_Server.Class_Initialize();


   m_wsa_error_code = m_C_Server.Class_Get_WSA_Error_Code();
   _stprintf_s( m_wsa_error_text, 
		          _countof( m_wsa_error_text ),  
                L"Init: %d", 
				    m_wsa_error_code );

   m_server_wsa_error_text.SetWindowText( m_wsa_error_text );

	m_method_status == true ? m_server_init_status.SetWindowText( L"OK" ) :
		                    m_server_init_status.SetWindowText( L"Error" );

}





void C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerListen()
{
		m_method_status = m_C_Server.Class_Listen();

      m_wsa_error_code = m_C_Server.Class_Get_WSA_Error_Code();
      m_server_wsa_error_text.SetWindowText( m_wsa_error_text );
      _stprintf_s( m_wsa_error_text, 
		            _countof( m_wsa_error_text ),  
		             L"Listen %d", 
				       m_wsa_error_code );

      m_server_wsa_error_text.SetWindowText( m_wsa_error_text );


	m_method_status == true ? m_server_listen_status.SetWindowText( L"OK" ) :
                             m_server_listen_status.SetWindowText( L"Error" );

}

void C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerAccept()
{
	
	bool method_status = false;

		method_status = m_C_Server.Class_Accept();

      m_wsa_error_code = m_C_Server.Class_Get_WSA_Error_Code();
      m_server_wsa_error_text.SetWindowText( m_wsa_error_text );
      _stprintf_s( m_wsa_error_text, 
		            _countof( m_wsa_error_text ),  
		             L"Accept %d", 
				       m_wsa_error_code );

      m_server_wsa_error_text.SetWindowText( m_wsa_error_text );


	method_status == true ? m_server_accept_status.SetWindowText( L"OK" ) :
		                    m_server_accept_status.SetWindowText( L"Error" );

      if( method_status == true )
      {
         m_okay_to_send_and_receive = true;
      }
}

void C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerClose()
{
	m_server_init_status.SetWindowText(   L"None" );
	m_server_listen_status.SetWindowText( L"None" );
   m_server_accept_status.SetWindowText( L"None" );

	m_C_Server.Class_Close();
   m_wsa_error_code = m_C_Server.Class_Get_WSA_Error_Code();

   _stprintf_s( m_wsa_error_text, 
	            _countof( m_wsa_error_text ),  
	           L"Close %d", 
	             m_wsa_error_code );

   m_server_wsa_error_text.SetWindowText( m_wsa_error_text );
}

/* *******************************************************
   CLIENT methods begin here
   *******************************************************  */


void C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientInit()
{
		m_method_status = m_C_Client.Class_Initialize();
        m_wsa_error_code = m_C_Client.Class_Get_WSA_Error_Code();

        _stprintf_s( m_wsa_error_text, 
			         _countof( m_wsa_error_text ),  
					 _T("Init %5d"), 
					 m_wsa_error_code );

	    m_client_wsa_error_text.SetWindowText( m_wsa_error_text );

	if( m_wsa_error_code != 0 )
		m_method_status = false;

	m_method_status == true ? m_client_init_status.SetWindowText( L"OK" ) :
		                    m_client_init_status.SetWindowText( L"Error" );
}



void C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientConnect()
{
//	button variable is:          btn_client_connect
//  the static text variable is: m_client_connect_status



	m_method_status = m_C_Client.Class_Connect();
	m_wsa_error_code = m_C_Client.Class_Get_WSA_Error_Code();

    _stprintf_s( m_wsa_error_text, 
		         _countof( m_wsa_error_text ),  
				 L"Connect %d", 
				 m_wsa_error_code );

	m_client_wsa_error_text.SetWindowText( m_wsa_error_text );

   if( m_method_status == true && m_wsa_error_code == 0 )
   {
      m_client_connect_status.SetWindowText( L"No Error" );
   }
   else if( m_method_status == true && m_wsa_error_code == 10035 )
   {
      m_client_connect_status.SetWindowText( L"OK Connected" );
   }
   else
   {
      m_client_connect_status.SetWindowText( L"Error" );
   }

}

void C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientClose()
{
// variable is: cbtn_client_close

	m_client_init_status.SetWindowText(    L"None" );
	m_client_connect_status.SetWindowText( L"None" );

	m_C_Client.Class_Close();

	m_wsa_error_code = m_C_Client.Class_Get_WSA_Error_Code();

    _stprintf_s(  m_wsa_error_text, 
		           _countof( m_wsa_error_text ),  
				      L"%Close d", 
				      m_wsa_error_code );

	m_client_wsa_error_text.SetWindowText( m_wsa_error_text );
}

// I think this was an accident
void C_MFC_Winsock_01_Dlg::OnStnClickedClientInitStatus()
{
	// TODO: Add your control notification handler code here
}


void C_MFC_Winsock_01_Dlg::OnBnClickedBtnServerSendSend()
{
   m_wsa_error_code = 0;
   if( m_okay_to_send_and_receive )
   {
      mp_C_Server_Send_Time_Socket->Class_Send( );

      m_wsa_error_code = mp_C_Server_Send_Time_Socket->Class_Get_WSA_Error_Code();

      _stprintf_s(  m_wsa_error_text, 
         _countof( m_wsa_error_text ),  
         L"Send %d", 
         m_wsa_error_code );
   }
   else
   {
      _stprintf_s(  m_wsa_error_text, 
         _countof( m_wsa_error_text ),  
         L"No Send %d", 
         m_wsa_error_code );
   }

   m_css_wsa_error_text.SetWindowText( m_wsa_error_text );

}


void C_MFC_Winsock_01_Dlg::OnBnClickedBtnClientReceive()
{
   bool method_status = m_C_Client.Class_Receive();

   method_status == true ? m_client_receive_status.SetWindowText( L"OK" ) :
                          m_client_receive_status.SetWindowText( L"Error" ) ;


   SYSTEMTIME current_time = m_C_Client.Class_Get_Time();
   _stprintf_s(  m_current_time, 
		           _countof( m_current_time ),  
                 L"%02d:%02d:%02d.%03d", 
				      current_time.wHour,
                  current_time.wMinute,
                  current_time.wSecond,
                  current_time.wMilliseconds );


   m_client_received_time.SetWindowText( m_current_time );
}

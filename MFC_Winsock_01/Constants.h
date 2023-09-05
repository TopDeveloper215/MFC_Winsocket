/*
file name Constants.h
*/
#pragma once

const UINT DEFAULT_SOCKET_PORT = 49000;

  // because the Create() method wants an argument formated
  // as LPCTSTR
   // max length IPv4 is "111.111.111.111" = 15 characters so make is 20 to be safe.
   //     length IPV6 is "1111:2222:3333:4444:5555:6666:7777:8888"  49 digits, make it 64
const unsigned int MAX_IP_ADDRESS_LENGTH = 64;
const TCHAR DEFAULT_IP_ADDRESS[] = _T("127.0.0.1");

const unsigned int WSA_ERROR_MAX_TEXT_LENGTH = 16;

const int WSA_WOULD_BLOCK = 10035;
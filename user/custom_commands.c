//Copyright 2015 <>< Charles Lohr, see LICENSE file.

#include <commonservices.h>
#include "esp82xxutil.h"
//#include "max7219.h"
#include "httpclient.h"

int ICACHE_FLASH_ATTR CustomCommand(char * buffer, int retsize, char *pusrdata, unsigned short len) {
	char * buffend = buffer;

	switch( pusrdata[1] ) {
		// Custom command test
		case 'C': case 'c':
			buffend += ets_sprintf( buffend, "CC" );
        	printf("CC");
			return buffend-buffer;
		break;

		// Echo to UART
		case 'E': case 'e':
			if( retsize <= len ) return -1;
			ets_memcpy( buffend, &(pusrdata[2]), len-2 );
			buffend[len-2] = '\0';
			printf( "%s\n", buffend );
			return len-2;
		break;
		case 'D': case 'd':
			if( retsize <= len ) return -1;
			// if ((scanf("%d",&n) != 1) && (len < 10)) // validate input
			// 	break;
			http_get("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=LJML3D84VX35SP1X", "", http_callback_example);
			//ets_memcpy( buffend, pusrdata, len );
			//max7219_writeInt(12);
			return len;
		break;
	}



	return -1;
}
// void ICACHE_FLASH_ATTR http_callback_example(char * response_body, int http_status, char * response_headers, int body_size)
// {
// 	printf("http_status=%d\n", http_status);
// 	if (http_status != HTTP_STATUS_GENERIC_ERROR) {
// 		printf("strlen(headers)=%d\n", strlen(response_headers));
// 		printf("body_size=%d\n", body_size);
// 		printf("body=%s<EOF>\n", response_body); // FIXME: this does not handle binary data.
// 	}
// }

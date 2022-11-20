#ifndef COLOR_H
#define COLOR_H

#if defined LINUX || defined OSX

// set color
#define BLK		"\e[30m"
#define RED 	"\e[31m"
#define GRN 	"\e[32m"
#define YEL 	"\e[33m"
#define BLU 	"\e[34m"
#define MAG 	"\e[35m"
#define CYN 	"\e[36m"
#define WHT 	"\e[37m"

// set light color
#define LBLK	"\e[0;30m"
#define LRED 	"\e[0;31m"
#define LGRN 	"\e[0;32m"
#define LYEL 	"\e[0;33m"
#define LBLU 	"\e[0;34m"
#define LMAG 	"\e[0;35m"
#define LCYN 	"\e[0;36m"
#define LWHT 	"\e[0;37m"

// set bold color
#define BBLK	"\e[1;30m"
#define BRED 	"\e[1;31m"
#define BGRN 	"\e[1;32m"
#define BYEL 	"\e[1;33m"
#define BBLU 	"\e[1;34m"
#define BMAG 	"\e[1;35m"
#define BCYN 	"\e[1;36m"
#define BWHT 	"\e[1;37m"

// set background
#define BLKB	"\e[40m"
#define REDB	"\e[41m"
#define GRNB 	"\e[42m"
#define YELB 	"\e[43m"
#define BLUB 	"\e[44m"
#define MAGB 	"\e[45m"
#define CYNB 	"\e[46m"
#define WHTB 	"\e[47m"

#define RESET	"\e[0m"
#define RES 	RESET

#endif // LINUX | OSX

#endif // COLOR_H
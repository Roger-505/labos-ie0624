;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
; PIC port for the 14-bit core
;--------------------------------------------------------
;	.file	"dado.c"
	list	p=12f675
	radix dec
	include "p12f675.inc"
;--------------------------------------------------------
; config word(s)
;--------------------------------------------------------
	__config 0x3ff7
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	__moduint
	extern	_ANSEL
	extern	_ADRESL
	extern	_TRISIO
	extern	_ADRESH
	extern	_CMCON
	extern	_GPIO
	extern	_ADCON0bits
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main
	global	_setupIO
	global	_setupADC
	global	_leerADC
	global	_mostrarDado

	global PSAVE
	global SSAVE
	global WSAVE
	global STK12
	global STK11
	global STK10
	global STK09
	global STK08
	global STK07
	global STK06
	global STK05
	global STK04
	global STK03
	global STK02
	global STK01
	global STK00

sharebank udata_ovr 0x0020
PSAVE	res 1
SSAVE	res 1
WSAVE	res 1
STK12	res 1
STK11	res 1
STK10	res 1
STK09	res 1
STK08	res 1
STK07	res 1
STK06	res 1
STK05	res 1
STK04	res 1
STK03	res 1
STK02	res 1
STK01	res 1
STK00	res 1

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_dado_0	udata
r0x1007	res	1
r0x1006	res	1
r0x1002	res	1
r0x1003	res	1
r0x1005	res	1
r0x1004	res	1
r0x1001	res	1
r0x1000	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; initialized absolute data
;--------------------------------------------------------
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; reset vector 
;--------------------------------------------------------
STARTUP	code 0x0000
	nop
	pagesel __sdcc_gsinit_startup
	goto	__sdcc_gsinit_startup
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_dado	code
;***
;  pBlock Stats: dbName = M
;***
;has an exit
;functions called:
;   _setupIO
;   _setupADC
;   _leerADC
;   __moduint
;   _mostrarDado
;   _setupIO
;   _setupADC
;   _leerADC
;   __moduint
;   _mostrarDado
;5 compiler assigned registers:
;   r0x1006
;   STK00
;   r0x1007
;   STK02
;   STK01
;; Starting pCode block
S_dado__main	code
_main:
; 2 exit points
;	.line	81; "dado.c"	setupIO();
	PAGESEL	_setupIO
	CALL	_setupIO
	PAGESEL	$
;	.line	82; "dado.c"	setupADC();
	PAGESEL	_setupADC
	CALL	_setupADC
	PAGESEL	$
;	.line	85; "dado.c"	unsigned int num_dado = (leerADC() % 6) + 1;
	PAGESEL	_leerADC
	CALL	_leerADC
	PAGESEL	$
	MOVWF	r0x1006
	MOVF	STK00,W
	MOVWF	r0x1007
	MOVLW	0x06
	MOVWF	STK02
	MOVLW	0x00
	MOVWF	STK01
	MOVF	r0x1007,W
	MOVWF	STK00
	MOVF	r0x1006,W
	PAGESEL	__moduint
	CALL	__moduint
	PAGESEL	$
	MOVWF	r0x1006
	MOVF	STK00,W
	MOVWF	r0x1007
	INCF	r0x1007,F
	BTFSC	STATUS,2
	INCF	r0x1006,F
_00106_DS_:
;	.line	89; "dado.c"	mostrarDado(num_dado);
	MOVF	r0x1007,W
	MOVWF	STK00
	MOVF	r0x1006,W
	PAGESEL	_mostrarDado
	CALL	_mostrarDado
	PAGESEL	$
	GOTO	_00106_DS_
;	.line	91; "dado.c"	}
	RETURN	
; exit point of _main

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;3 compiler assigned registers:
;   r0x1000
;   STK00
;   r0x1001
;; Starting pCode block
S_dado__mostrarDado	code
_mostrarDado:
; 2 exit points
;	.line	116; "dado.c"	void mostrarDado(unsigned int num_dado)
	MOVWF	r0x1000
	MOVF	STK00,W
	MOVWF	r0x1001
;;unsigned compare: left < lit(0x1=1), size=2
;	.line	118; "dado.c"	switch (num_dado)
	MOVLW	0x00
	SUBWF	r0x1000,W
	BTFSS	STATUS,2
	GOTO	_00141_DS_
	MOVLW	0x01
	SUBWF	r0x1001,W
_00141_DS_:
	BTFSS	STATUS,0
	GOTO	_00131_DS_
;;genSkipc:3307: created from rifx:0x7ffc22d955e0
;;swapping arguments (AOP_TYPEs 1/2)
;;unsigned compare: left >= lit(0x7=7), size=2
	MOVLW	0x00
	SUBWF	r0x1000,W
	BTFSS	STATUS,2
	GOTO	_00142_DS_
	MOVLW	0x07
	SUBWF	r0x1001,W
_00142_DS_:
	BTFSC	STATUS,0
	GOTO	_00131_DS_
;;genSkipc:3307: created from rifx:0x7ffc22d955e0
	DECF	r0x1001,F
	MOVLW	HIGH(_00143_DS_)
	MOVWF	PCLATH
	MOVLW	_00143_DS_
	ADDWF	r0x1001,W
	BTFSC	STATUS,0
	INCF	PCLATH,F
	MOVWF	PCL
_00143_DS_:
	GOTO	_00124_DS_
	GOTO	_00125_DS_
	GOTO	_00126_DS_
	GOTO	_00127_DS_
	GOTO	_00128_DS_
	GOTO	_00129_DS_
_00124_DS_:
;	.line	121; "dado.c"	GPIO = 0x20;    
	MOVLW	0x20
	BANKSEL	_GPIO
	MOVWF	_GPIO
;	.line	122; "dado.c"	break;
	GOTO	_00131_DS_
_00125_DS_:
;	.line	124; "dado.c"	GPIO = 0x04;    
	MOVLW	0x04
	BANKSEL	_GPIO
	MOVWF	_GPIO
;	.line	125; "dado.c"	break;
	GOTO	_00131_DS_
_00126_DS_:
;	.line	127; "dado.c"	GPIO = 0x30;   
	MOVLW	0x30
	BANKSEL	_GPIO
	MOVWF	_GPIO
;	.line	128; "dado.c"	break;
	GOTO	_00131_DS_
_00127_DS_:
;	.line	130; "dado.c"	GPIO = 0x12;  
	MOVLW	0x12
	BANKSEL	_GPIO
	MOVWF	_GPIO
;	.line	131; "dado.c"	break;
	GOTO	_00131_DS_
_00128_DS_:
;	.line	133; "dado.c"	GPIO = 0x32; 
	MOVLW	0x32
	BANKSEL	_GPIO
	MOVWF	_GPIO
;	.line	134; "dado.c"	break;
	GOTO	_00131_DS_
_00129_DS_:
;	.line	136; "dado.c"	GPIO = 0x16;
	MOVLW	0x16
	BANKSEL	_GPIO
	MOVWF	_GPIO
_00131_DS_:
;	.line	139; "dado.c"	}
	RETURN	
; exit point of _mostrarDado

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;5 compiler assigned registers:
;   r0x1002
;   r0x1003
;   r0x1004
;   r0x1005
;   STK00
;; Starting pCode block
S_dado__leerADC	code
_leerADC:
; 2 exit points
;	.line	110; "dado.c"	GO_DONE = 1;    
	BANKSEL	_ADCON0bits
	BSF	_ADCON0bits,1
_00119_DS_:
;	.line	111; "dado.c"	while (GO_DONE) // esperar a que la conversión ADC termine
	BANKSEL	_ADCON0bits
	BTFSC	_ADCON0bits,1
	GOTO	_00119_DS_
;	.line	113; "dado.c"	return (ADRESH<<8) + ADRESL;  
	MOVF	_ADRESH,W
	MOVWF	r0x1004
	MOVWF	r0x1002
	CLRF	r0x1003
;;99	MOVF	r0x1002,W
	CLRF	r0x1005
	BANKSEL	_ADRESL
	MOVF	_ADRESL,W
	MOVWF	r0x1002
	CLRF	r0x1003
	MOVF	r0x1002,W
	ADDWF	r0x1005,F
	MOVLW	0x00
	BTFSC	STATUS,0
	INCFSZ	r0x1003,W
	ADDWF	r0x1004,F
	MOVF	r0x1005,W
	MOVWF	STK00
	MOVF	r0x1004,W
;	.line	114; "dado.c"	}
	RETURN	
; exit point of _leerADC

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
S_dado__setupADC	code
_setupADC:
; 2 exit points
;	.line	102; "dado.c"	ANSEL |= 0x70;  
	MOVLW	0x70
	BANKSEL	_ANSEL
	IORWF	_ANSEL,F
;	.line	103; "dado.c"	CMCON |= 0x07;  
	MOVLW	0x07
	BANKSEL	_CMCON
	IORWF	_CMCON,F
;	.line	104; "dado.c"	ADFM = 1;       
	BSF	_ADCON0bits,7
;	.line	105; "dado.c"	ADON = 1;       
	BSF	_ADCON0bits,0
;	.line	106; "dado.c"	}
	RETURN	
; exit point of _setupADC

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
S_dado__setupIO	code
_setupIO:
; 2 exit points
;	.line	95; "dado.c"	TRISIO &= 0x09; 
	MOVLW	0x09
	BANKSEL	_TRISIO
	ANDWF	_TRISIO,F
;	.line	96; "dado.c"	ANSEL &= 0x71;  
	MOVLW	0x71
	ANDWF	_ANSEL,F
;	.line	97; "dado.c"	GPIO &= 0x08;   
	MOVLW	0x08
	BANKSEL	_GPIO
	ANDWF	_GPIO,F
;	.line	98; "dado.c"	}
	RETURN	
; exit point of _setupIO


;	code size estimation:
;	  112+   23 =   135 instructions (  316 byte)

	end

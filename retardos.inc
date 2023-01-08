;--------------------------------------------------------------------------
    ;@file    retardos.inc
    ;@autor   Jersson Alexander Castillo Machuca
    ;@date    08/01/2023
    ;MPLAB X IDE
    ;@version 6.00
    ;Este proyecto es una libreria de retardos la cual trabajara para 
    ;determinados tiempos (10us, 25us, 50us, 100us, 200us, 250us, 500us, 1ms,
    ;5ms, 10ms, 25ms, 50ms, 100ms, 200ms, 250ms)
    ;Frecuencia a trabajar = 4MHz
    ;TCY= 1us
    ;----------------------------------------------------------------------
    
    
PSECT udata_acs
variable1: DS 1      ;reserva un comentario en access ram
variable2: DS 1      ;reserva un comentario en access ram
  
PSECT code
    
;Retardo1 de 10us
;T=(6+4j1)*TCY 
			    
Delay_10us:                  ;  2TCY---CALL
    MOVLW  1                 ;  1TCY.... w=j1
    MOVWF  variable1,0       ;  1TCY
Loop1:   
    NOP                      ;  j1*TCY
    DECFSZ variable1,1,0     ;  (j1-1) + 3*TCY
    GOTO   Loop1             ;  (j1-1)*2TCY
    RETURN                   ;  2*TCY
    
; Retardo2 de 25us
;T=(6+4j1)*TCY 
    
Delay_25us:                  ;  2TCY---CALL
    MOVLW  5                 ;  1TCY.... w=j1
    MOVWF  variable1,0       ;  1TCY
Loop2:   
    NOP                      ;  j1*TCY
    DECFSZ variable1,1,0     ;  (j1-1) + 3*TCY
    GOTO   Loop2             ;  (j1-1)*2TCY
    RETURN                   ;  2*TCY
    
; Retardo3 de 50us
;T=(6+4j1)*TCY   
    
Delay_50us:                  ;  2TCY---CALL
    MOVLW  11                ;  1TCY.....w=j1
    MOVWF  variable1,0       ;  1TCY
Loop3:
    NOP                      ;  j1*TCY
    DECFSZ variable1,1,0     ;  (j1-1) + 3*TCY
    GOTO   Loop3             ;  (j1-1)*2TCY
    RETURN                   ;  2*TCY
                                  
                                  
; Retardo4 de 100us           
;T=(6+4j1)*TCY  
    
Delay_100us:                 ;  2TCY---CALL
    MOVLW  24                ;  1TCY....w=j1
    MOVWF  variable1,0       ;  1TCY
Loop4:
    NOP                      ;  j1*TCY
    DECFSZ variable1,1,0     ;  (j1-1) + 3*TCY
    GOTO   Loop4             ;  (j1-1)*2TCY
    RETURN                   ;  2*TCY

      
; Retardo5 de 200us
;T=(6+4j1)*TCY 
    
Delay_200us:                 ;  2TCY---CALL
    MOVLW  49                ;  1TCY
    MOVWF  variable1,0       ;  1TCY
Loop5:
    NOP                      ;  j1*TCY
    DECFSZ variable1,1,0     ;  (j1-1) + 3*TCY
    GOTO   Loop5             ;  (j1-1)*2TCY
    RETURN                   ;  2TCY

; Retardo6 de 250us
;T=(6+4j1)*TCY  
    
Delay_250us:             ; 2TCY---CALL
    MOVLW  61                ;  1TCY
    MOVWF  variable1,0       ;  1TCY
Loop6:
    NOP                      ;  j1*TCY
    DECFSZ variable1,1,0     ;  (j1-1) + 3*TCY
    GOTO   Loop6             ;  (j1-1)*2TCY
    RETURN                   ;  2TCY

    
; Retardo7 de 500us
;T=(6+4j1)*TCY  
    
Delay_500us:                 ;   2TCY---CALL
    MOVLW  124               ;   1TCY
    MOVWF  variable1,0       ;   1TCY
Loop7:
    NOP                      ;   j2*j1*TCY
    DECFSZ variable1,1,0     ;   (j1-1) + 3*TCY
    GOTO   Loop7             ;   (j1-1)*2TCY
    RETURN                   ;   2*TCY
    
    
; Retardo8 de 1ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+ j2*(1us)+ 6us
      
Delay_1ms:                    ;  2TCY---Call
    MOVLW  1                  ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext1:  
    MOVLW  249                ;  j2*TCY..... j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int1:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int1          ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext1          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY

  
; Retardo9 de 5ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+ j2*(1us)+ 6us
      
Delay_5ms:                    ;  2TCY---Call
    MOVLW  5                  ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
    ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext2:  
    MOVLW  249                ;  j2*TCY.....j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int2:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int2          ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext2          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY
    
    
; Retardo10 de 10ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+j2*(1us)+ 6us
    
Delay_10ms:                   ;  2TCY---Call
    MOVLW  10                 ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
    ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext3:  
    MOVLW  249                ;  j2*TCY.....j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int3:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int3          ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext3          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY
    
   
; Retardo11 de 25ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+j2*(1us)+ 6us 
        
Delay_25ms:                   ;  2TCY---Call
    MOVLW  25                 ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
      ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext4:  
    MOVLW  249                ;  j2*TCY.....j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int4:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int4         ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext4         ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY
    
    
; Retardo12 de 50ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+j2*(1us)+ 6us 
    
Delay_50ms:                   ;  2TCY---Call
    MOVLW  50                 ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
    ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext5:  
    MOVLW  249                ; j2*TCY.....j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int5:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int5          ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext5          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY  
                                  
                                   
; Retardo13 de 100ms            
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+ j2*(1us)+ 6us 
Delay_100ms:                  ;  2TCY---Call
    MOVLW  100                ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
    ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext6:                          
    MOVLW  249                ;  j2*TCY....j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int6:                             
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int6          ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext6          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY
   
    
; Retardo14 200ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+ j2*(1us)+ 6us 
Delay_200ms:                  ;  2TCY---Call
    MOVLW  200                ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
   ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext7:  
    MOVLW  249                ;  j2*TCY....j1=249
    MOVWF  variable1,0        ;  j2*TCU
Loop_int7:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*TCY)
    GOTO   Loop_int7         ;   j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext7          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY
    
    
; Retardo15 de 250ms
;T= (j2*(6+4(j1)us))+j2*(1us)+ 6*(1us)= (j2*(6+4(249)us))+ j2*(1us)+ 6us
    
Delay_250ms:                  ;  2TCY---Call
    MOVLW  250                ;  1TCY... w=j2
    MOVWF  variable2,0        ;  1TCY
    ; T= (6+4j1)ua= (6+4*(249))= 1ms 
Loop_ext8:  
    MOVLW  249                ;  j2*TCY.....j1=249
    MOVWF  variable1,0        ;  j2*TCY
Loop_int8:
    Nop                       ;  j2*j1*TCY
    DECFSZ variable1,1,0      ;  j2*((j1-1) + 3*Tcy)
    GOTO   Loop_int8          ;  j2((j1-1)*2TCY)
    DECFSZ variable2,1,0      ;  (j2-1) + 3*TCY
    GOTO   Loop_ext8          ;  (j2-1)*2TCY
    RETURN                    ;  2*TCY	




.section .text
.globl read_mvendorid  
.globl read_marchid    


read_mvendorid:
    csrr    a0, 0xF11      
    ret                    


read_marchid:
    csrr    a0, 0xF12   
    li      t0, 0x10002008  
    sw      a0, 0(t0)     
    ret                    